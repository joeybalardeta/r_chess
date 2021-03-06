#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

// including local modules
#include "UI.h" // responsible for drawing the game and showing it to the user
#include "Game.h" // responsible for the game loop and game logic
#include "ChessPiece.h" // responsible for the chess piece structs and rules
#include "MoveList.h"
#include "AI.h"
#include "Log.h"

// function declarations
void PrintMenu();
void ProcessInput();
void Uninstall();


int main(){

	/* Test code for debugging
	Game *game = CreateGame();
	MOVE *move = GetAIMove(game);
	DeleteMove(move);
	DeleteGame(game);

	return 0;

	*/


    printf("Welcome to r/chess!\n\n");

    int userSelection = 0;

    while (userSelection != 6 && userSelection != 5){
        PrintMenu();
        scanf("%d", &userSelection);
        ProcessInput(userSelection);

    }

    printf("Goodbye!\n");
    return 0;
}

void PrintMenu(){
    printf("Select an option:\n\n");
    printf("1 - Player Versus Computer\n");
    printf("2 - Player Versus Player\n");
    printf("3 - Computer Versus Computer\n");
    printf("4 - Show Log of Previous Game\n");
    printf("5 - Uninstall\n");
    printf("6 - Exit\n\n");

    printf("Enter choice here (1-6): ");
}


void ProcessInput(int option){
    switch (option){
        case 1:
            GameLoop(option);
            break;


        case 2:
            GameLoop(option);
            break;


        case 3:
            GameLoop(option);
            break;
               

        case 4:
            OpenLog();
            break;


        case 5:
            Uninstall();
            break;


        case 6:
            break;


        default:
            printf("That is not a valid option!\n");
            break;


    }

}


void Uninstall(){
	system("rm -f log.txt");
	system("rm -f r_chess");
    printf("r/chess has been successfully uninstalled.\n");
}

