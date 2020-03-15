#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int arrival[n], departure[n];
    for (int i = 0; i < n; i++)
        cin >> arrival[i];

    for (int i = 0; i < n; i++)
        cin >> departure[i];

    sort(arrival, arrival + n);
    sort(departure, departure + n);
    int i = 0, j = 0, chairs = 0, maxChairs = INT_MIN;
    while (i < n && j < n)
    {
        if (arrival[i] < departure[j])
        {
            chairs++;
            i++;
        }
        else
        {
            chairs--;
            j++;
        }
        if (chairs > maxChairs)
            maxChairs = chairs;
    }
    cout << maxChairs << endl;
    return 0;
}