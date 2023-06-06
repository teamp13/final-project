#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#endif

void display_board(char board[3][3]) {
    system("cls");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int check_winner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}

void make_computer_move(char board[3][3]) {
    int available_moves[9][2];
    int move_count = 0;

    // 빈 공간을 찾아서 가능한 이동 옵션을 수집합니다.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                available_moves[move_count][0] = i;
                available_moves[move_count][1] = j;
                move_count++;
            }
        }
    }

    // 랜덤으로 이동을 선택합니다.
    srand(time(NULL));
    int random_move = rand() % move_count;

    #ifdef _WIN32
        Sleep(500);
    #endif

    int row = available_moves[random_move][0];
    int col = available_moves[random_move][1];
    board[row][col] = 'O';
}

void game1() {
    
    int score = 0, win = 0 ,most_win = 0, life = 2;
    char name[7];
    int player = 1;

    printf("틱택토 게임을 시작합니다!\n\n");

    while (1) {
        char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
        int moves = 0;
        char winner = ' ';
        while (moves < 9 && winner == ' ') {
            display_board(board);
            printf("플레이어 %d의 차례:\n", player);
            if (player == 1) {
                int row, col;
                printf("행 (1-3)과 열 (1-3)을 공백으로 구분하여 입력하세요: ");
                scanf_s("%d %d", &row, &col);
                row--;
                col--;

                if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                    board[row][col] = 'X';
                    player = 2;
                    moves++;
                    winner = check_winner(board);
                }
            }
            else {
                printf("컴퓨터의 차례:\n");
                make_computer_move(board);
                player = 1;
                moves++;
                winner = check_winner(board);
            }
        }

        display_board(board);
        if (winner == 'X') {
            printf("플레이어 1이 승리했습니다!\n");
            player = 2;
            win += 1;
            score += win;
        }
        else if (winner == 'O') {
            printf("컴퓨터가 승리했습니다!\n");
            life = 0;
        }
        else {
            printf("무승부입니다!\n");
            win = 0;
            life -= 1;
        }
        if (win > most_win) { most_win = win; }

        if (life <= 0) {
            break;
        }
        printf("[점수: %d], [무승부 기회: %d], [%d 연승 중!]", score, life, win);
        #ifdef _WIN32
            Sleep(1500);
        #endif
    }
    printf("당신의 닉네임을 입력해 주세요(최대 7자): ");
    scanf_s("%s", name, 7);
    fio1(name, score, most_win);
}
