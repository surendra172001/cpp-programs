#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int a[n]; 

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        int t;
        t=a[0];
        for(int j=0;j<n-1;j++)
        {
            a[j]=a[j+1];
        }
        a[n-1]=t;
        if (a[n-i+1]!=0)
        {
            a[n-i+1]=0;
        }
        else
        {
            a[n-i]=0;
        }
          
    }

    cout<<a[0];

    return 0;
}