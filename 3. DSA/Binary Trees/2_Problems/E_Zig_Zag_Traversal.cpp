//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution{
    public:
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
    	queue<Node*> q;
    	q.push(root);
    	int l2r = 1;
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> res(size);
    	    
    	    for(int i=0;i<size;i++)
    	    {
    	        Node* temp  = q.front();
    	        q.pop();
    	        int idx = l2r? i: size-i-1;
    	        if(temp) res[idx] = temp->data;
    	        
    	        if(temp->left) q.push(temp->left);
    	        if(temp->right) q.push(temp->right);
    	    }
    	    l2r = (!l2r);
    	    for(auto val: res){
    	        ans.push_back(val);
    	    }
    	    
    	}
    	return ans;
    }
};
