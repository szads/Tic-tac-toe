#include <stdio.h>

#define MIN_SIZE 3
#define MAX_SIZE 9

void drawBoard(int size) {
    int count = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %2d ", count++);
            if (j < size - 1) printf("|");
        }
        printf("\n");
        if (i < size - 1) {
            for (int j = 0; j < size; j++) {
                printf("----");
                if (j < size - 1) printf("+");
            }
            printf("\n");
        }
    }
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
    int boardSize, choice;

    printf("Enter board size (%d to %d): ", MIN_SIZE, MAX_SIZE);
    if (scanf("%d", &boardSize) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (boardSize < MIN_SIZE || boardSize > MAX_SIZE) {
        printf("Invalid size! Must be between %d and %d.\n", MIN_SIZE, MAX_SIZE);
        return 1;
    }

    printf("\nTic Tac Toe Board (%dx%d):\n\n", boardSize, boardSize);
    drawBoard(boardSize);

    printf("\nSelect mode:\n");
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
