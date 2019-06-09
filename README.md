# Chess Simulator Project
## 월드 설명
### concept & explain
 체스 시뮬레이터에서 체스하는 장면을 만들었습니다. \
 전반적인 기물의 크기를 크게 제작함으로써 느낌을 살렸습니다.\
 말과 다른 사물들 모두 각각 하나의 함수로 구성되어있습니다.
 
 
 
## 기본 함수
### drawX
x축과 평행한 직선을 그리는 함수
```C
void drawX(BlockID block, int x, int y, int z, int len)
{
	for (int i = 0; i < len; i++)
		locateBlock(block, x + i, y, z);
}
```
### drawY
y축과 평행한 직선을 그리는 함수
```C
void drawY(BlockID block, int x, int y, int z, int len)
{
	for (int i = 0; i < len; i++)
		locateBlock(block, x, y + i, z);
}
```
### drawZ
z축과 평행한 직선을 그리는 함수
```C
void drawZ(BlockID block, int x, int y, int z, int len)
{
	for (int i = 0; i < len; i++)
		locateBlock(block, x, y, z + i);
}
```
### drawPlane
시작점, 가로와 세로의 길이를 입력하면 평면을 그리는 함수
```C
void drawPlane(BlockID block, int x, int y, int z, int width, int height)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			locateBlock(block, x + i, y, z + j);
}
```
### drawPlaneLine
시작점, 가로와 세로의 길이를 입력하면 속이 빈 평면을 그리는 함수
```C
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
```
### drawPlaneLine
시작점, 가로와 세로의 길이, 두께를 입력하면 속이 비고 두께가 존재하는 도형을 그리는 함수
```C
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
```
### drawCube
시작점과 가로, 세로, 높이를 입력하면 직육면체를 그리는 함수
```C
void drawCube(BlockID block, int x, int y, int z, int hor, int ver, int height)
{
	for (int i = 0; i < hor; i++)
		for (int j = 0; j < height; j++)
			for (int k = 0; k < ver; k++)
				locateBlock(block, x + i, y + j, z + k);
}
```
### drawCircle
원의 중심점과 반지름을 입력하면 속이 찬 원을 그리는 함수
```C
void drawCircle(BlockID block, int x, int y, int z, int r)
{
	for (int i = -r; i <= r; i++)
		for (int j = -r; j <= r; j++)
			if (i * i + j * j < (r + 0.5) * (r + 0.5))
				locateBlock(block, x + i, y, z + j);
}
```
### drawCircleLine
원의 중심점 반지름을 입력하면 속이 빈 원을 그리는 함수
```C
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
```
### drawSphere
원의 중심점과 반지름을 입력하면 구를 그리는 함수
```C
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
```
### drawLeg
보류
### chess_bottom
퀸과 비숍의 하단에 해당되는 부분을 생성하는 함수
```C
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
```
## 응용 함수
### drawQueen
말의 중심점을 입력하면 퀸을 생성하는 함수
```C
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
	//티아라
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
```
### drawBishop
말의 중심점을 입력하면 비숍을 생성하는 함수
```C
void Make_vishop(BlockID block, int x, int y, int z) {
	chess_bottom(block, x, y, z);
	drawCircleLine(block, x, y + 13, z, 4);
	drawCircle(block, x, y + 14, z, 5);
	drawCircle(block, x, y + 15, z, 4);
	drawCircle(block, x, y + 16, z, 4);
	drawCircle(block, x, y + 17, z, 3);
	drawCircle(block, x, y + 18, z, 2);
	drawCircle(block, x, y + 19, z, 1);
	locateBlock(block, x,y + 20, z );
}
```
### drawLook
말의 중심점을 입력하면 룩을 생성하는 함수
```C
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
```
### drawKing
말의 중심점을 입력하면 킹을 생성하는 함수
```C
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
```
### drawPawn
말의 중심점을 입력하면 폰을 생성하는 함수
```C
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
```
### drawChessBoard
시작점을 입력하면 체스보드를 생성하는 함수
```C
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
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			drawPlane(white, x + 2 + 26 * i, y + 14, z + 2 + 26 * j, 13, 13);
			drawPlane(black, x + 15 + 26 * i, y + 14, z + 2 + 26 * j, 13, 13);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			drawPlane(black, x + 2 + 26 * i, y + 14, z + 15 + 26 * j, 13, 13);
			drawPlane(white, x + 15 + 26 * i, y + 14, z + 15 + 26 * j, 13, 13);
		}
	}


}
```
### drawKnight
시작점을 입력하면 나이트를 생성하는 함수
```C
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
```
## 유튜브
