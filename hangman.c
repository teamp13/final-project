#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>    
#define WORD_COUNT 2999
//#define DEBUG

void map2();
void title();
void overlap(char input);//�ߺ� Ȯ��
void wrong(char input);//Ʋ�� ���ĺ� üũ
bool correct(char input);//���� ���ĺ� üũ
void print_input_word();
void get_word_fp();


char word[WORD_COUNT][20] = { "" };
char save[30] = { 0, };
int i, j, p, q;
char tmp[10];// �ܾ� ����
char input;//���ĺ� �Է�
char temp;//���� ó��
int local = 0;//�ܾ� ��ġ
int life = 10;//����    
char under_bar = '_';//�ʿ� ���
int k = 0;//�ߺ� ��� ����

void init_global_vars() {
    memset(word, 0, sizeof(word));
    memset(save, 0, sizeof(save));
    memset(tmp, 0, sizeof(tmp));

    i = 0;
    j = 0;
    p = 0;
    q = 0;

    input = 0;
    temp = 0;
    local = 0;
    life = 10;
    under_bar = '_';
    k = 0;
}

void get_word_fp() {
    int i = 0;
    FILE* fp = fopen("words.txt", "r");
    while (1) {
        if (fgets(&word[i], 2999, fp) == NULL) {
            break;
        }
        // �ٹٲ� ���� ����
        word[i][strcspn(word[i], "\n")] = '\0';
        i++;
    }
    fclose(fp);
}

int game3() {
    get_word_fp();
    title();
    srand(time(NULL));
    local = rand() % WORD_COUNT;
    printf("%s\n", word[local]); //�ܾ� üũ

    while (1) {
        printf("Life : %d\n", life);
        map2();
        printf("���ĺ��� �Է��ϼ��� : ");
        scanf_s(" %c", &input);
        scanf_s("%c", &temp); // ���� ���Ͱ� �����ֱ�

        for (q = 0; q <= p; ++q) {
            if (save[q] == input) {
                printf("OverLap\n");
                break;
            }
        }

        save[p] = input;//�Է� �޴°� ����
        p += 1;


        if (!correct(input)) {
            wrong(input);
        }

        print_input_word();

        for (i = 0; i < strlen(word[local]); ++i) {
            if (!strcmp(tmp, word[local])) {
                map2();
                printf("You Win!\n");
                init_global_vars();
                return 0;
            }
        }

        if (life == 0) {
            printf("Game Over\n");
            printf("������ : ");
            printf("%s\n", word[local]);
            init_global_vars();
            return 0;
        }

#ifdef DEBUG
        printf("[DEBUG]: ");
        for (int i = 0; i < 30; i++) {
            printf("%c ", save[i]);
        }
        printf("\n");
#endif
    }
}

void map2() {
    printf("��");
    for (i = 0; i < strlen(word[local]) * 2; ++i) {
        printf("��");
    }

    printf("��\n");
    printf("��");

    for (i = 0; i < strlen(word[local]); ++i) {
        printf("%c ", under_bar/*word[local][i]*/);
        for (j = 0; j < strlen(word[local]); ++j) {
            if (word[local][i] == tmp[j]) {
                printf("\b\b%c ", tmp[i]);
            }
        }
    }

    printf("��\n");
    printf("��");
    for (i = 0; i < strlen(word[local]) * 2; ++i) {
        printf("��");
    }
    printf("��\n");
}


void overlap(char input) {
    for (q = 0; q <= p; ++q) {
        if (save[q] == input) {
            printf("OverLap\n");
            break;
        }
    }
}


void  wrong(char input) {
    for (j = 0; j < strlen(word[local]); ++j) { //�ܾ� Ʋ���� üũ
        if (input != word[local][i]) {
            printf("Wrong!");
            Sleep(500);
            k += 1;
            life -= 1;
            if (k >= 1) {
                system("cls");
                break;
            }
        }
    }
}


bool correct(char input) {
    bool memo[200] = { false, };
    bool result = false;
    for (i = 0; i < strlen(word[local]); ++i) { //�ܾ� �´°� üũ
        if (input == word[local][i]) {
            if (memo[input])
            {
                result = true;
                tmp[i] = word[local][i];
                printf("Correct!");
                system("cls");
                continue;
            }
            result = true;
            tmp[i] = word[local][i];
            printf("Correct!");
            Sleep(500);
            system("cls");
            memo[input] = true;
        }
    }
    return result;
}


void print_input_word() {
    printf("Input Word : ");
    for (int i = 0; i < 30; i++) {
        printf("%c ", save[i]);
    }
    printf("\n");
}

void title() {
    system("title Hang Man");
}