#include <graphics.h>
#include<stdio.h>
#include"blocks.h"
#include <time.h>	
#include "draw.h"
#include "userinfo.h"

int draw() {
	// 动画控制变量，控制横坐标，初始值为0
	PIMAGE image1 = newimage();
	int y = 0;
	int x = 200;
	int boxx = 10;
	int boxy = 0;
	int presentRandNumber = 0;  //当前方块
	int nextRandNumber = 0; //下一方块
	int t = 0, j, k;
	char ch;
	int scores = 0;
	int passnumber = 1;  //关卡
	NextBlocks nextblocks;
	PIMAGE image[blocksNumber + 1]; //方块图片素材
									//setcolor(WHITE);
									//setfillcolor(WHITE);
									//	setlinestyle(CENTER_LINE, 0.5);
	setbkcolor(RGB(240, 255, 255));
	MUSIC bkmusic;
	MUSIC boom;
	bkmusic.OpenFile("music\\2.mp3");
	boom.OpenFile("music\\boom.mp3");
	bkmusic.Play();
	int map[panelHeight][panelWidth] = {
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	//产生0-6的随机数
	//随机数2是下一个图形的形状
	getImage(image); //加载图片素材
	randomize();
	presentRandNumber = random(6);
	nextRandNumber = random(6);
	setdifficulty(map, 0);
	//开始不断循环 重画
	for (; is_run(); delay_fps(300))
	{
		//背景音乐循环播放
		if (bkmusic.GetPlayStatus() == MUSIC_MODE_STOP) {
			bkmusic.Play(0);
		}
		// todo: 逻辑更新
		cleardevice();
		//调节速度
		t++;
		if (t > 90000) {
			t = 1;
		}
		if (t % (150 - 10 * passnumber) == 0) {
			boxy++;
		}
		//分界线
		line(panelWidth*width + width, 0, panelWidth*width + width, panelHeight*width);

		//方块底部接触判定，如果接触 把5*5小盒子非零的部分印到大盒子中
		if (crashTesting(map, nextblocks.nextBlockShape[presentRandNumber], boxx, boxy) == 0) {
			putBox(map, nextblocks.nextBlockShape[presentRandNumber], boxx, boxy - 1);
			boxx = 10;
			boxy = 0;
			presentRandNumber = nextRandNumber;
			nextRandNumber = random(6);//产生随机数2 是下一个图形的形状
		}
		//画大图形
		drawMap(map, image);
		//满行操作
		if (judgeFullRow(map) == 1) {
			scores += 10 * passnumber;
			//特效音乐
			passnumber = (scores / 50) + 1;
			if (boom.GetPlayStatus() == MUSIC_MODE_STOP) {
				boom.Play(0);
			}
		}

		//分数框
		setcolor(BLACK);
		setfont(30, 0, "宋体");
		xyprintf(400, 50, "scores:%d", scores);

		//下一图形
		xyprintf(400, 200, "next block:");
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				if (nextblocks.nextBlockShape[nextRandNumber][j][k] != 0) {
					putimage(400 + k * width, 250 + j * width, image[nextRandNumber]);
				}
			}
		}
		//负判定
		if (crashTesting(map, nextblocks.nextBlockShape[presentRandNumber], boxx, boxy) == 0) {
			j = downtouchTesting(map, nextblocks.nextBlockShape[presentRandNumber], boxx, boxy);
			putBox(map, nextblocks.nextBlockShape[presentRandNumber], boxx, boxy - j);
			drawMap(map, image);
			bkmusic.Close();
			Sleep(100);
			return scores;
		}
		//绘图，将正在移动的方块绘制到图形中
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				if (nextblocks.nextBlockShape[presentRandNumber][j][k] != 0) {
					putimage((boxx + k) * width, (boxy + j) * width, image[presentRandNumber]);
				}
			}
		}
		//键盘监测   
		if (kbhit()) {
			ch = getch();
			switch (ch) {
			case key_left:
				if (lefttouchTesting(map, nextblocks.nextBlockShape[presentRandNumber], boxx, boxy) == 1) {
					boxx--;
				}
				break;
			case key_right:
				if (righttouchTesting(map, nextblocks.nextBlockShape[presentRandNumber], boxx, boxy) == 1) {
					boxx++;
				}
				break;
			case key_down:
				boxy++;
				break;
			case key_up:
				rotateBox(nextblocks.nextBlockShape[presentRandNumber]);				//先让它反转，看翻转后状态，如果有重合，则调用反转函数三次使他恢复原来状态
				if (crashTesting(map, nextblocks.nextBlockShape[presentRandNumber], boxx, boxy) == 0) {
					rotateBox(nextblocks.nextBlockShape[presentRandNumber]);
					rotateBox(nextblocks.nextBlockShape[presentRandNumber]);
					rotateBox(nextblocks.nextBlockShape[presentRandNumber]);
				}
				break;
			case key_space:
				while (true) {
					if (kbhit()) {
						ch = getch();
						if (ch == key_space) {
							break;
						}
					}
				}
				break;
				//关闭背景音乐
			case key_esc:
				if (bkmusic.GetPlayStatus() == MUSIC_MODE_PLAY) {
					bkmusic.Pause();
				}
				else {
					bkmusic.Play();
				}
				break;
			}
		}
	}
	return scores;
}



