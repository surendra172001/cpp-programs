#include<bits/stdc++.h>
using namespace std;


int matchingSubstringStart(string text, string pattern) {
	int pLen = pattern.length();
	int n = text.length();
	int *p = new int [pLen]();

	int j = 0;
	int ans = -1;
	for (int i = 1; i < pLen;) {
		while (j < pLen && pattern[j] == pattern[i]) {
			p[i] = j+1;
			j++;
			i++;
		}

		while (j > 0 && pattern[j] != pattern[i]) {
			j = p[j-1];
		}

		if (j == 0) {
			p[i] = 0;
			i++;
		}
	}

	j = 0;
	int i = 0;

	while (i < n && j < pLen) {
		if (text[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			if (j != 0)
				j = p[j-1];
			else {
				i++;
			}
		}
	}


	if (j == pLen) {
		ans = i-pLen;
	}

	delete [] p;
	return ans;
}


int main() {
	string text, pattern;
	cin >> text >> pattern;

	cout << matchingSubstringStart(text, pattern) << "\n";

	return 0;
}