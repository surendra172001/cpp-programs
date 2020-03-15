#include <iostream>
#include <string>

using namespace std;

class Stack
{
public:
    int top;
    string arr[100];

    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == 99)
            return true;
        else
            false;
    }

    void push(string s)
    {
        arr[++top] = s;
    }

    string pop()
    {
        if (isEmpty())
            cout << "Under Flow\n";
        else
        {
            return arr[top--];
        }
    }
};

void PostfixToPrefix(string s)
{
    Stack S1;
    int i = 0;
    for (; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            string temp;
            temp += s[i];
            S1.push(temp);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            string a, b, c;
            b = S1.pop();
            a = S1.pop();
            c += s[i];
            c += a;
            c += b;
            S1.push(c);
        }
    }
    cout << S1.pop() << endl;
}

int main()
{
    string s;
    cout << "Enter the string\n";
    cin >> s;
    PostfixToPrefix(s);
    return 0;
}