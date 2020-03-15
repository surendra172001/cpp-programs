#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        prev = NULL;
        next = NULL;
    }
};

Node *Head = NULL;

void deleteList()
{
    Node *head = Head;
    Node *temp = NULL;
    while (head->next != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

Node *GetNewNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    return newNode;
}

void PushAtBack(int data)
{
    Node *newNode = GetNewNode(data);
    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        Node *iterator = Head;
        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = newNode;
        newNode->prev = iterator;
    }
}

void PushAtFront(int data)
{
    Node *newNode = GetNewNode(data);
    if (Head == NULL)
    {
        Head = newNode;
    }
    else
    {
        Node *temp = Head;
        Head = newNode;
        newNode->next = temp;
    }
}

void CreateList(int data)
{
    Node *newNode = GetNewNode(data);
    Head = newNode;
}

void PrintList()
{
    if (Head != NULL)
    {
        Node *temp = Head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    CreateList(1);
    Node *head = Head;
    for (int i = 9; i > 0; i--)
    {
        PushAtFront(i);
    }
    PrintList();
    deleteList();
    return 0;
}