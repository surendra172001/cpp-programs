/*
#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int input[], int start, int end) {
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (input[i] <= input[start])
            count++;
    }
    
    swap(input[start], input[start + count]);
    int pivot = start + count;
    cout << start << " " << pivot << endl;
    for (int i = start; i <= end; i++)
        cout << input[i] << " ";
    
    int i = start, j = end;

    while (i < pivot && j > pivot) {
        if (input[i] <= input[pivot]) 
            i++;
        else if (input[j] > input[pivot])
            j--;
        else {
            swap(input[i], input[j]);
            i++;
            j--;
        }
    }

    return pivot;
}

void quickSortUtil(int input[], int start, int end){
    if (start < end) {
        int pivot = partition(input, start, end);
        quickSortUtil(input, start, pivot - 1);
        quickSortUtil(input, pivot + 1, end);
    }
}

inline void quickSort(int input[], int size) {
    quickSortUtil(input, 0, size  - 1);
}

int main() {
    int size = 0;
    cin >> size;
    int *input = new int [size];
    for (int i = 0; i < size; i++)
        cin >> input[i];

    quickSort(input, size);
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }
    cout << endl;

    delete [] input;
    return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int Partition(int A[], int start, int end)
{
    int pIndex = start, i = start, pivot = A[end];
    for (; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            Swap(A[i], A[pIndex]);
            pIndex++;
        }
    }
    Swap(A[pIndex], A[end]);
    return pIndex;
}

int RandomPartition(int A[], int start, int end)
{
    srand((unsigned)time(0));
    int pIndex = rand() % end;
    Swap(A[pIndex], A[end]);
    return Partition(A, start, end);
}


void QuickSort(int A[], int start, int end)
{
    if (start < end)
    {        
        int pIndex = RandomPartition(A, start, end);
        QuickSort(A, start, pIndex - 1);
        QuickSort(A, pIndex + 1, end);
    }
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
    QuickSort(A, 0, i);

    for (int j = 0; j < i; j++)
        cout << A[j] << "  ";
    cout << endl;
    return 0;
}
