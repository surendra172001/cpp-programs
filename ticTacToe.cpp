#include<bits/stdc++.h>
using namespace std;


#define IO          ios::sync_with_stdio(0);
#define MOD 		1000000007
#define MAX			1000001
#define ll 			long long
#define nl 			cout << "\n";
#define mp 			make_pair
#define fi   		first
#define se 			second
#define dbg         cout << "Debug...\n";
#define prt(a)      cout << a << "\n";
#define p(a, b) 	pair< a, b >
#define vi			vector<int>
#define vb 			vector<bool>
#define w_is(a)     cerr << #a << " " << a << "\n";


#define pi          2*acos(0.0)

/*
lamda functions

[] (int a, int b) {return a > b;}

*/



/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction


bool check(char board[3][3], char curr) {
	if (curr == board[1][1]) {
		if(board[0][1] == board[1][1] && board[1][1] == board[2][1]) return true;
		if(board[2][0] == board[1][1] && board[1][1] == board[0][2]) return true;
		if(board[1][0] == board[1][1] && board[1][1] == board[1][2]) return true;
		if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
	}

	if(curr == board[0][0]) {
		if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) return true;
		if(board[0][0] == board[1][0] && board[1][0] == board[2][0]) return true;
	}

	if(curr == board[2][2]) {
		if(board[2][0] == board[2][1] && board[2][1] == board[2][2]) return true;
		if(board[0][2] == board[1][2] && board[1][2] == board[2][2]) return true;
	}
	return false;
}


int evaluate(char board[3][3]) {
	if(check(board, 'x')) return 10;
	if(check(board, 'o')) return -10;
	return 0;
}


bool isMoveLeft(char board[3][3], p(int, int) &pos) {
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(board[i][j] == '_') pos.fi = i, pos.se = j, return true;

	pos.fi = -1, pos.se = -1;
	return false;
}


int moveVal(char board[3][3], int &depth, char player) {
	char nextPlayer = (player == 'x' ? 'o' : 'x');
	int optimumVal = (player == 'x' ? INT_MIN : INT_MAX);

	// created for isMoveLeft function
	p(int, int) pos;
	if(isMoveLeft(board, pos)) {
		for(int i = pos.fi; i < 3; i++) {
			for(int j = pos.se; j < 3; j++) {
				if(board[i][j] == '_') {
					board[i][j] = player;
					int currVal = moveVal(board, depth+1, nextPlayer);
					// if player is maximizer
					if(player == 'x')
						if(optimumVal < currVal) optimumVal = currVal;
					else
						if(optimumVal > currVal) optimumVal = currVal;
				}
			}
		}
	}



	return optimumVal;
}



void findBestMoveForX(char board[3][3]) {
	int bestVal = INT_MIN;
	p(int, int) pos = {-1, -1};
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(board[i][j] == '_') {
				int currVal = moveVal(board, 0, 'x');
				if(currVal > bestVal) {
					pos.fi = i, pos.se = j;
					bestVal = currVal;
				}
			}

	cout << pos.fi << " " << pos.se << "\n";
}



int main() {

	IO

	int t;
	cin >> t;

	char board[3][3];

	while(t--) {
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				cin >> board[i][j];

		findBestMoveForX(board);
	}

	return 0;
}





/*

P - prefix
S - suffix
A - array
X - prefix+suffix => 2*n

*/




/*

conda install -c anaconda pandas
install -c conda-forge opencv

need to uninstall all the pip packages

pip install opencv-contrib-python
conda install -c anaconda pandas


*/