#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void fio1(char name[10], int score, int most_win) {
	FILE* fp = fopen("user1.txt", "at");
	fprintf(fp, "%s %d %d\n", name, score, most_win);

	fclose(fp);

	fp = fopen("user1.txt", "r");
	if (fp == NULL) {
		printf("파일이 없습니다.\n");
		return;
	}
}

void fio2(char name[10], int score, int least_win) {
	FILE* fp = fopen("user2.txt", "at");
	fprintf(fp, "%s %d %d\n", name, score, least_win);

	fclose(fp);

	fp = fopen("user2.txt", "r");
	if (fp == NULL) {
		printf("파일이 없습니다.\n");
		return;
	}
}

void fio3(char name[10], int score, int least_count) {
	FILE* fp = fopen("user3.txt", "at");
	fprintf(fp, "%s %d %d\n", name, score, least_count);

	fclose(fp);

	fp = fopen("user3.txt", "r");
	if (fp == NULL) {
		printf("파일이 없습니다.\n");
		return;
	}
}