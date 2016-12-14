#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

void menu_utama();
int pilih_menu(); 
void menu_konversi_binner();
void menu_hitung_huruf();
void menu_informasi_anggota();

int main(int argc, char *argv[])
{
    int menu; 
    do {
       menu_utama();
       menu = pilih_menu();
       switch(menu){
          case 1: 
               menu_konversi_binner();
               break;
          case 2:
               menu_hitung_huruf();
               break;
          case 3:
               menu_informasi_anggota();
       }    
    } while(menu!=4);
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void menu_utama()
{
    system("cls");
    cout<<"MENU PILIHAN"<<endl; 
    cout<<"==============================================="<<endl;
    cout<<"1.Kasus Konversi Desimal ke Binner"<<endl;
    cout<<"2.Kasus menghitung banyak sebuah karakter dalam kalimat"<<endl;
    cout<<"3.Informasi Anggota Kelompok"<<endl;  
    cout<<"4.Keluar"<<endl;    
    cout<<"==============================================="<<endl;
}

int pilih_menu()
{
    int menu;
    cout<<"Menu yang dipilih : "; 
    cin>>menu; 
    return menu;    
}


string konversi_binner(int desimal)
{
     stringstream temp;
     int tes; 
     if(desimal == 1){
        temp << desimal; 
        return temp.str();
     }else{
        tes = desimal % 2;
        temp << tes;  
        return konversi_binner(desimal / 2) + temp.str();         
     }        
}

int hitungKarakter(int posisi, string buffer, char karakterCari)
{
    if (buffer[posisi] == '\0') {
        return 0;
    }

    if (buffer[posisi] == karakterCari)
    {
        return hitungKarakter(posisi + 1, buffer, karakterCari) + 1;
    }
    else
    {
        return hitungKarakter(posisi + 1, buffer, karakterCari) + 0;
    }
}

void menu_konversi_binner()
{
    system("cls"); 
    int desimal; 
    string hasil; 
    
    cout<<"Konversi desimal ke binner"<<endl; 
    cout<<"============================"<<endl; 
    cout<<"Masukkan nilai desimal : ";
    cin>>desimal; 
    cout<<"Hasil konversi binner untuk nilai "<<desimal<<" adalah : "<<konversi_binner(desimal)<<endl; 
    
    cout<<"Tekan sembarang untuk kembali..";
    getch();     
}

void menu_hitung_huruf()
{
    system("cls");
    string nama; 
    char karakter; 
    
    cout<<"Masukkan sembarang nama : "; 
    fflush(stdin); 
    getline(cin,nama);
    cout<<"Masukkan karakter yang ingin dihitung : ";
    //karakter = getch();
    cin>>karakter;
    cout<<endl;
    system("cls"); 
    cout<<"Nama yang dimasukkan : "<<nama<<endl; 
    cout<<"Jumlah karakter "<<karakter<<" dalam nama tersebut adalah : "<<hitungKarakter(0,nama,karakter)<<endl;
    cout<<"Tekan sembarang untuk kembali..";
    getch();
}

void menu_informasi_anggota()
{
    system("cls"); 
    cout<<"ANGGOTA KELOMPOK 1"<<endl; 
    cout<<"=============================="<<endl;
    cout<<"1.(10115246) Ramdhan Rizki Jamaludin"<<endl; 
    cout<<"2.(10115219) Tioreza Febrian"<<endl; 
    cout<<"3.(10115364) Ilham Rizki Hidayatulloh"<<endl; 
    cout<<"4.(10115387) Tubagus Fikri Fatoni"<<endl; 
    cout<<"5.(10115137) Yudi Supriyadi"<<endl;      
    cout<<endl;
    cout<<"Tekan sembarang untuk kembali..."; 
    getch();
}
