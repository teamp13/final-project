#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#endif

void game2() {
    int score = 0, least_win = 10;
    int attempt = 10;
    char name[7];

    srand(time(NULL));

    do {
        int answer[3], input[3], strike, ball, i, j;
        attempt = 10; // �õ� Ƚ��

        // �� ���� (�ߺ����� �ʴ� ����)
        for (i = 0; i < 3; i++) {
            while (1) {
                int dup = 0;
                answer[i] = rand() % 10;

                for (j = 0; j < i; j++) {
                    if (answer[j] == answer[i]) {
                        dup = 1;
                        break;
                    }
                }

                if (dup == 0) {
                    break;
                }
            }
        }
        
        // printf("%d %d %d\n", answer[0], answer[1], answer[2]); // �׽�Ʈ �� Ȯ��

        // ���� ����
        while (attempt > 0) { // 10ȸ �õ� ����
            // ���� �Է� �ޱ�
            while (1) {
                int dup = 0;
                printf("���� 3�� �Է�(����): ");
                scanf_s("%d %d %d", &input[0], &input[1], &input[2]);

                // �Է��� ���� �ߺ� Ȯ��
                for (i = 0; i < 3; i++) {
                    for (j = i + 1; j < 3; j++) {
                        if (input[i] == input[j]) {
                            dup = 1;
                            break;
                        }
                    }
                }
                if (dup == 0) {
                    break;
                }
                else {
                    printf("�ߺ��� ���ڸ� �Է��Ͽ����ϴ�. �ٽ� �Է��� �ּ���.\n");
                }
            }

            // ��Ʈ����ũ�� �� ���
            strike = 0;
            ball = 0;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (i == j && answer[i] == input[j]) {
                        strike++;
                    }
                    else if (i != j && answer[i] == input[j]) {
                        ball++;
                    }
                }
            }

            // ��� ���
            printf("[��Ʈ����ũ: %d] [��: %d] [���� ����(%d)]\n\n", strike, ball, attempt-1);

            // 3��Ʈ����ũ�� ���� ����
            if (strike == 3) {
                printf("�����մϴ�! ���ӿ��� �¸��ϼ̽��ϴ�.\n");
                score += attempt;
                if (least_win > 11 - attempt) least_win = 11 - attempt;
                printf("[����: %d], [�ִ� ��: %d]", score, least_win);
                #ifdef _WIN32
                    Sleep(1500);
                    system("cls");
                    break;
                #endif
                    
                
            }

            attempt--;
        }

        if (attempt == 0) {
            printf("�ƽ����� ���ӿ��� �й��ϼ̽��ϴ�.\n");
            break;
        }
    }while (attempt != 0);

    printf("����� �г����� �Է��� �ּ���(�ִ� 7��): ");
    scanf_s("%s", name, 7);
    fio2(name, score, least_win);
    
}
