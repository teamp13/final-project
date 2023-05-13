#include <stdio.h>

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

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int player = 1;
    int moves = 0;
    int winner = ' ';

    printf("Welcome to Tic-Tac-Toe!\n\n");

    while (moves < 9 && winner == ' ') {
        printf("Player %d's turn:\n", player);
        display_board(board);
        int row, col;
        printf("Enter row (1-3) and column (1-3) separated by a space: ");
        scanf_s("%d %d", &row, &col);
        row--;
        col--;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = (player == 1) ? 'X' : 'O';
            player = (player == 1) ? 2 : 1;
            moves++;
            winner = check_winner(board);
        }
        else {
            printf("Invalid move. Please try again.\n");
        }
    }

    display_board(board);
    if (winner == 'X') {
        printf("Player 1 wins!\n");
    }
    else if (winner == 'O') {
        printf("Player 2 wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}
