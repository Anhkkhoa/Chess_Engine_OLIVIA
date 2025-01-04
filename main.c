#include <stdio.h>
#include <string.h>

//Board Initlialization
char board[8][8][4]; //4 character included the null terminator

//User Function Prototype
void PrintBoard();
void ResetBoard();
void PlacePieces();

int main() 
{
    ResetBoard();
    PlacePieces();
    PrintBoard();
    return 0;
}

//Print Board Function
void PrintBoard()
{
    printf("      a     b     c     d     e     f     g     h   \n");
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 8 | %s | %s | %s | %s | %s | %s | %s | %s |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 7 | %s | %s | %s | %s | %s | %s | %s | %s |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 6 | %s | %s | %s | %s | %s | %s | %s | %s |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 5 | %s | %s | %s | %s | %s | %s | %s | %s |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 4 | %s | %s | %s | %s | %s | %s | %s | %s |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 3 | %s | %s | %s | %s | %s | %s | %s | %s |\n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 2 | %s | %s | %s | %s | %s | %s | %s | %s |\n", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 1 | %s | %s | %s | %s | %s | %s | %s | %s |\n", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");

}

//Reset Board Function
void ResetBoard()
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            strcpy(board[row][col], "   ");
        }
    }
}


//Placing Pieces Function
void PlacePieces()
{
    //Rook
    strcpy(board[0][0], "[R]");
    strcpy(board[0][7], "[R]");

    strcpy(board[7][0], "{R}");
    strcpy(board[7][7], "{R}");

    //Knight
    strcpy(board[0][1], "[N]");
    strcpy(board[0][6], "[N]");

    strcpy(board[7][1], "{N}");
    strcpy(board[7][6], "{N}");


    //Bishop
    strcpy(board[0][2], "[B]");
    strcpy(board[0][5], "[B]");

    strcpy(board[7][2], "{B}");
    strcpy(board[7][5], "{B}");

    //Queen
    strcpy(board[0][3], "[Q]");
    strcpy(board[7][3], "{Q}");

    //King
    strcpy(board[0][4], "[K]");
    strcpy(board[7][4], "{K}");

    //Pawn
    for (int i = 0; i < 8; i++)
    {
        strcpy(board[1][i], "[P]");
        strcpy(board[6][i], "{P}");
    }
    
}