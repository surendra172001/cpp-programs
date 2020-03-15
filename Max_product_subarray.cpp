#include<bits/stdc++.h>
using namespace std;

int MaxProductSubarray(int arr[], int N)
{
    int Max_so_far = 1, current_max = 1, current_min = 1;
    for(int i = 0; i < N; i++)
    {
        if (arr[i] > 0)
        {
            current_max *= arr[i];
            current_min = min(1, current_min * arr[i]);
        }
        else if (arr[i] == 0)
            current_max = current_min = 1;
        else
        {
            int temp = current_max;
            current_max = max(1, current_min * arr[i]);
            current_min = temp * arr[i];
        }
        Max_so_far = max(Max_so_far, current_max);
    }
    return Max_so_far;
}

int main()
{
    int N = 0;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    cout << MaxProductSubarray(arr, N) << endl;
    return 0;
}