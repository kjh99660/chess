#include "fundamental.h"
#include "applied.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

int main()
{
	BlockID white = createPlanks(PLANKS_BIRCH);
	BlockID black = createPlanks(PLANKS_DARK_OAK);

	//chessboard
	drawChessBoard(white, 0, 4, 0);
	//white_1line
	drawLook(white, 16, 19, 16);
	drawBishop(white, 16, 19, 29);
	drawKnight(white, 16, 19, 42);
	drawKing(white, 16, 19, 55);
	drawQueen(white, 16, 19, 68);
	drawKnight(white, 16, 19, 81);
	drawBishop(white, 16, 19, 94);
	drawLook(white, 16, 19, 107);
	//white_2line
	for (int i = 0; i < 8; i++) {
		drawPawn(white, 29, 19, 16+13*i);
	}
	//black_1line
	drawLook(black, 107, 19, 16);
	drawBishop(black, 107, 19, 29);
	drawKnight(black, 107, 19, 42);
	drawKing(black, 107, 19, 55);
	drawQueen(black, 107, 19, 68);
	drawKnight(black, 107, 19, 81);
	drawBishop(black, 107, 19, 94);
	drawLook(black, 107, 19, 107);
	//black_2line
	for (int i = 0; i < 8; i++) {
		drawPawn(black, 94, 19, 16 + 13 * i);
	}
	
	
}