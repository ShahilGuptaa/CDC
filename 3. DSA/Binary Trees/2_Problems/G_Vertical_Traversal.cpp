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
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        map< int,map<int,vector<int> > > mp; //hd,level,vector of nodes at that hd and level
        queue<pair<Node*,pair<int,int>>> q; //node, hd, level
        
        q.push( make_pair(root,make_pair(0,0)) );
        
        while(!q.empty())
        {
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();
            
            Node *curr = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            mp[hd][level].push_back(curr->data);
            
            if(curr->left){
                q.push( make_pair(curr->left,make_pair(hd-1,level+1)) );
            }
            if(curr->right){
                q.push( make_pair(curr->right,make_pair(hd+1,level+1)) );
            }
        }
        for(auto i:mp){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
