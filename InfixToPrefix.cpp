#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

/*
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
            return false;
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

string InfixToPostfix(string s, Stack *Sn)
{
    string Place_holder;
    int i = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            if (Sn->isEmpty())
                Sn->push(s[i]);
            else if (precedence(s[i]) > precedence(Sn->peek()))
            {
                Sn->push(s[i]);
            }
            else if (precedence(s[i]) <= precedence(Sn->peek()))
            {
                while (precedence(s[i]) <= precedence(Sn->peek()))
                {
                    if (Sn->peek() != '(')
                    {
                        Place_holder += Sn->pop();
                    }
                    else
                        break;
                }
                Sn->push(s[i]);
            }
        }
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            Sn->push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            while (Sn->peek() != CounterPart(s[i]) && (!Sn->isEmpty()))
            {
                Place_holder += Sn->pop();
                cout << "Error\n";
            }

            Sn->pop();
        }
        else
            Place_holder += s[i];
    }
    while (!Sn->isEmpty())
    {
        Place_holder += Sn->pop();
    }
    return Place_holder;
}

string Reverse(string s)
{
    string new_string;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        new_string += s[i];
    }
    return new_string;
}

void InfixToPrefix(string s)
{
    Stack S1;
    s = Reverse(s);
    s = InfixToPostfix(s, &S1);
    s = Reverse(s);
    cout << s << endl;
}

int main()
{
    string s;
    cout << "Enter the string\n";
    cin >> s;
    InfixToPrefix(s);
    return 0;
}

*/


int prec(char ch) {
    if (ch == '^') 
        return 3;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else 
        return 0;
}

inline bool is_operator(char ch) {
    return (ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-' || ch == '^');
}



string infix_to_postfix(string infix) {
    if (infix.length() != 0) {
        stack<char> S;
        S.push('N');//indicator that stack is empty

        string temp;//for holding postfix expression

        int l = infix.length();
        for (int i = 0; i < l; i++) {
            //if current character is operator
            if (is_operator(infix[i])) {
                //if precedence of current operator is higher than the operator at the top of the stack
                if (prec(S.top()) < prec(infix[i])) {
                    S.push(infix[i]);
                }
                else {
                    //while precedence of current operator is lesser than or equal to the operator at the top of the stack
                    while (prec(S.top()) >= prec(infix[i]) && S.top() != 'N' && S.top() != '(') {
                        //append the top operator in output string
                        temp += S.top();
                        // pop it from the stack
                        S.pop();
                    }
                    // push the current operator into the satck
                    S.push(infix[i]);
                }
            }
            //if current character is opening paranthesis
            else if (infix[i] == '(') {
                S.push('(');
            }
            //if current character is closing paranthesis
            else if (infix[i] == ')') {
                // while opening paranthesis is not met and stack is not empty
                while (S.top() != '(' && S.top() != 'N') {
                    // append the top operator in the output string
                    temp += S.top();
                    S.pop();
                }
                // if stack is not empty pop the opening paranthesis
                if (S.top() != 'N') {
                    S.pop();
                }
            }
            else {
                temp += infix[i];
            }
        } 

        // append the rest of the operators remaining in the stack
        while (S.top() != 'N') {
            temp += S.top();
            S.pop();
        }

        infix = temp;
        return temp;
    }
    else {
        return infix;
    }
}

void Reverse(string &str) {
    reverse(str.begin(), str.end());
    // To reverse the orientation of the brackets in the reverse string
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            str[i] = ')';
        }
        else if (str[i] == ')') {
            str[i] = '(';
        }
    }
    
}

string infix_to_prefix (string infix) {
    Reverse(infix);
    infix = infix_to_postfix(infix);
    reverse(infix.begin(), infix.end());
    return infix;
}


int main() {
    string str;
    cin >> str;
    cout << infix_to_prefix(str) << "\n";
    return 0;
}