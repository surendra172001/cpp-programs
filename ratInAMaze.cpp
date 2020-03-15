#include<bits/stdc++.h>
using namespace std;

int solution[20][20];

void printPath(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << " ";
        }
    }
    cout << endl;
}


void positionExplorer(int maze[][20], int row, int col, int n) {
    if (row == n - 1 && col == n -1) {
        solution[row][col] = 1;
        printPath(n);
        solution[row][col] = 0;
    }
    else if (row >= n || col >= n || row < 0 || col < 0 || maze[row][col] == 0 || solution[row][col] == 1) {
        return;
    }
    else {
        solution[row][col] = 1;
        positionExplorer(maze, row - 1, col, n);
        positionExplorer(maze, row + 1, col, n);
        positionExplorer(maze, row, col + 1, n);
        positionExplorer(maze, row, col - 1, n);
        solution[row][col] = 0;
    }
}



void ratInAMaze(int maze[][20], int n){
    positionExplorer(maze, 0, 0, n);
}

int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  memset(solution, 0, 20 * 20 * sizeof(int));
  ratInAMaze(maze, n);
}
