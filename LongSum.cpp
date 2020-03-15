#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack< int > s1, s2, s3;
    int num = -1;
    cout << "Enter the first number digit by digit and enter -1 to end it\n";
    cin >> num;
    while (num > -1)
    {
        s1.push(num);
        cin >> num;
    }
    cout << "Enter the second number digit by digit and enter -1 to end it\n";
    cin >> num;
    while (num > -1)
    {
        s2.push(num);
        cin >> num;
    }

    int sum = 0, carry = 0, dig = 0;

    while ((!s1.empty()) && (!s2.empty()))
    {
        sum = s1.top() + s2.top() + carry;
        cout << sum << endl;
        s1.pop();
        s2.pop();
        dig = sum % 10;
        carry = sum / 10;
        s3.push(dig);
    }
    
    if (s1.empty())
    {
        while (!s2.empty())
        {
            sum = s2.top() + carry;
            s2.pop();
            carry = sum / 10;
            dig = sum % 10;
            s3.push(dig);
        }
    }

    if (s2.empty())
    {
        while (!s1.empty())
        {
            sum = s1.top() + carry;
            s1.pop();
            carry = sum / 10;
            dig  = sum % 10;
            s3.push(dig);
        }
    }

    if (carry)
        s3.push(carry);
    
    while (!s3.empty())
    {
        cout << s3.top();
        s3.pop();
    }
    cout << endl;
    return 0;
}