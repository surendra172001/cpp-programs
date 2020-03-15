#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long



int main() {
    int t;
    cin >> t;

    int *arr = new int[1001];
    while(t--) {
        int n;
        cin >> n;
        
        int *dp = new int[n];

        for(int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int maxM = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            if (dp[i] > maxM) maxM = dp[i];
        }
        delete [] dp;
        cout << maxM << "\n";
    }

    delete [] arr;
    return 0;
}