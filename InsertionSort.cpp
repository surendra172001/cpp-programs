#include <iostream>

using namespace std;

void InsertionSort(int A[], int size = 0)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && A[j - 1] > A[j])
        {
            int temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
            j--;
        }
    }

    for (int i = 0; i < size; i++)
        cout << A[i] << "  ";
    cout << endl;
}

int main()
{
    int A[30], i = 0, num = 0;
    cout << "Enter the elements of the array enter -1 to end the input\n";
    cin >> num;
    while (num != -1)
    {
        A[i] = num;
        cin >> num;
        i++;
    }
    InsertionSort(A, i);
    return 0;
}