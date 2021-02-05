#include <stdio.h>
#include <stdlib.h>

//modul board tictactoe 3x3
void ShowBoard(){
	char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	
	system("cls");
    printf("====================================\n");
	printf("             TIC TAC TOE            \n");
	printf("====================================\n");

    printf("You (X)  -  Komputer  (O)\n\n\n");


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
	char nama[50];
	
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
			
		} else if (mainmenu == 2){
			//modul highscore
		} else if (mainmenu == 3){
			return 0; //exit
		}
	return 0;
}


