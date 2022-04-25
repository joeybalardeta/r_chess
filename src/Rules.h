#ifndef RULES_H
#define RULES_H

#include "Game.h"
#include "Move.h"
#include "ChessPiece.h"

int isCheckmate(Game *game);

int isStalemate(Game *game);

int isLegalMove(Game *game, MOVE *move);

int isValidPieceMove(Game *game, MOVE *move);

int exposesKing(Game *game, MOVE *move);

int isObstructed(Game *game, MOVE *move);

int isInCheck(Game *game);

void checkPromotions(Game* game);

#endif
