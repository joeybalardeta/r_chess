#include <stdlib.h>
#include <stdio.h>

#include "AI.h"
#include "Game.h"
#include "Rules.h"
#include "Move.h"
#include "ChessPiece.h"
#include "MoveList.h"



// AI ENGING VARIABLES
#define PIECE_POINTS_MULTIPLIER 6
#define KING_DISTANCE_MULTIPLIER 8
#define DEFAULT_AGGRESSION_MULTIPLIER 2



MLIST *GetAllLegalMoves(Game *game){
	MLIST *mList = CreateMoveList();

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			ChessPiece *piece = game->board[i][j];
			if (piece != NULL && piece->color == game->whoTurn){
				for (int r = 0; r < 8; r++){
					for (int f = 0; f < 8; f++){
						MOVE *move = CreateMove(i, j, r, f);
						if (isLegalMove(game, move) && !exposesKing(game, move)){
							AppendMoveEntry(mList, move);
						}
						else {
							DeleteMove(move);
						}
					}
				}
			}
		}
	}

	return mList;
}

MLIST *RankMoves(Game *game, MLIST *mList){
	if (mList->Length == 0){
		return NULL;
	}

	Color who = game->whoTurn;

	int rK = 0, fK = 0;

	if (who == WHITE){
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				if (game->board[i][j] != NULL
					&& game->board[i][j]->p_type == KING
					&& game->board[i][j]->color == BLACK){
					rK = i;
					fK = j;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				if (game->board[i][j] != NULL
					&& game->board[i][j]->p_type == KING
					&& game->board[i][j]->color == WHITE){
					rK = i;
					fK = j;
				}
			}
		}
	}

	int AGGRESSION_MULTIPLIER = DEFAULT_AGGRESSION_MULTIPLIER;
	int aggro_points = 0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (game->board[i][j] != NULL && game->board[i][j]->color == game->whoTurn){
				ChessPiece *piece = game->board[i][j];

				switch (piece->p_type){
					case PAWN:
						aggro_points += PIECE_POINTS_MULTIPLIER * 1;
						break;

					case ROOK:
						aggro_points += PIECE_POINTS_MULTIPLIER * 5;
						break;

					case KNIGHT:
						aggro_points += PIECE_POINTS_MULTIPLIER * 3;
						break;

					case BISHOP:
						aggro_points += PIECE_POINTS_MULTIPLIER * 3;
						break;

					case QUEEN:
						aggro_points += PIECE_POINTS_MULTIPLIER * 9;
						break;

					default:
						break;
				}
			}
			else if (game->board[i][j] != NULL && game->board[i][j]->color != game->whoTurn){
				ChessPiece *piece = game->board[i][j];

				switch (piece->p_type){
					case PAWN:
						aggro_points -= PIECE_POINTS_MULTIPLIER * 1;
						break;

					case ROOK:
						aggro_points -= PIECE_POINTS_MULTIPLIER * 5;
						break;

					case KNIGHT:
						aggro_points -= PIECE_POINTS_MULTIPLIER * 3;
						break;

					case BISHOP:
						aggro_points -= PIECE_POINTS_MULTIPLIER * 3;
						break;

					case QUEEN:
						aggro_points -= PIECE_POINTS_MULTIPLIER * 9;
						break;

					default:
						break;
				}
			}
		}
	}

	AGGRESSION_MULTIPLIER += (aggro_points / 2);

	if (AGGRESSION_MULTIPLIER == 0){
		AGGRESSION_MULTIPLIER = 1;
	}

	MENTRY *mEntry = mList->First;

	for (int i = 0; i < mList->Length; i++){
		MOVE *move = mEntry->Move;

		int distFromKingR = abs(move->r2 - rK);
		int distFromKingF = abs(move->f2 - fK);

		int temp_points = (-(distFromKingR + distFromKingF) / KING_DISTANCE_MULTIPLIER) * AGGRESSION_MULTIPLIER;
		
		if (distFromKingR <= 1 && distFromKingF <= 1){
			temp_points -= 100;
		}

		if (game->board[move->r2][move->f2] != NULL){
			ChessPiece *piece = game->board[move->r2][move->f2];

			switch (piece->p_type){
				case PAWN:
					temp_points += PIECE_POINTS_MULTIPLIER * 1;
					break;

				case ROOK:
					temp_points += PIECE_POINTS_MULTIPLIER * 5;
					break;

				case KNIGHT:
					temp_points += PIECE_POINTS_MULTIPLIER * 3;
					break;

				case BISHOP:
					temp_points += PIECE_POINTS_MULTIPLIER * 3;
					break;

				case QUEEN:
					temp_points += PIECE_POINTS_MULTIPLIER * 9;
					break;

				default:
					break;
			}
		}



		if (game->board[move->r1][move->f1] != NULL){
			// ChessPiece *piece = game->board[move->r1][move->f1];

		}

		mEntry->points = temp_points;

		// printf("Points: %d\n", mEntry->points);
		mEntry = mEntry->Next;
	}

	mList = CullMoves(game, mList);

	return mList;
}


