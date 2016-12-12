#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

const int MAX_DATA = 100;
const int DENDA = 10000; // denda bisa diubah terserah kesepakatan

// Deklarasi struct
typedef struct 
{
   int tgl; 
   int bln; 
   int thn;             
} tanggal; 

typedef struct
{
   char kode[6]; 
   char nama_peminjam[61]; 
   char alamat_peminjam[81];
   char kode_buku[6];
   char judul_buku[81];
   tanggal tgl_pinjam; 
} dataPeminjaman; 

typedef struct
{
   char kode[6];
   char judul[81];
   char pengarang[61];
   char penerbit[61];
   int stok;            
} dataBuku; 

typedef struct
{
    char kode_peminjaman[6];
    char nama_peminjam[61];
    char kode_buku[6];
    char judul_buku[81];
    tanggal tgl_kembali; 
    int lama; 
    int biaya_pinjam;   
} dataPengembalian; 

// variabel Global
dataBuku            buku[MAX_DATA];
dataPeminjaman      peminjaman[MAX_DATA];
dataPengembalian    pengembalian[MAX_DATA];
// pointer penunjuk indeks terakhir dari array
int                 ptrBuku;
int                 ptrPeminjaman;
int                 ptrPengembalian;



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
    cout<<"CETAK BUKU";
    cout<<"==========";

    for (i = 0; i <= ptrBuku; i++) {
       cout<<"["<<i+1<<"]."<<endl; 
       cout<<"Judul     = "<<buku[i].judul<<endl;
       cout<<"Kode      = "<<buku[i].kode<<endl;
       cout<<"Penerbit  = "<<buku[i].penerbit<<endl;
       cout<<"Pengarang = "<<buku[i].pengarang<<endl;
       cout<<"Stok      = "<<buku[i].stok<<endl;
       cout<<endl;
    }

    getch(); 
}
void cari_buku()
{
    cout<<"PROCEDURE CARI BUKU ";
    getch(); 
}
void tambah_buku()
{
    cout<<"PROCEDURE TAMBAH BUKU ";
    getch(); 
}
void edit_buku()
{
    cout<<"PROCEDURE EDIT BUKU ";
    getch(); 
}
void hapus_buku()
{
    cout<<"PROCEDURE HAPUS BUKU ";
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
   cout<<"PROCEDURE CETAK PEMINJAMAN  ";
   getch();  
}
void peminjaman_buku()
{
   cout<<"PROCEDURE PEMINJAMAN BUKU  ";
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
   cout<<"PROCEDURE CETAK PENGEMBALIAN  ";
   getch();  
}
void pengembalian_buku()
{
   cout<<"PROCEDURE PENGEMBALIAN BUKU  ";
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
