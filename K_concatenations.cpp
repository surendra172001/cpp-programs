#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll BestSumSubArray(int arr[], int n, int k)
{
    ll Kadanes_sum = Kadane(arr, n);

    if (k == 1)
        return Kadanes_sum;
    
    ll max_prefix_sum = 0, max_suffix_sum = 0;
    ll current_prefix_sum = INT_MIN, current_suffix_sum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        current_prefix_sum += arr[i];
        max_prefix_sum = max(current_prefix_sum,max_prefix_sum);
    }

    ll total_sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        current_suffix_sum += arr[i];
        max_suffix_sum = max(current_suffix_sum, max_suffix_sum);
    }

    if (total_sum < 0)
        return max(max_prefix_sum + max_suffix_sum, Kadanes_sum);
    else
        return max(max_prefix_sum + max_suffix_sum + (k - 2) * total_sum, Kadanes_sum);
}

ll Kadane(int *a, int size)
{
    ll current_sum = 0;
    ll best_sum = 0;

    for (int i = 0; i < size; i++)
    {
        current_sum += a[i];
        if (current_sum > best_sum)
            best_sum = current_sum;
        if (current_sum < 0)
            current_sum = 0;
    }

    return best_sum;
}

int main()
{
    int T = 0;
    cin >> T;
    while(T--)
    {
        int *a = NULL;
        int N = 0, k = 0;
        cin >> N >> k;
        a = new int [N];

        for (int i = 0; i < N; i++)
            cin >> a[i];

        delete [] a;
    }
    return 0;
}