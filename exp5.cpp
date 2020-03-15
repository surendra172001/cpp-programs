#include<bits/stdc++.h>
using namespace std;
#define MOD 			1000000007
#define ll 				long long

struct node {
	int diff, int val;
	node() {
		diff = val = 0;
	}
};

void build(int *arr, node *st, int s, int e, int index) {
	if (s > e) return;
	if (s == e) {
		st[index] = arr[s];
		return;
	}

	st[index].val = st[2*index].val + st[2*index+1].val;
}


void update(node *st, int s, int e, int ind, int diff, int treeNode) {
	if (st[treeNode].diff != 0) {
		st[treeNode].val += st[treeNode].diff;
		int lc = 2*treeNode, rc = 2*treeNode+1;
		st[lc].diff += st[treeNode].diff;
		st[rc].diff += st[treeNode].diff;
		st[treeNode].diff = 0;		
	}
	if (i < s || i > e) return;

	// when start == end then ind == s.
	st[ind].val += diff;

	if (s != e) {
		int mid = (s+e)/2;
		update(st, s, mid, ind, diff);
		update(st, mid+1, e, diff);
	}
}

int query(node *st, int s, int e, int qs, int qe, int treeNode) {
	if (st[treeNode].diff != 0) {
		st[treeNode].val += st[treeNode].diff;
		int lc = 2*treeNode, rc = 2*treeNode+1;
		st[lc].diff += st[treeNode].diff;
		st[rc].diff += st[treeNode].diff;
		st[treeNode].diff = 0;	
	}

	if (qe < s || qs > e) return 0;

	if (qs <= s && e <= qe) return st[treeNode].val;

	int mid = (s+e)/2;

	int left = query(st, s, mid, qs, qe, 2*treeNode);
	int right = query(st, mid + 1, e, qs, qe, 2*treeNode + 1);
	return left + right;
}


int main() {
	int n;
	cin >> n;

	int *arr = new int [n];
	node *tree = new node [4*n+1];

	for (int i = 0; i<n; i++) cin >> arr[i];


	delete [] arr;
	delete [] tree;
    return 0;
}