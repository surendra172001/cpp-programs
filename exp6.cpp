#include <bits/stdc++.h>
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

BstNode *CreateBstNode(int data)
{
    BstNode *newBstNode = new BstNode;
    newBstNode->data = data;
    return newBstNode;
}

BstNode *INsert(BstNode *root, int data)
{
    if (root == NULL)
        root = CreateBstNode(data);

    else if (data <= root->data)
        root->left = INsert(root->left, data);

    else
        root->right = INsert(root->right, data);
    return root;
}

bool Search(BstNode *root, int data)
{
    if (root != NULL)
    {
        if (data <= root->data)
            return Search(root->left, data);

        else if (data > root->data)
            return Search(root->right, data);

        else
            return true;
    }
    else
        return false;
    /*BstNode *temp = root;
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
        }*/
}

int Min(BstNode *root)
{
    if (root != NULL)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }
    else
    {
        cout << "No elements in the BST\n";
        return -1;
    }
}

int Max(BstNode *root)
{
    if (root != NULL)
    {
        if (root->right == NULL)
            return root->data;
        else
            return Max(root->right);
    }
    else
    {
        cout << "No elements in the BST\n";
        return -1;
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

void DeleteBST(BstNode *root)
{
    if (root != NULL)
    {
        DeleteBST(root->left);
        DeleteBST(root->right);
        delete root;
    }
}

void LevelOrderPrint(BstNode *root)
{
    if (root != NULL)
    {
        queue<BstNode *> Q1;

        Q1.push(root);

        while (!Q1.empty())
        {
            BstNode *curr = Q1.front();
            Q1.pop();
            if (curr->left != NULL)
                Q1.push(curr->left);
            if (curr->right != NULL)
                Q1.push(curr->right);
            cout << curr->data << "\t";
        }
    }
}

void InOrderPrint(BstNode *root)
{
    if (root != NULL)
    {
        InOrderPrint(root->left);
        cout << root->data << endl;
        InOrderPrint(root->right);
    }
}

void PreOrderPrint(BstNode *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        PreOrderPrint(root->left);
        PreOrderPrint(root->right);
    }
}

void PostOrderPrint(BstNode *root)
{
    if (root != NULL)
    {
        PostOrderPrint(root->left);
        PostOrderPrint(root->right);
        cout << root->data << endl;
    }
}

bool IsBstUtil(BstNode *root, int min, int max)
{
    if (root != NULL)
    {
        if (root->data >= min && root->data < max && IsBstUtil(root->left, min, root->data) && IsBstUtil(root->right, root->data, max))
            return true;
        else
            return false;
    }
    else
        return true;
}

bool IsBst(BstNode *root)
{
    if (IsBstUtil(root, INT_MIN, INT_MAX))
        return true;
    else
        return false;
}

BstNode *FindMin(BstNode *root)
{
    if (root != NULL)
    {
        if (root->left == NULL)
            return root;
        else
            return FindMin(root->left);
    }
    else
        return root;
}

BstNode *DeleteNode(BstNode *root, int data)
{
    if (root != NULL)
    {
        if (data > root->data)
            root->right = DeleteNode(root->right, data);
        else if (data < root->data)
            root->left = DeleteNode(root->left, data);
        else
        {
            if (root->left == NULL && root->right == NULL) //case 1
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL) //case 2
            {
                BstNode *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL) //case 2
            {
                BstNode *temp = root;
                root = root->left;
                delete temp;
            }
            else //case 3
            {
                BstNode *temp = FindMin(root->right);
                root->data = temp->data;
                root->right = DeleteNode(root->right, temp->data);
            }
            return root;
        }
    }
    else
        return root;
}

BstNode *Find(BstNode *root, int data) //Related to inorder Successor
{
    if (root != NULL)
    {
        if (data < root->data)
            return Find(root->left, data);
        else if (data > root->data)
            return Find(root->right, data);
        else
            return root;
    }
    else
        return root;
}

