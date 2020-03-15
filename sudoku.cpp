#include<bits/stdc++.h>
using namespace std;

#define N 9
int grid[N][N];

bool findEmptyPosition(int &row,int &col) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[N][N] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    cout << "sudoku\n";
    return false;
}

bool isSafeInRow(int row, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeInCol(int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool isSafeInGrid(int row, int col, int num) {
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + rowFactor][j + colFactor] == num) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int row, int col, int num) {
    return (isSafeInRow(row, num), isSafeInCol(col, num), isSafeInGrid(row, col, num));
}

bool solveSudoku() {
    int row, col;
    if (!findEmptyPosition(row, col)) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(row, col, i)) {
            grid[row][col] = i;
            if (solveSudoku()) {
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}


