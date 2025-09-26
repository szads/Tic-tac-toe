#include <stdio.h>
#include <string.h>

#define MIN_SIZE 3
#define MAX_SIZE 9

char board[MAX_SIZE][MAX_SIZE];
int boardSize;

void drawBoard(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %c ", board[i][j]);
            if (j < size - 1) printf("|");
        }
        printf("\n");
        if (i < size - 1) {
            for (int j = 0; j < size; j++) {
                printf("---");
                if (j < size - 1) printf("+");
            }
            printf("\n");
        }
    }
}

void initBoard(int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = ' ';
}

int isValidMove(int row, int col) {
    return row >= 0 && row < boardSize &&
           col >= 0 && col < boardSize &&
           board[row][col] == ' ';
}

void gameUsers(int players) {
    char names[3][50];
    char marks[3] = {'X', 'O', '#'};

    for (int i = 0; i < players; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", names[i]);
        printf("%s will use '%c'\n", names[i], marks[i]);
    }

    initBoard(boardSize);
    int turn = 0, totalMoves = 0;

    while (totalMoves < boardSize * boardSize) {
        printf("\nCurrent Board:\n");
        drawBoard(boardSize);

        int row, col;
        int currentPlayer = turn % players;

        printf("%s's turn (%c). Enter row and column (0-%d): ",
               names[currentPlayer], marks[currentPlayer], boardSize - 1);
        scanf("%d %d", &row, &col);

        if (!isValidMove(row, col)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = marks[currentPlayer];
        turn++;
        totalMoves++;
    }

    printf("\nFinal Board:\n");
    drawBoard(boardSize);
    printf("Game Over!\n");
}

int main() {
    int choice;

    printf("Enter board size (%d to %d): ", MIN_SIZE, MAX_SIZE);
    if (scanf("%d", &boardSize) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (boardSize < MIN_SIZE || boardSize > MAX_SIZE) {
        printf("Invalid size! Must be between %d and %d.\n", MIN_SIZE, MAX_SIZE);
        return 1;
    }

    printf("\nSelect mode:\n");
    printf("1. User vs User (2 players)\n");
    printf("2. 3 Users\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (choice == 1) {
        gameUsers(2);
    } else if (choice == 2) {
        gameUsers(3);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}