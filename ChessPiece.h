#ifndef CHESSPIECE_H
#define CHESSPIECE_H

typedef enum {WHITE = 0, BLACK} Color;


typedef enum {PAWN = 0, KNIGHT, BISHOP, ROOK, QUEEN, KING} PieceType;


typedef struct{
	PieceType p_type;
	Color color;
} ChessPiece;


ChessPiece *CreatePiece(Color color, PieceType p_type);

void DeletePiece(ChessPiece *piece);

char *PrintPiece(ChessPiece *piece);

#endif
