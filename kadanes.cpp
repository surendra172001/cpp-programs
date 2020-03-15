#include<bits/stdc++.h>
using namespace std;

int kadanes(int *arr, int size) {
	int min_till_now = 0;
	int max_end_here = 0, best_so_far = INT_MIN;
	for (int i = 0; i < size; i++) {
		if (arr[i] < min_till_now) {
			min_till_now = arr[i];
		}
		max_end_here += arr[i];
		if (max_end_here > best_so_far) {
			best_so_far = max_end_here;
		} 

		if (max_end_here <= min_till_now) {
			max_end_here = 0;
		}
	}
	return best_so_far;
}

int main() {
	int length = 0;
	cin >> length;
	int *arr = new int[length];

	for (int i = 0; i < length; i++) {
		cin >> arr[i];
	}
	int bs = 0, be = 0, as = 0, ae = -1;
	int max_end_here = 0, best_so_far = 0;
	for (int i = 0; i < length; i++) {
		max_end_here += arr[i];
		ae++;
		if (max_end_here > best_so_far) {
			best_so_far = max_end_here;
			bs = as;
			be = ae;
		}
		if (max_end_here < 0) {
			max_end_here = 0;
			as = i + 1;
			ae = i;
		}
	}
	cout << best_so_far << endl;
	cout << bs << " " << be << endl;
	cout << kadanes(arr, length) << endl;
	delete [] arr;
	return 0;
}


