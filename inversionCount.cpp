#include<bits/stdc++.h>
using namespace std;


#define IO          ios::sync_with_stdio(0);
#define MOD         1000000007
#define MAX         1000001
#define ll          long long
#define nl          cout << "\n";
#define mp          make_pair
#define fi          first
#define se          second
#define dbg         cout << "Debug...\n";
#define prt(a)      cout << a << "\n";
#define vi          vector<int>
#define vb          vector<bool>
#define w_is(a)     cerr << #a << " " << a << "\n";


#define pi          2*acos(0.0)


ll countInversions(ll *arr, ll start, ll mid, ll end) {
    ll i = start, j = mid+1;
    ll res = 0;
    while(i <= mid && j <= end) {
        // cout << res << " ";
        // prt(i)
        if(arr[i] > arr[j]) {
            res += (mid-i+1);
            j++;
        } else {
            i++;
        }
    }
    return res;
}

void merge(ll *arr, ll start, ll mid, ll end) {
    ll *auxArr = new ll [end-start+1];

    ll i = start, j = mid+1;
    ll k = 0;
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            auxArr[k] = arr[i];
            i++;
        } else {
            auxArr[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        auxArr[k++] = arr[i++];
    }

    while(j <= end) {
        auxArr[k++] = arr[j++];
    }

    ll ptr = 0;
    for(int i = start; i <= end; i++) {
        arr[i] = auxArr[ptr++];;
    }

}


ll inversionsUtil(ll *arr, ll start, ll end) {
    if(start >= end) {
        return 0;
    }
    ll mid = (start+end)/2;
    ll res = 0;
    res += inversionsUtil(arr, start, mid);
    res += inversionsUtil(arr, mid+1, end);

    res += countInversions(arr, start, mid, end);
    merge(arr, start, mid, end);
    return res;
}

ll inversions(ll *arr, ll n) {
    return inversionsUtil(arr, 0, n-1);
}


int main() {

    IO
    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        ll *arr = new ll[n];

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << inversions(arr, n) << "\n";
        delete arr;
    }
    
    return 0;
}




/*
int main() {
    
    int n;
    cin >> n;
    
    ll *arr = new ll [n];
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    cout << inversions(arr, n) << "\n";
    
    // for(int i = 0; i < n; i++) cout << arr[i] << " ";
    
    delete arr;
    
    return 0;
}*/
























