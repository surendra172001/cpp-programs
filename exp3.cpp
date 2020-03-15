#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<bool> vb;

ll fact[1000001];

void fillFact() {
    fact[0] = fact[1] = 1;
    
    for (int i = 2; i <= 1000000; i++) {
        fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;
    }
    
}


inline bool isValid(int x, int y, int n, int m) {
    return !(x < 0 || y < 0 || x >= n || y >= m);
}


ll getSize(vb *pos, vb *visited, int n, int m, int x, int y) {
    visited[x][y] = 1;
    int size = 1;
    int i = x + 2;
    int j = y + 1;
    if (isValid(i, j, n, m)) {
        if (pos[i][j] && !(visited[i][j])) size += getSize(pos, visited, n, m, i, j);
    }

    i = x + 2;
    j = y - 1;
    if (isValid(i, j, n, m)) {
        if (pos[i][j] && !(visited[i][j])) size += getSize(pos, visited, n, m, i, j);
    }


    i = x - 2;
    j = y + 1;
    if (isValid(i, j, n, m)) {
        if (pos[i][j] && !(visited[i][j])) size += getSize(pos, visited, n, m, i, j);
    }


    i = x - 2;
    j = y - 1;
    if (isValid(i, j, n, m)) {
        if (pos[i][j] && !(visited[i][j])) size += getSize(pos, visited, n, m, i, j);
    }


    i = x - 1;
    j = y + 2;
    if (isValid(i, j, n, m)) {
        if (pos[i][j] && !(visited[i][j])) size += getSize(pos, visited, n, m, i, j);
    }


    i = x + 1;
    j =  y + 2;
    if (isValid(i, j, n, m)) {
        if (pos[i][j] && !(visited[i][j])) size += getSize(pos, visited, n, m, i, j);
    }


    i = x - 1;
    j = y - 2;
    if (isValid(i, j, n, m)) {
        if (pos[i][j] && !(visited[i][j])) size += getSize(pos, visited, n, m, i, j);
    }


    i = x + 1;
    j = y - 2;
    if (isValid(i, j, n, m)) {
        if (pos[i][j] && !(visited[i][j])) size += getSize(pos, visited, n, m, i, j);
    }

    return size;
}


int main() {
    int t;
    cin >> t;
    fillFact();
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vb *pos = new vb[n];
        vb *visited = new vb[n];
        vb temp(m, 0);

        for (int i = 0; i < n; i++) {
            pos[i] = temp;
            visited[i] = temp;
        }

        int sv, ev;
        for (int i = 0; i < q; i++) {
            cin >> sv >> ev;
            pos[sv - 1][ev - 1] = 1;
        }

        int ans = 1;

        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < m; j++) {
                if (pos[i][j] && !visited[i][j]) {
                    int f = getSize(pos, visited, n, m, i, j);
                    ans = (ans * fact[f]) % MOD;
                }
            }
            
        }
        
        cout << ans << "\n";

        delete [] pos;
        delete [] visited;
    }
    return 0;
}