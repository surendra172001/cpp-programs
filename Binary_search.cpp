#include <iostream>

using namespace std;

int Binary_search(int a[], int start, int end, int k)
{
    if (start <= end)
    {
        int middle = (start + end) / 2;
        if (a[middle] == k)
        {
            return 1;
        }
        else if (a[middle] > k)
        {
            return Binary_search(a, start, middle - 1, k);
        }
        else if (a[middle] < k)
        {
            return Binary_search(a, middle + 1, end, k);
        }
        else
            return (-1);
    }
    return -1;
}

int main()
{
    int T, N, x, k, a[100], p[20], temp, i;
    cin >> T;
    temp = T;
    x = 0;
    while (temp--)
    {
        cin >> N >> k;
        for (i = 0; i < N; i++)
            cin >> a[i];
        p[x] = Binary_search(a, 0, N - 1, k);
        x++;
    }
    for (i = 0; i < T; i++)
    {
        cout << p[i] << endl;
    }
    return 0;
}
