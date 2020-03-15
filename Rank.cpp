#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        unordered_map<char, stack<int> > indices;

        int l = str.length();
        for (int i = 0; i < l; i++) {
            indices[str[i]].push(i);
        }
        
        int ans = 0;
        for (unordered_map<char, stack<int> >::iterator it = indices.begin() ; it != indices.end(); it++) {
            if (it->second.size() > 1) {
                it->second.pop();
                int temp = (it->second.top() + 1);
                if (ans < temp) ans = temp;
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}