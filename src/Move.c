#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Move.h"
#include "Game.h"
#include "Rules.h"
#include "ChessPiece.h"
#include "AI.h"
#include "Log.h"

MOVE *CreateMove(int r1, int f1, int r2, int f2){
	MOVE *move = malloc(sizeof(MOVE));
	move->r1 = r1;
	move->f1 = f1;
	move->r2 = r2;
	move->f2 = f2;

	return move;
}



void DeleteMove(MOVE *move){
	free(move);
}



void Move(Game *game, MOVE *move){
    int currentRank, currentFile, newRank, newFile;
    
    currentRank = move->r1;
    currentFile = move->f1;
    newRank = move->r2;
    newFile = move->f2;
	
	if (currentRank == newRank && currentFile == newFile){
		return;
	}

	if (game->board[currentRank][currentFile] == NULL){
		printf("ERROR - Attempting to move a NULL piece!\n");
		return;
	}

	if (game->board[newRank][newFile] != NULL){
		DeletePiece(game->board[newRank][newFile]);
	}

	game->board[newRank][newFile] = game->board[currentRank][currentFile];
	game->board[currentRank][currentFile] = NULL;

	game->board[newRank][newFile]->numberOfMoves++;
}



MOVE *GetUserMove(Game *game){
    char currentPos[2];
	char newPos[2];
	MOVE *m = CreateMove(0, 0, 0, 0);
	int isLegal = 0;

	while(!isLegal){
   		printf("Enter the position of the piece you want to move: ");
		char temp[1000];
		scanf("%s", temp);
		currentPos[0] = temp[0];
		currentPos[1] = temp[1];

    	m->r1 = charToInt(currentPos[0]);
	    m->f1 = (currentPos[1]) - '0' - 1;
    		

		printf("Enter the position of the square you want to move your piece to: ");
		scanf("%s", temp);
		newPos[0] = temp[0];
		newPos[1] = temp[1];

    	m->r2 = charToInt(newPos[0]);
    	m->f2 = (newPos[1]) - '0' - 1;
	
		// printf("%d, %d, %d, %d", m->r1, m->f1, m->r2, m->f2);
			
		if (!isLegalMove(game, m)){
			printf("Move not valid!\n\n");
		}
		else {
			isLegal = 1;
			PlayerLog(game, m->r1, m->f1, m->r2, m->f2);
		}

	}
    return m;
}




MOVE *GetAIMove(Game *game){
	MLIST *mList = GetAllLegalMoves(game);
	mList = RankMoves(game, mList);
	MOVE *m = GetBestMove(game, mList);
	ComputerLog(game, m->r1, m->f1, m->r2, m->f2);
	return m;
}

int charToInt(char c)
{
    switch(c)
    {
        case 'A' :
            return 0;
        case 'a' :
            return 0;
        case 'B' :
            return 1;
        case 'b' :
            return 1;
        case 'C' :
            return 2;
        case 'c' :
            return 2;
        case 'D' :
            return 3;
        case 'd' :
            return 3;
        case 'E' :
            return 4;
        case 'e' :
            return 4;
        case 'F' :
            return 5;
        case 'f' :
            return 5;
        case 'G' :
            return 6;
        case 'g' :
            return 6;
        case 'H' :
            return 7;
        case 'h' :
            return 7;
        default :
            return -1;
    }
}
