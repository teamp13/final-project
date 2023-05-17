#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game2() {
    int answer[3], input[3], strike, ball, i;

    // 답 생성
    srand(time(NULL));
    for (i = 0; i < 3; i++) {
        answer[i] = rand() % 10;
    }

    // 게임 시작
    while (1) {
        // 숫자 입력 받기
        for (i = 0; i < 3; i++) {
            printf("숫자 입력: ");
            scanf_s("%d", &input[i]);
        }

        // 스트라이크와 볼 계산
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

        // 결과 출력
        printf("스트라이크: %d, 볼: %d\n", strike, ball);

        // 3스트라이크면 게임 종료
        if (strike == 3) {
            printf("축하합니다! 게임에서 승리하셨습니다.\n");
            break;
        }

        // 10회 시도 횟수 초과 시 게임 종료
        if (i == 9) {
            printf("아쉽지만 게임에서 패배하셨습니다.\n");
            break;
        }
    }
}