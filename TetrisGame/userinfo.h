#pragma once
#ifndef _USERINFO_H
#define _USERINFO_H

#define MAX_NAME_SIZE 21  //最长用户名20字符 
#define LEN sizeof(user)
#define topRanking 10
#define fileName "table.txt"

struct node {
	char name[MAX_NAME_SIZE];
	int score;
	node* next;
};
typedef struct node user;

void writeUserInfo(char* filename, user* head);
user* readUserInfo(char* filename);
user* scoreSort(user* head);
user* addUser(user* head, char* str);

#endif