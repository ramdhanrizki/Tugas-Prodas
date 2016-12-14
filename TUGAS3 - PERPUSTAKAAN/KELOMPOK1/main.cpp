#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

const int MAX_DATA = 100;
const int DENDA = 10000; // denda bisa diubah terserah kesepakatan
int i;
int jumlah_buku;

// Deklarasi struct
typedef struct
{
   int tanggal;
   int bulan;
   int tahun;
} tanggal;

typedef struct
{
   int kode;
   char nama_peminjam[61];
   char alamat_peminjam[81];
   int kode_buku;
   char judul_buku[81];
   tanggal tgl_pinjam;
   int jumlah_pinjam; 
} dataPeminjaman;

typedef struct
{
   int kode;
   char judul[81];
   char pengarang[61];
   char penerbit[61];
   int stok;
} dataBuku;

typedef struct
{
    int kode_peminjaman;
    char nama_peminjam[61];
    int kode_buku;
    char judul_buku[81];
    tanggal tgl_kembali;
    int lama;
    int biaya_pinjam;
} dataPengembalian;



// variabel Global
dataBuku            buku[MAX_DATA];
dataPeminjaman      peminjaman[MAX_DATA];
dataPengembalian    pengembalian[MAX_DATA];
tanggal tgl_sekarang; 
// pointer penunjuk indeks terakhir dari array
int                 ptrBuku = -1;
int                 ptrPeminjaman = -1;
int                 ptrPengembalian = -1;



//Inisialisasi Procedure
void cetak_menu();
void menu_buku();
void menu_peminjaman();
void menu_pengembalian();
void cetak_buku();
void cari_buku();
void tambah_buku();
void edit_buku();
void hapus_buku();

//fungsi generate tanggal sekarang 
tanggal generate_tanggal()
{
   tanggal temp;      
   time_t now = time(0);
   tm *ltm = localtime(&now);
   temp.tanggal = ltm->tm_mday;
   temp.bulan = 1 + ltm->tm_mon;
   temp.tahun = 1900 + ltm->tm_year;      
   return temp; 
}
//fungsi menghitung selisih hari dari 2 tanggal
int selisih_hari(tanggal tanggal1,tanggal tanggal2)
{
    //kurangi
    int hari=0; 
    hari += tanggal2.tanggal-tanggal1.tanggal;
    hari += (tanggal2.bulan-tanggal1.bulan) * 30;
    hari += (tanggal2.tahun-tanggal1.tahun) * 365; 
    return hari;
}

//program utama 
int main(int argc, char *argv[])
{
    int menu;

    do {
        cetak_menu();
        cout<<"Menu yang dipilih  : ";
        cin>>menu;

        switch(menu)
        {
            case 1:
                 menu_buku();
                 break;
            case 2:
                 menu_peminjaman();
                 break;
            case 3:
                 menu_pengembalian();
                 break;
            case 4:
                 cout<<"Terimakasih telah menggunakan program kami..";
                 getch();
        }
    } while(menu!=4);
    return EXIT_SUCCESS;
}

//end of main program 


void cetak_menu()
{
    system("cls");
    cout<<"SISTEM INFORMASI PERPUSTAKAAN"<<endl;
    cout<<"         UNIKOM BANDUNG      "<<endl;
    cout<<"============================="<<endl;
    cout<<"1. Buku"<<endl;
    cout<<"2. Peminjaman"<<endl;
    cout<<"3. Pengembalian"<<endl;
    cout<<"4. Keluar"<<endl;
}

void cetak_buku()
{
    system("cls");
    cout<<"CETAK BUKU"<<endl;
    cout<<"=========="<<endl;

    if (ptrBuku == -1) {
        cout<<"Tidak ada data!"<<endl;
    } else {
        for (i = 0; i <= ptrBuku; i++) {
           cout<<"["<<i+1<<"]."<<endl;
           cout<<"==========================================="<<endl;
           cout<<"| Judul     = "<<buku[i].judul<<endl;
           cout<<"| Kode      = "<<buku[i].kode<<endl;
           cout<<"| Penerbit  = "<<buku[i].penerbit<<endl;
           cout<<"| Pengarang = "<<buku[i].pengarang<<endl;
           cout<<"| Stok      = "<<buku[i].stok<<endl;
           cout<<"==========================================="<<endl;
           cout<<endl;
        }
    }

    getch();
}

