//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==NULL) return 0;
        if(node->left == NULL && node->right==NULL) return 1;
        
        int h = 1;
        h = max(1+height(node->left),1+height(node->right));
        
        return h;
    }
};