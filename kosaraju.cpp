#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef unordered_set<int> us;
typedef unordered_set<unordered_set<int>*> uus;
typedef vector<int> vec;


void dfs(vec *edges, stack<int> &s, vector<bool> &visited, int src) {
    visited[src] = 1;

    for (vec::iterator it = edges[src].begin(); it != edges[src].end(); it++) {
        if (!visited[*it]) {
            dfs(edges, s, visited, *it);
        }   
    }
    s.push(src);
}

void dfsTranspose(vec *edgesT, us *comp, vector<bool> &visited, int src) {
    comp->insert(src);
    visited[src] = true;
    for (vec::iterator it = edgesT[src].begin(); it != edgesT[src].end(); it++) {
        if (!visited[*it]) {
            dfsTranspose(edgesT, comp, visited, *it);
        }
    }
}


uus *getSCC(vec *edges, vec *edgesT, int n) {
    vector<bool> visited(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(edges, s, visited, i);
        }
    }

    uus *output = new uus();

    // marking unvisited for dfs of transposed graph
    visited.clear();
    visited = vector<bool>(n, 0);
    
    while (!s.empty()) {
        int curr = s.top();
        s.pop();
        if (!visited[curr]) {
            us *comp = new us();
            dfsTranspose(edgesT, comp, visited, curr);
            output->insert(comp);
        }
    }
    
    return output;
}


void printGraph(vector<int> *edges, int v) {
    for (int i = 0; i < v; i++) {
        cout << i + 1 << " -> ";
        for (vector<int>::iterator it = edges[i].begin(); it != edges[i].end(); it++) {
            cout << (*it) + 1 << " ";
        }
        cout << "\n";
    }
}


void printComponents(uus* components) {
    for (uus::iterator it1 = components->begin(); it1 != components->end(); it1++) {
        
        for (us::iterator it2 = (*it1)->begin(); it2 != (*it1)->end(); it2++) {
            cout << (*it2) + 1 << " ";
        }
        cout << "\n";
    }
}

void deleteComponents(uus *components) {
    for (uus::iterator it = components->begin(); it != components->end(); it++) {
        delete (*it);       
    }
    delete components;
}

int main() {
    int v, e;
    cin >> v >> e;

    vec *edges = new vec[v];
    vec *edgesT = new vec[v];
    
    int a, b;

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        // possibility of changes
        edges[a - 1].push_back(b - 1);
        edgesT[b - 1].push_back(a - 1);
    }

    // printGraph(edges, v);
    
    uus *components = getSCC(edges, edgesT, v);

    printComponents(components);

    deleteComponents(components);

    delete [] edges;
    delete [] edgesT;
    return 0;
}