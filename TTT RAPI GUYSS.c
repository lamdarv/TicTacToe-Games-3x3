#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char bidak = 'X', bidak2 = 'O';
int lvl, point, player = 1, skorbot=0, JumlahSeri= 0, maks, a, b;

//Main Menu
void ShowMainMenu();
void PlayGame();
void ShowHighscore();

//Modul start 
void InputPlayerName();
void SelectLevel();
void ShowBoard();

//Modul Highscore
int AmbilData();
void SortHighscore();
void SaveData();

//Modul saat bermain
int NumberChange();
int BonusPoin(int a, int b);
void FirstBoard();
int CekWin();
int Minimax(int x);
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
	//Deklarasi
	int mainmenu;
	
	//Proses
	ShowMainMenu();
		scanf("%d", &mainmenu);
		system("cls");
		if (mainmenu == 1){
			PlayGame(); //modul mulai permainan
		} else if (mainmenu == 2){
			ShowHighscore();//modul highscore
		} else if (mainmenu == 3){
			return 0; //exit
		}
	return 0;
}

//modul ShowMainMenu
void ShowMainMenu(){
	
		printf("====================================\n");
		printf("             TIC TAC TOE            \n");
		printf("====================================\n");
		printf("              MAIN MENU             \n");
		printf("====================================\n");
		printf("              [1]START              \n");
		printf("            [2]HIGHSCORE   	        \n");
		printf("              [3]EXIT               \n");
		printf("\n");
		printf("Masukan Pilihan(1,2,3) : ");

}

//modul input player name
void InputPlayerName(){
	system("cls");
	
		printf("====================================\n");
		printf("             TIC TAC TOE            \n");
		printf("====================================\n");
		printf("Masukkan Nama Player (Hanya 1 kata) : ");
		scanf("%s", &pemain.nama);
	
}

//modul SelectLevel
void SelectLevel(){
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
	
	system("cls");
    printf("====================================\n");
	printf("             TIC TAC TOE            \n");
	printf("====================================\n");

    printf("%s (X)  -  Komputer  (O)  \n", pemain.nama);
    printf("Skor : %d - %d   \n", pemain.skor, skorbot);
    printf("Jumlah Seri : %d  \n\n\n", JumlahSeri);


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

int AmbilData() {
	//  Mengambil data dari file highscore yang sudah disimpan dari modul SaveData
	int n = 0;
	FILE *fptr;
	fptr = fopen("Highscore.txt", "rb");
	while(fread(&list[n], sizeof(DataHighscore), 1, fptr) == 1) n++;
	fclose(fptr);
	return n;
}

void SortHighscore(int n){
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
	
	/* Memindahkan data pemain ke data highscore */
	strcpy(data.nama, pemain.nama);
	data.skor = pemain.skor;

	/* Tulis data ke dalam file */
	FILE *fptr; 
	fptr = fopen("Highscore.txt", "ab");
	fwrite(&data, sizeof(DataHighscore), 1, fptr);
	fclose(fptr);
}

void ShowHighscore(){
	int i, n;
	FILE*fptr;
	fptr = fopen("Highscore.txt", "rb");
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
	fclose(fptr);
	}
}


void PlayGame(){
			
	InputPlayerName(); // Input Player Name
	SelectLevel(); //Modul Select Level
	switch(lvl){
		case 1 : //Minimax level 1
			ShowBoard(); //Modul Showboard 3x3
			NumberChange(); //Modul untuk mengganti angka pada papan dengan bidak
			CekWin(); 
			break;
		case 2 : //Minimax Level 2
			break;
		case 3 : //Minimax level 3
			break;
	}
	SaveData();
}
//modul pergantian nomor papan dengan bidak X
int NumberChange(){
	int i,j, pilih;
	char bidak = 'X';
	pemain.skor = 0;
	
	do 
	{
		ShowBoard();
		
		if(player % 2 != 0){
	
			printf("Pilih nomor papan : ");	
			scanf("%d", &pilih);
			
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
			i = CekWin();
			player++;
		} else{
			//minimax 
			Minimax(lvl);
			j = CekWin();
			if(j==1){
				skorbot++;
				FirstBoard(); //kembali ke papan awal
			}
			player++;
		}
		
		if(i == 1){ //Kondisi jika Player 1 menang
		pemain.skor++;
		FirstBoard(); //kembali ke papan awal
		player = 1; 
		i = -1;	
		} else if(i == 0){ //Kondisi jika seri
			JumlahSeri++;
			if(JumlahSeri <3){
				FirstBoard(); //Kembali ke papan awal
				player = 1; 
				i = -1;
			} else if(JumlahSeri == 3){
				ShowPlayerWinOrLose();
			}
			
		}
		
		//Modul BonusPoin	
		BonusPoin(pemain.skor,skorbot);
		
		//ShowPlayerWin
		if(pemain.skor == 10 || skorbot == 10){
			ShowPlayerWinOrLose();	
			i=2;
		}
			
	} while(i == -1); 

    getch();
	return 0;
}

//Modul untuk menampilkan siapa yang menang atau kalah
int ShowPlayerWinOrLose(){
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

	printf("Tekan 1 untuk kembali ke Main Menu\n");
	printf("Masukkan pilihan : ");
	scanf("%d", &pilih);
	if(pilih == 1){
		system("cls");
		main();
	} else {
		return 0;
	}
	
}

//Modul untuk menambahkan bonus poin
int BonusPoin(int a, int b){
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

//modul Minimax
int Minimax(int x){
	int i;
	switch(x){
		case 1 : for(i=1;i<=9;i++){
					if((square[i] != bidak) && (square[i] != bidak2)){
						square[i]=bidak2;
						i=10;
					}
				}
				break; 
							
	}
}
