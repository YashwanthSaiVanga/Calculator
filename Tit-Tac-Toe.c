#include <stdio.h>

char board[3][3]; // Tic-Tac-Toe board

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the Tic-Tac-Toe board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

// Function to check if a player has won
int checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}

// Function to check if the board is full (draw condition)
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full yet
            }
        }
    }
    return 1; // Board is full
}

// Function to make a move
int makeMove(int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return 1; // Move successful
    }
    return 0; // Invalid move
}

// Main function
int main() {
    int row, col, turn = 0;
    char player;
    
    initializeBoard();
    printf("Tic-Tac-Toe Game!\n");
    printBoard();

    while (1) {
        player = (turn % 2 == 0) ? 'X' : 'O'; // Alternate between X and O
        printf("Player %c, enter your move (row and column: 0-2): ", player);
        scanf("%d %d", &row, &col);

        if (makeMove(row, col, player)) {
            printBoard();
            if (checkWin()) {
                printf("Player %c wins!\n", player);
                break;
            }
            if (checkDraw()) {
                printf("It's a draw!\n");
                break;
            }
            turn++;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    return 0;
}
