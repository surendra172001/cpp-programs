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

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    Node *createNode(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
            return true;
        else
        {
            return false;
        }
    }

    void enQueue(int data)
    {
        if (isEmpty())
        {
            rear = createNode(data);
            front = rear;
        }
        else
        {
            rear->next = createNode(data);
            rear = rear->next;
        }
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Empty Queue\nDequeueing not allowed\n";
        }
        else if (front == rear)
        {
            Node *temp = front;
            front = rear = NULL;
            delete temp;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int peek()
    {
        if (!isEmpty())
            return front->data;
    }

    void print()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << (temp->data) << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue()
    {
        if (!isEmpty())
        {
            Node *temp1 = front;
            Node *temp2 = NULL;
            while (temp1 != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
                delete temp2;
            }
        }
    }
};

int main()
{
    Queue Q1;
    int n = 0;
    while (1)
    {
        cout << "\nEnter \n";
        cout << "1.To Enqueue\n";
        cout << "2.To dequeue\n";
        cout << "3.To print\n";
        cout << "4.To view the front element\n";
        cout << "5.To exit\n";

        cin >> n;

        if (n == 5)
            break;
        switch (n)
        {
        case 1:
            cout << "Enter the element to be enqueued\n";
            cin >> n;
            Q1.enQueue(n);
            break;
        case 2:
            Q1.deQueue();
            break;
        case 3:
            Q1.print();
            break;
        case 4:
            cout << Q1.peek() << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}