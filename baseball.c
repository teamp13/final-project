#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game2() {
    int answer[3], input[3], strike, ball, i, j;
    int attempt = 10; // 시도 횟수

    // 답 생성 (중복되지 않는 숫자)
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

    // 게임 시작
    while (attempt > 0) { // 10회 시도 제한
        // 숫자 입력 받기
        while (1) {
            int dup = 0;
            printf("숫자 3개 입력(띄어쓰기): ");
            scanf_s("%d %d %d", &input[0], &input[1], &input[2]);

            // 입력한 숫자 중복 확인
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
                printf("중복된 숫자를 입력하였습니다. 다시 입력해 주세요.\n");
            }
        }

        // 스트라이크와 볼 계산
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

        // 결과 출력
        printf("[스트라이크: %d] [볼: %d] [남은 생명(%d)]\n\n", strike, ball, attempt-1);

        // 3스트라이크면 게임 종료
        if (strike == 3) {
            printf("축하합니다! 게임에서 승리하셨습니다.\n");
            break;
        }

        attempt--;
    }

    if (attempt == 0) {
        printf("아쉽지만 게임에서 패배하셨습니다.\n");
    }
}
