#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
struct pos;
typedef unordered_map<char, pos> um;


struct pos {
	int r, c;
	pos() {
		r = c = -1;
	}
};



bool get_ans(string *mat, vector<bool> *vis_pos, pos start, char ch, int r, int c, int &len, int n, int m) {
	// if this statement is false then ch == mat[r][c] and position is valid
	if (r < 0 || c < 0 || r >= n || c >= m || ch != mat[r][c]) return 0;

	// if the position is already visited then there is a cycle (from first statement and from this statement)
	if (vis_pos[r][c]) {
		// if length of cycle is greater then or eqaul to four then cycle is valid otherwise invalid
		if (len >= 4 && (start.r == r && start.c == c)) {
			return 1;
		}
		else return 0;
	}

	// if none of the above cases are true there is no cycle detected till now and
	// ch == mat[r][c] and this position is visited for the first time, so mark it visited and 
	// increses the len
	vis_pos[r][c] = 1;
	len++;

	// check for adjacent positions which lead to a valid cycle
	if (get_ans(mat, vis_pos, start, ch, r, c + 1, len, n, m)) return 1;
	if (get_ans(mat, vis_pos, start, ch, r + 1, c + 1, len, n, m)) return 1;
	if (get_ans(mat, vis_pos, start, ch, r + 1, c, len, n, m)) return 1;
	if (get_ans(mat, vis_pos, start, ch, r + 1, c - 1, len, n, m)) return 1;
	if (get_ans(mat, vis_pos, start, ch, r, c - 1, len, n, m)) return 1;
	if (get_ans(mat, vis_pos, start, ch, r - 1, c - 1, len, n, m)) return 1;
	if (get_ans(mat, vis_pos, start, ch, r - 1, c, len, n, m)) return 1;
	if (get_ans(mat, vis_pos, start, ch, r - 1, c + 1, len, n, m)) return 1;

	// if none of the adjacent positions lead to a valid cycle then this position will not lead to a valid cycle
	// so marking it as unvisited and
	// decrementing the len since this position is not contributing to the cycle

	vis_pos[r][c] = 0;
	len--;
	return 0;
}




bool isThereAnyCycle(string *mat, int n, int m) {
	char ch;
	
	bool ans = 0;

	// To keep track of all the positions that are already visited for a particular character
    vector<bool> visited[n], temp(n, 0);
    for (int i = 0; i < n; i++) {
        visited[i] = temp;
    }

	// finding all the distinct characters in the matrix
	unordered_map<char, bool> included;

	for (int i = 65; i <= 90; i++) {
		ch = (char) i;
		included['ch'] = 0;
	}

	string char_list;

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < m; j++) {
			if (!included[mat[i][j]]) {
				included[mat[i][j]] = 1;
				char_list += mat[i][j];
			}
		}
		
	}
	
	// checking for cycle for each of the distinct character present in the matrix until a cycle is found
	l = char_list.length();
	for (int i = 0; i < l; i++) {
		ch = char_list[i];

		for (int i = 0; i < n; i++) {
			
			for (int j = 0; j < m; j++) {
				if ((ch == mat[i][j]) && !visited[i][j]) {
					// visited positions for the given character during dfs
					vector<bool> vis_pos[n], temp(n, 0);
					for (int i = 0; i < n; i++) {
						vis_pos[i] = temp;
					}
                    
					// len -> length of cycle
					int len = 0;
					// start -> First position of the cycle required to detect the cycle when last element is reached
					pos start;
					start.r = i, start.c = j;
					if (get_ans(mat, visited, start, ch, i, j, len, n, m)) {
						ans = 1;
						break;
					}	
					visited[i][j] = 1;
				}			
			}
			
		}
	}

	return ans;
}






int solve(char board[][MAXN],int n, int m) {
	string mat[n];

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < m; j++) {
			mat[i] += board[i][j];
		}
		
	}

	return (int) isThereAnyCycle(mat, n, m);
	
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string *mat = new string [n];

    char ch;

    for (int i = 0; i < n; i++) {
    	
    	for (int j = 0; j < m; j++) {
    		cin >> ch;
    		mat[i] += ch;
    	}
    	
    }
    
    cout << isThereAnyCycle(mat, n, m) << "\n";

    delete [] mat;

    return 0;
}
