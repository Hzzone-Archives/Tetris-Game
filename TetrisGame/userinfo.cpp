#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userinfo.h"

void writeUserInfo(char* filename, user* head) {
	FILE* fp;
	user* p = head;
	//打开文件 
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("The file cannot be opened.\n");
		exit(1);
	}

	//把用户登录名,分数存到文件 
	if(head != NULL){
		do{
			fprintf(fp, "%s %d\n", p->name, p->score);
			p = p->next;
		}while(p!=NULL);
	}
	fclose(fp);
}

user* readUserInfo(char* filename) {
	FILE* fp;
	user* head = NULL;
	user* p1 = NULL;
	user* p2 = NULL;
	int n = 0;
	p1 = (user*)malloc(LEN);
	p2 = p1; //p2保存p1的位置 
	//打开文件 
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("The file cannot be opened.\n");
		exit(1);
	}
	//依次读取文件中用户名和分数 
	while (fscanf(fp, "%s%d", &p1->name, &p1->score) != EOF) {
		//printf("用户名：%s\n分数：%d\n", p1->name, p1->score);
		n++;
		if(n == 1){
			head = p1;
			p2->next = NULL; 
		}else{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (user*)malloc(LEN); //最后p1又分配了一块内存，所以需要free 
	}
	p2->next = NULL;
	free(p1);
	p1 = NULL; //防止p1成为野指针 
	fclose(fp);
	return head;
}


//前topRanking名分数排行，返回一个是个节点的链表 ,head为存储所有用户信息的链表 
user* scoreSort(user* head){
	user* p1;
	user* p2;
	char temp[MAX_NAME_SIZE];
	int t,n=1;
	for(p1 = head;p1!=NULL;p1=p1->next)
		for(p2 = p1->next;p2!=NULL;p2=p2->next){
			if(p1->score<p2->score){
				t = p1->score;
				p1->score = p2->score;
				p2->score = t;
				strcpy(temp, p1->name);
				strcpy(p1->name, p2->name);
				strcpy(p2->name, temp); 
			}
		}
	p1 = head;
	while(p1!=NULL){
		if(n==topRanking){
			p1->next = NULL;
			break;
		}
		p1 = p1->next;
		n++;
	} 
	return head;
	
}


user* addUser(user* head, char* str){
	user* p = head;
	user* x;
	while(p->next!=NULL){
		if(strcmp(str, p->name) == 0){
			return p;
		}
		p = p->next; 
	}
	if(strcmp(str, p->name) == 0){
			return p;
		}
	x = (user*)malloc(LEN);
	strcpy(x->name, str);
	x->score = 0;
	x->next = NULL;
	p->next = x;
	return x;
}



