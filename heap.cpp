#include<iostream>
using namespace std;

#define MAX 20

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void insert_MH(int max_heap[], int value, int &last) {
	max_heap[++last] = value;
	int curr = last, parent;
	while (curr > 0) {
		parent = (curr - 1) / 2;
		if (max_heap[parent] < max_heap[curr]) {
			swap(max_heap[parent], max_heap[curr]);
				curr = parent;
		}
		else {
			break;
		}
	} 
}

void extract_MH(int max_heap[], int &last_pos) {
	if (last_pos >= 0) {
		int last = max_heap[last_pos--];
		max_heap[0] = last;
		int curr_pos = 0, l_child = 2 * curr_pos + 1, r_child = l_child + 1;
		while(l_child < last_pos) {
			if (max_heap[curr_pos] > max_heap[l_child] && max_heap[curr_pos] > max_heap[r_child]) {
				break;
			}
			else if (max_heap[curr_pos] < max_heap[l_child]) {
				swap(max_heap[curr_pos], max_heap[l_child]);
				curr_pos = l_child;
			}
			else if (max_heap[curr_pos] < max_heap[r_child]) {
				swap(max_heap[curr_pos], max_heap[r_child]);
				curr_pos = r_child;
			}
			l_child = 2 * curr_pos + 1;
			r_child = l_child + 1;
		}
	}
}

void print(int max_heap[], int last_pos) {
	for (int i = 0; i <= last_pos; ++i) {
		cout << max_heap[i] << " ";	
	}
	cout << endl;
}

int main() {
	int max_heap[MAX], last = -1;
	int choice = 4;
	while(1) {
		cout << "Enter\n";
		cout << "1: Insert\n";
		cout << "2: Delete\n";
		cout << "3: Print\n";
		cout << "4: Exit\n";
		cin >> choice;
		if (choice == 4) {
			break;
		}
		switch(choice) {
			case 1:
				int value;
				cout << "Enter the value\n";
				cin >> value;
				insert_MH(max_heap, value, last);
				break;
			case 2:
				extract_MH(max_heap, last);
				break;
			case 3:
			print(max_heap, last);
				break;
		}
	}
	return 0;
}