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
* [showBox ��Ҫ���ܣ�չʾ������󣬲�����]
* @param p [����ȥ����ά�������]
*/
void showBox(int p[blocksNumber][blocksHeight][blocksLength]);

/**
* [rotateBox ��Ҫ���ܣ���������ת90��]
* @param box [��Ҫ��ת�ķ���]
*/
void rotateBox(int(*box1)[blocksLength]);
void swap(int* a, int* b);

/**
* [crashTesting ��Ҫ���ܣ���ײ��⣺
* ���������߽磬�½�ʱ������������]
* @param map ��Ϸ�����ͼ
* @param box ��������ķ���
* @param x ��������ķ�����Դ��ͼ�ĺ�����
* @param y ��������ķ�����Դ��ͼ��������
* @return 1 ���û����ײ�������򷵻�0
*/
int crashTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);

/**
* [putBox ��Ҫ���ܣ�������ӡ��map�Ķ�Ӧλ��]
* @param map ��Ϸ�����ͼ
* @param box ��������ķ���
*/
void putBox(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);

/**
* [showMap ��Ҫ���ܣ�չʾmap��������]
* @param map [��Ϸ��壬���ͼ]
*/
void  showMap(int(*map)[panelWidth]);
bool judgeFullRow(int(*map)[panelWidth]);

/**
* [resetMap ��Ҫ���ܣ����õ�ͼ]
* @param map ��Ϸ�����ͼ
*/
void resetMap(int(*map)[panelWidth]);

int lefttouchTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);
int righttouchTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);
int downtouchTesting(int(*map)[panelWidth], int(*box)[blocksLength], int x, int y);
void setdifficulty(int(*map)[panelWidth], int difficuty);

#endif