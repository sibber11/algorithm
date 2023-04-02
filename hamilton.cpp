#include <iostream>
#include <bitset>
#define N 5
using namespace std;

int graph[N][N] =
{
    {0, 1, 1, 1, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 1},
    {1, 1, 3, 0, 0},
    {0, 1, 1, 0, 0},
};
int VISITED = (1 << N) - 1;
bool hamilton(int node, int visited)
{
    // cout << "node:" << node+1 << " visited: " << bitset<5> (visited) << endl;
    // check if we already visited all the nodes
    if(visited == VISITED)
    {
        // we already visited all the nodes

        // check if it is possible to go back to the first node
        if(graph[node][0])
        {
            // print possible if there is a connection between the last visited node and the starting node. in this case its the 0th node.
            cout << "possible" << endl;
            // cout << node+1 << " ";

            // return true to indicate that the visiting is completed and to terminate the recursive funtion
            return true;
        }
        else
        {
            // cout << "Unable to go further at: " << node+1 << endl;

            // unable to go the the starting node from the last visited node.
            return false;
        }
    }
    // loop through all the node and visit all neighbouring nodes
    for(int i = 0; i < N; i++)
    {
        // here we check if ith node is a neighbour
        // and its not visited yet
        if(graph[i][node] && (visited&(1<<i)) == 0)
        {
            // cout << node+1 << "->" << i+1 << endl;
            // we could skip the if else here to count all the possibilities
            // we explore ith node and mark the ith node visited
            if(hamilton(i, visited|(1<<i))){
                // cout << node+1 << " ";

                // by returning true we can end the function and print the nodes in reverse order.
                // return true;
            }else{
                // cout << "dead end " << i+1 << endl;
            }
        }
        
    }

    // we have tried all the ways, there is no hamiltonian cycle.
    return false;
}

int main()
{
    // start visiting the first node and set the lsb to 1 to indicate it is already visited.
    hamilton(0, 1);
    cout << endl;

}
