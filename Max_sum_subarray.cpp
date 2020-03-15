#include<bits/stdc++.h>
using namespace std;

int Kadane(int *a, int size)
{
    int current_sum = 0;
    int best_sum = 0;

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
    int a[] = {12, -4, 67, 82, -24, 95, 10};
    int size = sizeof(a) / sizeof(a[0]);
    cout << Kadane(a, size) << endl;
    return 0;
}