BstNode *GetSuccessor(BstNode *root, int data)
{
    if (root != NULL)
    {
        BstNode *current = Find(root, data);
        if (current == NULL)
            return root;
        if (current->right != NULL)
            return FindMin(current->right);
        else
        {
            BstNode *Ancestor = root;
            BstNode *Successor = NULL;
            while (Ancestor != current)
            {
                if (current->data < Ancestor->data)
                {
                    Successor = Ancestor;
                    Ancestor = Ancestor->left;
                }
                else
                    Ancestor = Ancestor->right;
            }
            return Successor;
        }
    }
    else
        return root;
}

BstNode* levelOrderInsert(BstNode *root, int data)
{
    if (root != NULL)
    {
        queue< BstNode* > Q1;
        Q1.push(root);
        while (!Q1.empty())
        {
            BstNode *p = Q1.front();
            Q1.pop();
            if (p->left == NULL)
            {
                p->left = CreateBstNode(data);
                break;
            }
            else if (p->right == NULL)
            {
                p->right = CreateBstNode(data);
                break;
            }
            else
            {
                Q1.push(p->left);
                Q1.push(p->right);
            }
        }
        return root;
    }
    else
    {
        root = CreateBstNode(data);
        return root;
    }
    
}


inline bool full(BstNode *curr) {
    return (curr->left != NULL && curr->right != NULL);
}

inline bool leaf(BstNode *curr) {
    return (curr->left == NULL && curr->right == NULL);
}

bool is_CBT_I(BstNode *root) {
    if (root == NULL) {
        return true;
    }
    queue<BstNode*> q;
    q.push(root);
    bool non_full_node_seen = false;
    while(!q.empty()) {
        BstNode *curr = q.front();
        q.pop();
        if (curr->left) {
            if (non_full_node_seen) return false;
            q.push(curr->left);
        }
        else {
            non_full_node_seen = true;
        }

        if (root->right) {
            if (non_full_node_seen) return false;
            q.push(curr->right);
        }
        else {
            non_full_node_seen = true;
        }
    }
    return true;
}


int main()
{
    BstNode *root = NULL;
    int n = 0;
    int data = 0;
    while (1)
    {
        cout << "\nEnter\n";
        cout << "1. To add element to the Binary Search Tree\n";
        cout << "2. To search an element to the BST\n";
        cout << "3. To find min or max\n";
        cout << "4. To delete a node\n";
        cout << "5. To exit\n";
        cin >> n;
        if (n == 5)
        {
            break;
        }
        switch (n)
        {
        case 1:
            cout << "Enter the element to be inserted\n";
            cin >> data;
            root = INsert(root, data);
            break;
        case 2:
        {
            cout << "Enter the element to be searched\n";
            cin >> data;
            int p = 0;
            cout << "Enter\n";
            cout << "1. To search the element\n";
            cout << "2. To found the successor of the given element\n";
            cin >> p;
            switch (p)
            {
            case 1:
                if (Search(root, data))
                    cout << "Found\n";
                else
                {
                    cout << "Not found\n";
                }
                break;
            case 2:
                BstNode *holder = GetSuccessor(root, data);
                if (holder != NULL)
                    cout << holder->data << endl;
                else
                    cout << "No successor found\n";
            }
            break;
        }
        case 3:
        {

            int m = 0;
            cout << "\nEnter\n";
            cout << "1. To find min\n";
            cout << "2. To find max\n";
            cin >> m;
            switch (m)
            {
            case 1:
                cout << Min(root) << endl;
                break;
            case 2:
                cout << Max(root) << endl;
            }
            break;
        }
        case 4:
            char ch = 0;
            cout << "Want to view the nodes in order to select enter y/n\n";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
                InOrderPrint(root);
            int k = 0;
            cout << "Enter the element to be deleted\n";
            cin >> k;
            root = DeleteNode(root, k);
        }
    }

    cout << Height(root) << endl;

    cout << "Elements in the binary tree\n";

    InOrderPrint(root);
    cout << "\n\n"
         << endl;

    PreOrderPrint(root);
    cout << "\n\n"
         << endl;

    PostOrderPrint(root);
    cout << "\n\n"
         << endl;

    LevelOrderPrint(root);

    if (IsBst(root))
        cout << "The tree is binary search tree\n";
    else
        cout << "\nThe tree is not a binary search tree\n";


    DeleteBST(root);
    return 0;
}