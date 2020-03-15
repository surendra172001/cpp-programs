#include <iostream>

using namespace std;

class Matrix
{
public:
    int r, c;
    int *matrix;
    Matrix() {}
    Matrix(int row, int column)
    {
        r = row;
        c = column;
        matrix = new int(r * c);
    }
    ~Matrix()
    {
        delete matrix;
    }

    void GetElements()
    {
        int count = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                matrix[i * c + j] = ++count;
            }
        }
    }

    void Print()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << matrix[i * c + j] << "   ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int Ar = 0, Ac = 0, Br = 0, Bc = 0;

    cout << "Enter the order of the matrix A\n";

    cin >> Ar >> Ac;

    cout << "Enter the order of the matrix B\n";

    cin >> Br >> Bc;

    if (Ac != Br)
    {
        cout << "Matrix multiplication not viable\n";
        return 0;
    }

    Matrix A(Ar, Ac), B(Br, Bc);

    A.GetElements();
    B.GetElements();

    A.Print();
    cout << endl;
    cout << endl;
    B.Print();
    cout << endl;
    cout << endl;

    Matrix C(Ar, Bc);

    for (int i = 0; i < Ar; i++)
    {
        cout << "Yo\n";
        for (int j = 0; j < Bc; j++)
        {
            int sum = 0;
            int k = 0;
            for (; k < Br; k++)
            {
                //cout << A.matrix[i * Ac + k] << " " << B.matrix[k * Ac + j] << "\n";
                sum += A.matrix[i * Ac + k] * B.matrix[k * Ac + j];
            }
            //cout << sum << endl;
            C.matrix[i * Bc + j] = sum;
        }
    }

    C.Print();
    return 0;
}

/*
int main()
{
    int A[3][3], B[3][3], C[3][3];
    cout << "Enter the lements of the matrix A\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            A[i][j] = (i + 1) * (j + 1);
        }
    }
    cout << "Enter the lements of the matrix B\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            B[i][j] = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                sum += A[j][k] * B[k][j];
            }
            cout << sum << "\t";
        }
        cout << endl;
    }
    return 0;
}
*/