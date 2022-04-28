#ifndef AI_H
#define AI_H

#include "Game.h"
#include "Move.h"
#include "ChessPiece.h"
#include "MoveList.h"

MLIST *GetAllLegalMoves(Game *game);

MLIST *RankMoves(Game *game, MLIST *mList);

MLIST *CullMoves(Game *game, MLIST *mList);

MLIST *RankMovesFuture(Game *origin, Game *game, MLIST *mList, int depth);

MOVE *GetBestMove(Game *game, MLIST *mList);

#endif
