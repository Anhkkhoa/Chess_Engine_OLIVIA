#include <stdio.h>
#include <string.h>

//Board Initlialization
char side = 'W'; // Playing Black or White
int board[8][8];

//White Chess Piece
const int WPAWN = 1;
const int WROOK = 2;
const int WKNIGHT = 3;
const int WBISHOP = 4;
const int WQUEEN = 5;
const int WKING = 6;

//Black Chess Piece
const int BPAWN = 7;
const int BROOK = 8;
const int BKNIGHT = 9;
const int BBISHOP = 10;
const int BQUEEN = 11;
const int BKING = 12;


//User Function Prototype
void PrintBitBoard(); //Print out board with bit information
void PrintChessBoard(); //Print out board with chess pieces
void ResetBoard(char side); //Reset Board and placing chess pieces

int main() 
{
    ResetBoard(side);
    PrintBitBoard();
    PrintChessBoard();
    return 0;
}


//Print Board Function
void PrintChessBoard()
{
    //Adding Chess Piece Rank # Conversion later
    char chessboard[8][8][4]; // 4 letters + null character

    for (int row = 0; row < 8; row++ )
    {
        for (int col = 0; col < 8; col++)
        {
            switch(board[row][col]) //String Array is read only, use strcpy not =
            {
                //Empty
                case 0:
                    strcpy(chessboard[row][col], "   ");
                    break;

                //Pawn
                case WPAWN:
                    strcpy(chessboard[row][col], "[P]");
                    break;

                case BPAWN:
                    strcpy(chessboard[row][col], "{p}");
                    break;
                
                //Rook
                case WROOK:
                    strcpy(chessboard[row][col], "[R]");
                    break;

                case BROOK:
                    strcpy(chessboard[row][col], "{R}");
                    break;

                //Knight
                case WKNIGHT:
                    strcpy(chessboard[row][col], "[N]");
                    break;

                case BKNIGHT:
                    strcpy(chessboard[row][col], "{N}");
                    break;\
                    
                //Bishop
                case WBISHOP:
                    strcpy(chessboard[row][col], "[B]");
                    break;

                case BBISHOP:
                    strcpy(chessboard[row][col], "{B}");
                    break;

                //Queen
                case WQUEEN:
                    strcpy(chessboard[row][col], "[Q]");
                    break;

                case BQUEEN:
                    strcpy(chessboard[row][col], "{Q}");
                    break;

                //King
                case WKING:
                    strcpy(chessboard[row][col], "[K]");
                    break;

                case BKING:
                    strcpy(chessboard[row][col], "{K}");
                    break;
            }
        }
    }


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



//Print Bit Board Function
void PrintBitBoard()
{
    printf("      a     b     c     d     e     f     g     h   \n");
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 8 | %d | %d | %d | %d | %d | %d | %d | %d |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 7 | %d | %d | %d | %d | %d | %d | %d | %d |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 6 | %d | %d | %d | %d | %d | %d | %d | %d |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 5 | %d | %d | %d | %d | %d | %d | %d | %d |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 4 | %d | %d | %d | %d | %d | %d | %d | %d |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 3 | %d | %d | %d | %d | %d | %d | %d | %d |\n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 2 | %d | %d | %d | %d | %d | %d | %d | %d |\n", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 1 | %d | %d | %d | %d | %d | %d | %d | %d |\n", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
}


//Reset Board Function
void ResetBoard(char side)
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            board[row][col] = 0;
        }
    }

    if (side == 'W') //Did use Ternary, not pretty
    {
        //Rook
        board[0][0] = board[0][7] = BROOK;
        board[7][0] = board[7][7] = WROOK;

        //Knight
        board[0][1] = board[0][6] = BKNIGHT;
        board[7][1] = board[7][6] = WKNIGHT;

        //Bishop
        board[0][2] = board[0][5] = BBISHOP;
        board[7][2] = board[7][5] = WBISHOP;

        //Queen
        board[0][3] = BQUEEN;
        board[7][3] = WQUEEN;

        //King
        board[0][4] = BKING;
        board[7][4] = WKING;

        for (int i = 0; i < 8; i++)
        {
            board[1][i] = BPAWN;
            board[6][i] = WPAWN;
        }
    }
    else 
    {
        //Rook
        board[0][0] = board[0][7] = WROOK;
        board[7][0] = board[7][7] = BROOK;

        //Knight
        board[0][1] = board[0][6] = WKNIGHT;
        board[7][1] = board[7][6] = BKNIGHT;

        //Bishop
        board[0][2] = board[0][5] = WBISHOP;
        board[7][2] = board[7][5] = BBISHOP;

        //Queen
        board[0][4] = WQUEEN;
        board[7][4] = BQUEEN;
        
        //King
        board[0][3] = WKING;
        board[7][3] = BKING;

        for (int i = 0; i < 8; i++)
        {
            board[1][i] = WPAWN;
            board[7][i] = BPAWN;
        }
    }
}