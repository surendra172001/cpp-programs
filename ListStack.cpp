#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};

class Stack
{
    int count;
    Node *Top;
    Node *last;

public:
    Stack()
    {
        count = 0;
        Top = NULL;
        last = NULL;
    }
    bool isEmpty()
    {
        if (Top == NULL)
            return true;
        else
            return false;
    }

    void push(int data)
    {
        Node *newNode = new Node;
        if (count == 0)
            last = newNode;
        newNode->data = data;
        newNode->next = Top;
        Top = newNode;
        count++;
    }

    int Pop()
    {
        if (Top == NULL)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        else
        {
            Node *temp = Top;
            Top = Top->next;
            int n = temp->data;
            delete temp;
            return n;
        }
    }

    void DeleteStack()
    {

        while (Top != NULL)
        {
            Pop();
        }
    }
};

int main()
{
    Stack S1;
    for (int i = 1; i < 11; i++)
    {
        S1.push(i);
    }
    S1.Print();
    cout << S1.Pop() << endl;
    S1.Print();
    S1.DeleteStack();
    return 0;
}