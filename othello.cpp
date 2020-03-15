#include<bits/stdc++.h>
using namespace std;


#define IO          ios::sync_with_stdio(0);
#define MOD 		1000000007
#define MAX			1000001
#define ll 			long long
#define nl 			cout << "\n";
#define mp 			make_pair
#define fi   		first
#define se 			second
#define dbg         cout << "Debug...\n";
#define prt(a)      cout << a << "\n";
#define vi			vector<int>
#define vb 			vector<bool>
#define w_is(a)     cerr << #a << " " << a << "\n";

#define ull 		unsigned long long

int energyOutput(ull t, ull m) {

	int modVal = t%m;
	int flag = t/m;

	ull result = (flag == 1 ? m-1 : 1);

	for(int i = 2; i <= modVal; i++) {
		result = (result*i)%m;
	}

	return (int) result;
}



int main() {
	IO
	int n;
	cin >> n;

	while(n--) {
		ull t, m;
		cin >> t >> m;
		cout << energyOutput(t, m);
		nl
	}

	return 0;
}