/* mengembalikan -1 bila data tidak ditemukan */
int cariBukuByKode(int kode) {
    int i;

    for (i = 0; i <= ptrBuku; i++) {
        if (buku[i].kode == kode) {
            break;
        }
    }

    if (buku[i].kode == kode) {
        return i;
    } else {
        return -1;
    }
}

void cari_buku()
{
    int indeks_buku, kode_buku;

    system("cls");
    cout<<"CARI BUKU"<<endl;
    cout<<"========="<<endl;

    do {
        cout<<"Masukkan kode buku = ";
        cin>>kode_buku;

        indeks_buku = cariBukuByKode(kode_buku);
        if (indeks_buku == -1) {
            cout<<"Buku yang diminta tidak ditemukan!"<<endl;
        }
    } while (indeks_buku == -1);

    cout<<endl;
    cout<<"Detail buku"<<endl;
    cout<<"==========="<<endl;
    cout<<"Judul : "<<buku[indeks_buku].judul<<endl;
    cout<<"Kode : "<<buku[indeks_buku].kode<<endl;
    cout<<"Penerbit : "<<buku[indeks_buku].penerbit<<endl;
    cout<<"Pengarang : "<<buku[indeks_buku].pengarang<<endl;
    cout<<"Stok : "<<buku[indeks_buku].stok<<endl;

    getch();
}

void tambah_buku()
{
    int i;

    system("cls");
    cout<<"TAMBAH BUKU"<<endl;
    cout<<"==========="<<endl;

    cout<<"Jumlah buku yang ingin ditambah = ";
    cin>>jumlah_buku;
    cout<<endl;

    for (i = 0; i < jumlah_buku; i++) {
        ptrBuku = ptrBuku + 1;
        cout<<"["<<i+1<<"]."<<endl;
        cout<<"Judul = ";
        fflush(stdin); cin.get(buku[ptrBuku].judul, 80);
        cout<<"Kode = ";
        cin>>buku[ptrBuku].kode;
        cout<<"Penerbit = ";
        fflush(stdin); cin.get(buku[ptrBuku].penerbit, 60);
        cout<<"Pengarang = ";
        fflush(stdin); cin.get(buku[ptrBuku].pengarang, 60);
        cout<<"Stok = ";
        cin>>buku[ptrBuku].stok;
        cout<<endl;
    }

    getch();
}

void edit_buku()
{
    int kode_buku, indeks_buku;

    system("cls");
    cout<<"EDIT BUKU"<<endl;
    cout<<"========="<<endl;

    do {
        cout<<"Masukkan kode buku = ";
        cin>>kode_buku;

        indeks_buku = cariBukuByKode(kode_buku);
        if (indeks_buku == -1) {
            cout<<"Buku yang diminta tidak ditemukan!"<<endl;
        }
    } while (indeks_buku == -1);

    cout<<endl;
    cout<<"Detail buku"<<endl;
    cout<<"==========="<<endl;
    cout<<"Judul : "<<buku[indeks_buku].judul<<endl;
    cout<<"Kode : "<<buku[indeks_buku].kode<<endl;
    cout<<"Penerbit : "<<buku[indeks_buku].penerbit<<endl;
    cout<<"Pengarang : "<<buku[indeks_buku].pengarang<<endl;
    cout<<"Stok : "<<buku[indeks_buku].stok<<endl;
    cout<<endl;

    cout<<"Formulir Edit"<<endl;
    cout<<"Judul = ";
    fflush(stdin); cin.get(buku[indeks_buku].judul, 80);
    cout<<"Kode = ";
    cin>>buku[indeks_buku].kode;
    cout<<"Penerbit = ";
    fflush(stdin); cin.get(buku[indeks_buku].penerbit, 60);
    cout<<"Pengarang = ";
    fflush(stdin); cin.get(buku[indeks_buku].pengarang, 60);
    cout<<"Stok = ";
    cin>>buku[indeks_buku].stok;

    getch();
}

