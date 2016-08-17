#pragma once
#ifndef _BLOCKS_H_
#define _BLOCKS_H_

#include <graphics.h>

#define windowidth  700
#define widowheight 600

#define blocksNumber 7
#define blocksHeight 5
#define blocksLength 5
#define panelHeight 21	
#define panelWidth 17
#define width 20

typedef struct {
	int nextBlockShape[blocksNumber][blocksHeight][blocksLength] = {
		{
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 },
			{ 0,2,2,2,2 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
		},
		{
			{ 0,0,0,0,0 },
			{ 0,0,3,0,0 },
			{ 0,3,3,3,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
		},

		{
			{ 0,0,0,0,0 },
			{ 0,0,4,4,0 },
			{ 0,4,4,0,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
		},

		{
			{ 0,0,0,0,0 },
			{ 0,5,5,0,0 },
			{ 0,0,5,0,0 },
			{ 0,0,5,0,0 },
			{ 0,0,0,0,0 }
		},

		{
			{ 0,0,0,0,0 },
			{ 0,0,6,6,0 },
			{ 0,0,6,0,0 },
			{ 0,0,6,0,0 },
			{ 0,0,0,0,0 }
		},

		{
			{ 0,0,0,0,0 },
			{ 0,0,7,7,0 },
			{ 0,0,7,7,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
		},

		{
			{ 0,0,0,0,0 },
			{ 0,8,8,0,0 },
			{ 0,0,8,8,0 },
			{ 0,0,0,0,0 },
			{ 0,0,0,0,0 }
		},
	};

}NextBlocks;


/**
* [showBox 主要功能：展示方块矩阵，测试用]
* @param p [传进去的三维方块矩阵]
*/
void showBox(int p[blocksNumber][blocksHeight][blocksLength]);

/**
* [rotateBox 主要功能：将方块旋转90度]
* @param box [将要旋转的方块]
*/
void rotateBox(int(*box1)[blocksLength]);
void swap(int* a, int* b);

/**
* [crashTesting 主要功能：碰撞监测：
* 包括碰到边界，下降时碰到其他方块]
* @param map 游戏界面地图
* @param box 正在下落的方块
* @param x 正在下落的方块相对大地图的横坐标
* @param y 正在下落的方块相对大地图的纵坐标
* @return 1 如果没有碰撞到，否则返回0
*/
int crashTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);

/**
* [putBox 主要功能：将方块印到map的对应位置]
* @param map 游戏界面地图
* @param box 正在下落的方块
*/
void putBox(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);

/**
* [showMap 主要功能：展示map，测试用]
* @param map [游戏面板，大地图]
*/
void  showMap(int(*map)[panelWidth]);
bool judgeFullRow(int(*map)[panelWidth]);

/**
* [resetMap 主要功能：重置地图]
* @param map 游戏界面地图
*/
void resetMap(int(*map)[panelWidth]);

int lefttouchTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);
int righttouchTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);
int downtouchTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);
void setdifficulty(int(*map)[panelWidth], int difficuty);

#endif