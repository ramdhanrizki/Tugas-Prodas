#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

typedef struct
{
   int nim;
   string nama;
   string jurusan;             
}data_mahasiswa;

data_mahasiswa mahasiswa[50];
int poinMhs=0; 

void tampil_mahasiwa(data_mahasiswa mahasiswa)
{
   cout<<"NIM       : "<<mahasiswa.nim<<endl;      
   cout<<"NAMA      : "<<mahasiswa.nama<<endl;
   cout<<"JURUSAN   : "<<mahasiswa.jurusan<<endl;  
}

int main(int argc, char *argv[])
{
    int nimCari,i; 
    bool ketemu = false; 
    //inisialisasi data 
    mahasiswa[0].nim = 10115246; 
    mahasiswa[0].nama="Ramdhan Rizki";
    mahasiswa[0].jurusan="Teknik Informatika"; 
    
    mahasiswa[1].nim = 10115240; 
    mahasiswa[1].nama="Firman N";
    mahasiswa[1].jurusan="Teknik Informatika"; 
    
    mahasiswa[2].nim = 10115230; 
    mahasiswa[2].nama="Tioreza";
    mahasiswa[2].jurusan="Teknik Informatika";
    
    cout<<"Masukkan nim yang ingin dicari : "; 
    cin>>nimCari; 
    i=0;
    while(i<10 && ketemu==false)
    {
        if(nimCari == mahasiswa[i].nim){
           ketemu=true;
        } else {
          i++; 
        }          
    }
    if(ketemu==true){
       system("cls");           
       tampil_mahasiwa(mahasiswa[i]);
    } else {
       cout<<"Data yang dicari tidak ditemukan";
    }       
    system("PAUSE");
    return EXIT_SUCCESS;
}
