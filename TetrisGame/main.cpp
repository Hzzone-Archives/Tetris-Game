#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <Windows.h>
#include "blocks.h"	
#include "draw.h"
#include "userinfo.h"

int main() {
	char ch;
	MUSIC mus;
	setinitmode(INIT_ANIMATION);
	initgraph(windowidth, widowheight);
	do {
		drawLoginPanel();
		Sleep(200);
		gameover();
		mus.OpenFile("music\\2.mp3");
		mus.Play();
		ch = getch();
		mus.Close();
	} while (ch == 'Y' || ch == 'y');
	closegraph();
	return 0;
}





