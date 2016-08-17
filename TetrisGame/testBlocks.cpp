#include <stdio.h>
#include <stdlib.h>
#include "blocks.h"

//test crashTesting
/*int main(){
NextBlocks nextBlock;
int map[panelHeight][panelWidth];
int i,j;
int box1[blocksHeight][blocksLength] = {
{0,0,0,0,0},
{1,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0}
};
int box2[blocksHeight][blocksLength] = {
{1,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0}
};
for(i=0;i<panelHeight;i++)
for(j=0;j<panelWidth;j++){
map[i][j] = 0;
}
showMap(map);
printf("----------\n");
putBox(map, nextBlock.nextBlockShape[0], 0, 0);
showMap(map);
printf("----------\n");
printf("\n");
printf("box1: %d\n", crashTesting(map, box1, 0, 0));
printf("----------\n");
printf("\n");
printf("box2: %d\n", crashTesting(map, box2, 0, 0));
}*/

//test putBox
/*int main(){
nextBlocks nextBlock;
int map[panelHeight][panelWidth];
int i,j;
for(i=0;i<panelHeight;i++)
for(j=0;j<panelWidth;j++){
map[i][j] = 0;
}
putBox(map, nextBlock.nextBlockShape[0], 0, 0);
showBox(nextBlock.nextBlockShape);
printf("----------\n");
showMap(map);
return 0;
}*/

//test rotateBox
/*int main(){
nextBlocks nextBlock;
showBox(nextBlock.nextBlockShape);
printf("----------\n");
rotateBox(nextBlock.nextBlockShape[0]);
showBox(nextBlock.nextBlockShape);
printf("----------\n");
rotateBox(nextBlock.nextBlockShape[0]);
showBox(nextBlock.nextBlockShape);
printf("----------\n");
rotateBox(nextBlock.nextBlockShape[0]);
showBox(nextBlock.nextBlockShape);`
}*/

//test judgeFullRow
/*int main() {
	int map[panelHeight][panelWidth] = {
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};
	judgeFullRow(map);
	showMap(map);
	getchar();
	return 0;
}*/

