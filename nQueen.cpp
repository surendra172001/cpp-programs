#include<bits/stdc++.h>
using namespace std;

int board[11][11]; 

void print(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
    }
    cout << endl;
}

bool isPossible(int n,int row, int column) {
    // checking column wise
    for (int r = row - 1; r >= 0; r--) {
        if (board[r][column] == 1) {
            return false;
        }
    }

    // checking across left diagonal
    for (int r = row - 1, c = column - 1; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 1) {
            return false;
        }        
    }

    // checking across right diagonal
    for (int r = row - 1, c = column + 1; r >= 0 && c < n; r--, c++) {
        if (board[r][c] == 1) {
            return false;
        }        
    }
    return true;
}

void nQueenHelper(int n, int row) {
    if (row == n) {
        print(n);
    }
    else if (row < n) {
        for (int i = 0; i < n; i++) {
            if (isPossible(n, row, i)) {
                board[row][i] = 1;
                nQueenHelper(n, row + 1);
                board[row][i] = 0;
            }
        }
    }
}

inline void placeNqueens(int n) {
    nQueenHelper(n, 0);
}

int main() {
    int n = 0;
    cin >> n;
    memset(board, 0, n * n * sizeof(int));
    placeNqueens(n);
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

typedef pair< int, int > pos;
typedef vector< pos > capture;

capture *ptr = NULL;

int *positions = NULL;

void createVector(int size) {
    ptr = new capture [size];
    positions = new int [size];
}

void destroy_vector(int size) {
    for (int i = 0; i < size; i++)
        ptr[i].clear();
    delete [] ptr;
    delete [] positions;
}

void Mark(int row, int col, int size) { 
    for (int i = 0; i < size; i++)
        ptr[row].push_back(make_pair(row, i));

    int k = 1;
    for (int r = row + 1; r < size; r++) {
        if (col - k >= 0)
            ptr[row].push_back(make_pair(r, col - k));

        ptr[row].push_back(make_pair(r, col));

        if (col + k < size)
            ptr[row].push_back(make_pair(r, col + k));

        k++;
    }
}

void print(int size) {
    for (int i = 0; i < size; i++) {
        int j = 0;
        while(j < size) {
            if (j == positions[i])
                cout << 1 << " ";
            else 
                cout << 0 << " ";
            j++;
        }
    }
    cout << endl;
}

void update(int row, int col, int size) {
    positions[row] = col;
    Mark(row, col, size);
}

void Nqueen(int row, int size) {
    if (row < size) {
        if (row - 1 >= 0) {
            // checking for positions in row
            for (int i = 0; i < size; i++) {
                int r = row - 1;
                bool flag = false;
                // checking that position is captured or not by the queens of previous rows                 
                while (r >= 0 && !flag) {
                    capture::iterator it = ptr[r].begin();
                    for (; it != ptr[r].end(); it++) {
                        if (it->first == row && it->second == i) {
                            flag = true;
                            break;
                        }
                    }
                    r--;                    
                }
                if (!flag) {
                    update(row, i, size);
                    if (row == size - 1) {
                        print(size);
                        break;
                    }
                    Nqueen(row + 1, size);
                    ptr[row].clear();
                }                
            }
        }
        else {
            for (int i = 0; i < size; i++){
                update(row, i, size);
                Nqueen(row + 1, size);
                ptr[row].clear();
            }
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    createVector(n);

    Nqueen(0, n);

    destroy_vector(n);

    return 0;
}


*/