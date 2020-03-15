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

        for (vector<int>::iterator it = edges[i].begin(); it != edges[i].end(); it++) {
            cout << (*it) + 1 << " ";
        }
        cout << "\n";
    }
}


bool isBottom(vec *edges, vector<bool> &visited, us *comp, int src) {
    // marking the source as visited
    visited[src] = 1;

    // checking if any of the adjacent vertices of the source doesn't belongs to the SCC
    // to which the source belongs
    for (vec::iterator it = edges[src].begin(); it != edges[src].end(); it++) {
        // if it is so then given SCC is not a bottom so return false
        if (comp->find(*it) == comp->end()) {
            return false;
        }

        // if the current vertex belongs to the same SCC as that of the source ans
        // if it is not visited through some other as the source then
        // Make it as source and do the same thing what we have done above for its adjacent vertices
        if (!visited[*it]) {
            if (!isBottom(edges, visited, comp, *it)) return false;
        }
    }

    // if all the vertices adjacent to the source belongs to the same SCC as that of the source
    // Then return true
    return true;
}


set<int>* getBottom(vec* edges, uus *components, int n) {
    // using set
    set<int> *bottoms = new set<int>();

    // Iterating through all the SCC and checking if it is a bottom or not
    for (uus::iterator it1 = components->begin(); it1 != components->end(); it1++) {
        // Visited vector to keep track of the visited vertices
        vector<bool> visited(n, 0);

        // Initially assuming that the current SCC is a bottom
        bool ans = 1;

        // Then going to each vertex of current SCC to check whether the current SCC is bottom or not
        for (us::iterator it2 = (*it1)->begin(); it2 != (*it1)->end(); it2++) {
             
            // Checking if it the current vertex fullfills all the requirement for the current SCC to be bottom
            if (!isBottom(edges, visited, (*it1), *it2)) {

                // if the current fails to satisfy all the reqiurements 
                // then current SCC is not a bottom so assumption is wrong
                // marking current SCC as not a bottom and going out of the loop
                // becuase there is no need to check for the rest of the vertices
                ans = 0;
                break;
            }
        }

        if (ans) {
            // if current SCC is a bottom then inserting its all the vertices in the bottom set one by one
            for (us::iterator it2 = (*it1)->begin(); it2 != (*it1)->end(); it2++) {
                bottoms->insert(*it2);
            }
        }
    }

    return bottoms;
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

    while (1) {
        cin >> v;
        if (!v) break;
        cin >> e;
        vec *edges = new vec[v];
        vec *edgesT = new vec[v];
        
        int a, b;

        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            // possibility of changes
            edges[a - 1].push_back(b - 1);
            edgesT[b - 1].push_back(a - 1);
        }

        // getting strongly connected components
        uus *components = getSCC(edges, edgesT, v);

        // The bottoms will one of the strongly connected components
        // Because all bottoms are strongly connected components but all strongly connected components are not bottoms
        // getting bottoms in a set because it was asked in the question to print the elements in all the bottoms in sorted order
        // set stl is implemented using self-balancing BST. 
        // so its traversal will give the elements in sorted order
        set<int> *bottoms = getBottom(edges, components, v);

        // Printing the elements in sorted order
        for (set<int>::iterator it = bottoms->begin(); it != bottoms->end(); it++) {
            cout << (*it) + 1 << " ";
        }
        cout << "\n";
        deleteComponents(components);

        delete bottoms;

        delete [] edges;
        delete [] edgesT;
    }
    return 0;
}