#include<bits/stdc++.h>
using namespace std;

#define debug           cout<<"...";
#define nl              cout<<"\n"; 
#define rep(i,a,b)      for(ll i=a;i<b;i++) 
#define rrep(j,b,a)     for(ll j=b;j>=a;j--)
#define print(arr,n)    rep(i,0,n) cout<<arr[i]<<" "; 
#define println(arr,n)  print(arr,n); nl;
#define scan(arr,n)     rep(i,0,n) cin>>arr[i]; 
#define reset(a,k)      memset(a, k, sizeof(a))
#define IO              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll              long long
#define fi              first 
#define se              second
#define pb              push_back
#define mp              make_pair
#define all(a)          a.begin(), a.end()
#define tc              int tc; cin>>tc; while(tc--)
#define INT_SIZE        32


struct event {
	char type;
	int val;
};

void printBit(ll *BIT, int size) {
    for (int i = 1; i <= size; i++) cout << BIT[i] << " ";
    nl;
}


void update(ll *BIT, int ind, int val, int n) {

	for (; ind <= n; ind += (ind & (-ind))) {
		BIT[ind] += val;
	}

}


ll query(ll *BIT, int ind) {

	ll count = 0;
    
	for (; ind > 0; ind -= (ind & (-ind))) {
		count += BIT[ind];
	}

	return count;
}


int binarySearch(int arr[], int l, int r, int x) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
        
        return binarySearch(arr, mid + 1, r, x); 
    } 

    return -1; 
} 


int main() {
	int q;
	cin >> q;

	event *Q = new event [q];

	for (int i = 0; i < q; i++) {
		cin >> Q[i].type >> Q[i].val;
	}

	map<int, bool> m1;

	for (int i = 0; i < q; i++) {
		if (Q[i].type == 'I') {
			m1[Q[i].val] = 1;
		}
	}

	int size = m1.size();

	int *arr = new int [size + 1];

	int itr = 1;

	// since m1 is an ordered map all the values will be inserted in sorted order
	for (map<int, bool>::iterator it = m1.begin(); it != m1.end(); it++) {
		arr[itr] = it->fi;
        // cout << arr[itr] << " ";
		itr++;
	}
    
    // nl
        
	unordered_map<int, int> m2;

	for (int i = 1; i <= size; i++) {
		m2[arr[i]] = i;
	}

	ll *BIT = new ll [size + 1]();

	for (int i = 0; i < q; i++) {
		if (Q[i].type == 'I') {
			int x = Q[i].val;
			int index = m2[x];
			if (query(BIT, index) == query(BIT, index - 1)) {
                // cout << "I " << x << " " << index << "\n";
				update(BIT, index, 1, size);
                // printBit(BIT, size);
			}
		}
		else if (Q[i].type == 'D') {
			int x = Q[i].val;
			int index = m2[x];
			if (query(BIT, index) != query(BIT, index - 1)) {
				update(BIT, index, -1, size);
			}
		}
		else if (Q[i].type == 'K') {
            // printBit(BIT, size);
			int k = Q[i].val, y = 0;
			int start = 1, end = size;
            while (start <= end) {
                
                int mid = (start + end) / 2;
                int ans = query(BIT, m2[arr[mid]]);
                
                // cout << " k: "<< k << " mid: " << mid << " ans: " << ans << "\n";
                
                if (ans < k) {
                    start = mid + 1;
                }
                else if (ans > k) {
                    end = mid - 1;
                }
                else if (ans == k) {
                    y = mid;
                    break;
                }
                
            }
            
            // cout << k << " y: " << y << "\n";
            
			if (y == 0) {
				cout << "invalid\n";
			}
			else {
				cout << arr[y] << "\n";
			}
		}
		else if (Q[i].type == 'C') {
			int count = lower_bound(arr + 1, arr + size + 1, Q[i].val) - (arr + 1);
			cout << query(BIT, count - 1) << "\n";
		}
	}


	delete [] Q;
	delete [] arr;
	delete [] BIT;

	return 0;
}