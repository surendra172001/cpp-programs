#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int get_min_vertex(bool *visited, int *distance, int V) {
	int min_vertex = -1;

	for (int i = 0; i < V; i++) {
		if ((!visited[i]) && ((min_vertex == -1) || distance[i] < distance[min_vertex])) {
			min_vertex = i;
		}
	}
	
	return min_vertex;
}


void dijkstras(int **edge, int V) {
	bool *visited = new bool [V]();
	int *distance = new int [V];

	distance[0] = 0;
	for (int i = 1; i < V; i++) {
		distance[i] = INT_MAX;
	}

	for (int i = 0; i < V - 1; i++) {
		int min_vertex = get_min_vertex(visited, distance, V);
		visited[min_vertex] = true;

		for (int  j = 0; j < V; j++) {
			if (min_vertex == j) continue;
			if (edge[min_vertex][j] && (!visited[j])) {
				if ((edge[min_vertex][j] + distance[min_vertex]) < distance[j]) {
					distance[j] = edge[min_vertex][j] + distance[min_vertex];
				}
			}
		}
		
	}

	for (int i = 0; i < V; ++i) {
		cout << i << " " << distance[i] << "\n";
	}
	
	delete [] visited;
	delete [] distance;
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
    
    dijkstras(edge, V);

    for (int i = 0; i < V; i++) {
    	delete [] edge[i];
    }
    delete [] edge;

    return 0;
}

