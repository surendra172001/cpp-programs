#include<bits/stdc++.h>
using namespace std;

void print_mat(int **arr, int r, int c) {
	cout << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}



int	max_sum_rectangle(int **matrix, int r, int c) {
	int **sum_matrix = new int *[r];
	for (int i = 0; i < r; ++i) {
		sum_matrix[i] = new int [c];
	}

	sum_matrix[r - 1][c - 1] = matrix[r - 1][c - 1];

	for (int i = c - 2; i >= 0; --i) {
		sum_matrix[r - 1][i] = matrix[r - 1][i] + sum_matrix[r - 1][i + 1];
	}
	for (int i = r - 2; i >= 0; --i) {
		sum_matrix[i][c - 1] = matrix[i][c - 1] + sum_matrix[i + 1][c - 1];
	}

	for (int i = r - 2; i >= 0; --i) {
		for (int j = c - 2; j >= 0; j--) {
			sum_matrix[i][j] = matrix[i][j] + sum_matrix[i + 1][j] + sum_matrix[i][j + 1] - sum_matrix[i + 1][j + 1];
		}
	}
	cout << endl;
    print_mat(sum_matrix, r, c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int max_area_sum = sum_matrix[i][j];
			for (int k = i; k < r - 1; k++) {
				for (int l = j + 1; j < c; j++) {
					int sub_area_sum = sum_matrix[k][l] + sum_matrix[k + 1][j] - sum_matrix[k + 1][l];
					if ((sum_matrix[i][j] - sub_area_sum) > max_area_sum) {
						// cout << "\n ss " << (sum_matrix[i][j] - sub_area_sum) << endl;
						max_area_sum = sum_matrix[i][j] - sub_area_sum;
						// print_mat(sum_matrix, r, c);
					}
					cout << max_area_sum << " ";
				}
				for (int l = j + 1; j < c; j++) {
					if (sum_matrix[r - 1][l] > max_area_sum) {
						max_area_sum = sum_matrix[r - 1][l];
						cout << max_area_sum << " ";
					}
				}
			}
			cout << endl;
			sum_matrix[i][j] = max_area_sum;
			// print_mat(sum_matrix, r, c);
		}
	}	

	print_mat(sum_matrix, r, c);

	int ans = INT_MIN;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (ans < sum_matrix[i][j]) {
				ans = sum_matrix[i][j];
			}
		}
	}
    

	for (int i = 0; i < r; ++i) {
		delete [] sum_matrix[i];
	}
	delete [] sum_matrix;
	return ans;
}


int main() {
	int r, c;
	cin >> r >> c;
	int **matrix = new int *[r];
	for (int i = 0; i < r; i++) {
		matrix[i] = new int [c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}
	
	cout << max_sum_rectangle(matrix, r, c);

	for (int i = 0; i < r; i++) {
		delete [] matrix[i];
	}	
	delete [] matrix;

	return 0;
}

