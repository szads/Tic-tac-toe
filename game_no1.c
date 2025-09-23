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

int main() {
    int boardSize;

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

    return 0;
}
