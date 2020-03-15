#include<iostream>

using namespace std;


void corresponding (char *head,char *corresponding)
{
    if(*head=='(')
        *corresponding=')';
    else if(*head=='{')
        *corresponding='}';
    else if(*head=='[')
        *corresponding=']';
}


int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        string var;
        cin>>var;
        

    }
    return 0;
}