void getImage(PIMAGE image[blocksNumber + 1]) {
	image[0] = newimage();
	image[1] = newimage();
	image[2] = newimage();
	image[3] = newimage();
	image[4] = newimage();
	image[5] = newimage();
	image[6] = newimage();
	image[7] = newimage();
	getimage(image[0], "images\\1.jpg");
	getimage(image[1], "images\\2.jpg");
	getimage(image[2], "images\\3.jpg");
	getimage(image[3], "images\\4.jpg");
	getimage(image[4], "images\\5.jpg");
	getimage(image[5], "images\\6.jpg");
	getimage(image[6], "images\\7.jpg");
	getimage(image[7], "images\\8.jpg");

}

//将15*20的盒子画出图形
void drawMap(int(*map)[panelWidth], PIMAGE image[blocksNumber + 1]) {
	int i, j;
	setcolor(RGB(144, 238, 144));
	for (i = 0; i < panelHeight; i++) {
		line(0, i*width, panelWidth*width, i*width);
	}
	for (j = 0; j < panelWidth; j++) {
		line(j*width, 0, j*width, panelHeight*width);
	}
	for (i = 0; i < panelHeight; i++)
		for (j = 0; j < panelWidth; j++) {
			if (map[i][j] != 0) {
				if (map[i][j] == 1)
					putimage(j * width, i * width, image[7]);
				else
					putimage(j * width, i * width, image[map[i][j] - 2]);
			}

		}
}


//用户键入1，登入游戏，如果有该用户，则直接登入，否则创建新用户
void fun1(user* head) {
	cleardevice();
	char str[MAX_NAME_SIZE];
	inputbox_getline("登入", "请输入不超过不超过20个字符的用户名", str, MAX_NAME_SIZE);
	user* u = addUser(head, str);
	int newScore = draw();
	if (newScore > u->score) {
		u->score = newScore;
	}
	writeUserInfo(fileName, head);
	//getch();
}

//查看历史前十名
void fun2(user* head) {
	user* p = head;
	int y = 260;
	int i = 0;
	setcaption("登陆");
	cleardevice();
	/*outtextxy(100, 150, "这是世界上俄罗斯方块最牛逼的十个人（任意键返回）:");*/
	PIMAGE image1 = newimage();
	getimage(image1, "images\\background2.jpg");
	putimage(0, 0, image1);
	PIMAGE image2 = newimage();
	getimage(image2, "images\\background4.jpg");
	putimage(180, 250, image2);
	setcolor(BLACK);
	while (p != NULL) {
		xyprintf(250, y, "%2d.%20s %15d", i + 1, p->name, p->score);
		y += 30;
		i++;
		p = p->next;
	}
	getch();

}

//展示所有用户
void fun3(user* head) {
	user* p = head;
	int x = 160;
	int y = 200;
	int i = 1;
	setcaption("用户");
	cleardevice();
	outtextxy(100, 150, "这是所有用户（任意键返回）:");
	setcolor(BLACK);
	while (p != NULL) {
		xyprintf(x, y, "%d.%s", i+1, p->name);
		if (0 == i % 10) {
			x += 100;
			y = 160;
		}
		y += 40;
		p = p->next;
		i++;
	}
	getch();
}
void fun4() {
	setcaption("游戏规则");
	cleardevice();
	PIMAGE image = newimage();
	getimage(image, "images\\background3.jpg");
	putimage(0, 0, image);
	getch();
}

void drawLoginPanel() {
	char ch;
	PIMAGE image = newimage();
	getimage(image, "images\\background1.jpg");
	user* head = readUserInfo(fileName);
	setbkcolor(RGB(240, 255, 255));
	setfillcolor(BLACK);
	do {
		setcaption("菜单");
		cleardevice();
		putimage(0, 0, image);
		ch = getch();
		if (ch == '1') {
			fun1(head);
			break;
		}
		else if (ch == '2') {
			fun2(scoreSort(head));
		}
		else if (ch == '3') {
			fun3(head);
		}
		else if (ch == '4') {
			fun4();
		}
		else if (ch == key_esc) {
			exit(1);
		}
	} while (1);

}

void gameover() {
	cleardevice();
	PIMAGE image1 = newimage();
	getimage(image1, "images\\gameover.jpg");
	putimage(0, 0, image1);
}



