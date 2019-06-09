#pragma once

#include <CoalaMOD.h>

void drawX(BlockID block, int x, int y, int z, int len);
void drawY(BlockID block, int x, int y, int z, int len);
void drawZ(BlockID block, int x, int y, int z, int len);
void drawPlane(BlockID block, int x, int y, int z, int width, int height);
void drawPlaneLine(BlockID block, int x, int y, int z, int width, int height);
void drawPlaneLine(BlockID block, int x, int y, int z, int width, int height, int thickness);
void drawCube(BlockID block, int x, int y, int z, int hor, int ver, int height);
void drawCircle(BlockID block, int x, int y, int z, int r);
void drawCircleLine(BlockID block, int x, int y, int z, int r);
void drawSphere(BlockID block, int x, int y, int z, int r);