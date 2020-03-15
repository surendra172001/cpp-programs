#include <iostream>

using namespace std;

void merge(int a[], int start, int middle, int end)
{
    //Determining size
    int size_temp1 = (middle - start) + 1;
    int size_temp2 = end - middle;

    //creating temporary arrays
    int temp1[size_temp1], temp2[size_temp2];

    int i;

    //copying values
    for (i = 0; i < size_temp1; i++)
    {
        temp1[i] = a[start + i];
    }

    for (i = 0; i < size_temp2; i++)
    {
        temp2[i] = a[middle + 1 + i];
    }

    i = 0;
    int j = 0, k = start;
    while (i < size_temp1 && j < size_temp2)
    {
        if (temp1[i] < temp2[j])
        {
            a[k] = temp1[i];
            i++;
        }
        else
        {
            a[k] = temp2[j];
            j++;
        }
        k++;
    }

    //copying rest of the elements
    while (i < size_temp1)
    {
        a[k] = temp1[i];
        i++;
        k++;
    }

    while (j < size_temp2)
    {
        a[k] = temp2[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        merge_sort(a, start, middle);
        merge_sort(a, middle + 1, end);
        merge(a, start, middle, end);
    }
}


/*
void mergeSort(string, int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        merge_sort(a, start, middle);
        merge_sort(a, middle + 1, end);
        merge(a, start, middle, end);
    }
}

void merge(string str, int start, int middle, int end)
{
    //Determining size
    int size_temp1 = (middle - start) + 1;
    int size_temp2 = end - middle;

    sub1 = str.substr()
}


*/

int main()
{

    int a[] = {1, 34, 54, 62, 12, 11, 23, 93, 64, 88, 41};
    /* 
    string str = "surendra";
    merge_sort(str, 0, str.length());
    cout << str << endl;
    */

    int size = sizeof(a) / sizeof(a[0]);

    merge_sort(a, 0, size - 1);

    //printing array elements
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;

    return 0;
}