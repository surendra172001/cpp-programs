#include <iostream>

using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
    BstNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    ~BstNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

class BST
{
    BstNode *root;
    int count;

public:
    BST()
    {
        root = NULL;
    }

    BstNode *CreateBstNode(int data)
    {
        BstNode *newBstNode = new BstNode;
        newBstNode->data = data;
        return newBstNode;
    }

    //BstNode *INsert(BstNode* root,int data);

    void Insert(int data)
    {
        if (root == NULL)
        {
            cout << "yo\n";
            root = CreateBstNode(data);
            cout << root << endl;
        }
        else
        {
            int count = 0;
            BstNode *temp = root;
            while (temp != NULL)
            {
                cout << ++count << endl;
                if (data > temp->data)
                {
                    temp = temp->right;
                    cout << temp << endl;
                }
                else if (data < temp->data)
                {
                    temp = temp->left;
                    cout << temp << endl;
                }
            }
            if (temp == NULL)
            {
                temp = CreateBstNode(data);
                cout << temp << endl;
            }
        }
    }

    BstNode *getRoot()
    {
        return root;
    }

    bool Search(int data)
    {
        if (root == NULL)
        {
            return false;
        }
        else
        {
            BstNode *temp = root;
            while (temp != NULL)
            {
                if (temp->data == data)
                {
                    return true;
                }
                else if (temp->data <= data)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            if (temp == NULL)
            {
                cout << "Element not present\n";
                return false;
            }
        }
    }

    void EDeleteBstNode(BstNode *holder)
    {
        if (holder != NULL)
        {
            if (holder->left != NULL)
            {
                EDeleteBstNode(holder->left);
            }
            if (holder->right != NULL)
            {
                EDeleteBstNode(holder->right);
            }
            delete holder;
        }
    }

    void DeleteBST()
    {
        if (root != NULL)
        {
            EDeleteBstNode(root);
        }
        else
        {
            cout << "Empty BST\n";
        }
    }

    int Height(BstNode *Head)
    {
        if (Head != NULL)
        {
            int L = Height(Head->left);
            int R = Height(Head->right);
            return (L > R ? L : R) + 1;
        }
        else
        {
            return -1;
        }
    }

    int Min()
    {
        if (root != NULL)
        {
            BstNode *temp = root;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            return temp->data;
        }
        else
        {
            cout << "No elements in the BST\n";
        }
    }

    int Max()
    {
        if (root != NULL)
        {
            BstNode *temp = root;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            return temp->data;
        }
        else
        {
            cout << "Noelements in the BST\n";
        }
    }
};

/*
BstNode* BST::INsert(BstNode* root,int data)
{
    if(root == NULL)
    {
        root = CreateBstNode(data);
    }
    else if(data > root->data)
    {
        root->right = INsert(root->right,data);
    }
    else if(data < root->data)
    {
        root->right = INsert(root->left,data);
    }
    return root;
}
*/

int main()
{
    BST B1;
    int n = 0;
    int data = 0;
    while (1)
    {
        cout << "\nEnter\n";
        cout << "1. To add element to the Binary Search Tree\n";
        cout << "2. To Search an element to the BST\n";
        cout << "3. To exit\n";
        cin >> n;
        if (n == 3)
        {
            break;
        }
        switch (n)
        {
        case 1:
            cout << "Enter the element to be inserted\n";
            cin >> data;
            B1.Insert(data);
            break;
        case 2:
            cout << "Enter the element to be searched\n";
            cin >> data;
            if (B1.Search(data))
                cout << "Found\n";
            else
            {
                cout << "Not found\n";
            }
            break;
        }
    }

    cout << B1.Height(B1.getRoot()) << endl;

    B1.DeleteBST();
    return 0;
}