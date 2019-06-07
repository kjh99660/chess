#pragma once

#include <CoalaMOD.h>

void chess_bottom(BlockID block, int x, int y, int z);
void drawQueen(BlockID block, int x, int y, int z);
void drawBishop(BlockID block, int x, int y, int z);
void drawLook(BlockID block, int x, int y, int z);
void drawKing(BlockID block, int midx, int y, int midz);
void drawPawn(BlockID block, int midx, int y, int midz);
void drawChessBoard(BlockID block, int x, int y, int z);
void drawKnight(BlockID block, int x, int y, int z);