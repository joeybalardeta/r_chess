#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Game.h"
#include "UI.h"
#include "Rules.h"
#include "Move.h"
#include "Log.h"
#include "MoveList.h"

Game *CreateGame(){
	Game *game = malloc(sizeof(Game));
	assert(game);

	
	game->whoTurn = WHITE;

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			game->board[i][j] = NULL;
		}
	}

	
	game->board[0][7] = CreatePiece(BLACK, ROOK);
	game->board[1][7] = CreatePiece(BLACK, KNIGHT);
	game->board[2][7] = CreatePiece(BLACK, BISHOP);
	game->board[3][7] = CreatePiece(BLACK, QUEEN);
	game->board[4][7] = CreatePiece(BLACK, KING);
	game->board[5][7] = CreatePiece(BLACK, BISHOP);
	game->board[6][7] = CreatePiece(BLACK, KNIGHT);
	game->board[7][7] = CreatePiece(BLACK, ROOK);

	game->board[0][6] = CreatePiece(BLACK, PAWN);
	game->board[1][6] = CreatePiece(BLACK, PAWN);
	game->board[2][6] = CreatePiece(BLACK, PAWN);
	game->board[3][6] = CreatePiece(BLACK, PAWN);
	game->board[4][6] = CreatePiece(BLACK, PAWN);
	game->board[5][6] = CreatePiece(BLACK, PAWN);
	game->board[6][6] = CreatePiece(BLACK, PAWN);
	game->board[7][6] = CreatePiece(BLACK, PAWN);


	game->board[0][0] = CreatePiece(WHITE, ROOK);
	game->board[1][0] = CreatePiece(WHITE, KNIGHT);
	game->board[2][0] = CreatePiece(WHITE, BISHOP);
	game->board[3][0] = CreatePiece(WHITE, QUEEN);
	game->board[4][0] = CreatePiece(WHITE, KING);
	game->board[5][0] = CreatePiece(WHITE, BISHOP);
	game->board[6][0] = CreatePiece(WHITE, KNIGHT);
	game->board[7][0] = CreatePiece(WHITE, ROOK);

	game->board[0][1] = CreatePiece(WHITE, PAWN);
	game->board[1][1] = CreatePiece(WHITE, PAWN);
	game->board[2][1] = CreatePiece(WHITE, PAWN);
	game->board[3][1] = CreatePiece(WHITE, PAWN);
	game->board[4][1] = CreatePiece(WHITE, PAWN);
	game->board[5][1] = CreatePiece(WHITE, PAWN);
	game->board[6][1] = CreatePiece(WHITE, PAWN);
	game->board[7][1] = CreatePiece(WHITE, PAWN);

	return game;
}


void DeleteGame(Game *game){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			DeletePiece(game->board[i][j]);
		}
	}

	
	free(game);
}


Game *CloneGame(Game *game){
	Game *clone = malloc(sizeof(Game));
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (game->board[i][j] != NULL){
				clone->board[i][j] = CreatePiece(game->board[i][j]->color, game->board[i][j]->p_type);
			}
			else{
				clone->board[i][j] = NULL;
			}
		}
	}


	clone->PLAYERW = game->PLAYERW;
	clone->PLAYERB = game->PLAYERB;
	clone->whoTurn = game->whoTurn;

	return clone;
}


