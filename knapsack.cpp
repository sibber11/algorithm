#include <iostream>
#include <queue>
// #include "print_array.hpp"
using namespace std;

struct knapsack
{
    int weight;
    int profit;

    int ratio()
    {
        return this->weight / this->profit;
    }
};

int main()
{
    // int weight[] = {3, 4, 5, 6};
    // int profit[] = {2, 3, 4, 1};
    // int max_weight = 8;
    int weight[] = {1, 1, 2, 3, 4, 5, 7};
    int profit[] = {3, 6, 10, 5, 18, 15, 7};
    int max_weight = 15;
    int num_of_item = sizeof weight / sizeof weight[0];

    // using dynamic approach
    int row = num_of_item + 1;
    int col = max_weight + 1;
    int matrix[row][col] = {0};

    // initialize the matrix as all 0;
     for (int i = 0; i < row; ++i)
         for (int j = 0; j < col; ++j)
             matrix[i][j] = 0;

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (j < weight[i - 1])
            {
                matrix[i][j] = matrix[i - 1][j];
                continue;
            }

            matrix[i][j] = max(profit[i - 1] + matrix[i - 1][j - weight[i - 1]], matrix[i - 1][j]);
        }
    }
    // for (int i = 0; i < row; i++)
    // {
    //     // std::cout << i << ": ";
    //     for (int j = 0; j < col; j++)
    //         cout << matrix[i][j] << "\t";
    //     cout << endl;
    // }
    // cout << endl;
    cout << "using dynamic: " << matrix[row-1][col-1] << endl;
    // using ratio greedy
    float ratio[num_of_item];
    priority_queue<pair<int, pair<int, int> > > pq;
    // fill the ratio array
    for (int i = 0; i < num_of_item; i++)
    {
        ratio[i] = profit[i] / weight[i];
        //cout << ratio[i] << "\t";
        pq.push(make_pair(ratio[i], make_pair(weight[i], profit[i])));
    }
    cout << endl;

    int sum = 0;
    int rem = max_weight;

    while (!pq.empty())
    {

        sum += pq.top().second.second;
        rem -= pq.top().second.first;
        pq.pop();
        if (pq.top().second.first > rem)
        {
            break;
        }
    }

    cout << "using greedy ratio: " <<  sum << endl;
}