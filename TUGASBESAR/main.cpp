#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string.h>

using namespace std;
	
typedef struct {
	char username[11];
	char password[9];
}input;

typedef struct {
	float matematika;
	float ipa;
	float b_indonesia;
	float b_inggris;
} pelajaran;

typedef struct {
	int no_pendaftaran;
	char nama[51];
	char jenis_kelamin;
	pelajaran nilai;
	int jurusan1;
	int jurusan2;
	int status;
} pendaftaran;


// area deklarasi fungsi dan procedure
int menu(float tkj, float rpl, float titl, float toi, float av, float mm, pelajaran jurusan[6]);
void passing(float tkj, float rpl, float titl, float toi, float av, float mm, pelajaran jurusan[6]);
void login(input entry[20],float tkj, float rpl, float titl, float toi, float av, float mm, int *insiswa, pendaftaran siswa[200], pelajaran jurusan[6]);
void search(int insiswa, pendaftaran siswa[200]);
void persyaratan(float tkj, float rpl, float titl, float toi, float av, float mm, pelajaran jurusan[6]);
void inputentry(input entry[200]);
void inputsiswa(float tkj, float rpl, float titl, float toi, float av, float mm, int *insiswa, pendaftaran siswa[200], pelajaran jurusan[6]);
void datapendaftar(int insiswa, pendaftaran siswa[200]);
void dataditerima(int insiswa, pendaftaran siswa[200]);
void dataditolak(int insiswa, pendaftaran siswa[200]);
void ubahnilai(pelajaran jurusan[6]);
void standar(pelajaran jurusan[6]);
void rata_rata(float *tkj, float *rpl, float *titl, float *toi, float *av, float *mm, pelajaran jurusan[6]);
int seleksi(int jur,float tkj, float rpl, float titl, float toi, float av, float mm, int insiswa, pendaftaran siswa[200], pelajaran jurusan[6]);
int sorting(int stat, int insiswa, pendaftaran siswa[200]);
void upgrade(int stat, int insiswa, pendaftaran siswa[200], pelajaran jurusan[6]);

// area deklarasi array dan variabel global
int inentry = 0;


