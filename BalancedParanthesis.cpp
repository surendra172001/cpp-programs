#include<iostream>
#include<string>
#include<stack>

using namespace std;

char Corresponding(char ch)
{
    switch(ch)
    {
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
    }
}

int ParanthesisCheck(string str)
{
    stack <char>St;
    if(str[0]==')'||str[0]==']'||str[0]=='}')
    {
        cout<<"Unbalanced\n";
        return 0;
    }
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
        {
            St.push(str[i]);
        }
        if(str[i]==')'||str[i]==']'||str[i]=='}')
        {
            if(St.top() == Corresponding(str[i]))
                St.pop();
            else 
            {
                cout<<"Unbalanced\n";
                return 0;
            }
        }
    }
    if(St.empty())
    {
        cout<<"Balanced\n";
        return 1;
    }
    else
    {
        cout<<"Unbalanced\n";
        return 0;
    }
}

int main()
{
    string str;
    cout<<"Enter the string\n";
    cin>>str;
    ParanthesisCheck(str);
    return 0;
}