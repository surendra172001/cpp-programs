#include<bits/stdc++.h>
using namespace std;



vector<int> getLCS(int *arr, int n) {

	unordered_map<int, bool> m;
	unordered_map<int, int> index;

	for (int i = 0; i < n; i++)
		index[arr[i]] = -1;

	for (int i = 0; i < n; i++) {
		m[arr[i]] = 1;
		if (index[arr[i]] == -1)
			index[arr[i]] = i;
	}

	int minStart = INT_MAX, maxLen = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (m[arr[i]]) {
			m[arr[i]] == 0;
			int startCurr = i, lastNum = arr[i], num = arr[i]+1, len = 1;

			while (m[num]) {
				m[num] = 0;
				len++;
				num++;
			}

			num = arr[i]-1;

			while (m[num]) {
				m[num] = 0;
				len++;
				num--;
			}

			if ((num+1) < lastNum) {
				startCurr = index[num+1];
			}

			if (len > maxLen) {
				minStart = startCurr;
				maxLen = len;
			} else if (len == maxLen) {
				if (startCurr < minStart) {
					minStart = startCurr;
				}
			}
		}
	}

	int num = arr[minStart];

	vector<int> lcs(maxLen, 0);
	for (int i = 0; i < maxLen; i++) {
		lcs[i] = num++;
	}
	return lcs;
}





int main() {
	int n;
	cin >> n;

	int *arr = new int [n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> lcs = getLCS(arr, n, lcs);

	for (vector<int>::iterator it = lcs.begin(); it != lcs.end(); it++) {
		cout << (*it) << " ";
	}

	cout << "\n";

	delete [] arr;
	return 0;
}