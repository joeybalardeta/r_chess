#ifndef GAME_H
#define GAME_H

#include "ChessPiece.h"

typedef enum {HUMAN = 0, COMPUTER = 1} PLAYER_TYPE;


typedef struct{
	ChessPiece *board[8][8];
	PLAYER_TYPE PLAYERW;
	PLAYER_TYPE PLAYERB;
	Color whoTurn;
} Game;


Game *CreateGame();

void DeleteGame(Game *game);

Game *CloneGame(Game *game);

void GameLoop(int option);

void EndGame(Game *game);



#endif
