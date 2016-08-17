#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include "blocks.h"

void rotateBox(int(*box)[blocksLength]) {
	int i, j;
	for (i = 0; i<blocksHeight; i++)
		for (j = i + 1; j<blocksHeight; j++)
			swap(&box[i][j], &box[j][i]);
	for (i = 0; i<blocksHeight / 2; i++)
		for (j = 0; j<blocksHeight; j++)
			swap(&box[i][j], &box[blocksHeight - 1 - i][j]);
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}


int crashTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y) {
	int i, j;
	for (j = 0; j<blocksHeight; j++)
		for (i = 0; i<blocksLength; i++) {
			if (box[j][i] != 0) {
				if (map[y + j][x + i] != 0)
					return 0;
			}
		}
	return 1;
}

int lefttouchTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y) {
	int i, j;
	for (j = 0; j<blocksHeight; j++)
		for (i = 0; i<blocksLength; i++) {
			if (box[j][i] != 0) {
				if (map[y + j][x + i - 1] != 0)
					return 0;
			}
		}
	return 1;
}

int righttouchTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y) {
	int i, j;
	for (j = 0; j<blocksHeight; j++)
		for (i = 0; i<blocksLength; i++) {
			if (box[j][i] != 0) {
				if (map[y + j][x + i + 1] != 0)
					return 0;
			}
		}
	return 1;
}

int downtouchTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y) {
	int i, j;
	for (j = 0; j<blocksHeight; j++)
		for (i = 0; i<blocksLength; i++) {
			if (box[j][i] != 0) {
				if (map[y + j][x + i] != 0)
					return i;
			}
		}
	return 0;
}

void putBox(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y) {
	int i, j;

	for (j = 0; j<blocksHeight; j++)
		for (i = 0; i<blocksLength; i++) {
			if (box[j][i] != 0) {
				map[y + j][x + i] = box[j][i];
			}
		}
}


bool judgeFullRow(int(*map)[panelWidth])
{
	int i = 0, j = 0, k = 0;
	for (i = panelHeight - 2; i > 0; i--) {
		while (map[i][j] != 0) {
			j++;
			if (j == panelWidth - 1) {
				break;
			}												//从下至上扫描  
		}													//满行判定
		if (j == panelWidth - 1) {							//如果满行	
			for (k = i; k > 0; k--) {						//从下至上，下移一格；
				for (j = 1; j < panelWidth - 1; j++)
				{
					map[k][j] = map[k - 1][j];
				}
			}
			return true;
		}
		j = 0;
	}
	return false;
}
//设置难度
void setdifficulty(int(*map)[panelWidth],int difficuty)
{
	int nuber = 0,i = 2 * difficuty;
	int j, k, randnumber1, randnumber2;
	srand((unsigned)time(NULL));
	randnumber1 = rand() % 5 + 15;
	randnumber2 = rand() % (panelWidth-2)+1;
	for (j = 0; j < i; j++) {
		map[randnumber1][randnumber2] = 1;
		randnumber1 = rand() % 3 + 17;
		randnumber2 = rand() % (panelWidth - 2) + 1;
	}
}




