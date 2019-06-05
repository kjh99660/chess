#include "fundamental.h"
#include "applied.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

void makeKing(BlockID block, int midx, int y, int midz)
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

void makePawn(BlockID block, int midx, int y, int midz)
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

int main()
{

}