MLIST *CullMoves(Game *game, MLIST* mList){
	MLIST *mListClone = CloneMoveList(mList);

	int length = mList->Length;

	MENTRY *mEntry = mList->First;

	int total = 0;

	for (int i = 0; i < length; i++){
		total += mEntry->points;

		mEntry = mEntry->Next;
	}

	int average = total / mList->Length;

	mEntry = mList->First;

	for (int i = 0; i < length; i++){
		if (mEntry->points < average){
			AppendMoveEntry(mListClone, CloneMove(mEntry->Move));
			mListClone->Last->points = mEntry->points;
		}
		mEntry = mEntry->Next;
	}

	DeleteMoveList(mList);

	return mListClone;
}


MLIST *RankMovesFuture(Game *game, MLIST *mList, int depth){


	MENTRY *entry = mList->First;

	for (int i = 0; i < mList->Length; i++){
		// printf("%c%d to %c%d\n", 'a' + entry->Move->r1, 1 + entry->Move->f1, 'a' + entry->Move->r2, 1 + entry->Move->f2);

		Game *clone = CloneGame(game);
		clone->PLAYERW = COMPUTER;
		clone->PLAYERB = COMPUTER;

		if (!isLegalMove(clone, entry->Move)){
			DeleteGame(clone);
			entry->points -= 10000;
			entry = entry->Next;
			continue;
		}


		Move(clone, entry->Move);
		checkPromotions(clone);
		clone->whoTurn = (clone->whoTurn + 1) % 2;
		if (isCheckmate(clone)){
			DeleteGame(clone);
			entry->points += 10000;
			entry = entry->Next;

			continue;
		}
		MLIST *futureMoves = RankMoves(clone, GetAllLegalMoves(clone));


		MENTRY *entryFuture = futureMoves->First;

		int total = 0;

		for (int j = 0; j < futureMoves->Length; j++){
			total += entryFuture->points;
			entryFuture = entryFuture->Next;
		}

		entry->points -= 20 * (total / (futureMoves->Length == 0 ? 1 : futureMoves->Length));

		if (depth > 0){
			futureMoves = RankMovesFuture(clone, futureMoves, depth - 1);
		}

		entry = entry->Next;

		DeleteMoveList(futureMoves);

		DeleteGame(clone);
	}

	return mList;
}



MOVE *GetBestMove(Game *game, MLIST *mList){
	if (mList->Length == 0){
		return NULL;
	}

	MENTRY *bestMove = mList->First;
	MENTRY *mEntry = mList->First;

	for (int i = 0; i < mList->Length; i++){
		if (mEntry->points > bestMove->points){
			bestMove = mEntry;
		}


		mEntry = mEntry->Next;
	}


	MOVE *temp_move = CreateMove(bestMove->Move->r1, bestMove->Move->f1, bestMove->Move->r2, bestMove->Move->f2);

	DeleteMoveList(mList);

	return temp_move;	
}
