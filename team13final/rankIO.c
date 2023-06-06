#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 틱택토게임 유저 데이터
typedef struct{
    //DATA
    char name[10];
    int score;
    int most_win;
} User1;

// 베이스볼게임 유저 데이터
typedef struct {
    //DATA
    char name[10];
    int score;
    int least_win;
} User2;

// 행맨게임 유저 데이터
typedef struct {
    //DATA
    char name[10];
    int score;
    int least_count;
} User3;

void rank1() {
    int num = 0, j = 0, k = 0, n = 100;
    User1 users[100];
    User1 temp;
    
    FILE* fp1 = fopen("user1.txt", "r");

    if (fp1 == NULL) {
        printf("파일이 없습니다.\n");
        return;
    }

    while (1) {
        int result = fscanf_s(fp1, "%s %d %d", users[num].name, sizeof(users[num].name), &users[num].score, &users[num].most_win);
        if (result != 3)
            break;
        num++;
    }


    fclose(fp1);

    // Sort users based on score
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (users[j].score < users[j + 1].score) {
                temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
    for (int a = 0; a < num; a++) {
        printf("|%d\t|%s\t|%d\t|%d\t|\n", a + 1, users[a].name, users[a].score, users[a].most_win);
    }
}

void rank2() {
    int num = 0, j = 0, k = 0, n = 100;
    User2 users[100];
    User2 temp;

    FILE* fp2 = fopen("user2.txt", "r");

    if (fp2 == NULL) {
        printf("파일이 없습니다.\n");
        return;
    }

    while (1) {
        int result = fscanf_s(fp2, "%s %d %d", users[num].name, sizeof(users[num].name), &users[num].score, &users[num].least_win);
        if (result != 3)
            break;
        num++;
    }

    fclose(fp2);

    // Sort users based on score
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (users[j].score < users[j + 1].score) {
                temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
    for (int a = 0; a < num; a++) {
        printf("|%d\t|%s\t|%d\t|%d\t|\n", a + 1, users[a].name, users[a].score, users[a].least_win);
    }
}

void rank3() {
    int num = 0, j = 0, k = 0, n = 100;
    User3 users[100];
    User3 temp;

    FILE* fp3 = fopen("user3.txt", "r");

    if (fp3 == NULL) {
        printf("파일이 없습니다.\n");
        return;
    }

    while (1) {
        int result = fscanf_s(fp3, "%s %d %d", users[num].name, sizeof(users[num].name), &users[num].score, &users[num].least_count);
        if (result != 3)
            break;
        num++;
    }

    fclose(fp3);

    // Sort users based on score
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (users[j].score < users[j + 1].score) {
                temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
    for (int a = 0; a < num; a++) {
        printf("|%d\t|%s\t|%d\t|%d\t|\n", a + 1, users[a].name, users[a].score, users[a].least_count);
    }
}
