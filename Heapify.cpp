#include<iostream>
using namespace std;

void print(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

inline int left(int curr) {
	return (2 * curr + 1);
}


inline int right(int curr) {
	return (2 * curr + 2);
}


inline int parent(int curr) {
	return (curr - 1) / 2;
} 


void swap(int &a, int &b) {
	int t  = a;
	a = b;
	b = t;
}





// ############################################### //
// ############################################### //

// K_th max in arry using heap

void max_heapify(int *arr, int start, int size) {
	int largest = start;
	int l = left(start);
	int r = right(start);
	
	if (l < size && arr[l] > arr[start]) {
		largest = l;
	}
	
	if (r < size && arr[r] > arr[largest]) {
		largest = r;
	}
	
	if (largest != start) {
		swap(arr[largest], arr[start]);
		max_heapify(arr, largest, size);
	}
}


void extract_max(int *arr, int &size) {
	if (size != 0) {
		int ans = arr[0];
		arr[0] = arr[size - 1];
		size--;
		max_heapify(arr, 0, size);
	}
	else {
		cout << "Underflow\n";
	}
}


int get_kth_max(int *arr, int p, int n) {
	if (p == 1) {
		return arr[n];
	}
	else {
		extract_max(arr, n);
		max_heapify(arr, 0, n);
		return get_kth_max(arr, p - 1, n);
	}
}


// ############################################### //
// ############################################### //


void increase_key(int *arr, int old_key, int new_key, int size) {	
	int it = 0;
	while (arr[it] != arr[old_key] && it <= size) {
		it++;
	}
	
	if (it < size) {
		arr[it] = new_key;
		int p = parent(it);
		while (it > 1 && arr[p] < arr[it]) {
			swap(arr[it], arr[p]);
			it = p;
			p = parent(it);
		}
	}
}


void build_max_heap(int *arr, int size) {
	int mid = size / 2;
	for (int i = mid; i >= 0; i--) {
		max_heapify(arr, i, size);
	}
}



int get_max(int *arr, int size) {
	if (size > 0) {
		return arr[0];
	}
	else {
		return -1;
	}
}


void heap_sort(int *arr, int size) {
	int t_size = size - 1;
	while (t_size >= 2) {
		swap(arr[t_size--], arr[0]);
		max_heapify(arr, 0, t_size);
	}
}



int main() {
	int n;
	cin >> n;
	int *arr = new int [n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	build_max_heap(arr, n);
	// print(arr, n);
	// cout << get_max(arr, n) << endl;
	// extract_max(arr, n);
	// cout << get_max(arr, n) << endl;
	// print(arr, n);
	// heap_sort(arr, n);
	// print(arr, n);
	// increase_key(arr, 9, 15, n);
	print(arr, n);
	int k;
	cin >> k;
	cout << get_kth_max(arr, k, n) << "\n";
	print(arr, n);

	delete [] arr;
	return 0;
}


               