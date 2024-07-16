//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    vector<int> le,ri,leafs;
    
    void leftT(Node *root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) return;
        
        le.push_back(root->data);
        if(root->left) leftT(root->left);
        else leftT(root->right);
    }
    void rightT(Node *root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) return;
        
        ri.push_back(root->data);
        if(root->right) rightT(root->right);
        else rightT(root->left);
    }
    void ltraversal(Node *root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            leafs.push_back(root->data);
            return;
        }
        ltraversal(root->left);
        ltraversal(root->right);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        
        ans.push_back(root->data);
        if(root->left==NULL && root->right==NULL) return ans;
        
        if(root->left) leftT(root->left);
        if(root->right) rightT(root->right);
        
        ltraversal(root);
        
        reverse(ri.begin(),ri.end());
        
        for(auto val: le){
            ans.push_back(val);
        }
        for(auto val: leafs){
            ans.push_back(val);
        }
        for(auto val: ri){
            ans.push_back(val);
        }
        return ans;
    }
};
