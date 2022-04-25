#include <stdlib.h>
#include <stdio.h>
#include "Move.h"
#include "MoveList.h"


MLIST *CreateMoveList(){
	MLIST *mList = (MLIST *) malloc(sizeof(MLIST));
	mList->Length = 0;
	mList->First = NULL;
	mList->Last = NULL;

	return mList;
}

void DeleteMoveList(MLIST *mList){
	int tempLength = mList->Length;

	for (int i = 0; i < tempLength; i++){
		DeleteMoveEntry(mList, 0);
	}

	mList->Last = NULL;
	mList->First = NULL;

	free(mList);
}

void AppendMoveEntry(MLIST *mList, MOVE *m){
	MENTRY *entry = malloc(sizeof(MENTRY));

	entry->mList = mList;

	mList->Length++;

	entry->Move = m;

	entry->Next = NULL;

	entry->points = 0;
	

	if (mList->Length == 1){
		entry->Prev = NULL;
		mList->First = entry;
	}
	else {
		entry->Prev = mList->Last;
		mList->Last->Next = entry;
	}
	

	mList->Last = entry;

}

void DeleteMoveEntry(MLIST *mList, int index){
	MENTRY *entry = mList->First;

	if (index < 0 || index >= mList->Length){
		return;
	}

	for (int i = 0; i < index; i++){
		entry = entry->Next;
	}

	MENTRY *entryprev = entry->Prev;
	MENTRY *entrynext = entry->Next;

	if (mList->Length == 1){
		mList->Last = NULL;
		mList->First = NULL;
	}
	else if (index == 0){
		mList->First = entry->Next;
		entrynext->Prev = NULL;
	}
	else if (index == mList->Length - 1){
		mList->Last = entry->Prev;
		entryprev->Next = NULL;
	}
	else {
		entryprev->Next = entrynext;
		entrynext->Prev = entryprev;
	}

	entry->Next = NULL;
	entry->Prev = NULL;

	if (entry->Move != NULL){
		DeleteMove(entry->Move);
		entry->Move = NULL;
	}

	entry->mList = NULL;

	free(entry);

	mList->Length--;

}
















