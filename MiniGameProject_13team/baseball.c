#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game2() {
    int answer[3], input[3], strike, ball, i;

    // �� ����
    srand(time(NULL));
    for (i = 0; i < 3; i++) {
        answer[i] = rand() % 10;
    }

    // ���� ����
    while (1) {
        // ���� �Է� �ޱ�
        for (i = 0; i < 3; i++) {
            printf("���� �Է�: ");
            scanf_s("%d", &input[i]);
        }

        // ��Ʈ����ũ�� �� ���
        strike = 0;
        ball = 0;
        for (i = 0; i < 3; i++) {
            if (answer[i] == input[i]) {
                strike++;
            }
            else if (answer[i] == input[i - 1] || answer[i] == input[i + 1]) {
                ball++;
            }
        }

        // ��� ���
        printf("��Ʈ����ũ: %d, ��: %d\n", strike, ball);

        // 3��Ʈ����ũ�� ���� ����
        if (strike == 3) {
            printf("�����մϴ�! ���ӿ��� �¸��ϼ̽��ϴ�.\n");
            break;
        }

        // 10ȸ �õ� Ƚ�� �ʰ� �� ���� ����
        if (i == 9) {
            printf("�ƽ����� ���ӿ��� �й��ϼ̽��ϴ�.\n");
            break;
        }
    }
}