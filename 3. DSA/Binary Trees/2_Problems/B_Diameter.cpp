// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
#include<bits/stdc++.h>
using namespace std;


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

//O(N3)
class Solution {
  public:
    int height(Node* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        
        return (1 + max(height(root->left),height(root->right)) );
    }
    //O(N2)
    // Function to return the diameter of a Binary Tree -> this is becase height is getting called at every recursion
    int diameter(Node* root) {
        // Your code here
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        
        int ans = max(diameter(root->left),diameter(root->right));
        ans = max(ans,1+height(root->left)+height(root->right));
        
        return ans;
    }
};


//O(N2)
class Solution {
  public:
    pair<int,int> fastD(Node* root){
        if(root==NULL){
            return make_pair(0,0);   
        } 
        pair<int,int> h1 = fastD(root->left);
        pair<int,int> h2 = fastD(root->right);
        
        int op1 = h1.first;
        int op2 = h2.first;
        int op3 = 1 + h1.second + h2.second;
        
        int ans = max({op1,op2,op3});
        int h = 1 + max(h1.second,h2.second);
        
        return make_pair(ans,h);
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return fastD(root).first;
    }
};