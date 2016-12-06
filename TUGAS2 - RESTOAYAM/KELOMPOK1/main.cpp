#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int MAX_ARRAY=100;
int costumer = 0; 
int stok_ayam = 50; 
int stok_bebek =50; 

void cetak_menu();
int pilih_menu();
int menu; 
int pelanggan=0; 
int jumlah_pesan; 
int i; 

//record 
typedef struct
{
   int jumlah_ayam; 
   int jumlah_bebek;
}data_pesanan; 

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void pemesanan(int *pelanggan,int *jumlah_pesan,data_pesanan pesanan[MAX_ARRAY])
{
     system("cls");
     *pelanggan+=1;     
     bool input=false;
     //gotoxy(5,9); cout<<"Selamat datang!!";
     cout<<"Pelanggan no : "<<*pelanggan<<endl;
     cout<<"Masukkan jumlah pemesanan : ";
     cin>>*jumlah_pesan;
     for(i=0;i<*jumlah_pesan;i++)
     {
        do{                                              
            cout<<"Banyak ayam-"<<i+1<<" : "; 
            cin>>pesanan[i].jumlah_ayam; 
            if(stok_ayam<pesanan[i].jumlah_ayam) {
               cout<<"Mohon maaf stok ayam hanya tinggal : "<<stok_ayam<<"..."<<endl;
               getch();
               system("cls");
            } else {
              cout<<"Banyak bebek-"<<i+1<<" : "; 
              cin>>pesanan[i].jumlah_bebek;
              if(stok_bebek<pesanan[i].jumlah_bebek){
                 cout<<"Mohon maaf stok ayam hanya tinggal : "<<stok_ayam<<"..."<<endl;                                    
                 getch();
                 system("cls");
              } else {
                 input=true;    
              }
            }
        }while(input==false); 
        stok_ayam -= pesanan[i].jumlah_ayam;                 
        stok_bebek -= pesanan[i].jumlah_bebek;
     }  
     cout<<"Pesanan anda telah disimpan tekan semabarang untuk kembali..";
     getch();   
}

void cetak_stok()
{
    system("cls"); 
    cout<<"STOK AYAM DAN BEBEK RESTO"<<endl; 
    cout<<"=========================="<<endl; 
    cout<<"STOK AYAM    : "<<stok_ayam<<endl; 
    cout<<"STOK BEBEK   : "<<stok_bebek<<endl; 
    cout<<"=========================="<<endl;
    cout<<endl;
    cout<<"Tekan sembarang untuk kembali ke menu..";
    getch(); 
}
data_pesanan pesanan[MAX_ARRAY];

int main(int argc, char *argv[])
{
    do{
       cetak_menu();
       menu = pilih_menu();
       switch(menu) {
          case 1:
               pemesanan(&pelanggan,&jumlah_pesan,pesanan);
               break;                       
          case 2:
               
               break;
          case 3:
               cetak_stok();
               break;       
       }
    } while(menu!=4);    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void cetak_menu()
{
    system("cls"); 
    cout<<"MENU RESTO AYAM"<<endl; 
    cout<<"=============================="<<endl; 
    cout<<"1. Pemesanan"<<endl; 
    cout<<"2. Cetak Seluruh Pemesanan"<<endl;
    cout<<"3. Stok Ayam dan Bebek"<<endl;
    cout<<"4. Keluar"<<endl; 
}

int pilih_menu()
{
    int menu;
    cout<<"Menu yang dipilih : "; 
    cin>>menu;
    return menu; 
}
