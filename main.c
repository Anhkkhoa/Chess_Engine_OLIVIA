#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Board Initlialization
char side = 'W'; // Playing Black or White
int board[8][8]; //Bit Board
char chessboard[8][8][4]; // Pieces Name Board (3 letters + null character)

//Chess Pieces
enum chesspieces
{
    EMPTY, //Empty Square
    WPAWN, WROOK, WKNIGHT, WBISHOP, WQUEEN, WKING, //White Pieces
    BPAWN, BROOK, BKNIGHT, BBISHOP, BQUEEN, BKING //Black Pieces
};

//User Function Prototype
void ResetBoard(char side); //Reset Board and placing chess pieces
void PiecesBoard(); //Turning Bit board into board with pieces name
void PrintBitBoard(); //Print out board with bit information
void PrintChessBoard(); //Print out board with chess pieces


int main() 
{
    ResetBoard(side);
    PiecesBoard();
    PrintChessBoard();

    for (int i = 0; i < 8; i++)
    {
        int player_row;
        char player_col;
            
        printf("Enter chess piece location (Row/Col): ");
        fflush(stdout);
        scanf("%d %c", &player_row, &player_col);

        //Conversion to board array location (row flip back and col to integer)
        player_row = 8 - player_row;

        switch(player_col)
        {
            case 'a': player_col = 0; break;
            case 'b': player_col = 1; break;
            case 'c': player_col = 2; break;
            case 'd': player_col = 3; break;
            case 'e': player_col = 4; break;
            case 'f': player_col = 5; break;
            case 'g': player_col = 6; break;
            case 'h': player_col = 7; break;
        }
        
        PiecesBoard();
        printf("%s at row: %d / col: %d\n", chessboard[player_row][player_col], player_row, player_col);
        printf("Here are possible move(s)\n");
    }
}

//------------------------------------------------------------------------------------------------------------
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
            board[6][i] = BPAWN;
        }
    }
}

//Duplicate Board with pieces name
void PiecesBoard()
{
    for (int row = 0; row < 8; row++ )
    {
        for (int col = 0; col < 8; col++)
        {
            switch(board[row][col]) //String Array is read only, use strcpy 
            {
                //Empty
                case EMPTY: strcpy(chessboard[row][col], "   "); break;
                    
                //Pawn
                case WPAWN: strcpy(chessboard[row][col], "[P]"); break;
                case BPAWN: strcpy(chessboard[row][col], "{p}"); break;
                
                //Rook
                case WROOK: strcpy(chessboard[row][col], "[R]"); break;
                case BROOK: strcpy(chessboard[row][col], "{r}"); break;

                //Knight
                case WKNIGHT: strcpy(chessboard[row][col], "[N]"); break;
                case BKNIGHT: strcpy(chessboard[row][col], "{n}"); break;
                    
                //Bishop
                case WBISHOP: strcpy(chessboard[row][col], "[B]"); break;
                case BBISHOP: strcpy(chessboard[row][col], "{b}"); break;

                //Queen
                case WQUEEN: strcpy(chessboard[row][col], "[Q]"); break;
                case BQUEEN: strcpy(chessboard[row][col], "{q}"); break;

                //King
                case WKING: strcpy(chessboard[row][col], "[K]"); break;
                case BKING: strcpy(chessboard[row][col], "{k}"); break;
            }
        }
    }
}
//Print Board Function
void PrintChessBoard()
{
    printf("      a     b     c     d     e     f     g     h   \n");
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 8 | %s | %s | %s | %s | %s | %s | %s | %s |\n", chessboard[0][0], chessboard[0][1], chessboard[0][2], chessboard[0][3], chessboard[0][4], chessboard[0][5], chessboard[0][6], chessboard[0][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 7 | %s | %s | %s | %s | %s | %s | %s | %s |\n", chessboard[1][0], chessboard[1][1], chessboard[1][2], chessboard[1][3], chessboard[1][4], chessboard[1][5], chessboard[1][6], chessboard[1][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 6 | %s | %s | %s | %s | %s | %s | %s | %s |\n", chessboard[2][0], chessboard[2][1], chessboard[2][2], chessboard[2][3], chessboard[2][4], chessboard[2][5], chessboard[2][6], chessboard[2][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 5 | %s | %s | %s | %s | %s | %s | %s | %s |\n", chessboard[3][0], chessboard[3][1], chessboard[3][2], chessboard[3][3], chessboard[3][4], chessboard[3][5], chessboard[3][6], chessboard[3][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 4 | %s | %s | %s | %s | %s | %s | %s | %s |\n", chessboard[4][0], chessboard[4][1], chessboard[4][2], chessboard[4][3], chessboard[4][4], chessboard[4][5], chessboard[4][6], chessboard[4][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 3 | %s | %s | %s | %s | %s | %s | %s | %s |\n", chessboard[5][0], chessboard[5][1], chessboard[5][2], chessboard[5][3], chessboard[5][4], chessboard[5][5], chessboard[5][6], chessboard[5][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 2 | %s | %s | %s | %s | %s | %s | %s | %s |\n", chessboard[6][0], chessboard[6][1], chessboard[6][2], chessboard[6][3], chessboard[6][4], chessboard[6][5], chessboard[6][6], chessboard[6][7]);
    printf("   +-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf(" 1 | %s | %s | %s | %s | %s | %s | %s | %s |\n", chessboard[7][0], chessboard[7][1], chessboard[7][2], chessboard[7][3], chessboard[7][4], chessboard[7][5], chessboard[7][6], chessboard[7][7]);
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


