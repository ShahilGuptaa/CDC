#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli, lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

/*
Pre Order traversal
1 3 7 11 5 17

In Order traversal
7 3 11 1 17 5

Post Order traversal
7 11 3 17 5 1
*/

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrdertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // separator
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << '\n';
            if (!q.empty())
            { // queue still has some element
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << ' ';

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        cout << root->data << ' ';
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->left);
        cout << root->data << ' ';
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << ' ';
    }
}

int height(struct node *root)
{
    // code here
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    int h = 1;
    h = max(1 + height(root->left), 1 + height(root->right));

    return h;
}

node *buildtree(node *root)
{
    cout << "Enter data: ";
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    root = new node(x);

    cout << "Enter left data for " << x << ":\n";
    root->left = buildtree(root->left);

    cout << "Enter right data for " << x << ":\n";
    root->right = buildtree(root->right);

    return root;
}

void buildFromLOT(node *&root)
{
    queue<node *> q;
    cout << "Enter root value: ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left data for " << temp->data << '\n';
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter right data for " << temp->data << '\n';
        cin >> data;
        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}

void solve()
{
    node *root = NULL;
    // root = buildtree(root); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    buildFromLOT(root); // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    cout << "\n\nLevel Order traversal\n";
    levelOrdertraversal(root);
    cout << "\n\nPre Order traversal\n";
    preorder(root);
    cout << "\n\nIn Order traversal\n";
    inorder(root);
    cout << "\n\nPost Order traversal\n";
    postorder(root);

    return;
}

int main()
{
    solve();
}