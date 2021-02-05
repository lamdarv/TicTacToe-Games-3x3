#include <stdio.h>
#include <stdlib.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char nama[50];

//modul board tictactoe 3x3
void ShowBoard(){
	int skor = 0;
	
	system("cls");
    	printf("====================================\n");
	printf("             TIC TAC TOE            \n");
	printf("====================================\n");

    printf("%s (X)  -  Komputer  (O)  -  Skor : %d\n\n\n", nama, skor);


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
	int player = 1, i, pilih, skor = 0;
	char bidak = 'X';

	do 
	{
		ShowBoard();
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
	            printf("Invalid move ");
				player--;
				getch();
			}
		i = CekWin();
		player++;
	} while(skor == 10); 

	ShowBoard();
	if(skor == 10){
		printf("==>\aPlayer %d menang ", --player);
	} else {
		printf("==>\aGame draw");
	}
    getch();
	return 0;
}

int CekWin()
{
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
	int lvl;
		
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


int main()
{
	//Deklarasi
	int mainmenu;
	
	//Proses
	ShowMainMenu();
		scanf("%d", &mainmenu);
		system("cls");
		if (mainmenu == 1){
			InputPlayerName(); //Modul Input Player Name
			
			SelectLevel(); //Modul Select Level
			
			ShowBoard(); //Modul Showboard 3x3
			//modul Minimax
			NumberChange();
			
		} else if (mainmenu == 2){
			//modul highscore
		} else if (mainmenu == 3){
			return 0; //exit
		}
	return 0;
}


