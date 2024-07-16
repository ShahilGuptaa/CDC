//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        
        map<int,int> mp;
        queue<pair<Node*,int>> q; //node,hd
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp  = q.front(); q.pop();
            
            Node* curr = temp.first;
            int hd = temp.second;
            
            if(mp.find(hd)==mp.end())  mp[hd] = curr->data;
            
            if(curr->left){
                q.push(make_pair(curr->left,hd-1));
            }
            if(curr->right){
                q.push(make_pair(curr->right,hd+1));
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        map<int,int> mp; //hd,node->data
        queue<pair<Node*,int>> q; //node, hd
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* curr = temp.first;
            int hd = temp.second;
            
            mp[hd] = curr->data;
            if(curr->left){
                q.push(make_pair(curr->left,hd-1));
            }
            if(curr->right){
                q.push(make_pair(curr->right,hd+1));
            }
        }
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};