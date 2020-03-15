#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef unordered_set<int> us;
typedef unordered_set<unordered_set<int>*> uus;


void dfs(vector<int> *edges, vector<bool> &visited, unordered_set<int> *comp, int src) {
	visited[src] = true;
	comp->insert(src);

	for (vector<int>::iterator it = edges[src].begin(); it != edges[src].end(); it++) {
		if (!visited[*it]) {
			dfs(edges, visited, comp, *it);
		}
	}
	
}


uus* connected_components(vector<int> *edges, int n) {
	vector<bool> visited(n, 0);

	uus* components = new uus();

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			us *comp = new us();
			dfs(edges, visited, comp, i);
			components->insert(comp);
		}
	}
	return components;
}

void printGrqph(vector<int> *edges, int v) {
    for (int i = 0; i < v; i++) {

	    for (vector<int>::iterator it = edges[i].begin(); it != edges[i].end(); it++) {
	    	cout << (*it) + 1 << " ";
	    }
    	cout << "\n";
    }
}


void printComponents(uus *components) {

	for (uus::iterator it1 = components->begin(); it1 != components->end(); it1++) {

		for (us::iterator it2 = (*it1)->begin(); it2 != (*it1)->end(); it2++) {
			cout << (*it2) + 1 << " ";
		}
		cout << "\n";
	}
	
}

void deleteComponents(uus *components) {

	for (uus::iterator it1 = components->begin(); it1 != components->end(); it1++) {
		delete (*it1);		
	}
	delete components;
}


int main() {
    cout << "One based indexing\n";

    int v, e;
    cin >> v >> e;

    vector<int> edges[v];

    int a, b;
    for (int i = 0; i < e; i++) {
    	cin >> a >> b;
    	edges[a - 1].push_back(b - 1);
    	edges[b - 1].push_back(a - 1);
    }

    uus *components = connected_components(edges, v);

    printComponents(components);

    deleteComponents(components);

    return 0;
}