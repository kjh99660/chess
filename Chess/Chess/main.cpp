#include "fundamental.h"
#include "applied.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

int main()
{
	WoolID white = createWool(COLOR_WHITE);
	WoolID black = createWool(COLOR_BLACK);
	
	//chessboard
	drawChessBoard(white, 0, 4, 0);
	//white_1line
	drawLook(white, 8, 19, 8);
	drawBishop(white, 8, 19, 21);
	drawKnight(white, 8, 19, 34);
	drawKing(white, 8, 19, 47);
	drawQueen(white, 8, 19, 60);
	drawKnight(white, 8, 19, 73);
	drawBishop(white, 8, 19, 86);
	drawLook(white, 8, 19, 99);
	//white_2line
	for (int i = 0; i < 8; i++) {
		drawPawn(white, 21, 19, 8+13*i);
	}
	//black_1line
	drawLook(black, 99, 19, 8);
	drawBishop(black, 99, 19, 21);
	drawKnight(black, 99, 19, 34);
	drawKing(black, 99, 19, 47);
	drawQueen(black, 99, 19, 60);
	drawKnight(black, 99, 19, 73);
	drawBishop(black, 99, 19, 86);
	drawLook(black, 99, 19, 99);
	//balck_2line
	for (int i = 0; i < 8; i++) {
		drawPawn(black, 86, 19, 8 + 13 * i);
	}
	return 0;
}
