#include <bits/stdc++.h>
using namespace std;


struct Triplet {
	int x, y, gcd;
};

Triplet extendedEuclid(int a, int b) {
	Triplet ans;
	if (b == 0) {
		ans.x = 1;
		ans.y = 0;
		ans.gcd = a;
		return ans;
	}

	Triplet ans1 = extendedEuclid(b, a%b);
	ans.x = ans1.y;
	ans.y = ans1.x - (a/b)*ans1.y;
	ans.gcd = ans1.gcd;
	return ans;
}

int mmInverse(int a, int m) {
	Triplet ans = extendedEuclid(a, m);
	return ans.x;
}

int main() {
	int a, m;
	cin >> a >> m;

	int ans = mmInverse(a, m);

	cout << ans << "\n";

	return 0;
}