main(){ // block program utama
	pendaftaran siswa[200];
	input entry[20];
	int insiswa = 0;
	pelajaran jurusan[6];
	float tkj,rpl,mm,toi,av,titl;
	
 	standar(jurusan);
 	int i = 0;
	while( i == 0){
		int pilihan = menu(tkj, rpl, titl, toi, av, mm, jurusan);
		switch (pilihan){
			case 1:
					login(entry, tkj, rpl, titl, toi, av, mm, &insiswa, siswa, jurusan);
				break;
			case 2:
					search(insiswa, siswa);
				break;
			case 3:
					persyaratan(tkj, rpl, titl, toi, av, mm, jurusan);
					system("pause");
				break;
			case 4:
					system("cls");
					cout << "======== Aplikasi Penerimaan Siswa Baru SMK Negeri 4 Bandung ========\n";
					cout << "---------------------------------------------------------------------\n";
					cout << "----------Terima Kasih Telah Menggunakan Aplikasi kami---------------\n";
					cout << "---------------------------------------------------------------------\n";
					i++;
					system("pause");
				break;
			default:
					system("cls");
					cout << "================ Maaf pilihan anda tidak terdefinisi ================\n";
					cout << "---------------------------------------------------------------------\n";
					cout << "----------------------- Silahkan Coba Lagi !!! ----------------------\n";
					cout << "---------------------------------------------------------------------\n";
					system("pause");
				break;
		}
		system("cls");		
	}
 getche();

}

 void standar(pelajaran jurusan[6]){
	jurusan[0].matematika = 75;jurusan[0].b_indonesia = 75; jurusan[0].b_inggris = 75;jurusan[0].ipa = 75; // untuk jurusan tkj
	jurusan[1].matematika = 75;jurusan[1].b_indonesia = 75; jurusan[1].b_inggris = 75;jurusan[1].ipa = 75; // untuk jurusan rpl
	jurusan[2].matematika = 75;jurusan[2].b_indonesia = 75; jurusan[2].b_inggris = 75;jurusan[2].ipa = 75; // untuk jurusan mm
	jurusan[3].matematika = 75;jurusan[3].b_indonesia = 75; jurusan[3].b_inggris = 75;jurusan[3].ipa = 75; // untuk jurusan av
	jurusan[4].matematika = 75;jurusan[4].b_indonesia = 75; jurusan[4].b_inggris = 75;jurusan[4].ipa = 75; // untuk jurusan toi
	jurusan[5].matematika = 75;jurusan[5].b_indonesia = 75; jurusan[5].b_inggris = 75;jurusan[5].ipa = 75; // untuk jurusan titl
}

 int menu (float tkj, float rpl, float titl, float toi, float av, float mm, pelajaran jurusan[6]){
	int hasil;
	cout << "======== Aplikasi Penerimaan Siswa Baru SMK Negeri 4 Bandung ========\n";
	passing(tkj, rpl, titl, toi, av, mm, jurusan);
	cout << "Menu :\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "1. Login\n" ;
	cout << "2. Search\n" ;
	cout << "3. Persyaratan Nilai\n" ;
	cout << "4. Keluar\n" ;
	cout << "---------------------------------------------------------------------\n";
	cout << "Masukan no menu pilihan anda :" ;
	cin  >> hasil;
	return hasil;
 }
 
 void passing(float tkj, float rpl, float titl, float toi, float av, float mm, pelajaran jurusan[6]){
 	rata_rata(&tkj, &rpl, &titl, &toi, &av, &mm, jurusan);
 	cout << "---------------------------------------------------------------------\n";
	cout << "Passinggrade Saat Ini :\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "1. Teknik Komputer dan Jaringan\t\t:"<<tkj<<"\n" ;
	cout << "2. Teknik Rekayasa Perangkat Lunak\t:"<<rpl<<"\n" ;
	cout << "3. Teknik Instalasi Tenaga Listrik\t:"<<titl<<"\n" ;
	cout << "4. Teknik Otomasi Industri\t\t:"<<toi<<"\n" ;
	cout << "5. Teknik Audio Video\t\t\t:"<<av<<"\n" ;
	cout << "6. Multi Media\t\t\t\t:"<<mm<<"\n" ;
	cout << "---------------------------------------------------------------------\n";
 }
 
 void login(input entry[20],float tkj, float rpl, float titl, float toi, float av, float mm, int *insiswa, pendaftaran siswa[200], pelajaran jurusan[6]){
	char username[10],password[8];
	system("cls");
	cout << "---------------------------------------------------------------------\n";
	cout << "Login System :\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "Masukan username\t: " ;
	cin  >> username;
	cout << "Masukan password\t: " ;
	cin  >> password;
	
	if((strcmp(username,"admin") == 0)&&(strcmp(password,"admin") == 0)){
		int m = 0;
		while(m == 0){
			cout << "======== Aplikasi Penerimaan Siswa Baru SMK Negeri 4 Bandung ========\n";
		    cout << "---------------------------------------------------------------------\n";
		    cout << "Selamat Datang Administrator!\n";
			cout << "---------------------------------------------------------------------\n";
			passing(tkj, rpl, titl, toi, av, mm, jurusan);
			cout << "Menu :\n";
			cout << "---------------------------------------------------------------------\n";
			cout << "1. Tambah User Tim Entry \n" ;
			cout << "2. Ubah Standar Nilai\n" ;
			cout << "3. Data Pendaftar\n" ;
			cout << "4. Data Diterima\n" ;
			cout << "5. Data Ditolak\n" ;
			cout << "6. Logout\n" ;
			cout << "---------------------------------------------------------------------\n";
			cout << "Masukan no menu pilihan anda :" ;
			int adminmenu;
			cin  >> adminmenu;
				switch(adminmenu){
					case 1 :
						inputentry(entry);
						break;
					case 2 :
						system("cls");
						ubahnilai(jurusan);
						break;
					case 3 :
						system("cls");
						datapendaftar(*insiswa, siswa);
						break;
					case 4 :
						system("cls");
						dataditerima(*insiswa, siswa);
						break;
					case 5 :
						system("cls");
						dataditolak(*insiswa, siswa);
						break;
					case 6 :
						m++;
						break;
					default :
						break;
				}
		}
		system("pause");
	}else{
		int stat =0;
		for(int a = 0; a < 20 ;a++){
			if((strcmp(username,entry[a].username) == 0)&&(strcmp(password,entry[a].password) == 0)){
				system("cls");
				int m  = 0;
				stat++;
				while(m == 0){
					cout << "======== Aplikasi Penerimaan Siswa Baru SMK Negeri 4 Bandung ========\n";
				    cout << "---------------------------------------------------------------------\n";
				    cout << "Selamat Datang " << entry[a].username << "\n";
					cout << "---------------------------------------------------------------------\n";
					cout << "Menu :\n";
					cout << "---------------------------------------------------------------------\n";
					cout << "1. Tambah Data Pendaftar\n" ;
					cout << "2. Logout\n" ;
					cout << "---------------------------------------------------------------------\n";
					cout << "Masukan menu pilihan :" ;
					int entrymenu;
					cin  >> entrymenu;
						switch(entrymenu){
							case 1 :
								inputsiswa(tkj, rpl, titl, toi, av, mm, insiswa, siswa, jurusan);
								break;
							case 2 :
								m++;
								break;
							default :
								break;
						}
				}
				system("pause");
				break;
			}
		}
		if(stat == 0){
			cout << "Username / Password Salah\n";
			system("pause");
		}
	}
	
 }
 
 void search(int insiswa, pendaftaran siswa[200]){
	int  index;
	system("cls");
	cout << "---------------------------------------------------------------------\n";
	cout << "Search System :\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "Masukan No Pendaftaran\t:" ;
	cin  >> index;
	for(int a = 0; a <= insiswa ; a++){
		if(siswa[a].no_pendaftaran == index){
		cout << "---------------------------------------------------------------------\n";
		cout << "No. Pendaftaran 	: "<<siswa[a].no_pendaftaran<<"\n";
		cout << "Nama Lengkap 		: "<<siswa[a].nama<<"\n";
		cout << "Jenis Kelamin		: "<<siswa[a].jenis_kelamin<<"\n";
		if(siswa[a].status > 0){
			cout << "status			: Diterima Di Jurusan "<<siswa[a].status<<"\n";
		}else{
			cout << "status			: Tidak Diterima \n";	
		}
		cout << "---------------------------------------------------------------------\n";
		cout << "Nilai Matematika	: "<<siswa[a].nilai.matematika<<"\n";
		cout << "Nilai Bahasa Indo	: "<<siswa[a].nilai.b_inggris<<"\n";
		cout << "Nilai Bahasa Ingg	: "<<siswa[a].nilai.b_indonesia<<"\n";
		cout << "Nilai IPA		: "<<siswa[a].nilai.ipa<<"\n";
		cout << "---------------------------------------------------------------------\n";
		break;	
	 	}
	}
	cout << "|-----------Daftar Jurusan----------|\n";
	cout << "|1.| Teknik Komputer dan Jaringan   |\n";
	cout << "|2.| Teknik Rekayasa Perangkat Lunak|\n";
	cout << "|3.| Teknik Instalasi Tenaga Listrik|\n";
	cout << "|4.| Teknik Otomasi Industri        |\n";
	cout << "|5.| Teknik Audio Video             |\n";
	cout << "|6.| Multi Media                    |\n";
	cout << "-------------------------------------------------------------------------\n";
	system("pause");
 }
 
 void persyaratan(float tkj, float rpl, float titl, float toi, float av, float mm, pelajaran jurusan[6]){
  	system("cls");
  	rata_rata(&tkj, &rpl, &titl, &toi, &av, &mm, jurusan);
 	cout << "--------------------------------------------------------------------------------\n";
	cout << "|NO| JURUSAN                        | MTK | B. ING | IPA | B. INDO | PASSING GRADE |\n";
	cout << "--------------------------------------------------------------------------------\n";
	cout << "|1.| Teknik Komputer dan Jaringan   |  "<<jurusan[0].matematika <<" |   "<<jurusan[0].b_inggris<<"   |  "<<jurusan[0].ipa<<" |    "<<jurusan[0].b_indonesia<<"   |  "<<tkj<<"       |\n";
	cout << "|2.| Teknik Rekayasa Perangkat Lunak|  "<<jurusan[1].matematika <<" |   "<<jurusan[1].b_inggris<<"   |  "<<jurusan[1].ipa<<" |    "<<jurusan[1].b_indonesia<<"   |  "<<rpl<<"       |\n";
	cout << "|3.| Multi Media                    |  "<<jurusan[2].matematika <<" |   "<<jurusan[2].b_inggris<<"   |  "<<jurusan[2].ipa<<" |    "<<jurusan[2].b_indonesia<<"   |  "<<mm<<"       |\n";
	cout << "|4.| Teknik Audio Video             |  "<<jurusan[3].matematika <<" |   "<<jurusan[3].b_inggris<<"   |  "<<jurusan[3].ipa<<" |    "<<jurusan[3].b_indonesia<<"   |  "<<av<<"       |\n";
	cout << "|5.| Teknik Otomasi Industri        |  "<<jurusan[4].matematika <<" |   "<<jurusan[4].b_inggris<<"   |  "<<jurusan[4].ipa<<" |    "<<jurusan[4].b_indonesia<<"   |  "<<toi<<"       |\n";
	cout << "|6.| Teknik Instalasi Tenaga Listrik|  "<<jurusan[5].matematika <<" |   "<<jurusan[5].b_inggris<<"   |  "<<jurusan[5].ipa<<" |    "<<jurusan[5].b_indonesia<<"   |  "<<titl<<"       |\n";
	cout << "--------------------------------------------------------------------------------\n";
 }
 
 void rata_rata(float *tkj, float *rpl, float *titl, float *toi, float *av, float *mm, pelajaran jurusan[6]){
 	*tkj = (jurusan[0].matematika + jurusan[0].b_inggris + jurusan[0].ipa + jurusan[0].b_indonesia);
 	*rpl = (jurusan[1].matematika + jurusan[1].b_inggris + jurusan[1].ipa + jurusan[1].b_indonesia);
 	*mm = (jurusan[2].matematika + jurusan[2].b_inggris + jurusan[2].ipa + jurusan[2].b_indonesia);
 	*av = (jurusan[3].matematika + jurusan[3].b_inggris + jurusan[3].ipa + jurusan[3].b_indonesia);
 	*toi = (jurusan[4].matematika + jurusan[4].b_inggris + jurusan[4].ipa + jurusan[4].b_indonesia);
 	*titl = (jurusan[5].matematika + jurusan[5].b_inggris + jurusan[5].ipa + jurusan[5].b_indonesia);
 }
 
 void inputsiswa(float tkj, float rpl, float titl, float toi, float av, float mm, int *insiswa, pendaftaran siswa[200], pelajaran jurusan[6]){
	bool exist; //inisialisasi variable local
	do{
	exist = false;
	system("cls");
	cout << "---------------------------------------------------------------------\n";
	cout << "Masukan No Pendaftaran \t\t\t: ";
	cin  >> siswa[*insiswa].no_pendaftaran;
	
	//validasi no_pelajaran 
	if(*insiswa != 0){
		int i = 0;
		while(i != (*insiswa) && exist != true){
			if(siswa[i].no_pendaftaran == siswa[*insiswa].no_pendaftaran){
				exist = true;
			}
			i++;
		}
		
		if (exist){
			cout<<"Nomer pendaftaran sudah ada"<<endl;
			getche();
		}else{
			exist = false;
		}
	}
	cout<<*insiswa;
	}while(exist != false);
	
	
	cout << "Masukan Nama Calon Siswa \t\t: ";
	fflush(stdin);
	cin.get(siswa[*insiswa].nama, 50);
	cout << "Masukan Jenis Kelamin Calon Siswa (L/P) : ";
	cin  >> siswa[*insiswa].jenis_kelamin;
	cout << "---------------------------------------------------------------------\n";
	cout << "|-----------Daftar Jurusan----------|\n";
	cout << "|1.| Teknik Komputer dan Jaringan   |\n";
	cout << "|2.| Teknik Rekayasa Perangkat Lunak|\n";
	cout << "|3.| Multi Media                    |\n";
	cout << "|4.| Teknik Audio Video             |\n";
	cout << "|5.| Teknik Otomasi Industri        |\n";
	cout << "|6.| Teknik Instalasi Tenaga Listrik|\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "Masukan Pilihan Pertama : ";
	cin  >> siswa[*insiswa].jurusan1;
	cout << "Masukan Pilihan Kedua \t: ";
	cin  >> siswa[*insiswa].jurusan2;
	cout << "---------------------------------------------------------------------\n";
	cout << "Masukan Nilai Bahasa Indonesia \t: ";
	cin  >> siswa[*insiswa].nilai.b_indonesia;
	cout << "Masukan Nilai Bahasa Inggris \t: ";
	cin  >> siswa[*insiswa].nilai.b_inggris;
	cout << "Masukan Nilai IPA \t\t: ";
	cin  >> siswa[*insiswa].nilai.ipa;
	cout << "Masukan Nilai Matematika \t: ";
	cin  >> siswa[*insiswa].nilai.matematika;
	//awal proses seleksi
	int hasil = seleksi(siswa[*insiswa].jurusan1, tkj, rpl, titl, toi, av, mm, *insiswa, siswa, jurusan);
	if(hasil >0){
	siswa[*insiswa].status = hasil;
	}else{
		hasil = seleksi(siswa[*insiswa].jurusan2, tkj, rpl, titl, toi, av, mm, *insiswa, siswa, jurusan);
		siswa[*insiswa].status = hasil;
	}
	 hasil = sorting(siswa[*insiswa].status, *insiswa, siswa);
	 siswa[*insiswa].status = hasil;
	 
	 upgrade(siswa[*insiswa].status, *insiswa, siswa, jurusan);
	 
	//akhir
	cout << "---------------------------------------------------------------------\n";
	cout << "----------------------------Data Tersimpan---------------------------\n";
	cout << "---------------------------------------------------------------------\n";
	*insiswa = *insiswa + 1;
	system("pause");
	system("cls");
 }
 
 int sorting(int stat, int insiswa, pendaftaran siswa[200]){
 	int temp[20];
 	int param = 0 ;
 	int pl = stat;
 	
 	for(int a = 0; a <= insiswa ; a++){
 		if(siswa[a].status == stat){
 			temp[param] = a;
 			param++;
		 }
	}
	
	for(int b = 0; b <= param ; b++ ){
		if((siswa[temp[b]].nilai.matematika <= siswa[insiswa].nilai.matematika)&&(siswa[temp[b]].nilai.ipa <= siswa[insiswa].nilai.ipa)&&(siswa[temp[b]].nilai.b_inggris <= siswa[insiswa].nilai.b_inggris)&&(siswa[temp[b]].nilai.b_indonesia <= siswa[insiswa].nilai.b_indonesia)){
			siswa[temp[b]].status = -1;
			stat = pl; 
			break; 	
		}else{
			stat = -1;
		}
	}
	
	return stat;	
 }
 
 void upgrade(int stat, int insiswa, pendaftaran siswa[200], pelajaran jurusan[6]){
 	int parx = 1,l = 0;
	int c = stat;
	c--; 	
 	float ratamat = jurusan[c].matematika, rataing = jurusan[c].b_inggris, rataind = jurusan[c].b_indonesia,rataipa = jurusan[c].ipa;
 	do{
		if(siswa[l].status == stat){
			ratamat += siswa[l].nilai.matematika;
			rataipa += siswa[l].nilai.ipa;
			rataing += siswa[l].nilai.b_inggris;
			rataind += siswa[l].nilai.b_indonesia;
			parx++;
			cout << ratamat <<"|"<< rataipa <<"|"<< rataing <<"|"<< rataind <<"|"<< parx <<"\n";
		}
		l++;
	}while(l <= insiswa);
	
	if(parx == 0){
		parx = 1;
	}
	ratamat /= parx;
	rataipa /= parx;
	rataing /= parx;
	rataind /= parx;

	jurusan[c].matematika = ratamat;
	jurusan[c].ipa = rataipa;
	jurusan[c].b_inggris = rataing;
	jurusan[c].b_indonesia = rataind;
 }
 
 int seleksi(int jur, float tkj, float rpl, float titl, float toi, float av, float mm, int insiswa, pendaftaran siswa[200], pelajaran jurusan[6]){
 	rata_rata(&tkj, &rpl, &titl, &toi, &av, &mm, jurusan);
 	float rata = (siswa[insiswa].nilai.matematika + siswa[insiswa].nilai.ipa + siswa[insiswa].nilai.b_inggris + siswa[insiswa].nilai.b_indonesia);
 	jur--;
	if(jur == 0){
		if(rata >= tkj){
			if((jurusan[0].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[0].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[0].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[0].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 1;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 1){
		if(rata >= rpl){
			if((jurusan[1].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[1].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[1].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[1].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 2;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 2){
		if(rata >= mm){
			if((jurusan[2].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[2].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[2].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[2].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 3;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 3){
		if(rata >= av){
			if((jurusan[3].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[3].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[3].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[3].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 4;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 4){
		if(rata >= toi){
			if((jurusan[4].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[4].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[4].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[4].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 5;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(jur == 5){
		if(rata >= toi){
			if((jurusan[5].matematika<=siswa[insiswa].nilai.matematika)&&(jurusan[5].ipa<=siswa[insiswa].nilai.ipa)&&(jurusan[5].b_inggris<=siswa[insiswa].nilai.b_inggris)&&(jurusan[5].b_indonesia<=siswa[insiswa].nilai.b_indonesia)){
				return 6;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else{
		return -1;
	}
 }
 
 void inputentry(input entry[20]){
	cout << "Masukan Username :";
	cin  >> entry[inentry].username;
	cout << "Masukan Password :";
	cin  >> entry[inentry].password;
	inentry++;
 }
 
 void datapendaftar(int insiswa, pendaftaran siswa[200]){
 	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "--------------------------------------Data Siswa Terdaftar-------------------------------------------\n";
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "| No Pendaftaran | Nama                         | L/P | PIL 1 | PIL 2 | MAT | B.INGG | B.INDO | IPA |\n";
	cout << "-----------------------------------------------------------------------------------------------------\n";
	for(int a = 0; a <= insiswa ; a++){
 		cout << "| "<<siswa[a].no_pendaftaran<<" | "<<siswa[a].nama<<" | "<<siswa[a].jenis_kelamin<<" | "<<siswa[a].jurusan1<<" | "<<siswa[a].jurusan2<<" | "<<siswa[a].nilai.matematika<<" | "<<siswa[a].nilai.b_inggris<<" | "<<siswa[a].nilai.b_indonesia<<" | "<<siswa[a].nilai.ipa<<" |\n";
		cout << "-----------------------------------------------------------------------------------------------------\n";	
	}
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "------------------------------------------Keterangan-------------------------------------------------\n";
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "--------------------------------|-----------Daftar Jurusan----------|--------------------------------\n";
	cout << "--------------------------------|1.| Teknik Komputer dan Jaringan   |--------------------------------\n";
	cout << "--------------------------------|2.| Teknik Rekayasa Perangkat Lunak|--------------------------------\n";
	cout << "--------------------------------|3.| Teknik Instalasi Tenaga Listrik|--------------------------------\n";
	cout << "--------------------------------|4.| Teknik Otomasi Industri        |--------------------------------\n";
	cout << "--------------------------------|5.| Teknik Audio Video             |--------------------------------\n";
	cout << "--------------------------------|6.| Multi Media                    |--------------------------------\n";
	cout << "-----------------------------------------------------------------------------------------------------\n"; 
	system("pause");
 }
 
 void dataditerima(int insiswa, pendaftaran siswa[200]){
 	for(int x = 0; x <= 5; x++){
	 	cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "--------------------------------Data Siswa Diterima Di Jurusan "<< x <<"--------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "| No Pendaftaran | Nama                         | L/P | PIL 1 | PIL 2 | MAT | B.INGG | B.INDO | IPA |\n";
		cout << "-----------------------------------------------------------------------------------------------------\n";
		for(int a = 0; a <= insiswa ; a++){
			if(siswa[a].status == x){
		 		cout << "| "<<siswa[a].no_pendaftaran<<" | "<<siswa[a].nama<<" | "<<siswa[a].jenis_kelamin<<" | "<<siswa[a].jurusan1<<" | "<<siswa[a].jurusan2<<" | "<<siswa[a].nilai.matematika<<" | "<<siswa[a].nilai.b_inggris<<" | "<<siswa[a].nilai.b_indonesia<<" | "<<siswa[a].nilai.ipa<<" |\n";
				cout << "-----------------------------------------------------------------------------------------------------\n";	
			}
		}
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "---------------------------------------------Keterangan----------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "--------------------------------|-----------Daftar Jurusan----------|--------------------------------\n";
		cout << "--------------------------------|1.| Teknik Komputer dan Jaringan   |--------------------------------\n";
		cout << "--------------------------------|2.| Teknik Rekayasa Perangkat Lunak|--------------------------------\n";
		cout << "--------------------------------|3.| Teknik Instalasi Tenaga Listrik|--------------------------------\n";
		cout << "--------------------------------|4.| Teknik Otomasi Industri        |--------------------------------\n";
		cout << "--------------------------------|5.| Teknik Audio Video             |--------------------------------\n";
		cout << "--------------------------------|6.| Multi Media                    |--------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------\n"; 
	 }
	system("pause");
 }
 
 void dataditolak(int insiswa, pendaftaran siswa[200]){
	 	cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "------------------------------------------Data Siswa Ditolak-----------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "| No Pendaftaran | Nama                         | L/P | PIL 1 | PIL 2 | MAT | B.INGG | B.INDO | IPA |\n";
		cout << "-----------------------------------------------------------------------------------------------------\n";
		for(int a = 0; a <= insiswa ; a++){
			if(siswa[a].status == -1){
		 		cout << "| "<<siswa[a].no_pendaftaran<<" | "<<siswa[a].nama<<" | "<<siswa[a].jenis_kelamin<<" | "<<siswa[a].jurusan1<<" | "<<siswa[a].jurusan2<<" | "<<siswa[a].nilai.matematika<<" | "<<siswa[a].nilai.b_inggris<<" | "<<siswa[a].nilai.b_indonesia<<" | "<<siswa[a].nilai.ipa<<" |\n";
				cout << "-----------------------------------------------------------------------------------------------------\n";	
			}
		}
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "---------------------------------------------Keterangan----------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "--------------------------------|-----------Daftar Jurusan----------|--------------------------------\n";
		cout << "--------------------------------|1.| Teknik Komputer dan Jaringan   |--------------------------------\n";
		cout << "--------------------------------|2.| Teknik Rekayasa Perangkat Lunak|--------------------------------\n";
		cout << "--------------------------------|3.| Teknik Instalasi Tenaga Listrik|--------------------------------\n";
		cout << "--------------------------------|4.| Teknik Otomasi Industri        |--------------------------------\n";
		cout << "--------------------------------|5.| Teknik Audio Video             |--------------------------------\n";
		cout << "--------------------------------|6.| Multi Media                    |--------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------------\n"; 
	system("pause");
 }
 
 void ubahnilai(pelajaran jurusan[6]){
 	int c;
 	cout << "-------------------------------------------------------------------------\n";
 	cout << "|-----------Daftar Jurusan----------|\n";
	cout << "|1.| Teknik Komputer dan Jaringan   |\n";
	cout << "|2.| Teknik Rekayasa Perangkat Lunak|\n";
	cout << "|3.| Teknik Instalasi Tenaga Listrik|\n";
	cout << "|4.| Teknik Otomasi Industri        |\n";
	cout << "|5.| Teknik Audio Video             |\n";
	cout << "|6.| Multi Media                    |\n";
	cout << "-------------------------------------------------------------------------\n";
	cout << "Masukan Pilihan Jurusan	: ";
	cin  >> c;
	cout << "Masukan Nilai Matematika	: ";
	cin  >> jurusan[c].matematika;
	cout << "Masukan Nilai Bahasa Indo	: ";
	cin  >> jurusan[c].b_indonesia ;
	cout << "Masukan Nilai Bahasa Ingg	: ";
	cin  >> jurusan[c].b_inggris;
	cout << "Masukan Nilai IPA			: ";
	cin  >> jurusan[c].ipa;
	
}

