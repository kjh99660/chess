#include "applied.h"
#include "fundamental.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

void chess_bottom(BlockID block, int x, int y, int z) {
	drawCircleLine(block, x, y, z, 6);
	drawCircleLine(block, x, y + 1, z, 6);
	drawCircle(block, x, y + 2, z, 5);
	drawCircleLine(block, x, y + 3, z, 4);
	drawCircleLine(block, x, y + 4, z, 4);
	drawCircleLine(block, x, y + 5, z, 4);
	drawCircleLine(block, x, y + 6, z, 4);
	drawCircleLine(block, x, y + 7, z, 4);
	drawCircleLine(block, x, y + 8, z, 4);
	drawCircleLine(block, x, y + 9, z, 3);
	drawCircleLine(block, x, y + 10, z, 3);
	drawCircleLine(block, x, y + 11, z, 3);
	drawCircleLine(block, x, y + 12, z, 3);

}

void drawQueen(BlockID block, int x, int y, int z) {
	chess_bottom(block, x, y, z);
	drawCircleLine(block, x, y + 13, z, 3);
	drawCircle(block, x, y + 14, z, 4);
	drawCircleLine(block, x, y + 15, z, 5);
	drawCircle(block, x, y + 16, z, 5);
	drawCircle(block, x, y + 17, z, 6);
	drawCircleLine(block, x, y + 18, z, 5);
	drawCircle(block, x, y + 19, z, 4);
	drawCircle(block, x, y + 20, z, 3);
	drawCircleLine(block, x, y + 21, z, 3);
	drawCircle(block, x, y + 22, z, 3);
	//Æ¼¾Æ¶ó
	locateBlock(block, x + 3, y + 23, z);
	locateBlock(block, x, y + 23, z + 3);
	locateBlock(block, x, y + 23, z - 3);
	locateBlock(block, x - 3, y + 23, z);
	locateBlock(block, x + 2, y + 23, z + 2);
	locateBlock(block, x + 2, y + 23, z - 2);
	locateBlock(block, x + 2, y + 23, z + 2);
	locateBlock(block, x - 2, y + 23, z + 2);
	locateBlock(block, x - 2, y + 23, z - 2);
	locateBlock(block, x + 2, y + 24, z - 2);
	locateBlock(block, x + 2, y + 24, z + 2);
	locateBlock(block, x - 2, y + 24, z + 2);
	locateBlock(block, x - 2, y + 24, z - 2);


}

void drawBishop(BlockID block, int x, int y, int z) {
	chess_bottom(block, x, y, z);
	drawCircleLine(block, x, y + 13, z, 4);
	drawCircle(block, x, y + 14, z, 5);
	drawCircle(block, x, y + 15, z, 4);
	drawCircle(block, x, y + 16, z, 4);
	drawCircle(block, x, y + 17, z, 3);
	drawCircle(block, x, y + 18, z, 2);
	drawCircle(block, x, y + 19, z, 1);
	locateBlock(block, x, y + 20, z);
}

