#pragma once
#ifndef _DRAW_H
#define _DRAW_H

#include "blocks.h"
#include "userinfo.h"

int draw();

/**
* [getImage ��Ҫ���ܣ�����ͼƬ�ز�]
* @param image ����ͼƬ�ز�
*/
void getImage(PIMAGE image[blocksNumber + 1]);

//��15*20�ĺ��ӻ���ͼ��
void drawMap(int(*map)[panelWidth], PIMAGE image[blocksNumber + 1]);

void drawLoginPanel();

void gameover();

#endif