void hapus_buku()
{
    int kode_buku, i, indeks_buku;

    system("cls");
    cout<<"HAPUS BUKU"<<endl;
    cout<<"=========="<<endl;

    do {
        cout<<"Masukkan kode buku = ";
        cin>>kode_buku;

        indeks_buku = cariBukuByKode(kode_buku);
        if (indeks_buku == -1) {
            cout<<"Buku yang diminta tidak ditemukan!"<<endl;
        }
    } while (indeks_buku == -1);

    /* untuk melakukan penghapusan, maka perlu pemindahan data
     * yang setelah indeks yang akan dihapus. Sehingga
     * tempat data yang dihapus tidak kosong didalam array
     */

    // lakukan pengulangan sebanyak ptrBuku - indeks_buku
    for (i = 0; i < ptrBuku - indeks_buku; i++) {
        strcpy(buku[indeks_buku + i].judul, buku[indeks_buku + 1+i].judul);
        buku[indeks_buku + i].kode = buku[indeks_buku + 1+i].kode;
        strcpy(buku[indeks_buku + i].penerbit, buku[indeks_buku + 1+i].penerbit);
        strcpy(buku[indeks_buku + i].pengarang, buku[indeks_buku + 1+i].pengarang);
        buku[indeks_buku + i].stok = buku[indeks_buku + 1+i].stok;
    }

    // mengosongkan indeks terakhir
    strcpy(buku[ptrBuku].judul, "");
    buku[ptrBuku].kode = 0;
    strcpy(buku[ptrBuku].penerbit, "");
    strcpy(buku[ptrBuku].pengarang, "");
    buku[ptrBuku].stok = 0;

    ptrBuku = ptrBuku - 1;

    getch();
}

void menu_buku()
{
    int menu;

    do {
        system("cls");
        cout<<"SISTEM INFORMASI PERPUSTAKAAN"<<endl;
        cout<<"         UNIKOM BANDUNG      "<<endl;
        cout<<"     MENU BUKU PERPUSTAKAAN  "<<endl;
        cout<<"============================="<<endl;
        cout<<"1. Cetak Buku"<<endl;
        cout<<"2. Cari Buku"<<endl;
        cout<<"3. Tambah Buku"<<endl;
        cout<<"4. Edit Buku"<<endl;
        cout<<"5. Hapus Buku"<<endl;
        cout<<"6. Kembali"<<endl;
        cout<<"Menu yang dipilih : ";
        cin>>menu;

        switch(menu) {
             case 1:
                  cetak_buku();
                  break;
             case 2:
                  cari_buku();
                  break;
             case 3:
                  tambah_buku();
                  break;
             case 4:
                  edit_buku();
                  break;
             case 5:
                  hapus_buku();
                  break;
        }
    } while(menu!=6);
}

