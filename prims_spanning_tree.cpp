#include <iostream>
#include <queue>
// #include <bitset>
using namespace std;

#define V 5
#define INF INT_MAX

typedef pair<int, pair<int, int > > pi;

typedef priority_queue<pi, vector<pi>, greater<pi>> min_pq;

int graph[V][V] = {
	{0, 9, 75, 0, 0},
	{9, 0, 95, 19, 42},
	{75, 95, 0, 51, 66},
	{0, 19, 51, 0, 31},
	{0, 42, 66, 31, 0}};
min_pq pq;

int VISITED = (1<<V)-1;

int main()
{
	int current_node = 0;
	int visited = 1;
	int cost = 0;
	// cout << bitset<V> (VISITED) << endl;
	while (visited != VISITED)
	{
		for (int i = 0; i < V; i++)
		{
			// cout << bitset<V> (visited) << " ";
			// cout << bitset<V> (1<<i) << endl;
			if ((visited&(1<<i)))
			{
				continue;
			}
			if (graph[current_node][i])
			{
				pq.push(make_pair(graph[current_node][i], make_pair(i, current_node)));
			}
		}
		pi top = pq.top();
		while((visited&(1<<top.second.first)))
		{
			pq.pop();
			top = pq.top();
		}
		
		visited = (visited|(1<<top.second.first));
		cost += top.first;
		cout << top.second.second+1 << "->" << top.second.first+1 << ":" << top.first << endl;
		pq.pop();
		current_node = top.second.first;
	}
	cout << endl << cost << endl;
}
