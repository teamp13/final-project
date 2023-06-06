#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#endif
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
char save[99] = { 0, };
int i, j, p, q;
char tmp[10];// �ܾ� ����
char input;//���ĺ� �Է�
char temp;//���� ó��
int local = 0;//�ܾ� ��ġ
int life = 10;//����
int count = 0, least_count = 99;
char under_bar = '_';//�ʿ� ���
int k = 0;//�ߺ� ��� ����
bool corr = false;

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
    count = 0;
    under_bar = '_';
    k = 0;

    corr = false;
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
    title();
    srand(time(NULL));
    int score = 0;
    char name[7];
    while (life != 0) {
        init_global_vars();
        get_word_fp();
        local = rand() % WORD_COUNT;
        while (1) {
            printf("Life : %d\n", life);
            // printf("%s\n", word[local]); //�ܾ� üũ
            map2();
            printf("���ĺ��� �Է��ϼ��� : ");
            scanf_s(" %c", &input);
            scanf_s("%c", &temp); // ���� ���Ͱ� �����ֱ�

            overlap(input);

            save[p] = input;//�Է� �޴°� ����
            p += 1;


            if (!correct(input)) {
                wrong(input);
            }
            count++;

            print_input_word();

            for (i = 0; i < strlen(word[local]); ++i) {
                if (!strcmp(tmp, word[local])) {
                    map2();
                    score += strlen(word[local]) * life;
                    if (least_count > count) { least_count = count; }
                    printf("�����Դϴ�!\n");
                    printf("[���� ����: %d], [�ִܱ��: %dȸ]\n", score, least_count);
                    #ifdef _WIN32
                    Sleep(1500);
                    corr = true;
                    #endif
                    
                }
            }

            if (life == 0) {
                printf("Game Over\n");
                printf("������ : ");
                printf("%s\n", word[local]);
                break;
            }

            if (corr == true) {
                system("cls");
                break;
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
    printf("����� �г����� �Է��� �ּ���(�ִ� 7��): ");
    scanf_s("%s", name, 7);
    fio3(name, score, least_count);
    
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
            printf("*�ߺ��� ���ĺ�*\n");
            count--;
            break;
        }
    }
}


void  wrong(char input) {
    for (j = 0; j < strlen(word[local]); ++j) { //�ܾ� Ʋ���� üũ
        if (input != word[local][i]) {
            printf("Ʋ�Ƚ��ϴ�!");
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
                printf("������ϴ�!");
                system("cls");
                continue;
            }
            result = true;
            tmp[i] = word[local][i];
            printf("������ϴ�!");
            Sleep(500);
            system("cls");
            memo[input] = true;
        }
    }
    return result;
}


void print_input_word() {
    printf("�Է��� �ܾ� : ");
    for (int i = 0; i < 30; i++) {
        printf("%c ", save[i]);
    }
    printf("\n");
}

void title() {
    system("title Hang Man");
}