#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char bidak = 'X', bidak2 = 'O';
int lvl, player = 1, skorbot=0, JumlahSeri= 0, maks, bagian = 0, angka;
bool bag = false, bagA = false, bagB = false, bagC = false, bagD = false, bagE = false, bagF = false;

//Main Menu
void ShowMainMenu();
void PlayGame();
int ShowHighscore();
int ShowHelp();
int ShowAbout();

//Modul start 
void InputPlayerName();
void SelectLevel();
void ShowBoard();

//Modul Highscore
int AmbilData();
void SortHighscore(int n);
void SaveData();

//Modul saat bermain
int NumberChange();
int BonusPoin(int a, int b);
void FirstBoard();
void KondisiAwalAI();
int CekWin();
int BotMove(int x);
int ShowPlayerWinOrLose();


typedef struct{
	char nama[50];
	int skor;
} Player;
Player pemain;

typedef struct{
	char nama[50];
	int skor;
} DataHighscore;
DataHighscore data, list[50], temp;

int main(){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Modul utama untuk menjalankan semua modul dalam program
Initial State :Program belum berjalan
Final State : Program berhenti
Version dan Tanggal : 14.02.2021
*/
	//Deklarasi
	int mainmenu;
	
	//Proses
	ShowMainMenu();
		printf("\n\nMasukkan angka yang sesuai!\n");
		printf("Jika tidak, program akan berakhir\n");
		scanf("%d", &mainmenu);
		system("cls");
		if (mainmenu == 1){
			PlayGame(); //modul mulai permainan
		} else if (mainmenu == 2){
			ShowHighscore();//modul highscore
			if(angka == 1){
				system("cls");
				main();
			}
		} else if(mainmenu == 3){
			ShowHelp(); //modul help
			if(angka == 1){
				system("cls");
				main();
			}
		} else if(mainmenu == 4){
			ShowAbout(); //modul about
			if(angka==1){
				system("cls");
				main();
			}
		}
		  else if (mainmenu == 5){
			return 0; //exit
		} 
	return 0;
}

//modul ShowMainMenu
void ShowMainMenu(){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Menampilkan 3 pilihan main menu yaitu start, highscore, dan exit
Initial State : Program belum berjalan
Final State : Terlihat 5 pilihan menu di layar, yang dapat dipilih user untuk dijalankan
Version dan Tanggal : 04.02.2021
*/
	
		printf("====================================\n");
		printf("             TIC TAC TOE            \n");
		printf("====================================\n");
		printf("              MAIN MENU             \n");
		printf("====================================\n");
		printf("              [1]START              \n");
		printf("              [2]HIGHSCORE   	    \n");
		printf("              [3]HELP               \n");
		printf("              [4]ABOUT              \n");
		printf("              [5]EXIT               \n");
		printf("\n");
		printf("Masukan Pilihan(1,2,3,4,5) : ");

}

//modul input player name
void InputPlayerName(){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Modul untuk menginputkan nama player 1 yang akan bermain dengan batasan 50 karakter
Initial State : Variabel nama belum terisi
Final State : Variabel nama sudah terisi
Version dan Tanggal : 03.02.2021
*/
	system("cls");
	
		printf("====================================\n");
		printf("             TIC TAC TOE            \n");
		printf("====================================\n");
		printf("Masukkan Nama Player (Hanya 1 kata) : ");
		scanf("%s", &pemain.nama);
	
}

//modul SelectLevel
void SelectLevel(){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Akan tampil 3 pilihan level (easy, medium, hard)  pada layar dan user akan memilih satu level untuk bermain
Initial State : Level belum terpilih
Final State : Level sudah terpilih
Version dan Tanggal : 04.02.2021
*/
	system("cls");
		
		printf("====================================\n");
		printf("             TIC TAC TOE            \n");
		printf("====================================\n");
		printf("            SELECT LEVEL            \n");
		printf("              [1]EASY               \n");
		printf("              [2]MEDIUM   	        \n");
		printf("              [3]HARD               \n\n");
		printf("Masukkan Pilihan(1,2,3) = ");
		scanf("%d", &lvl);
	
}

