#include <iostream>

using namespace std;

//.....................previous linked list.................

/*

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **headref, int new_data)
{
    Node *new_node = new Node();
    //2
    new_node->data = new_data;
    //3
    new_node->next = (*headref);
    //4
    (*headref) = new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
    //1
    if (prev_node == 0)
    {
        cout << "The given previous element can not be null\n";
        return;
    }
    //2
    Node *new_node = new Node();
    //3
    new_node->data = new_data;
    //4
    new_node->next = prev_node->next;
    //5
    prev_node->next = new_node;
}

void append(Node **headref, int new_data)
{
    //1
    Node *new_node = new Node();
    //2
    new_node->data = new_data;
    //3
    new_node->next = 0;

    Node *last = (*headref); //to be used
    //4
    if ((*headref) == 0) //i.e if the list is empty
    {
        (*headref) = new_node;
    }
    else
    {
        while (last->next != 0) //else going to the last element
        {
            last = last->next;
        }
        //6
        last->next = new_node;
    }
}

void printList(Node *n)
{
    while (n != 0)
    {
        cout << (n->data) << "\t";
        n = n->next;
    }
    cout << endl;
}

Node *createList(int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int NodeCount(Node *n)
{
    int count = 0;
    while (n != NULL)
    {
        count++;
        n = n->next;
    }
    return count;
}

void DestroyList(Node *head)
{
    Node *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete head;
    }
}

Node *ReverseList(Node *head)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

/* 
//List reverse through recursion
Node *ReverseList(Node *head,Node *curr,Node *prev)
{
    if(curr == NULL)
    {
        head = prev;
        return head;
    }
    else
    {
        Node *temp = curr->next;
        curr->next = prev;
        return ReverseList(head,temp,curr);
    }  
}
 

bool isPalindrome(Node *Head)
{
    bool flag = true;
    Node *n = Head;
    Node *head2 = createList(Head->data);
    Head = Head->next;
    while (Head != NULL)
    {
        append(&head2, Head->data);
        Head = Head->next;
    }
    head2 = ReverseList(head2);

    Node *slow_ptr1 = n;
    Node *fast_ptr = n;
    Node *rev_ptr = head2;
    while (fast_ptr != NULL || fast_ptr->next != NULL)
    {
        if (rev_ptr->data != slow_ptr1->data)
        {
            flag = false;
            break;
        }
        else
        {
            slow_ptr1 = slow_ptr1->next;
            fast_ptr = fast_ptr->next->next;
            rev_ptr = rev_ptr->next;
        }
    }
    return flag;
}

void SwapNode(Node *head, int x, int y)
{
    if (x == y)
    {
        return;
    }
    
    Node *currX = head;
    Node *currY = head;
    Node *prevx = NULL;
    while (currX && currX->data != x)
    {
        prevx = currX;
        currX = currX->next;
    }

    Node *prevy = NULL;
    while (currY && currY->data != y)
    {
        prevy = currY;
        currY = currY->next;
    }

    if(currX == NULL||currY == NULL)
        return;


    if(prevx != NULL)
    {
        prevx->next = currY;
    }
    else
    {
        head = currY;
    }

    if(prevy != NULL)
    {
        prevy->next = currX;
    }
    else
    {
        head = currX;
    }
    
    Node *temp = currX;
    currX = currY;
    currY = temp;



    /*
    
    if (currX->next == currY)
    {
        Node *L1 = currX->next;
        currX->next = currY->next;
        Node *next2 = currY->next->next;
        currX->next->next = L1;
        L1->next = next2;
    }
    else
    {
        Node *temp = currX->next;
        Node *next2 = currY->next->next;
        currX->next = currY->next;
        currX->next->next = temp->next;
        currY->next = temp;
        temp->next = next2;
    }
}

int main()
{
    Node *Head = createList(1);
    append(&Head, 3);
    append(&Head, 5);
    append(&Head, 7);
    append(&Head, 9);
    append(&Head, 8);
    append(&Head, 11);
    printList(Head);
    //Head = ReverseList(Head);
    //printList(Head);
    //bool t = isPalindrome(Head);
    //cout<<"\n"<<t<<endl;
    SwapNode(Head, 7, 9);
    printList(Head);
    DestroyList(Head);
    return 0;
}
*/
//.....................previous linked list.................

struct Node
{
    int data;
    Node *next;
};

class LL
{
    Node *head;
    Node *end;
    int Length;

public:
    LL()
    {
        head = end = NULL;
        Length = 0;
    }

    Node *getNode(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        Length++;
        return newNode;
    }

