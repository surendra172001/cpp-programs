#include <iostream>

using namespace std;

const int MAX = 5;

class Queue
{
    int arr[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((rear + 1) % MAX == front)
            return true;
        else
            return false;
    }

    void enQueue(int data)
    {
        if (isFull())
            cout << "No space available\n";
        else if (isEmpty())
        {
            front++;
            rear++;
            arr[rear] = data;
        }
        else
        {
            rear = (rear + 1) % MAX;
            arr[rear] = data;
        }
    }

    void deQueue()
    {
        if (isEmpty())
            cout << "Underflow\n";
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Empty Queue\n";
            return -1;
        }
        else
            return arr[front];
    }

    void print()
    {
        if (rear != MAX - 1)
        {
            for (int i = front; i != (rear + 1) % MAX; i = (i + 1) % MAX)
            {
                cout << arr[i] << "\t";
            }
            cout << endl;
        }
        else
        {
            for (int i = front; i < MAX; i++)
            {
                cout << arr[i] << "\t";
            }
            cout << endl;
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