//modul board tictactoe 3x3
void ShowBoard(){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Modul untuk menampilkan papan 3x3 yang diisi angka 1-9 serta akan digunakan untuk bermain
Initial State : Tampilan di layar masih berupa pilihan level
Final State : Tampilan berubah menjadi papan bermain yang tiap kotaknya berisi angka 1 sampai 9.
Version dan Tanggal : 03.02.2021
*/
	
	system("cls");
    printf("====================================\n");
	printf("             TIC TAC TOE            \n");
	printf("====================================\n");

    printf("%s (X)  -  Komputer  (O)  \n", pemain.nama);
    printf("Skor : %d - %d   \n", pemain.skor, skorbot);
    printf("Jumlah Seri : %d  \n", JumlahSeri);


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
    
    if(lvl == 3 || lvl == 2){
    	printf("Giliran pertama harus menginput angka 3!\n");
    	printf("Jika tidak, maka program ini akan otomatis menginput X di angka 3!\n");
	}
}

int AmbilData() {
/*
Author : Fiora Berliana Putri
Deskripsi : Mengambil data dari file highscore yang sudah disimpan modul SaveData() 
dan akan mengembalikan nilai n (banyaknya list dalam file highscore)
Initial State : -
Final State : -
Version dan Tanggal : 14.02.2021
*/
	//  Mengambil data dari file highscore yang sudah disimpan dari modul SaveData
	int n = 0;
	FILE *fptr;
	fptr = fopen("Highscore.dat", "rb");
	while(fread(&list[n], sizeof(DataHighscore), 1, fptr) == 1){
		n++;
	}	
	fclose(fptr);
	return n;
}

