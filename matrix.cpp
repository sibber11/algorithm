#include <iostream>
using namespace std;
#define ROW 3
#define COL 4

void multiply_row(float matrix[ROW][COL], int row, float factor)
{
    for (int i = 0; i < COL; i++)
    {
        matrix[row][i] *= factor;
    }
}

void subtract_row(float matrix[ROW][COL], int row1, int row2, float factor = 1)
{
    for (int i = 0; i < COL; i++)
    {
        matrix[row1][i] -= matrix[row2][i] * factor;
    }
}

void add_row(float matrix[ROW][COL], int row1, int row2, float factor = 1)
{
    for (int i = 0; i < COL; i++)
    {
        matrix[row1][i] += matrix[row2][i] * factor;
    }
}

void divide_row(float matrix[ROW][COL], int row, float factor)
{
    for (int i = 0; i < COL; i++)
    {
        matrix[row][i] /= factor;
    }
}

void print_matrix(float matrix[ROW][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    float matrix[ROW][COL] = {
        {2, 3, -1, 5},
        {4, 4, -3, 3},
        {-2, 3, -1, 1}};
    print_matrix(matrix);
    add_row(matrix, 2, 0);
    subtract_row(matrix, 1, 0, 2);
    print_matrix(matrix);
    add_row(matrix, 2, 1, 3);
    print_matrix(matrix);
    divide_row(matrix, 0, 2);
    divide_row(matrix, 1, -2);
    divide_row(matrix, 2, -5);
    print_matrix(matrix);
    add_row(matrix, 0, 2, 0.5);
    subtract_row(matrix, 1, 2, 0.5);
    print_matrix(matrix);
    add_row(matrix, 0, 1, 1.5);
    print_matrix(matrix);
    subtract_row(matrix, 0, 1, 3);
    print_matrix(matrix);

    return 0;
}