#include<iostream>

using namespace std;

class Node
{
    public:
           int data;
           Node *next;
};

Node* Delete(Node *head,int x)
{
    Node *Head = head;
    if(head==0)
    {
        cout<<"An element can not be deleted roman empty list\n";
        return 0;
    }

    while(head->next!=0)
    {
        head=head->next;
        if(head->data==x)
        {
            head->next=0;
        }
    }

    return Head;
}