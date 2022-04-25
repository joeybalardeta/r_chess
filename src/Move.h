#ifndef MOVE_H
#define MOVE_H

#include "Game.h"
#include "ChessPiece.h"

typedef struct {
	int r1; // rank to go from
	int f1; // file to go from
	int r2; // rank to go to
	int f2; // file to go to
	Color who;

} MOVE;


MOVE *CreateMove(int r1, int f1, int r2, int f2);



void DeleteMove(MOVE *move);



// moves a piece on the board
void Move(Game *game, MOVE *move);

// gets the move from the user, will check if the move is legal
MOVE *GetUserMove(Game *game);

// gets the move from the computer, will check if the move is legal
MOVE *GetAIMove(Game *game);

// converts char into int
int charToInt(char c);
#endif
