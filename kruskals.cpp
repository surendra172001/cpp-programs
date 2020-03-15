#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

struct edge {
	// start vertex, end vertex, weight
	int sv, ev, w;
};


inline bool cmp(edge a, edge b) {
	return (a.w < b.w);
}

int top_most_parent(int *parent, int v) {
	int it = v;
	while (it != parent[it]) {
		it = parent[it];
	}
	return it;
}

void MST_kruskal(edge *input, int V, int E) {
	sort(input, input + E, cmp);

	int *parent = new int [V];

	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}

	edge *output = new edge [V - 1];
	int edge_cnt = 0, it = 0;

	while (edge_cnt < V - 1) {
		int s = input[it].sv, e = input[it].ev;
		int src_p = top_most_parent(parent, s), des_p = top_most_parent(parent, e);
		if (src_p != des_p) {
			parent[des_p] = src_p;
			if (s <= e) {
				output[edge_cnt].sv = s;
				output[edge_cnt].ev = e;
			}
			else {
				output[edge_cnt].sv = e;
				output[edge_cnt].ev = s;
			}
			output[edge_cnt].w = input[it].w;
			edge_cnt++;
		}
		it++;
	}
	

	for (int i = 0; i < V - 1; i++) {
		cout << output[i].sv << " " << output[i].ev << "\n";
	}
	

	delete [] output;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    edge *input = new edge [E];

    for (int i = 0; i < E; i++) {
    	cin >> input[i].sv >> input[i].ev >> input[i].w;	
    }
    
    MST_kruskal(input, V, E);

    delete [] input;
    return 0;
}