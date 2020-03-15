#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


int get_min_vertex(int *weight, bool *visited, int V) {
	int min_vertex = -1;

	for (int i = 0; i < V; i++) {
		if ((!visited[i]) && ((min_vertex == -1) || weight[i] < weight[min_vertex])) {
			min_vertex = i;
		}
	}
	
	return min_vertex;
}


void prims(int **edge, int V, int E) {
	bool *visited = new bool [V]();
	int *parent = new int [V];
	int *weight = new int [V];

	weight[0] = 0;
	for (int i = 1; i < V; i++) {
		weight[i] = INT_MAX;
	}

	parent[0] = -1;

	for (int i = 0; i < V - 1; i++) {
		int min_vertex = get_min_vertex(weight, visited, V);
		visited[min_vertex] = true;
		for (int j = 0; j < V; j++) {
			if (min_vertex == j) continue;
			if ((edge[min_vertex][j]) && (!visited[j])) {
				if (weight[j] > edge[min_vertex][j]) {
					weight[j] = edge[min_vertex][j];
					parent[j] = min_vertex;
				}
			}
		}
		
	}

	for (int i = 1; i < V; i++) {
		if (i < parent[i]) {
			cout << i << " " << parent[i] << " " << weight[i] << "\n";
		}
		else {
			cout << parent[i] << " " << i  << " " << weight[i] << "\n";
		}
	}

	delete [] visited;
	delete [] parent;
	delete [] weight;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    int **edge = new int *[V];

    for (int i = 0; i < V; i++) {
    	edge[i] = new int [V];
    }
    
    int start, end, weight;
    for (int i = 0; i < E; i++) {
		cin >> start >> end >> weight;
		edge[start][end] = weight;
		edge[end][start] = weight;
    }
    
    prims(edge, V, E);

    for (int i = 0; i < V; i++) {
    	delete [] edge[i];
    }
    delete [] edge;

    return 0;
}
