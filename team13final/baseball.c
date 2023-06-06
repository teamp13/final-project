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
        attempt = 10; // 시도 횟수

        // 답 생성 (중복되지 않는 숫자)
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
        
        // printf("%d %d %d\n", answer[0], answer[1], answer[2]); // 테스트 답 확인

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
                score += attempt;
                if (least_win > 11 - attempt) least_win = 11 - attempt;
                printf("[점수: %d], [최단 승: %d]", score, least_win);
                #ifdef _WIN32
                    Sleep(1500);
                    system("cls");
                    break;
                #endif
                    
                
            }

            attempt--;
        }

        if (attempt == 0) {
            printf("아쉽지만 게임에서 패배하셨습니다.\n");
            break;
        }
    }while (attempt != 0);

    printf("당신의 닉네임을 입력해 주세요(최대 7자): ");
    scanf_s("%s", name, 7);
    fio2(name, score, least_win);
    
}
