#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


struct trieNode {
    trieNode *left;
    trieNode *right;
    trieNode() {
        left = right = NULL;
    }
};

void insert(trieNode *head, int num) {

    trieNode *curr = head;

    // int type has 32 bits numbered from 0 - 31
    // so we are inserting a bit out of 31 bits for a number 
    // if that bit in number is not present in the trie
    for (int i = 31; i >= 0; i--) {
        // getting the bit value 1 or 0
        int b = num & (1 << i);

        if (b == 0) {
            // if bit is zero but left child of current root not exist
            // => that the bit is not inserted by any of the numbers till now
            // so we create left child of the current trieNode which is 
            // equivalent as inserting the bit 0
            if (!curr->left) {
                curr->left = new trieNode();
            }

            // otherwise the bit is already there so we need to go to left child of current node
            // and check for the next bit of the number
            curr = curr->left;
        }
        else {
            // again if current bit is 1 and right child of the current node doesn't exist
            // we will create right child which is equivalent of inserting bit 1
            if (!curr->right) {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
    
}


int getMax(int *arr, trieNode *head, int n) {

    int max_xor = INT_MIN;

    // A number pair will give a maximum result on xoring, 
    // if both the numbers in the pair are complementary to each other
    // we will iterate through each element in the array find its counterpart.
    // If the complement number of the current element is not present in the array,
    // the algorithm that is used finds the counterpart that has maximum number of complementary bits wrt the given number.
    // if it is present it will find that and we will get the maximum xor value,
    // which that pair can generate.
    // If that value is maximum till now we will store the result

    for (int i = 0; i < n; i++) {
        trieNode *curr = head;
        int curr_xor = 0;
        int num = arr[i];
        for (int j = 31; j >= 0; j--) {
            int b = num & (1 << j);
            if (b == 0) {
                if (curr->right != NULL) {
                    curr_xor += (1 << j);
                    curr = curr->right;
                }
                else {
                    curr = curr->left;
                }
            }
            else {
                if (curr->left != NULL) {
                    curr_xor += (1 << j);
                    curr = curr->left;
                }
                else {
                    curr = curr->right;
                }
            }
            if (curr_xor > max_xor) {
                max_xor = curr_xor;
            }
        }
    }

    // after finding maximum xor pair possible for each element, 
    // we will return greatest among all of them
    return max_xor;
}



int main() {
    trieNode *head = new trieNode();

    int n;
    cin >> n;
    int *arr = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        insert(head, arr[i]);
    }
    

    // getting maximum xor pair
    cout << getMax(arr, head, n) << "\n";

    delete [] arr;
    return 0;
}