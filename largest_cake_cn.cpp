#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> V;

void findLargestCakePieceUtil(V *A, V *visited, int n, int &size, int i, int j) {
	// if any of the condition is true then position is invalid
	if (i < 0 || j < 0 || i >= n || j >= n || A[i][j] == 0 || visited[i][j]) {
		return;
	}

	// if all the conditions above are false then we are visiting this position for the first time
	// so marking as visited and increase the size of the current piece
	visited[i][j] = 1;
	size++;

	// checking if the adjacent position of the given position increase the size of the current piece or not
	findLargestCakePieceUtil(A ,visited, n, size, i, j + 1);
	findLargestCakePieceUtil(A ,visited, n, size, i + 1, j + 1);
	findLargestCakePieceUtil(A ,visited, n, size, i + 1, j);
	findLargestCakePieceUtil(A ,visited, n, size, i + 1, j - 1);
	findLargestCakePieceUtil(A ,visited, n, size, i, j - 1);
	findLargestCakePieceUtil(A ,visited, n, size, i - 1, j - 1);
	findLargestCakePieceUtil(A ,visited, n, size, i - 1, j);
	findLargestCakePieceUtil(A ,visited, n, size, i - 1, j + 1);
}

int findLargestCakePiece(V *A, int n) {
	// visited matrix to keep track which positions are already visited and temp will be used for marking every element as unvisited
	V visited[n], temp(n, 0);

	// marking all positions as unvisited
	for (int i = 0; i < n; i++) {
		visited[i] = temp;
	}

	// checking for the largest piece of connected positions
	// ans -> to store the size of largest connected piece
	int ans  = 0;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			// if current position is not visited then
			if (!visited[i][j]) {
				int size = 0;
				findLargestCakePieceUtil(A, visited, n, size, i, j);
				// if this piece has size greater then all the pieces found till now then this is new answer
				if (size > ans) {
					ans = size;
				}
			}
		}
		
	}
	 
	return ans; 
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    V A[n];

    char ch;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> ch;
    		A[i].push_back(ch - '0');
    	}
    }
    
    cout << findLargestCakePiece(A, n) << "\n";

    return 0;
}