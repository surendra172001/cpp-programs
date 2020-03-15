#include <iostream>
#include <string>

using namespace std;

class Stack
{
public:
    int top;
    char arr[100];

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

    void push(char data)
    {
        arr[++top] = data;
    }

    char pop()
    {
        if (isEmpty())
            cout << "Under Flow\n";
        else
        {
            return arr[top--];
        }
    }

    char size()
    {
        return top;
    }

    char peek()
    {
        return arr[top];
    }
};

char CounterPart(char ch)
{
    switch (ch)
    {
    case ')':
        return '(';
    case ']':
        return '[';
    case '}':
        return '}';
    default:
        return '\0';
    }
}

int precedence(char ch)
{
    if (ch == '^')
        return 4;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 1;
}

void InfixToPostfix(string s)
{
    Stack S1;
    int i = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            if (S1.isEmpty())
                S1.push(s[i]);
            else if (precedence(s[i]) > precedence(S1.peek()))
                S1.push(s[i]);
            else if (precedence(s[i]) <= precedence(S1.peek()))
            {
                while (precedence(s[i]) <= precedence(S1.peek()))
                {
                    if (S1.peek() != '(' || S1.peek() != '[' || S1.peek() != '{')
                        cout << S1.pop();
                    else
                        break;
                }
                S1.push(s[i]);
            }
        }
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            S1.push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            while (S1.peek() != CounterPart(s[i]))
                cout << S1.pop();
            S1.pop();
        }
        else
            cout << s[i];
    }
    while (!S1.isEmpty())
    {
        cout << S1.pop();
    }
}

int main()
{
    string s;
    cout << "Enter the string\n";
    cin >> s;
    InfixToPostfix(s);
    return 0;
}
