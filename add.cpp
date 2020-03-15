#include<iostream>
using namespace std;

void update(int output[], int size)
{
    for(int i = 0; i < size; i++)
        output[i] += 1;
}

void shift(int output[], int size)
{
    for(int i = size; i >= 0; i--)
        output[i + 1] = output[i];
    output[0] = 0;
}

int allIndexes(int input[], int size, int x, int output[])
{
    if (size == 0)
        return 0;
    else
    {
        int ans = allIndexes(input + 1, size - 1, x, output);
        update(output, ans);
        if (input[0] == x)
        {
            shift(output, ans);
            return ans + 1;
        }
        else
            return ans;
    }  
}


int firstIndex(int input[], int size, int x)
{
    if (size == 0)
        return -1;
    else
    {
        if (input[0] == x)
            return 0;
        int ans = firstIndex(input + 1, size - 1, x);
        if (ans == -1)
            return -1;
        else 
            return ans + 1;
    }    
}


int lastIndex(int input[], int size, int x)
{
    if (size == 0)
        return -1;
    else
    {
        int ans = lastIndex(input + 1, size - 1, x);
        if (ans == -1)
        {
            if (input[0] == x)
                return 0;
            else 
                return -1;
        }
        else 
            return ans + 1;
    }  
}

int main()
{
    /*
    int a[] = {9, 8, 10, 8, 11, 17, 19, 9, 8};
    int size = sizeof(a) / sizeof(a[0]);
    
    int *output = new int[size];
    int ans = allIndexes(a, size, 9, output);
    for(int i = 0; i < ans; i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    cout << firstIndex(a, size, 19);*/
    char c = 'a';
    char* p = &c;
    cout << p << endl;
    return 0;
}
/*
int main()
{
    int N = 0,profit = 0, maxProfit = 0;

    cin >> N;

    int priceList[N];
    for(int i = 0; i < N; i++)
    {
        cin >> priceList[i];
    }

    for(int i = 0; i < N - 1; i++)
    {
        int j = i + 1;
        while(j < N)
        {
            profit = priceList[j] - priceList[i];
            if(profit > maxProfit)
                maxProfit = profit;
            j++;
        }
    }

    cout << maxProfit << endl;
    return 0;
}
*/