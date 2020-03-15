#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;


bool bipartiateUtil(vi *edges, vb &visited, int src) {
    // Two sets
    unordered_set<int> colorSet[2];
    // inserting the first element in first set
    colorSet[0].insert(src);
    // Stores the vertices that are yet to be visited
    vi pendingVertices;

    // marking the source as discovered and ready to be visited
    pendingVertices.push_back(src);

    while (!pendingVertices.empty()) {
        // getting the vertex to be visited now
        int curr = pendingVertices.back();
        pendingVertices.pop_back();
        /*
            Here we are removing the last element of the vector because it is constant time operation.
            Removal from the front will take O(n) time which is costly
        */

        // getting the set of the current vertex
        int currSet = (colorSet[0].count(curr) > 0 ? 0 : 1);

        // marking the current vertex as visited
        visited[curr] = 1;

        // number of  vertices adjacent to the current vertex
        int l = edges[curr].size();

        for (int i = 0; i < l; i++) {
            // current neighbour
            int neighbour = edges[curr][i];

            // if nieghbour is not there in both the sets i.e it is discovered
            if ((colorSet[1].count(neighbour) == 0) && (colorSet[0].count(neighbour) == 0)) {
                // Inserting the neighbour in the set other than the set of current vertex
                colorSet[1 - currSet].insert(neighbour);
                // marking the neighbour as a pending vertex that is yet to be visited
                pendingVertices.push_back(neighbour);
            }
            // if the nieghbour is already discovered
            // checking if it is present in the set of the current vertex
            // if it is so then graph is non colorable
            else if (colorSet[currSet].count(neighbour) > 0) {
                return false;
            }
            // if the nieghbour is already discovered and
            // not present in the set of the current vertex then 
            // we don't need to do anything with it check for rest of the neighbours
        }
        
    }

    // if control reaches here then current connected component is colorable

    return true;
}


bool bipartiate(vi *edges, int n) {
    // if no vertices are there in the graph then it is colorable
    if (n == 0) return true;

    // mainting visited vector in case graph is disconnected
    vb visited(n, 0);

    // checking for each connected component that it is colorable or not
    for (int i = 0; i < n; i++) {
        // if ith vertex is unvisited then it is treated as the source of the current connected component
        if (!visited[i]) {
            // if any of the connected component is incolorable then graph is incolorable
            if (!bipartiateUtil(edges, visited, i)) {
                return false;
            }
        }
    }

    // if control reaches here then graph is colorable;
    return true;
}


int main() {

    while (1) {
        int v, e;
        cin >> v;
        if (!v) break;
        cin >> e;

        vi *edges = new vi[v];

        int sv, ev;
        for (int i = 0; i < e; i++) {
            cin >> sv >> ev;
            edges[sv].push_back(ev);
            edges[ev].push_back(sv);
        }

        bool ans = bipartiate(edges, v);

        delete [] edges;

        if (ans) cout << "COLOURABLE\n";
        else cout << "INCOLOURABLE\n";

    }

    return 0;
}