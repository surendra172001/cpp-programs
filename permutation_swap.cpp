#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;




void findIslandUtil(vector<int> *A, vector<int> *visited, int N, int M, int i, int j) {
    if (i < 0 || j < 0 || i >= N || j >= M || visited[i][j] || (A[i][j] == 0)) {
        return;
    }
    
    visited[i][j] = 1;
    findIslandUtil(A, visited, N, M, i, j + 1);
    findIslandUtil(A, visited, N, M, i + 1, j + 1);
    findIslandUtil(A, visited, N, M, i + 1, j);
    findIslandUtil(A, visited, N, M, i + 1, j - 1);
    findIslandUtil(A, visited, N, M, i, j - 1);
    findIslandUtil(A, visited, N, M, i - 1, j - 1);
    findIslandUtil(A, visited, N, M, i - 1, j);
    findIslandUtil(A, visited, N, M, i - 1, j + 1);
}




int findIslands(vector<int> A[], int N, int M) {
    vector<int> visited[N], temp(M, 0);
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        visited[i] = temp;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((!visited[i][j]) && A[i][j]) {
                count++;
                findIslandUtil(A, visited, N, M, i, j);
            }
        }
    }
    
    return count;
}





void dfs(list<int> *edge, bool *visited, int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		visited[curr] = true;

		for (list<int>::iterator it = edge[curr].begin(); it != edge[curr].end(); it++) {
			if (!visited[*it]) {
				q.push(*it);
			}
		}
		
	}
}


int get_connected_comp(list<int> *edge, int m) {
	bool *visited = new bool [m]();

	int count = 0;
	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			count++;
			dfs(edge, i);
		}
	}

	delete [] visited;
	return count;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    list<int> *edge = new list<int>[n];
    int u, v;
    for (int i = 0; i < m; i++) {
    	cin >> u >> v;
    	edge[u].push_back(v);
    	edge[v].push_back(u);
    }
    
    cout << get_connected_comp(edge, m) << "\n";

    delete [] edge;

    return 0;
}