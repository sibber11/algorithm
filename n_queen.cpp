#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#define N 4
using namespace std;

struct pos
{
    int x;
    int y;
    pos(int a, int b)
    {
        x = a;
        y = b;
    }
};

bool is_placeable(pos *chess_board[N][N], int row, int col)
{
    bool placeble = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (chess_board[i][j] != NULL)
            {
                pos *queen = chess_board[i][j];
                if (queen->x == row || queen->y == col || abs(queen->x - row) == abs(queen->y - col))
                {
                    placeble = false;
                    break;
                }
            }
        }
    }
    return placeble;
}

void draw(pos *chess_board[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (chess_board[row][col] == NULL)
                cout << 0 << " ";
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int place(pos *chess_board[N][N], int row)
{
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++)
    {
        // cout << row << "," << col << "->";
        if (is_placeable(chess_board, row, col))
        {
            // cout << 1 << endl;
            chess_board[row][col] = new pos(row, col);
            if (place(chess_board, row + 1))
            {
                return true;
            }

            delete chess_board[row][col];
            chess_board[row][col] = NULL;
        }
    }
    return false;
}


int main()
{
    pos *chess_board[N][N] = {NULL};
    draw(chess_board);
    place(chess_board, 0);
    draw(chess_board);
}