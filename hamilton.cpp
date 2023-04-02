#include <iostream>
#include <bitset>
#define N 5
using namespace std;

int graph[N][N] =
{
    {0, 1, 1, 1, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 0},
};
int VISITED = (1 << N) - 1;
bool hamilton(int node, int visited)
{
    if(visited == VISITED)
    {
        if(graph[node][0])
        {
            cout << "possible: " <<  graph[node][0] << endl;
            return true;
        }
        else
        {
            //cout << "Unable to go further at: " << node << endl;
            return false;
        }
    }


    cout << "node:" << node+1 << " visited: " << bitset<5> (visited) << endl;
    // loop through all the node
    for(int i = 0; i < N; i++)
    {
        if(i == node)
            continue;
        if(graph[i][node] && (visited&(1<<i)) == 0)
        {
            if(!hamilton(i, visited|(1<<i)))
            {
                //cout << i << endl;
                //node += 1;
            }
        }
    }
}

int main()
{
    // start visiting the first node;
    cout << hamilton(0, 1);

}
