#include<iostream>

using namespace std;

void BubbleSort(int A[], int size)
{
    int flag = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
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
    while(num != -1)
    {
        A[i] = num;
        cin >> num;
        i++;
    }
    BubbleSort(A, i);
    return 0;
}