void drawLook(BlockID block, int x, int y, int z)
{
	for (int dy = 0; dy < 2; dy++)
		drawCircle(block, x, y + dy, z, 6);
	drawCircle(block, x, y + 2, z, 5);
	for (int dy = 3; dy < 10; dy++)
		drawCircle(block, x, y + dy, z, 4);
	for (int dy = 10; dy < 18; dy++)
		drawCircle(block, x, y + dy, z, 3);
	drawCircle(block, x, y + 18, z, 4);
	for (int dy = 19; dy < 23; dy++)
	drawCircleLine(block, x, y + dy, z, 5);

	BlockID air = createBlock(BLOCK_AIR);
	drawCube(air, x - 5, y + 21, z - 1, 1, 3, 2);
	drawCube(air, x + 5, y + 21, z - 1, 1, 3, 2);
	drawCube(air, x - 1, y + 21, z + 5, 3, 1, 2);
	drawCube(air, x - 1, y + 21, z - 5, 3, 1, 2);
}
void drawKing(BlockID block, int midx, int y, int midz)
{
	int h = 0, r = 5;
	drawCircle(block, midx, y + h, midz, r);
	h++;
	for (int i = 0; i < 3; i++, h++, r--)
		drawCircle(block, midx, y + h, midz, r);
	for (int i = 0, t = r; i < 4; i++, h++) {
		r = t - i / 2;
		drawCircle(block, midx, y + h, midz, r);
	}

	r--;
	for (int i = 0; i < 3; i++, h++)
		drawCircle(block, midx, y + h, midz, r);

	r = 3;
	for (int i = 0; i < 3; i++, h++, r--)
		drawCircle(block, midx, y + h, midz, r);
	for (int i = 0; i < 3; i++, h++, r++) {
		drawCircle(block, midx, y + h, midz, r);
	}
	for (int i = 0; i < 3; i++, h++, r--)
		drawCircle(block, midx, y + h, midz, r);

	locateBlock(block, midx, y + h, midz);
	h++;
	for (int i = -1; i < 2; i++)
		locateBlock(block, midx + i, y + h, midz);
	h++;
	locateBlock(block, midx, y + h, midz);
}
void drawPawn(BlockID block, int midx, int y, int midz)
{
	int h = 0, r = 4;
	drawCircle(block, midx, y + h, midz, r);
	h++;
	for (int i = 0; i < 3; i++, h++, r--)
		drawCircle(block, midx, y + h, midz, r);
	for (int i = 0, t = r; i < 4; i++, h++) {
		r = t - i / 2;
		drawCircle(block, midx, y + h, midz, r);
	}

	r = 2;
	drawCircle(block, midx, y + h, midz, r);

	r = 3;
	h = h + 3;
	drawSphere(block, midx, y + h, midz, r);
}
void drawChessBoard(BlockID block, int x, int y, int z)
{
	drawCube(block, x, y, z, 10, 10, 3);
	drawCube(block, x + 94, y, z, 10, 10, 3);
	drawCube(block, x, y, z + 114, 10, 10, 3);
	drawCube(block, x + 114, y, z + 114, 10, 10, 3);
	drawCube(block, x, y + 3, z, 124, 124, 11);
	drawPlaneLine(block, x, y + 14, z, 124, 124, 10);


	WoolID white = createWool(COLOR_WHITE);
	WoolID black = createWool(COLOR_BLACK);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			drawPlane(white, x + 2 + 26 * i, y + 14, z + 2 + 26 * j, 13, 13);
			drawPlane(black, x + 15 + 26 * i, y + 14, z + 2 + 26 * j, 13, 13);
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			drawPlane(black, x + 2 + 26 * i, y + 14, z + 15 + 26 * j, 13, 13);
			drawPlane(white, x + 15 + 26 * i, y + 14, z + 15 + 26 * j, 13, 13);
		}
	}


}
void drawKnight(BlockID block, int x, int y, int z)
{
	for (int dy = 0; dy < 2; dy++)
		drawCircle(block, x, y + dy, z, 6);
	drawCircle(block, x, y + 2, z, 5);
	drawCube(block, x - 3, y + 3, z - 3, 8, 7, 3);
	drawCube(block, x - 1, y + 6, z - 3, 6, 7, 3);
	drawCube(block, x + 1, y + 9, z - 3, 4, 7, 2);
	drawCube(block, x - 3, y + 11, z - 3, 8, 7, 6);
	drawCube(block, x - 6, y + 12, z - 2, 3, 5, 1);
	drawCube(block, x - 6, y + 14, z - 2, 3, 5, 2);
	drawCube(block, x - 1, y + 17, z - 3, 2, 1, 4);
	drawCube(block, x - 1, y + 17, z + 3, 2, 1, 4);

	for (int i = 0; i < 3; i++)
	{
		drawCube(block, x - 2 + 3 * i, y + 17, z - 1, 1, 3, 2);
		drawCube(block, x - 3 + 3 * i, y + 19, z - 3, 1, 3, 1);
	}

	WoolID black = createWool(COLOR_BLACK);
	drawCube(black, x - 1, y + 17, z - 4, 2, 1, 2);
	drawCube(black, x - 1, y + 17, z + 4, 2, 1, 2);

}