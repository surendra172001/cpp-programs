#include <iostream>

using namespace std;

int main()
{
    float A[20][20], x[20];
    int k = 0, l = 0, n = 0, i = 0, j = 0;

    cout << "Enter the order of the square matrix\n";
    cin >> n;

    cout << "Enter the elements of the augmented matrix\n";
    for (i = 0; i < n; i++)
    {
        cout << "Row : " << i + 1 << endl;
        for (j = 0; j <= n; j++)
            cin >> A[i][j];
    }

    for (i = 0; i < n; i++)
    {
        if (A[i][i] != 0)
        {
            for (j = i + 1; j <= n; j++)
            {
                for (k = 0; k <= n; k++)
                {
                    A[j][k] -= A[j][i] * (A[i][k] / A[i][i]);
                }
            }
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        if (A[i][i] != 0)
        {
            x[i] = A[i][n];
            j = 0;
            k = n - 1;
            while (j < n - 1 - i)
            {
                x[i] -= A[i][k] * x[k];
                j++;
                k--;
            }
            x[i] /= A[i][i];
        }
    }

    cout << "The row echelon form is\n";

    for (i = 0; i < n; i++)
    {
        if (A[i][i] != 0)
        {
            int c = A[i][i];
            for (j = 0; j <= n; j++)
            {
                A[i][j] /= c;
                if (j == n)
                    cout << "= " << A[i][j];
                else
                    cout << A[i][j] << "  ";
            }
            cout << endl;
        }
    }

    cout << "The solution of equations are\n";
    for (i = 0; i < n; i++)
        cout << x[i] << endl;
    return 0;
}