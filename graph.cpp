// Adjacency matrix


#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


class graph {
	int v;
	int **edges;
public:
	graph(int v);
	void add_edge(int, int);
	void BFS(int);
	void DFS(int);
	~graph();
};


graph::graph(int v) {
	this->v = v;

	edges = new int*[v + 1];
	for (int i = 0; i <= v; i++) {
		edges[i] = new int[v + 1];
		for (int j = 0; j <= v; j++) {
			edges[i][j] = 0;
		}
	}
}


inline void graph::add_edge(int start, int end) {
	if ((start <= v && start >= 0) && (end <= v && end >= 0) && (edges[start][end] != 1)) {
		edges[start][end] = 1;
		edges[end][start] = 1;
	}
}

void graph::BFS(int start) {
	bool *visited = new bool[v + 1];

	for (int i = 0; i <= v; i++) {
		visited[i] = false;		
	}

	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		cout << a << " ";

		for (int i = 0; i <= v; i++) {
			if (a == i) continue;
			if (edges[a][i] == 1 && (!visited[i])) {
				q.push(i);
				visited[i] = true;
			}
		}
		
	}
    
    // if graph is disconnected
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            cout << i << " ";
            visited[i] = true;
        }
    }

	delete [] visited;
}

void graph::DFS(int start) {
	bool *visited = new bool[v + 1];

	for (int i = 0; i <= v; i++) {
		visited[i] = false;
	}

	stack<int> s;
	s.push(start);
	visited[0] = true;
	while (!s.empty()) {
		int a = s.top();
		s.pop();
		cout << a << " ";

		for (int i = 0; i <= v; i++) {
			if (a == i) continue;
			if (edges[a][i] == 1 && (!visited[i])) {
				s.push(i);
				visited[i] = true;
			}
		}
		
	}

	delete [] visited;
}


graph::~graph() {
	for (int i = 0; i <= v; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, start;
    cin >> v >> e;

    graph g1(v);

    for (int i = 0; i < e; i++) {
    	int f, s;
    	cin >> f >> s; 
    	g1.add_edge(f, s);
    }
    
    // cout << "\nDFS\n";
    g1.DFS(0);
    // cout << "\nBFS\n";
    // g1.BFS(0);
    return 0;
}