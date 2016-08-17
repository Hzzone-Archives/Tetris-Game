#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userinfo.h"

void writeUserInfo(char* filename, user* head) {
	FILE* fp;
	user* p = head;
	//���ļ� 
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("The file cannot be opened.\n");
		exit(1);
	}

	//���û���¼��,�����浽�ļ� 
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
	p2 = p1; //p2����p1��λ�� 
	//���ļ� 
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("The file cannot be opened.\n");
		exit(1);
	}
	//���ζ�ȡ�ļ����û����ͷ��� 
	while (fscanf(fp, "%s%d", &p1->name, &p1->score) != EOF) {
		//printf("�û�����%s\n������%d\n", p1->name, p1->score);
		n++;
		if(n == 1){
			head = p1;
			p2->next = NULL; 
		}else{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (user*)malloc(LEN); //���p1�ַ�����һ���ڴ棬������Ҫfree 
	}
	p2->next = NULL;
	free(p1);
	p1 = NULL; //��ֹp1��ΪҰָ�� 
	fclose(fp);
	return head;
}


//ǰtopRanking���������У�����һ���Ǹ��ڵ������ ,headΪ�洢�����û���Ϣ������ 
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



