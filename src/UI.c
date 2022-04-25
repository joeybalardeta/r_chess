#include <stdio.h>
#include "Game.h"
#include "ChessPiece.h"


void PrintBoard(Game *game){



	for (int i = 8; i > 0; i--){
		printf("  +----+----+----+----+----+----+----+----+\n");

		printf("%d |", i);
		for (int j = 0; j <= 7; j++){
			char *name = "  ";
			if (game->board[j][i - 1] != NULL){
				name = game->board[j][i - 1]->name;
			}
			printf(" %s |", name);
		}
		printf("\n");
	}






	printf("  +----+----+----+----+----+----+----+----+\n");
	printf("    A    B    C    D    E    F    G    H\n");
}

void PrintBoardR(Game *game){
    for (int i = 0; i < 8; i++){
        printf("  +----+----+----+----+----+----+----+----+\n");

        printf("%d |", i + 1);
        for (int j = 8; j > 0; j--){
            char *name = "  ";
            if (game->board[j - 1][i] != NULL){
                name = game->board[j - 1][i]->name;
            }
            printf(" %s |", name);
        }
        printf("\n");
    }





    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("    H    G    F    E    D    C    B    A\n");

}