/*
   Bagian Peminjaman Buku
*/
void cetak_peminjaman()
{
    system("cls");
    cout<<"CETAK DATA PEMINJAMAN"<<endl;
    cout<<"=========="<<endl;

    if (ptrPeminjaman == -1) {
        cout<<"Tidak ada data!"<<endl;
    } else {
        for (i = 0; i <= ptrPeminjaman; i++) {
           cout<<"["<<i+1<<"]."<<endl;
           cout<<"Nama Peminjam     = "<<peminjaman[i].nama_peminjam<<endl;
           cout<<"Alamat            = "<<peminjaman[i].alamat_peminjam<<endl;
           cout<<"Kode Buku         = "<<peminjaman[i].kode_buku<<endl;
           cout<<"Judul Buku        = "<<peminjaman[i].judul_buku<<endl;
           cout<<"Waktu Pinjam      = "<<peminjaman[i].tgl_pinjam.tanggal<<" - "<<peminjaman[i].tgl_pinjam.bulan<<" - "<<peminjaman[i].tgl_pinjam.tahun<<endl;
           cout<<"==================================================="<<endl;
           cout<<endl;
        }
    }
   getch();
}
void peminjaman_buku()
{    
   int kodeCari;
   bool ketemu;
   i = 0;
   int jml_buku_pinjam;
   time_t now = time(0);
   tm *ltm = localtime(&now);
   
   cout<<endl;
   cout<<"Masukkan Kode Buku yang akan anda pinjam : "; 
   cin>>kodeCari; 
   while(i<=ptrBuku && ketemu==false)
   {
        if(kodeCari == buku[i].kode){
           ketemu=true;
        } else {
          i++; 
        }          
    }
    if(ketemu==true){
       if(buku[i].stok == 0) {
         cout<<endl;
         cout<<"Maaf stok buku yang akan anda pinjam telah habis."<<endl;
       }else{
           system("cls");
           cout<<"Detail Buku yang akan dipinjam"<<endl;
           cout<<"==================================="<<endl;   
           cout<<"Judul     = "<<buku[i].judul<<endl;
           cout<<"Kode      = "<<buku[i].kode<<endl;
           cout<<"Penerbit  = "<<buku[i].penerbit<<endl;
           cout<<"Pengarang = "<<buku[i].pengarang<<endl;
           cout<<"Stok = "<<buku[i].stok<<endl;
           cout<<endl;
           cout<<"Masukkan Jumlah Buku yang akan anda Pinjam : ";
           cin>>jml_buku_pinjam;
           cout<<endl;
           while(buku[i].stok < jml_buku_pinjam){
             cout<<"Maaf stok buku tidak cukup, silahkan masukan kembali jumlah buku yang akan dipinjam."<<endl;
             getch();
             cout<<endl;
             cout<<"Masukkan Jumlah Buku yang akan anda Pinjam : ";
             cin>>jml_buku_pinjam;
             cout<<endl;
           }
           ptrPeminjaman += 1;
           cout<<"Masukkan Nama Anda : ";
           fflush(stdin); cin.get(peminjaman[ptrPeminjaman].nama_peminjam, 61);
           cout<<endl;
           cout<<"Masukkan Alamat Anda : ";
           fflush(stdin); cin.get(peminjaman[ptrPeminjaman].alamat_peminjam, 81);
           peminjaman[ptrPeminjaman].kode = ptrPeminjaman;
           peminjaman[ptrPeminjaman].kode_buku = buku[i].kode;
           strcpy(peminjaman[ptrPeminjaman].judul_buku,buku[i].judul);
           peminjaman[ptrPeminjaman].tgl_pinjam.tanggal = ltm->tm_mday;
           peminjaman[ptrPeminjaman].tgl_pinjam.bulan = 1 + ltm->tm_mon;
           peminjaman[ptrPeminjaman].tgl_pinjam.tahun = 1900 + ltm->tm_year;
           peminjaman[ptrPeminjaman].jumlah_pinjam=jml_buku_pinjam; 
           buku[i].stok -= jml_buku_pinjam;
           cout<<endl;
           cout<<"Selamat, Buku berhasil dipinjam."<<endl;
       }
  
    } else {
       cout<<"Kode tidak ditemukan";
    }       
   
   getch();
}
void menu_peminjaman()
{
    int menu;  
    do{
        system("cls");
        cout<<"SISTEM INFORMASI PERPUSTAKAAN"<<endl;
        cout<<"         UNIKOM BANDUNG      "<<endl;
        cout<<"      MENU PEMINJAMAN BUKU   "<<endl;
        cout<<"============================="<<endl;
        cout<<"1. Cetak Data Peminjaman"<<endl;
        cout<<"2. Peminjaman Buku"<<endl;
        cout<<"3. Kembali"<<endl;
        cout<<"Menu yang dipilih : ";
        cin>>menu;
        switch(menu){
             case 1:
                  cetak_peminjaman();
                  break;
             case 2:
                  peminjaman_buku();
                  break;
        }
    } while(menu!=3);
}


/*
   Bagian Pengembalian Buku
*/
void cetak_pengembalian()
{
   system("cls");
   cout<<"DATA PENGEMBALIAN BUKU";
   cout<<endl;
   for (i = 0; i <= ptrPengembalian; i++) {
      cout<<"["<<i+1<<"]."<<endl;
      cout<<"==================================================="<<endl;
      cout<<"Nama Peminjam     = "<<pengembalian[i].nama_peminjam<<endl;
      cout<<"Judul Buku        = "<<pengembalian[i].judul_buku<<endl;
      cout<<"Lama Peminjaman   = "<<pengembalian[i].lama<<" hari"<<endl;  
      cout<<"Tanggal Kembali   = "<<pengembalian[i].tgl_kembali.tanggal<<" - "<<pengembalian[i].tgl_kembali.bulan<<" - "<<pengembalian[i].tgl_kembali.tahun<<endl;
      cout<<"Denda             = Rp. "<<pengembalian[i].biaya_pinjam<<endl;    
      cout<<"==================================================="<<endl;
      cout<<endl;
   }
   
   getch();
}

