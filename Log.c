#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Log.h"
#include "ChessPiece.h"
#include "Game.h"

void CreateLog(){
    FILE *f;
    f = fopen("log.txt", "w");
    fprintf(f, "PRESS Q TO EXIT\n\n");
    fclose(f);	

}

void PlayerLog(Game *game, int Rank1, int File1, int Rank2, int File2){
    FILE *f;
    f = fopen("log.txt", "a");
    char color[10] = "";
    char name[10] = "";
    int c = game->board[Rank1][File1]->color;
    int n = game->board[Rank1][File1]->p_type;
    if (c == WHITE){
        strcpy(color, "white");
    }
    else{
        strcpy(color, "black");
    }
    if (n == PAWN){
        strcpy(name, "pawn");
    }
    if (n == BISHOP){
        strcpy(name, "bishop");
    }
    if (n == KNIGHT){
        strcpy(name, "knight");
    }
    if (n == ROOK){
        strcpy(name, "rook");
    }
    if (n == QUEEN){
        strcpy(name, "queen");
    }
    if (n == KING){
        strcpy(name, "king");
    }
    fprintf(f,"Player moved %s %s from %c%d to %c%d.\n", color, name, Rank1 + 97, File1 + 1, Rank2 + 97, File2 + 1);
    fclose(f);

}

void ComputerLog(Game *game, int Rank1, int File1, int Rank2, int File2){
    FILE *f;
    f = fopen("log.txt", "a");
    char color[10] = "";
    char name[10] = "";
    int c = game->board[Rank1][File1]->color;
    int n = game->board[Rank1][File1]->p_type;
	if (c == WHITE){
        strcpy(color, "white");
    }
    else{         
        strcpy(color, "black");
    }
    if (n == PAWN){
        strcpy(name, "pawn");
    }
    if (n == BISHOP){
        strcpy(name, "bishop");
    }
    if (n == KNIGHT){
        strcpy(name, "knight");
    }
    if (n == ROOK){
        strcpy(name, "rook");
    }
    if (n == QUEEN){
        strcpy(name, "queen");
    }
    if (n == KING){
        strcpy(name, "king");
    }
    fprintf(f,"Computer moved %s %s from %c%d to %c%d.\n", color, name, Rank1 + 97, File1 + 1, Rank2 + 97, File2 + 1);
    fclose(f);
}

void OpenLog(){
    FILE *f;
    f = fopen("log.txt", "r");
    if (f == NULL){
        printf("Log file does not exist.\n\n");
    }
    else{
        fclose(f);
        system("less log.txt");
    }
}
