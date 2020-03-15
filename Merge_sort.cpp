
#include<bits/stdc++.h>
using namespace std;

void merge(int input[], int start, int mid, int end) {
    int size = end - start + 1;
    int *aux = new int [size];

    int i = start, j = mid + 1, k = 0; 
    while (i <= mid && j <= end) {
        if (input[i] < input[j])
            aux[k] = input[i++];
        else 
            aux[k] = input[j++];
        k++;
    }

    while (i <= mid)
        aux[k++] = input[i++];
    
    while (j <= end)
        aux[k++] = input[j++];

    for (int i = 0; i < size; i++)
        input[start + i] = aux[i];

    delete [] aux;
}

void mergeSortUtil(int input[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSortUtil(input, start, mid);
        mergeSortUtil(input, mid + 1, end);
        merge(input, start, mid, end);
    }
}


inline void mergeSort(int input[], int size) {
    mergeSortUtil(input, 0, size - 1);
}

int main() {
    int size = 0;
    cin >> size;
    int *input = new int [size];
    for (int i = 0; i < size; i++)
        cin >> input[i];

    mergeSort(input, size);

    for (int i = 0; i < size; i++)
        cout << input[i] << " ";
    cout << endl;

    delete [] input;
    return 0;
}



/*

struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
    //Function to mergesort the linked list
    //It should return head of the modified list 
   

Node* getNode(int data) {
    Node *newNode = new Node(data);
    return newNode;
}


Node* merge(Node *head, int start, int mid, int end) {
    Node *midPtr = head, *headPtr = head, *auxPtr = NULL;
    
    // getting to the mid element of the list
    for (int i = start; i < mid; i++) midPtr = midPtr->next;
    
    int i = start, j = mid + 1;
    
    // initializing the auxillary list otherwise on doing temp->next in the upcoming while loop we will get segmentation fault
    if (head->data < midPtr->data) {
        auxPtr = getNode(head->data);
        midPtr = midPtr->next;
        i++;
    }
    else {
        auxPtr = getNode(midPtr->data);
        headPtr = headPtr->next;
        j++;
    }
    
    // Merging
    Node *temp = auxPtr;
    while (i <= mid && j <= end) {
        if (headPtr->data < midPtr->data) {
            temp->next = getNode(headPtr->data);
            headPtr = headPtr->next;
            i++;
        }
        else {
            temp->next = getNode(midPtr->data);
            midPtr = midPtr->next;
            j++;
        }
        temp = temp->next;
    }
    
    // copying the remianing values 
    while (i <= mid) {
        temp->next = getNode(headPtr->data);
        temp = temp->next;
    }
    
    while (j <= end) {
        temp->next = getNode(midPtr->data);
        temp = temp->next;
    }
    
    // updating the original list
    temp = auxPtr;
    headPtr = head;
    
    while (temp != NULL) {
        headPtr->data = temp->data;
        headPtr = headPtr->next;
        temp = temp->next;
    }
    
    // deleting the auxillary list
    while (auxPtr != NULL) {
        temp = auxPtr;
        auxPtr = auxPtr->next;
        delete temp;
        temp = NULL;
    }
    
    return head;
    
}
   
   
Node* mergeSortUtil(Node* head, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSortUtil(head, start, mid);
        mergeSortUtil(head, mid + 1, end);
        merge(head, start, mid, end);
    }
    return head;
}
   
Node* mergeSort(Node* head) {
    int len = 0;
    Node *temp = head;
    for (;temp != NULL; len++) temp = temp->next;
    return mergeSortUtil(head, 0, len - 1);
}


*/