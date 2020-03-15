#include<bits/stdc++.h>
using namespace std;

int SOT(int n) {
	bool *sieve = new bool[n+1];

	for (int i = 0; i <= n; i++) {
		sieve[i] = 1;
	}

	sieve[0] = sieve[1] = 0;

	for(int i = 2; i*i <= n; i++) {
		if(sieve[i]) {
			for(int p = i*i; p <= n; p += i) {
				sieve[p] = 0;
			}
		}
	}

	int count = 0;
    
	for(int i = 2; i <= n; i++) {
		if(sieve[i] == 1) {
			count++;
		}
        
	}

    delete [] sieve;
	return count;

}

int main() {
	int n;
	cin >> n;

	cout << SOT(n) << "\n";

	return 0;
}