#include <stdio.h>
#include <string.h>

#define MIN_SIZE 3
#define MAX_SIZE 9
#define CELL_LEN 4

char board[MAX_SIZE][MAX_SIZE][CELL_LEN];
int boardSize;

void initBoard() {
    int count = 1;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            sprintf(board[i][j], "%d", count++);
        }
    }
}

void drawBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardSize; j++) {
            printf(" %2s ", board[i][j]);
            if (j < boardSize - 1) printf("|");
        }
        printf("\n");
        if (i < boardSize - 1) {
            for (j = 0; j < boardSize; j++) {
                printf("----");
                if (j < boardSize - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

void gameUserUser() {
    printf("Starting User vs User mode...\n");
}
void gameUserComputer() {
    printf("Starting User vs Computer mode...\n");
}
void game3Users() {
    printf("Starting 3 Users mode...\n");
}

int main() {
    int choice;

    printf("Enter board size (%d to %d): ", MIN_SIZE, MAX_SIZE);
    if (scanf("%d", &boardSize) != 1 || boardSize < MIN_SIZE || boardSize > MAX_SIZE) {
        printf("Invalid size!\n");
        return 1;
    }

    initBoard();
    printf("\nTic Tac Toe Board (%dx%d):\n", boardSize, boardSize);
    drawBoard();

    printf("Select mode:\n");
    printf("1. User vs User\n");
    printf("2. User vs Computer\n");
    printf("3. 3 Users\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    switch (choice) {
        case 1: gameUserUser(); break;
        case 2: gameUserComputer(); break;
        case 3: game3Users(); break;
        default: printf("Invalid choice!\n"); break;
    }

    return 0;
}