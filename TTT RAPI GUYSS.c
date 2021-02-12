#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char nama[50];
char bidak = 'X', bidak2 = 'O';
int lvl, point, player = 1, skorplayer = 0, skorbot=0, JumlahSeri= 0, maks, a, b;

void ShowMainMenu();
void InputPlayerName();
void SelectLevel();
void ShowBoard();
int NumberChange();
int BonusPoin(int a, int b);
void FirstBoard();
int CekWin();
int Minimax(int x);
void ShowPlayerWinOrLose();

int main(){
	//Deklarasi
	int mainmenu;
	
	//Proses
	ShowMainMenu();
		scanf("%d", &mainmenu);
		system("cls");
		if (mainmenu == 1){
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
			
		} else if (mainmenu == 2){
			//modul highscore
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
		printf("Masukan Pilihan(1,2,3) :");

}

//modul input player name
void InputPlayerName(){
	system("cls");
	
		printf("====================================\n");
		printf("             TIC TAC TOE            \n");
		printf("====================================\n");
		printf("Masukkan Nama Player (Hanya 1 kata) :");
		scanf("%s", &nama);
	
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

    printf("%s (X)  -  Komputer  (O)  \n", nama);
    printf("Skor : %d - %d   \n", skorplayer, skorbot);
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

//modul pergantian nomor papan dengan bidak X
int NumberChange(){
	int i,j, pilih;
	char bidak = 'X';
	
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
		skorplayer++;
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
		BonusPoin(skorplayer,skorbot);
		
		//ShowPlayerWin
		if(skorplayer == 10 || skorbot == 10){
			ShowPlayerWinOrLose();
			i=2;
		}
			
	} while(i == -1); 

    getch();
	return 0;
}

//Modul untuk menampilkan siapa yang menang atau kalah
void ShowPlayerWinOrLose(){
	if(JumlahSeri == 3){
		system("cls");
		if(skorplayer > skorbot){
			printf("Selamat %s menang dalam permainan ini!", nama);
		} else if(skorplayer < skorbot){
			printf("Selamat %s kalah dalam permainan ini!", nama);	
		} else if(skorplayer == skorbot){
			printf("Selamat %s mendapatkan hasil seri dalam permainan ini!", nama);	
		}
	}
	
	if(skorplayer ==10){
			system("cls");
			printf("Selamat %s menang dalam permainan ini!", nama);
		} else if(skorbot == 10){
			system("cls");
			printf("Selamat %s kalah dalam permainan ini!", nama);	
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
				skorplayer+=3;
				return skorplayer;
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
        return  - 1;
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


