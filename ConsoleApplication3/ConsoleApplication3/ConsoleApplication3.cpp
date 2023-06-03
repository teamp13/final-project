#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer[3];  // 컴퓨터가 생성한 정답 숫자 배열
    int guess[3];   // 사용자의 추측 숫자 배열
    int strikes, balls; // 스트라이크와 볼의 개수
    int i, j;
    int attempts = 0; // 시도 횟수

    srand(time(NULL));  // 랜덤 시드 초기화

    printf("숫자야구 게임을 시작합니다!\n");

    while (1) {
        attempts = 0;

        // 컴퓨터가 임의의 3자리 숫자를 생성
        for (i = 0; i < 3; i++) {
            answer[i] = rand() % 10;
        }

        // 게임 반복
        while (1) {
            strikes = 0;
            balls = 0;

            // 사용자로부터 숫자 입력 받기
            printf("3자리 숫자를 입력하세요 (0부터 9까지의 숫자 중복 없이): ");
            scanf_s("%1d%1d%1d", &guess[0], &guess[1], &guess[2]);

            // 스트라이크와 볼 개수 계산
            for (i = 0; i < 3; i++) {
                if (guess[i] == answer[i]) {
                    strikes++;
                }
                else {
                    for (j = 0; j < 3; j++) {
                        if (guess[i] == answer[j]) {
                            balls++;
                            break;
                        }
                    }
                }
            }

            // 결과 출력
            printf("결과: %d 스트라이크, %d 볼\n\n", strikes, balls);

            // 정답일 경우 게임 종료
            if (strikes == 3) {
                printf("정답입니다!\n");
                break;
            }

            attempts++;
            // 시도 횟수가 10회를 초과하면 게임 종료
            if (attempts >= 10) {
                printf("시도 횟수를 초과하여 게임을 종료합니다.\n");
                break;
            }
        }

        // 게임 재시작 여부 확인
        char restart;
        printf("게임을 다시 시작하시겠습니까? (Y/N): ");
        scanf_s(" %c", &restart);
        if (restart != 'Y' && restart != 'y') {
            printf("게임을 종료합니다.\n");
            break;
        }
    }

    return 0;
}