void GameLoop(int option){
	Game *game = CreateGame();
	CreateLog();
	if (option == 1){
		int userSelection = 0;
		
		while (userSelection != 1 && userSelection != 2){
			printf("What color do you want to be?\n\n");
			printf("1 - White\n");
			printf("2 - Black\n\n");
			printf("Enter color here (1-2): ");
			scanf("%d", &userSelection);
		}
		
		if (userSelection == 1){
			game->PLAYERW = HUMAN;
			game->PLAYERB = COMPUTER;
		}
		else {
			game->PLAYERB = HUMAN;
			game->PLAYERW = COMPUTER;
		}
		
		if (game->PLAYERW == HUMAN){
			while (!isCheckmate(game) && !isStalemate(game)){
				if (game->whoTurn == WHITE){
					PrintBoard(game);
					MOVE *pmove = GetUserMove(game);
					Move(game, pmove);
					DeleteMove(pmove);				
					checkPromotions(game);
					game->whoTurn = BLACK;
				}
				else {
					PrintBoard(game);
					MOVE *AImove = GetAIMove(game);
					Move(game, AImove);
					printf("\n\nComputer moved %c%d to %c%d!\n\n", 'a' + AImove->r1, AImove->f1 + 1, 'a' + AImove->r2, AImove->f2 + 1);
					DeleteMove(AImove);
					checkPromotions(game);
					game->whoTurn = WHITE;
				}
			}
			EndGame(game);	
		}
		else{
			PrintBoardR(game);
            MOVE *AImove = GetAIMove(game);
            Move(game, AImove);
            printf("\n\nComputer moved %c%d to %c%d!\n\n", 'a' + AImove->r1, AImove->f1 + 1, 'a' + AImove->r2, AImove->f2 + 1);
            DeleteMove(AImove);
			game->whoTurn = BLACK;
			while (!isCheckmate(game) && !isStalemate(game)){
				if (game->whoTurn == BLACK){
					printf("\n");
					PrintBoardR(game);
					printf("\n");
					MOVE *pmove = GetUserMove(game);
					Move(game, pmove);
					DeleteMove(pmove);				
					checkPromotions(game);
					game->whoTurn = WHITE;
				}
				else {
					PrintBoardR(game);
					MOVE *AImove = GetAIMove(game);
					Move(game, AImove);
					printf("\n\nComputer moved %c%d to %c%d!\n\n\n", 'a' + AImove->r1, AImove->f1 + 1, 'a' + AImove->r2, AImove->f2 + 1);
					DeleteMove(AImove);
					checkPromotions(game);
					game->whoTurn = BLACK;
				}
			}
			EndGame(game);	
		}
	}
	else if (option == 2){
		game->PLAYERW = HUMAN;
        game->PLAYERB = HUMAN;
		while (!isCheckmate(game) && !isStalemate(game)){
	    	if (game->whoTurn == WHITE){
				printf("\n");
                PrintBoard(game);
				printf("\n");
                MOVE *pmove = GetUserMove(game);
                Move(game, pmove);
                DeleteMove(pmove);
               	checkPromotions(game);
                game->whoTurn = BLACK;
            }
            else {
				printf("\n");
                PrintBoardR(game);
				printf("\n");
                MOVE *pmove = GetUserMove(game);
                Move(game, pmove);
                DeleteMove(pmove);
               	checkPromotions(game);
                game->whoTurn = WHITE;
	        }
		}
		EndGame(game);
		

	}
	else {
		game->PLAYERW = COMPUTER;
		game->PLAYERB = COMPUTER;

		
		while (!isCheckmate(game) && !isStalemate(game)){
			if (game->whoTurn == WHITE){
				PrintBoard(game);
				MOVE *AImove = GetAIMove(game);
				Move(game, AImove);
				printf("\n\nComputer moved %c%d to %c%d!\n\n\n", 'a' + AImove->r1, AImove->f1 + 1, 'a' + AImove->r2, AImove->f2 + 1);
				DeleteMove(AImove);
				checkPromotions(game);
				game->whoTurn = BLACK;
			}
			else {
				PrintBoard(game);
				MOVE *AImove = GetAIMove(game);
				Move(game, AImove);
				printf("\n\nComputer moved %c%d to %c%d!\n\n\n", 'a' + AImove->r1, AImove->f1 + 1, 'a' + AImove->r2, AImove->f2 + 1);
				DeleteMove(AImove);
				checkPromotions(game);
				game->whoTurn = WHITE;
			}
		}
		EndGame(game);	
	}
}


// determine the winner and clean up memory
void EndGame(Game *game){
	if (game->PLAYERB == HUMAN){
		PrintBoardR(game);
	}
	else {
		PrintBoard(game);
	}
	if (isCheckmate(game)){
		if (game->whoTurn == WHITE){
			printf("Black wins!\n\n");
		}
		else {
			printf("White wins!\n\n");
		}
		LogWin(game);
	}
	else if (isStalemate(game)){
		printf("It's a draw!\n\n");
	}
}
