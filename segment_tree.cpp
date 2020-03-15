#include<bits/stdc++.h>
using namespace std;

void build_tree(int arr[], int tree[], int start, int end, int tree_node) {
	if (start == end) {
		tree[tree_node] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		build_tree(arr, tree, start, mid, 2 * tree_node);
		build_tree(arr, tree, mid + 1, end, 2 * tree_node + 1);	
		tree[tree_node] = tree[2 * tree_node] + tree[2 * tree_node + 1];
	}
}

void update_tree(int arr[], int tree[], int start, int end, int tree_node, int index, int value) {
	if (start == end) {
		arr[index] = value;
		tree[tree_node] = value;
	}
	else {
		int mid = (start + end) / 2;
		if (index <= mid) {
			update_tree(arr, tree, start, mid, 2 * tree_node, index, value);
		}
		else {
			update_tree(arr, tree, mid + 1, end, 2 * tree_node + 1, index, value);	
		}
		tree[tree_node] = tree[2 * tree_node] + tree[2 * tree_node + 1];
	}
}

int query(int tree[], int start, int end, int left, int right, int tree_node) {
	if (right < start || left > end) {
		return 0;
	}
	if (start >= left && end <= right) {
		return tree[tree_node];
	}
	int mid = (start + end) / 2;
	int ans1 = query(tree, start, mid, left, right, 2 * tree_node);
	int ans2 = query(tree, mid + 1, end, left, right, 2 * tree_node + 1);
	return ans1 + ans2;
}


void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	int n = 0; 
	cin >> n;
	int *arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int tree_size = 2 * n;
	int *tree = new int [tree_size];
	tree[0] = 0;
	build_tree(arr, tree, 0, n - 1, 1);
	int start = 0, end = n - 1;

	while (true) {
		cout << "Enter\n";
		cout << "1. To print\n";
		cout << "2. To update\n";
		cout << "3. To raise a query\n";
		cout << "4. To exit\n";
		int n;
		cin >> n; 
		if (n == 4) break;
		switch (n) {
			case 1:
				print(tree, tree_size);
				break;
			case 2:
				cout << "Enter the index and value\n";
				int idx, value;
				cin >> idx >> value;
				update_tree(arr, tree, start, end, 1, idx, value);
				break;
			case 3:
				cout << "Enter the range of the query\n";
				int L, R;
				cin >> L >> R;
				cout << query(tree, start, end, L, R, 1) << endl;
				break;
		}
	}
	cout << "Happy coding\n";
	delete [] arr;
	delete [] tree;
	return 0;
}