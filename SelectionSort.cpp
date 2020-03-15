#include<iostream>

using namespace std;

void SelectionSort(int a[], int size = 0)
{
    int iMin = 0, temp = 0;

    for (int i = 0; i < size - 1; i++)
    {
        iMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if(a[iMin] > a[j])
                iMin = j;
        }
        temp = a[iMin];
        a[iMin] = a[i];
        a[i] = temp;
    }

    for (int i = 0; i < size; i++)
        cout << a[i] << "  ";
    cout << endl;
}

int main()
{
    int A[30], i = 0, num = 0;
    cout << "Enter the elements of the array enter -1 to end the input\n";
    cin >> num;
    while(num != -1)
    {
        A[i] = num;
        cin >> num;
        i++;
    }
    SelectionSort(A, i);
    return 0;
}