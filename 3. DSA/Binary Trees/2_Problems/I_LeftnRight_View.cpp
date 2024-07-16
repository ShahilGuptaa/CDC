//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    
    map<int,int> mp; //level, value
    queue<pair<Node*,int>> q; //node add, level
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<Node*,int> temp = q.front(); q.pop();
        Node* curr = temp.first;
        int l = temp.second;
        
        mp[l] = curr->data;
        
        if(curr->left){
            q.push(make_pair(curr->left,l+1));
        }
        if(curr->right){
            q.push(make_pair(curr->right,l+1));
        }
    }
    for(auto i: mp){
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    
    map<int,int> mp; //level, value
    queue<pair<Node*,int>> q; //node add, level
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<Node*,int> temp = q.front(); q.pop();
        Node* curr = temp.first;
        int l = temp.second;
        
        if(mp.find(l)==mp.end()) mp[l] = curr->data;
        
        if(curr->left){
            q.push(make_pair(curr->left,l+1));
        }
        if(curr->right){
            q.push(make_pair(curr->right,l+1));
        }
    }
    for(auto i: mp){
        ans.push_back(i.second);
    }
    return ans;
}
