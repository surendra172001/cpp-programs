#include<bits/stdc++.h>
using namespace std;


int parse(char ch)
{
    return ch - '0';
}

int Evaluate(char ch, int a, int b)
{
    switch(ch)
    {
        case '+':
            return a + b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return a ^ b; 
        case '-':
            return a - b;
    }
}

int PostfixEvalution(string exp)
{
    stack<int > st;
    for (int i = 0; i < exp.length(); i++)
    {
        cout << i << endl;
        int p = parse(exp[i]);
        if (exp[i] ==  '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            cout << a << " " << b << endl;
            int n = Evaluate(exp[i], b, a);
            st.push(n);
        }
        else if (p >= 0 && p < 10)
        {
            st.push(p);
        }
    }
    int result = st.top();
    st.pop();
    return result;
}

int main()
{
    string exp;
    cout << "Enter the postfix expression\n";
    cin >> exp;
    cout << PostfixEvalution(exp) << endl;
    return 0;
}