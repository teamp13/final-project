#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_board(char board[3][3]) {
    printf("\n");
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
    int row = available_moves[random_move][0];
    int col = available_moves[random_move][1];
    board[row][col] = 'O';
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    int player = 1;
    int moves = 0;
    char winner = ' ';

    printf("틱택토 게임을 시작합니다!\n\n");

    while (moves < 9 && winner == ' ') {
        printf("플레이어 %d의 차례:\n", player);
        display_board(board);

        if (player == 1) {
            int row, col;
            printf("행 (1-3)과 열 (1-3)을 공백으로 구분하여 입력하세요: ");
            scanf("%d %d", &row, &col);
            row--;
            col--;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = 'X';
                player = 2;
                moves++;
                winner = check_winner(board);
            }
            else {
                printf("잘못된 이동입니다. 다시 시도하세요.\n");
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
    }
    else if (winner == 'O') {
        printf("컴퓨터가 승리했습니다!\n");
    }
    else {
        printf("무승부입니다!\n");
    }

    return 0;
}
