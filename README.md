#chess simulator project
---
##함수 설명
###drawX
```C
void drawX(BlockID block, int x, int y, int z, int len)
{
	for (int i = 0; i < len; i++)
		locateBlock(block, x + i, y, z);
}
```
x축과 평행한 직선을 그리는 함수
###drawY
```C
void drawY(BlockID block, int x, int y, int z, int len)
{
	for (int i = 0; i < len; i++)
		locateBlock(block, x, y + i, z);
}
```
y축과 평행한 직선을 그리는 함수
###drawZ
```C
void drawZ(BlockID block, int x, int y, int z, int len)
{
	for (int i = 0; i < len; i++)
		locateBlock(block, x, y, z + i);
}
```
z축과 평행한 직선을 그리는 함수
###drawPlane
```C
void drawPlane(BlockID block, int x, int y, int z, int width, int height)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			locateBlock(block, x + i, y, z + j);
}
```
시작점, 너비와 높이를 입력하면 평면을 만들어주는 함수
###drawPlaneLine
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
시작점, 너비와 높이를 입력하면 속이 빈 평면을 만들어주는 함수
###drawPlaneLine
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
블록,시작점,가로,세로와 두께를 입력하면 속이 비고 두께가 존재하는 도형을 만들어주는 함수
###drawCube
```C
void drawCube(BlockID block, int x, int y, int z, int hor, int ver, int height)
{
	for (int i = 0; i < hor; i++)
		for (int j = 0; j < height; j++)
			for (int k = 0; k < ver; k++)
				locateBlock(block, x + i, y + j, z + k);
}
```
시작점과 가로, 세로, 높이, 블록을 입력하면 직육면체를 생성해주는 함수
###drawCircle
```C
void drawCircle(BlockID block, int x, int y, int z, int r)
{
	for (int i = -r; i <= r; i++)
		for (int j = -r; j <= r; j++)
			if (i * i + j * j < (r + 0.5) * (r + 0.5))
				locateBlock(block, x + i, y, z + j);
}
```
블록, 원의 중심과 반지름을 입력하면 속이 찬 원을 생성하는 함수
###drawCircleLine
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
블록과 원의 중심과 반지름을 입력하면 속이 빈 원을 생성하는 함수
###drawSphere
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
블록,원의 중심과 반지름을 입력하면 구를 생성하는 함
###drawLeg
보류
###chess_bottom
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
퀸과 비숍의 하단에 해당되는 부분을 만드는 함수
###Make_queen
```C
void Make_queen(BlockID block,int x,int y,int z){
	chess_bottom(block, x, y, z);
	drawCircleLine(block, x, y + 13, z, 3);
	drawCircle(block, x, y + 14, z, 4);
	drawCircleLine(block, x, y + 15, z, 5);
	drawCircle(block, x, y + 16, z, 5);
	drawCircle(block, x, y + 17, z, 6);
	drawCircleLine(block, x, y + 18, z, 5);
	drawCircle(block, x, y + 18, z, 3);
	drawCircle(block, x, y + 19, z, 3);
	//티아라
	locateBlock(block, x+3, y + 20, z);
	locateBlock(block, x , y + 20, z+3);
	locateBlock(block, x , y + 20, z-3);
	locateBlock(block, x-3, y + 20, z);
	locateBlock(block, x+2, y + 20, z+2);
	locateBlock(block, x + 2, y + 20, z-2);
	locateBlock(block, x + 2, y + 20, z+2);
	locateBlock(block, x - 2, y + 20, z+2);
	locateBlock(block, x - 2, y + 20, z-2);
	locateBlock(block, x + 2, y + 21, z - 2);
	locateBlock(block, x + 2, y + 21, z + 2);
	locateBlock(block, x - 2, y + 21, z + 2);
	locateBlock(block, x - 2, y + 21, z - 2);


}
```
블록과 말의 중심을 입력하면 퀸을 생성해주는 함수
###Make_vishop
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
블록과 말의 중심을 입력하면 비숍을 생성해주는 함수