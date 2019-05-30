#include <math.h>
#include "fundamental.h"
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

void drawX(BlockID block, int x, int y, int z, int len)
{
	for (int i = 0; i < len; i++)
		locateBlock(block, x + i, y, z);
}

void drawY(BlockID block, int x, int y, int z, int len)
{
	for (int i = 0; i < len; i++)
		locateBlock(block, x, y + i, z);
}

void drawZ(BlockID block, int x, int y, int z, int len)
{
	for (int i = 0; i < len; i++)
		locateBlock(block, x, y, z + i);
}

void drawPlane(BlockID block, int x, int y, int z, int width, int height)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			locateBlock(block, x + i, y, z + j);
}

void drawPlaneLine(BlockID block, int x, int y, int z, int width, int height)
{
	for (int i = 0; i < width; i++) {
		locateBlock(block, x + i, y, z);
		locateBlock(block, x + i, y, z + height - 1);
	}

	for (int i = 0; i < height; i++) {
		locateBlock(block, x, y, z + i);
		locateBlock(block, x + width - 1, y, z + i);
	}
}

void drawPlaneLine(BlockID block, int x, int y, int z, int width, int height, int thickness)
{
	for (int j = 0; j < thickness; j++) {
		for (int i = j; i < width - j; i++) {
			locateBlock(block, x + i, y, z + j);
			locateBlock(block, x + i, y, z + height - 1 + j);
		}

		for (int i = j; i < height - j; i++) {
			locateBlock(block, x + j, y, z + i);
			locateBlock(block, x + width - 1 - j, y, z + i);
		}
	}
}

void drawCube(BlockID block, int x, int y, int z, int hor, int ver, int height)
{
	for (int i = 0; i < hor; i++)
		for (int j = 0; j < height; j++)
			for (int k = 0; k < ver; k++)
				locateBlock(block, x + i, y + j, z + k);
}

void drawCircle(BlockID block, int x, int y, int z, int r)
{
	for (int i = -r; i <= r; i++)
		for (int j = -r; j <= r; j++)
			if (i * i + j * j < (r + 0.5) * (r + 0.5))
				locateBlock(block, x + i, y, z + j);
}

void drawCircleLine(BlockID block, int x, int y, int z, int r)
{

	int i, j;

	locateBlock(block, x, y, z + r);
	locateBlock(block, x, y, z - r);
	locateBlock(block, x + r, y, z);
	locateBlock(block, x - r, y, z);

	j = r;
	i = 1;
	j = (int)(sqrt(r * r - 1) + 0.5);

	while (i < j) {
		locateBlock(block, x + i, y, z + j);
		locateBlock(block, x + i, y, z - j);
		locateBlock(block, x - i, y, z + j);
		locateBlock(block, x - i, y, z - j);
		locateBlock(block, x + j, y, z + i);
		locateBlock(block, x + j, y, z - i);
		locateBlock(block, x - j, y, z + i);
		locateBlock(block, x - j, y, z - i);
		i += 1;
		j = (int)(sqrt(r * r - i * i) + 0.5);
	}

	if (i == j) {
		locateBlock(block, x + i, y, z + j);
		locateBlock(block, x + i, y, z - j);
		locateBlock(block, x - i, y, z + j);
		locateBlock(block, x - i, y, z - j);
	}
}

void drawSphere(BlockID block, int x, int y, int z, int r)
{
	for (int i = -r; i <= r; i++) {
		for (int j = -r; j <= r; j++) {
			for (int k = -r; k <= r; k++) {
				if (i * i + j * j + k * k < (r + 0.5) * (r + 0.5))
					locateBlock(block, x + i, y + j, z + k);
			}
		}
	}
}

void drawLeg(BlockID block, int x, int y, int z, int theta)
{
	//º¸·ù
}