    int LengthLL(Node *node, int length)
    {
        if (node == NULL)
        {
            return length;
        }
        else
        {
            return LengthLL(node->next, length + 1);
        }
    }

    int getLength()
    {
        return Length;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    void Reverse()
    {
        Node *prev, *curr, *next;
        prev = curr = next = NULL;
        prev = head;
        curr = head->next;
        head->next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void Push(int data)
    {
        if (head != NULL)
        {
            Node *newNode = getNode(data);
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *newNode = getNode(data);
            newNode->next = head;
            head = newNode;
            end = newNode;
        }
    }

    void Append(int data)
    {
        if (head != NULL)
        {
            Node *newNode = getNode(data);
            /*
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            end = newNode;
            */
            end->next = newNode;
            end = end->next;
        }
        else
        {
            Node *newNode = getNode(data);
            head = newNode;
            end = newNode;
        }
    }

    void insert(int N, int data)
    {
        if (head != NULL && N <= Length)
        {
            if (N == 1)
            {
                Push(data);
            }
            else if (N = Length)
            {
                Append(data);
            }
            else
            {
                int count = 1;
                Node *temp = head;
                while (count != N - 1)
                {
                    temp = temp->next;
                    count++;
                }
                Node *newNode = getNode(data);
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
        else if (N > Length)
        {
            Append(data);
        }
        else
        {
            cout << "Empty list\n";
            Push(data);
        }
    }

    void deleteNode(int n)
    {
        if (n == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            Length--;
        }
        else if (n > Length)
        {
            cout << "under flow\n";
        }
        else
        {
            int count = 1;
            Node *temp = head;
            while (count != n - 1 && (count < Length))
            {
                temp = temp->next;
                count++;
            }
            Node *currnode = temp->next;
            temp->next = currnode->next;
            delete currnode;
            Length--;
        }
    }

    void deleteList()
    {
        if (head != NULL)
        {
            Node *temp1 = head;
            Node *temp2 = NULL;
            while (temp1 != NULL)
            {
                temp2 = temp1;
                delete temp2;
                temp1 = temp1->next;
            }
        }
    }
};

int main()
{
    int n = 0;
    LL l1;
    while (1)
    {
        cout << "\nEnter\n";
        cout << "1. To add element in the list\n";
        cout << "2. To remove element from the list\n";
        cout << "3. To print the list\n";
        cout << "4. To exit\n";
        cin >> n;
        if (n == 4)
            break;
        switch (n)
        {
        case 1:
        {
            int m = 0, N = 0;
            cout << "Enter\n";
            cout << "1. To add element at the front\n";
            cout << "2. To add element at the last\n";
            cout << "3. To add element at Nth node\n";
            cin >> m;
            cout << "Enter the element\n";
            cin >> N;
            switch (m)
            {
            case 1:
                l1.Push(N);
                break;
            case 2:
                l1.Append(N);
                break;
            case 3:
                int pos = 0;
                cout << "Enter the position at which you want to insert the element\n";
                cin >> pos;
                l1.insert(pos, N);
                break;
            }
            break;
        }
        case 2:
        {
            int m = 0;
            cout << "\nEnter\n";
            cout << "1. To remove an element from the front\n";
            cout << "2. To remove an element from the end\n";
            cout << "3. To remove an element from the nth position\n";
            cin >> m;
            switch (m)
            {
            case 1:
                l1.deleteNode(1);
                break;
            case 2:
                l1.deleteNode(l1.getLength());
                break;
            case 3:
                int N = 0;
                cout << "Enter the position of element\n";
                cin >> N;
                l1.deleteNode(N);
                break;
            }
            break;
        }
        case 3:
        {
            l1.print();
            break;
        }
        default:
            break;
        }
    }

    l1.deleteList();

    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

struct node {
    int data;
    node *next;
};

node *get_node(int data) {
    node *new_node = new node();
    new_node->data = data;
    return new_node;
}


int main() {
    int n;
    cin >> n;
    int a = 0;
    cin >> a;
    node *head = get_node(a);
    cin >> a;
    node *temp = get_node(a);
    head->next = temp;
    for (int i = 0; i < n - 2; i++) {
        cin >> a;
        temp->next = get_node(a);
        temp = temp->next;
    }
    temp = head;

    node *prev = NULL, *curr = head, *next = head->next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    temp = head;
    for (int i = 0; i < n && (temp != NULL); i++, temp = temp->next) {
        cout << temp->data << " ";
    }
    cout << "\n";

    temp = head;
    while (temp->next != NULL) {
        node* temp2 = temp;
        temp = temp->next;
        delete temp2;
    }

    delete temp;

    return 0;
}


*/