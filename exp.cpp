#include<bits/stdc++.h>
using namespace std;

#define INF		1e7;


int main() {

	int t;
	cin >> t;

	while(t--) {

		long v;
		cin >> v;

		long mat[v][v];

		for(long i = 0; i < v; i++) {
			for(long j = 0; j < v; j++) {
				cin >> mat[i][j];
			}
		}

		// todo		long toggle = 0;

		long dp[2][v][v];

		memset(dp, 0, sizeof(dp));

		for(long i = 0; i < v; i++) {
			dp[toggle][0][i] = mat[0][i];
			dp[toggle][i][0] = mat[i][0];
		}


		for(long i = 1; i < v; i++) {

			if(i == 0)
				continue;

			for(long j = 0; j < v; j++) {

				long sum = dp[toggle][i][0] + dp[toggle][0][j];

				dp[toggle][i][j] = (mat[i][j] < sum ? mat[i][j] : sum);

			}

		}

		// for(long i = 1; i < v; i++) {
		// 	for(long j = 0; j < v; j++) {
				
		// 	}
		// }


	}

	return 0;
}