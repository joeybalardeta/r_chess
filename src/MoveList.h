#ifndef MOVELIST_H
#define MOVELIST_H

#include "ChessPiece.h"
#include "Move.h"

typedef struct MoveList MLIST;
typedef struct MoveEntry MENTRY;



struct MoveList{
	MENTRY *First;
	MENTRY *Last;
	unsigned int Length;

};

struct MoveEntry {
	MLIST *mList;
	MENTRY *Next;
	MENTRY *Prev;

	MOVE *Move;

	int points;
};


MLIST *CreateMoveList();

void DeleteMoveList(MLIST *mList);

void AppendMoveEntry(MLIST *mList, MOVE *m);

void DeleteMoveEntry(MLIST *mList, int index);

#endif
