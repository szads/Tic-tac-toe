#include <stdio.h>
#include <stdlib.h> //Memory allocation
#include <string.h>
#include <time.h> //For seeding random numbers

char **board; //Pointer to the 2D array
int size;

void initBoard(int n) {
    size = n; // To save chosen board size
    board = (char **)malloc(size * sizeof(char *)); //Allocate the memory for raws
    for (int i = 0; i < size; i++) {
        board[i] = (char *)malloc(size * sizeof(char)); //Allocate the memory for columns
        for (int j = 0; j < size; j++) {
            board[i][j] = ' ';
        }
    }
}

void drawBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %c ", board[i][j]); //Print the value of cell
            if (j < size - 1) printf("|");//print to separate the columns
        }
        printf("\n");
        if (i < size - 1) {
            for (int j = 0; j < size; j++) {
                printf("---"); //print to separate the raws
                if (j < size - 1) printf("+");
            }
            printf("\n");
        }
    }
}

void logBoard(const char *filename) {
    FILE *fp = fopen(filename, "a"); //open a file in append mode
    if (!fp) return; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(fp, "%c ", board[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "------------------\n");
    fclose(fp);
}

int checkWinner(char sym) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size - 3; j++) {
            if (board[i][j] == sym && board[i][j+1] == sym && board[i][j+2] == sym) //check the raws
                return 1;
        }
    }
    for (int j = 0; j < size; j++) {
        for (int i = 0; i <= size - 3; i++) {
            if (board[i][j] == sym && board[i+1][j] == sym && board[i+2][j] == sym) //check the columns
                return 1;
        }
    }
    for (int i = 0; i <= size - 3; i++) {
        for (int j = 0; j <= size - 3; j++) {
            if (board[i][j] == sym && board[i+1][j+1] == sym && board[i+2][j+2] == sym) //check the (\) side diagonals
                return 1;
        }
    }
    for (int i = 0; i <= size - 3; i++) {
        for (int j = 2; j < size; j++) {
            if (board[i][j] == sym && board[i+1][j-1] == sym && board[i+2][j-2] == sym) //check the (/) side diagonals
                return 1;
        }
    }
    return 0;
}

int isFull() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (board[i][j] == ' ') return 0; //to confirm the cell is empty 
    return 1;
}

void userMove(char sym) {
    int raw, column;
    while (1) {
        printf("Enter raw    (0 to %d): ", size - 1); //enter the nubmer of raw
        scanf("%d", &raw);
        printf("Enter column (0 to %d): ", size - 1); //enter the number of columns
        scanf("%d", &column);
        if (raw >= 0 && raw < size && column >= 0 && column < size && board[raw][column] == ' ') {
            board[raw][column] = sym; //mark the symboles if entered nubmers are valid
            break;
        } else {
            printf("Invalid move!!! Try again.\n"); 
        }
    }
}

void computerMove(char sym) {
    int raw, column;
    srand(time(NULL)); //show the random cells
    while (1) {
        raw = rand() % size; //random raws
        column = rand() % size; //random columns
        if (board[raw][column] == ' ') {
            board[raw][column] = sym;
            break;
        }
    }
}

int main() {
    char name1[20], name2[20], name3[20];
    char symbols[3] = {'X','O','Z'};
    int mode;

    printf("##### ##### #####     ##### ##### #####     ##### ##### #####\n"); // print the name of the game
    printf("  #     #   #           #   #   # #           #   #   # #\n");
    printf("  #     #   #     ###   #   ##### #     ###   #   #   # ###\n");
    printf("  #     #   #           #   #   # #           #   #   # #\n");
    printf("  #   ##### #####       #   #   # #####       #   ##### #####\n");
  
    do {
        printf("\nEnter board size (3-10): "); //print the size of board
        scanf("%d", &size);
    } while (size < 3 || size > 10);
    initBoard(size);

    do {
        printf("\nSELECT THE MODE:\n");//print the mode of playing 
        printf("1>>> User vs User\n");
        printf("2>>> User vs Computer\n");
        printf("3>>> 2 User vs Computer\n");
        scanf("%d", &mode);
    } while (mode < 1 || mode > 3);

    if (mode == 1) {// user user mode
        printf("\nEnter Player 1 name: ");
        scanf("%s", name1);
        printf("Enter Player 2 name: ");
        scanf("%s", name2);

        int turn = 0;
        while (1) {
            drawBoard();
            printf("%s's turn (%c)\n", turn==0 ? name1 : name2, symbols[turn]);
            userMove(symbols[turn]);
            logBoard("game_log.txt");

            if (checkWinner(symbols[turn])) {
                drawBoard();
                printf("Winner is %s!\n", turn==0 ? name1 : name2);
                break;
            }
            if (isFull()) {
                drawBoard();
                printf("It's a draw!!!\n");
                break;
            }
            turn = 1 - turn;
        }
    } 
    else if (mode == 2) {    //user vs computer mode
        printf("\nEnter Your name: ");
        scanf("%s", name1);
        strcpy(name2, "Computer");

        int turn = 0;
        while (1) {
            drawBoard();
            if (turn == 0) {
                printf("%s's turn (%c)\n", name1, symbols[0]);
                userMove(symbols[0]);
            } else {
                printf("%s's turn (%c)\n", name2, symbols[1]);
                computerMove(symbols[1]);
            }
            logBoard("game_log.txt");

            if (checkWinner(symbols[turn])) {
                drawBoard();
                printf("Winner is %s!\n", turn==0 ? name1 : name2);
                break;
            }
            if (isFull()) {
                drawBoard();
                printf("It's a draw!!!\n");
                break;
            }
            turn = 1 - turn;
        }
    } 
    else if (mode == 3){              // two user and computer mode          
        printf("\nEnter player 1 name: ");
        scanf("%s", name1);
        printf("Enter Player 2 name: ");
        scanf("%s", name2);
        strcpy(name3,"Computer");

        int turn = 0;
        while (1) {
            drawBoard();
            if (turn == 0) {
                printf("%s's turn (%c)\n", name1, symbols[0]);
                userMove(symbols[0]);
            } else if (turn == 1) {
                printf("%s's turn (%c)\n", name2, symbols[1]);
                userMove(symbols[1]);
            } else {
                printf("%s's turn (%c)\n", name3, symbols[2]);
                computerMove(symbols[2]);
            }
            logBoard("game_log.txt");

            if (checkWinner(symbols[turn])) {
                drawBoard();
                if (turn==0) printf("Winner is %s!\n", name1);
                else if (turn==1) printf("Winner is %s!\n", name2);
                else printf("Winner is %s!!!\n", name3);
                break;
            }
            if (isFull()) {
                drawBoard();
                printf("It's a draw!!!\n");
                break;
            }
            turn = (turn + 1) % 3;
        }
    }

    for (int i = 0; i < size; i++) free(board[i]);
    free(board);

    printf(" Thank you for playing!!!\n");
    return 0;
} 