#include <iostream>
#include <stack>
using namespace std;

/*
class Stack
{
public:
    int Top;
    int *arr;

    Stack()
    {
        Top = -1;
        arr = NULL;
    }

    Stack(int N)
    {
        Top = -1;
        arr = NULL;
        arr = new int[N];
    }

    bool empty()
    {
        if (Top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (Top == 99)
            return true;
        else
            return false;
    }

    void push(int data)
    {
        if (isFull())
            cout << "Over Flow\n";
        else
        {
            arr[++Top] = data;
        }
    }

    int pop()
    {
        if (empty())
            cout << "Under Flow\n";
        else
        {
            return arr[Top--];
        }
    }

    int size()
    {
        return Top;
    }

    int top()
    {
        return arr[Top];
    }

    ~Stack()
    {
        delete arr;
    }
};

int main()
{
    int T = 0, N = 0, next = 0;
    int *arr = NULL;
    Stack S1;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        arr = new int[N];
        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }
        S1.push(arr[0]);
        for (int k = 1; k < N; k++)
        {
            next = arr[k];
            while ((!S1.empty()) && next > S1.top())
            {
                cout << next << " ";
                S1.pop();
            }
            S1.push(next);
        }
        while (!S1.empty())
        {
            cout << "-1 ";
            S1.pop();
        }
        cout << endl;
        delete arr;
    }
    return 0;
}
*/

int main()
{
    long long num = 0, N = 0, k = 0, i = 0;
    cin >> N >> k;
    stack<long long> s1, s2;
    for (i = 0; i < N; i++)
    {
        cin >> num;
        s1.push(num);
    }
    for (i = 0; i < N; i++)
    {
        num = s1.top();
        s2.push(num);
        s1.pop();
    }
    for (i = 0; i < k; i++)
    {
        num = s2.top();
        while ((!s1.empty()) && num > s1.top())
        {
            s1.pop();
        }
        s2.pop();
        s1.push(num);
    }
    while (!s1.empty())
    {
        num = s1.top();
        s1.pop();
    }
    cout << num << endl;
    return 0;
}