//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

#include <bits/stdc++.h>
using namespace std;
// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int flag = 1;
    int height(Node *root){
        if(root==NULL) return 0;
        
        int hl = height(root->left);
        int hr = height(root->right);
        
        if(abs(hl-hr)>1) flag = 0;
        
        return max(hl,hr)+1;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int h = height(root);
        return flag;
    }
};
