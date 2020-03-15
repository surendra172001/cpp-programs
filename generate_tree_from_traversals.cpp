#include<iostream>
using namespace std;

struct node {
	int data;
	node *left, *right;
	node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
};
	
node* get_node(int data) {
	node *new_node = new node();
	new_node->data = data;
	return new_node;
}


node* generate_tree_1(int *inorder, int *order_arr, int size, int &node_count) {
	if (size <= 0) {
		return NULL;
	}
	if (size == 1) {
		node_count++;
		return get_node(inorder[0]);
	}
	int key = order_arr[node_count], index = 0;
	node_count++;

	for (int i = 0; i < size; i++) {
		if (inorder[i] == key) {
			index = i;
			break;
		}
	}
	
	node *new_node = get_node(key);
	new_node->left = generate_tree_1(inorder, order_arr, index, node_count);
	new_node->right = generate_tree_1(inorder + index + 1, order_arr, size - index - 1, node_count);
	return new_node;
}


node* generate_tree_2(int *inorder, int *order_arr, int size, int &node_count, int t_size) {
	if (size <= 0) {
		return NULL;
	}
	if (size == 1) {
		node_count++;
		return get_node(inorder[0]);
	}
	int key = order_arr[t_size - node_count - 1], index = 0;

	for (int i = size - 1; i >= 0; i--) {
		if (inorder[i] == key) {
			index = i;
		}
	}
	node_count++;
	node *new_node = get_node(key);
	new_node->right = generate_tree_2(inorder + index + 1, order_arr, size - index - 1, node_count, t_size);
	new_node->left = generate_tree_2(inorder, order_arr, index, node_count, t_size);
	return new_node;
}

void pre_order(node *root) {
	if (root != NULL) {
		cout << root->data << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
}



void delete_tree(node *root) {
	if (root != NULL) {
		delete_tree(root->left);
		delete_tree(root->right);
		delete root;
		root = NULL;
	}
}

void post_order(node *root) {
	if (root != NULL) {
		post_order(root->left);
		post_order(root->right);
		cout << root->data << " ";
	}
}

int main() {
	int n;
	cout << "Enter the total number of elements in the tree\n";
	cin >> n;

	int *inorder = new int [n];
	int *order_arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> order_arr[i];
	}

	int node_count = 0;
	// node *root = generate_tree_1(inorder, order_arr, n, node_count);

	// post_order(root);

	node *root = generate_tree_2(inorder, order_arr, n, node_count, n);
	pre_order(root);

	delete_tree(root);

	delete [] inorder;
	delete [] order_arr;
    return 0;
}