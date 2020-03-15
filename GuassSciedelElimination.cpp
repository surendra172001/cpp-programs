
#include <iostream>

using namespace std;

int main()
{
    float A[10][10], V[10], X[10];
    int i = 0, j = 0, k = 0, nI = 0, n = 0, f = 0;

    cout << "Enter the order of the matrix\n";
    cin >> n;

    cout << "Enter the Augmented Matrix\n";

    for (i = 0; i < n; i++)
    {
        cout << "Row " << i + 1 << endl;
        for (j = 0; j <= n; j++)
            cin >> A[i][j];
    }

    cout << "Enter the number of iterations you want to perform\n";
    cin >> nI;

    cout << "Want to give the initial values Enter\n1 - for yes\n";
    cin >> f;

    for (i = 0; i < n; i++)
    {
        X[i] = V[i] = 0;
    }

    if (f == 1)
    {
        cout << "Enter the values\n";
        for (int l = 0; l < n; l++)
        {
            cin >> V[l];
        }
    }
    
    for (k = 0; k < nI; k++)
    {
        for (i = 0; i < n; i++)
        {
            X[i] = A[i][n];
            for (j = 0; j <= n; j++)
            {
                if (i == j)
                    continue;
                X[i] -= A[i][j] * V[j];
            }
            X[i] /= A[i][i];
        }

        cout << "Values for iteration no. " << k + 1 << endl;

        for (i = 0; i < n; i++)
        {
            cout << X[i] << "  ";
            V[i] = X[i];
        }
        cout << endl;
    }

    return 0;
}
