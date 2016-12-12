#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;
const int max_data=100;
//Record
typedef struct 
{
   int tanggal; 
   int bulan; 
   int tahun;             
} tanggal; 

typedef struct
{
   char kode_peminjaman[6]; 
   char nama_peminjam[61]; 
   char alamat_peminjam[81];
   char kode_buku[6];
   char judul_buku[81];
   tanggal tanggal_pinjam; 
} data_peminjaman; 

typedef struct
{
   char kode[6];
   char judul[81];
   char pengarang[61];
   char penerbit[61];
   int stok;            
} data_buku; 

typedef struct
{
    char kode_peminjaman[6];
    char nama_peminjam[61];
    char kode_buku[6];
    char judul_buku[81];
    tanggal tanggal_kembali; 
    int lama; 
    int biaya_pinjam;   
} data_pengembalian; 
//Akhir dari record 
data_buku buku[max_data];
data_peminjaman peminjaman[max_data];
data_pengembalian pengembalian[max_data];

//Array of Record 

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
    do{
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
    cout<<"PROCEDURE CETAK BUKU ";
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
    do{
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
        switch(menu){
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
