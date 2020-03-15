#include <iostream>
#include <stack>

using namespace std;

void CalculateSpan(int price[], int n)
{
    stack<int> St;
    int i = 0;
    cout << 1 << " ";
    for (i = 1; i < n; i++)
    {
        while (!St.empty() && price[i] >= price[St.top()])
        {
            St.pop();
        }

        cout << ((St.empty()) ? i + 1 : i - St.top()) << " ";

        St.push(i);
    }
    cout << endl;
}

int main()
{
    int arr[] = {11, 22, 12, 33, 14, 45, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    CalculateSpan(arr, n);
    return 0;
}
