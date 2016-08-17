#pragma once
#ifndef _DRAW_H
#define _DRAW_H

#include "blocks.h"
#include "userinfo.h"

int draw();

/**
* [getImage 主要功能：加载图片素材]
* @param image 方块图片素材
*/
void getImage(PIMAGE image[blocksNumber + 1]);

//将15*20的盒子画出图形
void drawMap(int(*map)[panelWidth], PIMAGE image[blocksNumber + 1]);

void drawLoginPanel();

void gameover();

#endif
