#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

const int MAX_ARRAY=100;
int costumer = 0; 
int stok_ayam = 50; 
int stok_bebek =50; 

int pesanan_ayam[MAX_ARRAY];
int pesanan_bebek[MAX_ARRAY];

void cetak_menu();
int pilih_menu();
int menu; 

void pemesanan(int *costumer,int pesanan_ayam[MAX_ARRAY],int pesanan_bebek[MAX_ARRAY])
{
          
}
int main(int argc, char *argv[])
{
    do{
       cetak_menu();
       pilih_menu();
       switch(menu) {
          case 1:
               
               break;                       
          case 2:
               
               break;
          case 3:
               
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
