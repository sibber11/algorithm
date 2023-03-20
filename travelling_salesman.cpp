#include <iostream>
using namespace std;
#define DIM 4

/*
Algorithm: Traveling-Salesman-Problem
Cost (1, {}, 1) = 0
for s = 2 to n do
   for all subsets S belongs to {1, 2, 3, … , n} of size s
      Cost (s, S, 1) = Infinity
   for all i Є S and i ≠ 1
      Cost (i, S, j) = min {Cost (i, S – {i}, j) + dist(i, j) for j Є S and i ≠ j}
Return min(i) Cost (i, {1, 2, 3, …, n}, j) + d(j, i)
*/
int matrix[4][4] = {
    {0, 10, 15, 20}, // values of a graph in a form of matrix
    {5, 0, 9, 10},
    {6, 13, 0, 12},
    {8, 8, 9, 0}};

int VISITED = (1 << DIM) - 1;
// function to find the shortest path for the travelling salesman problem
int tsp(int visited, int pos){
    if (visited == VISITED)
        return matrix[pos][0];
    int ans = INT_MAX;
    for (size_t i = 0; i < DIM; i++)
    {
        if ((visited&(1<<i)) == 0)
        {
            int newAns = matrix[pos][i] + tsp(visited|(1<<i), i);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main()
{
       
    cout << "The shortest path is: " << tsp(1, 0) << endl;
    return 0;
}