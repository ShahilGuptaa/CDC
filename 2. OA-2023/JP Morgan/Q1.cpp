#include <bits/stdc++.h>
using namespace std;

// defined structure of node
struct Node
{
    int data;
    struct Node *left, *right;
    Node(int item)
    {
        data = item;
        left = right = NULL;
    }
};

// function defined to find the sum of cousins
int sum_of_the_cousins(Node *root, int key)
{
    if (root == NULL)
        return -1;

    // Root node has no cousins so return -1.
    if (root->data == key)
    {
        return -1;
    }

    // To store sum of cousins.
    int currSum = 0;

    // To store size of current level.
    int size;

    // applying BFS
    queue<Node*> q;
    q.push(root);
    bool found = false;

    while (!q.empty())
    {
        // if we found the node
        if (found == true)
        {
            return currSum;
        }

        size = q.size();
        currSum = 0;

        while (size)
        {
            root = q.front();
            q.pop();

            // checking for the left and right
            if ((root->left && root->left->data == key) || (root->right && root->right->data == key))
            {
                found = true;
            }
            else
            {
                if (root->left)
                {
                    currSum += root->left->data;
                    q.push(root->left);
                }

                if (root->right)
                {
                    currSum += root->right->data;
                    q.push(root->right);
                }
            }

            size--;
        }
    }

    return -1;
}

// creating binary tree from level order traversal
Node *insertValue(struct Node *root, int value, queue<Node*> &q)
{
    Node *node = new Node(value);

    if (root == NULL)
        root = node;
    else if (q.front()->left == NULL)
        q.front()->left = node;
    else
    {
        q.front()->right = node;
        q.pop();
    }

    q.push(node);

    return root;
}

// function defined to create tree
Node *createTree(int arr[], int n)
{
    Node *root = NULL;
    queue<Node*> q;

    for (int i = 0; i < n; i++)
    {
        root = insertValue(root, arr[i], q);
    }

    return root;
}

// Driver Code
int main()
{
    int k;
    cin >> k;
    int height;
    cin >> height;
    int n = pow(2, height + 1) - 1;
    int lvl[n];

    for (int i = 0; i < n; i++)
    {
        cin >> lvl[i];
        if (lvl[i] == -1)
            lvl[i] = 0;
    }

    Node* root = createTree(lvl, n);

    cout <<sum_of_the_cousins(root, k) << endl;
    return 0;
}
