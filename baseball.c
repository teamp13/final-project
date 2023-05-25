#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game2() {
    int answer[3], input[3], strike, ball, i, j;
    int attempt = 10; // �õ� Ƚ��

    // �� ���� (�ߺ����� �ʴ� ����)
    srand(time(NULL));
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
            break;
        }

        attempt--;
    }

    if (attempt == 0) {
        printf("�ƽ����� ���ӿ��� �й��ϼ̽��ϴ�.\n");
    }
}