int hitung_denda(tanggal tgl_pinjam)
{
   tgl_sekarang = generate_tanggal();
   int selisih = selisih_hari(tgl_pinjam,tgl_sekarang);
   if(selisih>3)
     return selisih * DENDA; 
   else 
     return 0;   
}

void pengembalian_buku()
{
   int kodePinjam;  
   int ketemu = false; 
   int i=0;
   char cek; 
   tgl_sekarang = generate_tanggal();
   cout<<"Masukkan kode peminjaman :  ";
   cin>>kodePinjam; 
   while(!ketemu && i<=ptrPeminjaman) {
      if(kodePinjam==peminjaman[i].kode)
         ketemu=true; 
      else 
         i++;              
   }
   if(ketemu){
     system("cls");
     cout<<"Data Peminjaman"<<endl; 
     cout<<"========================"<<endl; 
     cout<<"Kode Peminjam : "<<kodePinjam<<endl;
     cout<<"Nama   : "<<peminjaman[i].nama_peminjam<<endl; 
     cout<<"Alamat : "<<peminjaman[i].alamat_peminjam<<endl;
     cout<<"Tanggal Pinjam : "<<peminjaman[i].tgl_pinjam.tanggal<<"/"<<peminjaman[i].tgl_pinjam.bulan<<"/"<<peminjaman[i].tgl_pinjam.tahun<<endl;
     cout<<"Buku yang dipinjam : "<<peminjaman[i].judul_buku; 
     cout<<"Tanggal Pengembalian : "<<tgl_sekarang.tanggal<<"/"<<tgl_sekarang.bulan<<"/"<<tgl_sekarang.tahun<<endl;
     cout<<"Denda  : "<<hitung_denda(peminjaman[i].tgl_pinjam)<<endl; 
     cout<<endl; 
     cout<<"Apakah buku yang ingin dikembalikan sudah benar ? [y/t] : "; 
     cin>>cek; 
     if(cek=='y' || cek=='Y'){
       ptrPengembalian++; 
       pengembalian[ptrPengembalian].kode_peminjaman = peminjaman[i].kode; 
       
       strcpy(pengembalian[ptrPengembalian].nama_peminjam,peminjaman[i].nama_peminjam);
       pengembalian[ptrPengembalian].kode_buku=peminjaman[i].kode_buku; 
       strcpy(pengembalian[ptrPengembalian].judul_buku,peminjaman[i].judul_buku);       
       pengembalian[ptrPengembalian].tgl_kembali = tgl_sekarang; 
       pengembalian[ptrPengembalian].lama=selisih_hari(peminjaman[i].tgl_pinjam,tgl_sekarang); 
       pengembalian[ptrPengembalian].biaya_pinjam = hitung_denda(peminjaman[i].tgl_pinjam);
       
       //cari buku 
       ketemu=false; 
       int j=0;
       while(ketemu==false && j<=ptrBuku){
           if(buku[j].kode==peminjaman[i].kode_buku){
             ketemu=true;  
           } else {
             j++;
           }              
       }
       if(ketemu){
         buku[j].stok += peminjaman[i].jumlah_pinjam;
       } 
       cout<<endl; 
       cout<<"Data sudah disimpan.. tekan sembarang untuk kembali.."; 
       getch();
     }else {
       cout<<"Tekan sembarang untuk kembali..";
       getch();
     }
   }else {
     cout<<"Kode peminjaman tidak ditemukan.."<<endl;
     
   }
   getch();
}

void menu_pengembalian()
{
    int menu;
    do{
        system("cls");
        cout<<"SISTEM INFORMASI PERPUSTAKAAN"<<endl;
        cout<<"         UNIKOM BANDUNG      "<<endl;
        cout<<"    MENU PENGEMBALIAN BUKU   "<<endl;
        cout<<"============================="<<endl;
        cout<<"1. Data Pengembalian"<<endl;
        cout<<"2. Pengembalian Buku"<<endl;
        cout<<"3. Kembali"<<endl;
        cout<<"Menu yang dipilih : ";
        cin>>menu;
        switch(menu){
             case 1:
                  cetak_pengembalian();
                  break;
             case 2:
                  pengembalian_buku();
                  break;
        }
    } while(menu!=3);
}