void SortHighscore(int n){
/*
Author : Fiora Berliana Putri
Deskripsi : Mengurutkan skor dari yang tertinggi sampai terendah untuk ditampilkan pada menu highscore
Initial State : Urutan skor masih sesuai dengan player terakhir yang bermain
Final State : Highscore sudah terurut 
Version dan Tanggal : 14.02.2021
*/
	int i, j ;
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(list[i].skor < list[j].skor){
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}	
void SaveData(){
/*
Author : Fiora Berliana Putri
Deskripsi : Modul untuk menyimpan data nama dan skor player 1 ke dalam file highscore.
Initial State : file highscore masih kosong
Final State : file highscore sudah terisi
Version dan Tanggal : 14.02.2021
*/
	
	//Memindahkan data pemain ke data highscore 
	strcpy(data.nama, pemain.nama);
	data.skor = pemain.skor;

	//Tulis data ke dalam file 
	FILE *fptr; 
	fptr = fopen("Highscore.dat", "ab");
	fwrite(&data, sizeof(DataHighscore), 1, fptr);
	fclose(fptr);
}

int ShowHighscore(){
/*
Author : Fiora Berliana Putri
Deskripsi : Menampilkan tampilan highscore di layar.
Initial State : -
Final State : -
Version dan Tanggal : 14.02.2021
*/
	int i, n;
	n = AmbilData();
	SortHighscore(n);

	printf("====================================\n");
	printf("             TIC TAC TOE            \n");
	printf("====================================\n");
	printf("             HIGHSCORE              \n\n");
	printf("Nama Player\tSkor");
	printf("\n");
	for(i = 0; i < n; i++){
		printf("%s", list[i].nama);
		printf("\t\t");
		printf("%d", list[i].skor);
		printf("\t\t");
		printf("\n");
	}
	printf("\n\nKetik angka 1 untuk kembali ke mainmenu : ");
	scanf("%d", &angka);

	return angka;
}


void PlayGame(){
/*
Author : Fiora Berliana Putri dan Lamda Richo Vanjaya Sumaryadi	
Deskripsi : Modul induk dari beberapa modul saat permainan dimulai.
Initial State : Tampilan layar masih berupa Main Menu.
Final State : Permainan berakhir dan kembali ke Main Menu
Version dan Tanggal : 13.02.2021
*/
	system("mode 60,25");	
	InputPlayerName(); // Input Player Name
	SelectLevel(); //Modul Select Level
	switch(lvl){
		case 1 : //Minimax level 1
			NumberChange(); //Modul untuk mengganti angka pada papan dengan bidak
			SaveData();
			system("cls");
			main();
			break;
		case 2 : //Minimax Level 2
			NumberChange(); //Modul untuk mengganti angka pada papan dengan bidak
			SaveData();
			system("cls");
			main();
			break;
		case 3 : //Minimax level 3
			NumberChange(); //Modul untuk mengganti angka pada papan dengan bidak
			SaveData();
			system("cls");
			main();
			break;
	}
}
//modul pergantian nomor papan dengan bidak X
int NumberChange(){
/*
Author : Fiora Berliana Putri dan Lamda Richo Vanjaya Sumaryadi
Deskripsi : Modul yang digunakan untuk pergerakan dari player 1 pada permainan
Initial State : Papan permainan masih berisi angka 1 sampai 9
Final State : Papan permainan yang dipilih player 1 akan berubah menjadi bidak ‘X’
Version dan Tanggal : 14.02.2021
*/
	int i,j,a, pilih;
	char bidak = 'X';
	pemain.skor=0;
	
	do 
	{
		ShowBoard();
		
		if(player % 2 != 0){
	
			printf("Pilih nomor papan : ");	
			scanf("%d", &pilih);
			
		if(lvl == 1){
			if (pilih == 1 && square[1] == '1'){
		         square[1] = bidak;        
		   } else if (pilih == 2 && square[2] == '2'){
		            square[2] = bidak;
		   } else if (pilih == 3 && square[3] == '3'){
		            square[3] = bidak;
		   } else if (pilih == 4 && square[4] == '4'){
		            square[4] = bidak;
		   } else if (pilih == 5 && square[5] == '5'){
		            square[5] = bidak;
		   } else if (pilih == 6 && square[6] == '6'){
		            square[6] = bidak;
		   } else if (pilih == 7 && square[7] == '7'){
		            square[7] = bidak;
		   } else if (pilih == 8 && square[8] == '8'){
		            square[8] = bidak;
		   } else if (pilih == 9 && square[9] == '9'){
		            square[9] = bidak;
		        } else {
		            printf("Nomor papan sudah terisi, silakan pilih nomor lain");
					player--;
					getch();
				}
		}	else if(lvl == 2 || lvl == 3){
				if(player == 1 && square[3] != 3){
					if (pilih == 1){
			        	square[3] = bidak;        
			   		} else if (pilih == 2){
			            square[3] = bidak;
			   		} else if (pilih == 3){
			            square[3] = bidak;
				    } else if (pilih == 4){
				        square[3] = bidak;
				    } else if (pilih == 5){
				        square[3] = bidak;
				    } else if (pilih == 6){
				        square[3] = bidak;
				    } else if (pilih == 7){
				        square[3] = bidak;
				    } else if (pilih == 8){
				        square[3] = bidak;
				    } else if (pilih == 9){
				        square[3] = bidak;
				    }
				} else if(player > 1){
					if (pilih == 1 && square[1] == '1'){
			        	square[1] = bidak;        
			   		} else if (pilih == 2 && square[2] == '2'){
			            square[2] = bidak;
			   		} else if (pilih == 3 && square[3] == '3'){
			            square[3] = bidak;
			   		} else if (pilih == 4 && square[4] == '4'){
			            square[4] = bidak;
			   		} else if (pilih == 5 && square[5] == '5'){
			            square[5] = bidak;
			 		} else if (pilih == 6 && square[6] == '6'){
			            square[6] = bidak;
			   		} else if (pilih == 7 && square[7] == '7'){
			            square[7] = bidak;
			   		} else if (pilih == 8 && square[8] == '8'){
			            square[8] = bidak;
			   		} else if (pilih == 9 && square[9] == '9'){
			            square[9] = bidak;
			        } else {
			            printf("Nomor papan sudah terisi, silakan pilih nomor lain");
						player--;
						getch();
					}
			}
			
		}
			
			i = CekWin();
			
			switch(player){
				case 3 : 
				if(square[1]==bidak){
					bag = true;
				} else if(square[2]==bidak){
					bagA = true;
				} else if(square[4]==bidak){
					bagB = true;
				} else if(square[6]==bidak){
					bagC = true;
				} else if(square[7]==bidak){
					bagD = true;
				} else if(square[8]==bidak){
					bagE = true;
				} else if(square[9]==bidak){
					bagF = true;
				} 
				break;

			}
			player++;
		} else{
			//minimax
			bagian++;
			BotMove(lvl);
			j = CekWin();
			if(j==1){ //kondisi bot kalo menang
				skorbot++;
				FirstBoard(); //kembali ke papan awal
				player=1;
				bagian=0;
				KondisiAwalAI();
				j=-1;
			} 
			else{
				player++;
			}
		}
		
		if(i == 1){ //Kondisi jika Player 1 menang
			pemain.skor++;
			FirstBoard(); //kembali ke papan awal
			player=1;
			bagian=0;
			KondisiAwalAI();
			i = -1;	
		} else if(i == 0){ //Kondisi jika seri
			JumlahSeri++;
			if(JumlahSeri <3){
				FirstBoard(); //Kembali ke papan awal	
				player=1; 
				bagian=0;
				KondisiAwalAI();
				i = -1;
			} else if(JumlahSeri == 3){
				ShowPlayerWinOrLose();
				printf("\n\nKetik angka 1 untuk kembali ke mainmenu : ");
				scanf("%d", &angka);
				FirstBoard();
				JumlahSeri = -1;
				skorbot=0;
				return angka;
			}
			
		}
		
		//Modul BonusPoin	
		BonusPoin(pemain.skor,skorbot);
		
		//ShowPlayerWin
		if(pemain.skor == 10 || skorbot == 10){
			ShowPlayerWinOrLose();
			printf("\n\nKetik angka 1 untuk kembali ke mainmenu : ");
			scanf("%d", &angka);
			skorbot=0;
			return angka;
		}
			
	} while(i == -1); 

    getch();
	return 0;
}

//Modul untuk menampilkan siapa yang menang atau kalah
int ShowPlayerWinOrLose(){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Menampilkan ke layar status player 1, apakah menang, kalah, atau seri.
Initial State : -
Final State : -
Version dan Tanggal : 14.02.2021
*/
	int pilih;
	system("cls");

	if(JumlahSeri == 3){
		if(pemain.skor > skorbot){
			printf("\aSelamat %s menang dalam permainan ini!\n\n", pemain.nama);
		} else if(pemain.skor < skorbot){
			printf("\aMaaf %s kalah dalam permainan ini, jangan menyerah!\n\n", pemain.nama);	
		} else if(pemain.skor == skorbot){
			printf("\aSelamat %s mendapatkan hasil seri dalam permainan ini!\n\n", pemain.nama);	
		}
	}
	
	if(pemain.skor == 10){
		printf("\aSelamat %s menang dalam permainan ini!\n\n", pemain.nama);
	} else if(skorbot == 10){;
		printf("\aMaaf %s kalah dalam permainan ini, jangan menyerah!\n\n", pemain.nama);	
	}
	
}

//Modul untuk menambahkan bonus poin
int BonusPoin(int a, int b){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Modul untuk menambahkan poin sebanyak 3 poin kepada pemain yang lebih cepat mendapatkan 2 poin.
Initial State : -
Final State : -
Version dan Tanggal : 12.02.2021
*/
	if(a == 2 || b == 2){ //Kondisi jika player atau bot mendapatkan poin 2 terlebih dahulu		
		if(a>b){
			maks = a;
		} else{
			maks = b;
		}
				
		if(maks == 2){
			if(maks == a){
				pemain.skor+=3;
				return pemain.skor;
			} else if(maks == b){
				skorbot+=3;
				return skorbot;
			}
		}
	}
}

//Modul untuk menampilkan papan awal
void FirstBoard(){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Mengembalikan keadaan papan seperti saat pertama kali mulai permainan
Initial State : -
Final State : -
Version dan Tanggal : 12.02.2021
*/
	square[1]='1';
	square[2]='2';
	square[3]='3';
	square[4]='4';
	square[5]='5';
	square[6]='6';
	square[7]='7';
	square[8]='8';
	square[9]='9';
}

//Modul untuk mengecek kondisi jika papan sudah penuh
int CekWin(){
/*
Author : Fiora Berliana Putri
Deskripsi : Modul ini akan memeriksa apakah di dalam papan sudah terdapat bidak yang membentuk pola lurus, 
jika sudah maka akan mengembalikan nilai 1, jika belum maka akan mengembalikan nilai -1, dan jika papan masih 
seperti keadaan awal maka akan mengembalikan nilai 0.
Initial State : -
Final State :  -
Version dan Tanggal : 04.02.2021
*/
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}
//Modul Untuk mengembalikan kondisi AI 
void KondisiAwalAI(){
/*
Author : 
Deskripsi : Membuat AI kembali pada kondisi awal agar BotMove bisa berjalan di ronde selanjutnya
Initial State : bag = true OR bagA = true OR bagB = true OR bagC = true OR bagD = true OR bagE = true OR bagF = true
Final State : bag = false AND bagA = false AND bagB = false AND bagC = false AND bagD AND bagE = false AND bagF = false
Version dan Tanggal : 14.02.2021
*/
	bag = false;
	bagA = false;
	bagB = false;
	bagC = false;
	bagD = false;
	bagE = false;
	bagF = false;
}

//modul Minimax
int BotMove(int x){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Mengisi nomor papan sesuai tingkat kecerdasan (easy, medium, hard)
Initial State : -
Final State : -
Version dan Tanggal : 14.02.2021
*/
	int i;
	switch(x){
		//Level 1
		case 1 : 
		for(i=1;i<=9;i++){
			if((square[i] != bidak) && (square[i] != bidak2)){
				square[i]=bidak2;
				i=10;
			}
		}
		break; 
		//Level 2
		case 2 :
		if(bagian >= 1 && square[3] == bidak){
		 	square[5]=bidak2;
		 	if(bag == true){
		 		if(bagian >= 2 && square[1] == bidak){
		 		square[2] = bidak2;
		 		if(bagian >=3 && square[8] == bidak){
		 			square[6] = bidak2;
		 			if(bagian >= 4 && square[4] == bidak){
		 				square[9] = bidak2; //Sengaja kasih kesempatan biar player menang
					} else if(bagian >= 4 && square[4]=='4' &&square[9]==bidak && square[7]=='7'){
					 	square[4] = bidak2;	 //AI Win					 
					} else if(bagian >=4 && square[7]==bidak){
						square[9] = bidak2;
					}
				} else if( bagian >=3 && square[8]=='8'){
				 	square[8] = bidak2;//AI Win
				}
			 }
		 	
			} else if(bagA==true){
			   if(bagian >= 2 && square[2] == bidak){
			   square[1] = bidak2;
		       if(bagian >=3 && square[9]==bidak){
					square[6] = bidak2;
				 	if(bagian >= 4 && square[4]==bidak){
						square[7]=bidak2; //Tie
		    		} else if(bagian >= 5 && square[7]=='7'){
					 	square[7] = bidak2; //Sengaja kasih kesempatan biar player menang
					} else if(bagian >= 5 && square[8]=='8'){
						square[8] = bidak2; //Sengaja kasih kesempatan biar player menang
					}
			   } else if(bagian >= 3 && square[9]=='9'){
					square[9] = bidak2; //AI Win
			   }	
			   }
			} else if(bagB==true){
			   if(bagian >= 2 && square[4]==bidak){
			   square[1]=bidak2;
			   if(bagian >= 3 && square[9]==bidak){
					square[6]=bidak2;
					if(bagian >= 4 && square[8]==bidak && square[2]=='2'){
						square[2]=bidak2; //Sengaja kasih kesempatan biar player menang
					} else if(bagian >= 4 && square[7]==bidak){
						square[8]=bidak2; //Tie
					} else if(bagian >= 4 && square[2]==bidak){
						square[8]=bidak2; //Tie
					}
				} else if(bagian >=3 &&square[9]=='9'){
					square[9]=bidak2; //AI Win
			    }
	  		  	}
			} else if(bagC==true){
				if(bagian >= 2 && square[6]==bidak){
				square[9]=bidak2;
			 	if(bagian >= 3 && square[1]==bidak){
					square[2]=bidak2;
			 		if(bagian >= 4 && square[8]==bidak){
			 			square[7]=bidak2; //Tie
		       		} else if(bagian >= 4 && square[4]==bidak){
					 	square[7]=bidak2; //Sengaja kasih kesempatan biar player menang
					} else if(bagian >=4 && square[7]==bidak){
						square[4]==bidak2; //Sengaja kasih kesempatan biar player menang
					}
			    } else if(bagian >= 3 && square[1]=='1'){
					square[1]=bidak2; //AI Win
				}
			  	}	
			} else if(bagD==true){
				if(bagian >= 2 && square[7]==bidak){
				square[4]=bidak2;
				if(bagian >= 3 && square[6]==bidak){
					square[9]=bidak2;
					if(bagian >= 4 && square[1]==bidak){
						square[2]=bidak2; //Tie
					} else if(bagian >= 4 && square[2]==bidak){
						square[8]=bidak2; //Sengaja kasih kesempatan biar player menang
					} else if(bagian >=4 && square[8]==bidak){
						square[2]=bidak2; //Sengaja kasih kesempatan biar player menang
					}
				} else if(bagian >= 3 && square[6]=='6'){
					square[6]=bidak2; //AI Win
				}
				}
			} else if(bagE==true){
				if(bagian >= 2 && square[8]==bidak){
			    square[9]=bidak2;
			    if(bagian >= 3 && square[1]==bidak){
			   		square[2]=bidak2;
					if(bagian >= 4 && square[4]==bidak && square[6]=='6'){
						square[6]=bidak2; //Sengaja kasih kesempatan biar player menang
					} else if(bagian >= 4 && square[7]==bidak){
						square[4]=bidak2; //Tie
					} else if(bagian >= 4 && square[6]==bidak){
						square[4]=bidak2; //Tie
					}		
			    } else if(bagian >= 3 && square[1]=='1'){
			   		square[1]=bidak2; //AI Win
			    }
			    }
			} else if(bagF == true){
				if(bagian >= 2 && square[9]==bidak){
			    square[6]=bidak2;
			    if(bagian >= 3 && square[4]==bidak){
			   		square[2]=bidak2;
					if(bagian >= 4 && square[8]==bidak){
						square[1]=bidak2; //Sengaja kasih kesempatan biar player menang
					} else if(bagian >= 4 && square[8]=='8'){
						square[8]=bidak2; //AI Win
					}
			   } else if(bagian >= 3 && square[4]=='4'){
			   	 square[4]=bidak2; //AI Win
			   }
			   }	
			} 
			
			break;	
		}	 
		//Level 3
		case 3 :
		if(bagian >= 1 && square[3] == bidak){
		 	square[5]=bidak2;
		 	if(bag == true){
		 		if(bagian >= 2 && square[1] == bidak){
		 		square[2] = bidak2;
		 		if(bagian >=3 && square[8] == bidak){
		 			square[6] = bidak2;
		 			if(bagian >= 4 && square[4] == bidak){
		 				square[7] = bidak2; //Tie
					} else if(bagian >= 4 && square[4]=='4'){
					 	square[4] = bidak2;	 //AI Win					 
					}
				} else if( bagian >=3 && square[8]=='8'){
				 	square[8] = bidak2;//AI Win
				}
			 }
		 	
			} else if(bagA==true){
			   if(bagian >= 2 && square[2] == bidak){
			   square[1] = bidak2;
		       if(bagian >=3 && square[9]==bidak){
					square[6] = bidak2;
				 	if(bagian >= 4 && square[4]==bidak){
						square[7]=bidak2; //Tie
		    		} else if(bagian >= 5 && square[4]=='4'){
					 	square[4] = bidak2; //AI Win
					}			 
			   } else if(bagian >= 3 && square[9]=='9'){
					square[9] = bidak2; //AI Win
			   }	
			   }
			} else if(bagB==true){
			   if(bagian >= 2 && square[4]==bidak){
			   square[1]=bidak2;
			   if(bagian >= 3 && square[9]==bidak){
					square[6]=bidak2;
					if(bagian >= 4 && square[8]==bidak){
						square[7]=bidak2; //Tie
					} else if(bagian >= 4 && square[7]==bidak){
						square[8]=bidak2; //Tie
					} else if(bagian >= 4 && square[2]==bidak){
						square[8]=bidak2; //Tie
					}
				} else if(bagian >=3 &&square[9]=='9'){
					square[9]=bidak2; //AI Win
			    }
	  		  	}
			} else if(bagC==true){
				if(bagian >= 2 && square[6]==bidak){
				square[9]=bidak2;
			 	if(bagian >= 3 && square[1]==bidak){
					square[2]=bidak2;
			 		if(bagian >= 4 && square[8]==bidak){
			 			square[7]=bidak2; //Tie
		       		} else if(bagian >= 4 && square[8]=='8'){
					 	square[8]=bidak2; //AI Win
					}
			    } else if(bagian >= 3 && square[1]=='1'){
					square[1]=bidak2; //AI Win
				}
			  	}	
			} else if(bagD==true){
				if(bagian >= 2 && square[7]==bidak){
				square[4]=bidak2;
				if(bagian >= 3 && square[6]==bidak){
					square[9]=bidak2;
					if(bagian >= 4 && square[1]==bidak){
						square[2]=bidak2; //Tie
					} else if(bagian >= 4 && square[1]=='1'){
						square[1]=bidak2; //AI Win
					}
				} else if(bagian >= 3 && square[6]=='6'){
					square[6]=bidak2; //AI Win
				}
				}
			} else if(bagE==true){
				if(bagian >= 2 && square[8]==bidak){
			    square[9]=bidak2;
			    if(bagian >= 3 && square[1]==bidak){
			   		square[2]=bidak2;
					if(bagian >= 4 && square[4]==bidak){
						square[7]=bidak2; //Tie
					} else if(bagian >= 4 && square[7]==bidak){
						square[4]=bidak2; //Tie
					} else if(bagian >= 4 && square[6]==bidak){
						square[4]=bidak2; //Tie
					}		
			    } else if(bagian >= 3 && square[1]=='1'){
			   		square[1]=bidak2; //AI Win
			    }
			    }
			} else if(bagF == true){
				if(bagian >= 2 && square[9]==bidak){
			    square[6]=bidak2;
			    if(bagian >= 3 && square[4]==bidak){
			   		square[2]=bidak2;
					if(bagian >= 4 && square[8]==bidak && square[7]=='7'){
						square[7]=bidak2; //Tie
					} else if(bagian >= 4 && square[8]=='8'){
						square[8]=bidak2; //AI Win
					}
			   } else if(bagian >= 3 && square[4]=='4'){
			   	 square[4]=bidak2; //AI Win
			   }
			   }	
			} 
				
		break;	
		}
	}
}

//Modul untuk menjelaskan peraturan dan tata cara permainan
int ShowHelp(){
/*
Author : Fiora Berliana Putri
Deskripsi : Menampilkan tampilan mengenai tata cara bermain dan aturan permainan ini. serta akan mengembalikan 
nilai 1 untuk kembali ke Main Menu
Initial State :-
Final State : -
Version dan Tanggal : 14.02.2021
*/
	char help[300];
	FILE *fp;

	system("mode 80,50");
	fp = fopen("Help.txt","rb");
	while(fgets(help, sizeof(help), fp)){
		printf("%s", help);
	}
	fclose(fp);
	
	printf("\n\nKetik angka 1 untuk kembali ke mainmenu : ");
	scanf("%d", &angka);

	return angka;
}					
	
//Modul untuk menampilkan halaman about
int ShowAbout(){
/*
Author : Lamda Richo Vanjaya Sumaryadi
Deskripsi : Modul untuk menampilkan mengenai kami sebagai pembuat program serta tujuan pembuatan program tic tac toe ini.
Initial State : Tampilan layar berupa Mian Menu
Final State : Tampilan layar berupa about
Version dan Tanggal : 14.02.2021
*/
	
	char about[300];
	FILE *abt;
	
	system("mode 80,45");
	abt = fopen("About.txt", "rb");
	while(fgets(about, sizeof(about), abt)){
		printf("%s", about);
	}
	fclose(abt);
	
	printf("\n\nKetik angka 1 untuk kembali ke mainmenu : ");
	scanf("%d", &angka);
	
	return angka;
}
