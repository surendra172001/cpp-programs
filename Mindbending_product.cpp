#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T = 0;
    cin >> T;
    while(T--)
    {
        int N = 0;
        cin >> N;
        int *arr = new int[N];
        ll *p = new ll [N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];
        
        ll left_product_element = 1, right_product_element = 1;

        for (int i = 0; i < N; i++)
        {
            p[i] = left_product_element;
            left_product_element *= arr[i];
        }

        for (int i = N - 1; i >= 0; i--)
        {
            p[i] *= right_product_element;
            right_product_element *= arr[i];
        }

        for (int i = 0; i < N; i++)
            cout << p[i] << " ";

        cout << endl;

        delete [] arr;
        delete [] p;
    }
    return 0;
}