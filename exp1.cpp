#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;



ll divCount(int n) {
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

	ll cnt = 0;

	ll factCnt = 1;

	for (int i = 1; i <= n; i++) {
		if (sieve[i]) {
			cnt = 0;
			while (n%i == 0) {
				cnt++;
				n /= i;
			}
			factCnt = (factCnt * (cnt+1))%MOD;
		}
	}
	delete [] sieve;
	return factCnt;
}




int main() {
	int n;
	cin >> n;
	cout << divCount(n) << "\n";
    return 0;
}