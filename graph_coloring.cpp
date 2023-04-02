#include <iostream>
#include "print_array.hpp"
#define N 4
using namespace std;

int graph[N][N] = {
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1, 0},
};
int max_color = 2;
int color_array[N];
bool check_adjacency(int n){
    for (int i = 0; i < N; i++)
    {
        if (i == n)
            continue;
        if (graph[i][n] != 0)
        {
            if (color_array[i] == color_array[n])
                return true;
        }
    }
    return false;
}
bool m_color(int n)
{
    if (n == N)
        return true;
    for (int i = 0; i <= max_color; i++)
    {
        color_array[n]= i;
        if (check_adjacency(n))
            continue;
        if (m_color(n+1))
            return true;    
    }
    return false;
}

int main()
{
    for (int i = 0; i < N; i++)
        color_array[i] = -1;
    m_color(0);
}