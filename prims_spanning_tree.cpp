#include <bits/stdc++.h>
using namespace std;
#define V 5
#define INF numeric_limits<int>::max()
int main(){
	/*
	int graph[V][V] =
	{
	{0,0,5,8,4},//
	{0,0,2,0,1},
	{5,2,0,3,4},
	{8,0,3,0,4},
	{4,1,4,4,0}
	};
	*/
	int graph[V][V] = {
	  {0, 9, 75, 0, 0},
	  {9, 0, 95, 19, 42},
	  {75, 95, 0, 51, 66},
	  {0, 19, 51, 0, 31},
	  {0, 42, 66, 31, 0}
  };
	int weight[V];
	int node = 0;
	memset(weight, INF,V);
	
	while(node < V - 1){
		int short_node = INF;
		int current_node = node;
		for(int i = node; i < V; i++){
			int current_weight = graph[i][node];
			if(current_weight){
				weight[i] = min(weight[i], current_weight);
				if(current_weight < short_node){
					short_node = current_weight;
					current_node = i;
				}
			}
		}
		cout << node <<" --> "<< current_node << " " <<": " << short_node << endl;
		node++;
	}
}
