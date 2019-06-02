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