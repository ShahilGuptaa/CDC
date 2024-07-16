#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *child[26];
    int cnt;
    vector<string> wend;
    node()
    {
        cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

class Trie
{
public:
    node *root;
    Trie()
    {
        root = new node();
    }

    void insert(string &s)
    {
        node *cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            cur->cnt++;
            int x = s[i] - 'a';
            if (cur->child[x] == NULL)
            {
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt++;
        cur->wend.push_back(s);
    }

    int countWordsEqualTo(string &s)
    {
        node *cur = root;
        int f = 1;
        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 'a';
            if (cur->child[x] == NULL)
            {
                f = 0;
                break;
            }
            cur = cur->child[x];
        }
        if (f)
            return cur->wend.size();
        else
            return 0;
    }

    int countWordsStartingWith(string &s)
    {
        node *cur = root;
        int f = 1;
        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 'a';
            if (cur->child[x] == NULL)
            {
                f = 0;
                break;
            }
            cur = cur->child[x];
        }
        if (f)
            return cur->cnt;
        else
            return 0;
    }

    void erase(string &s)
    {
        node *cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            cur->cnt--;
            int x = s[i] - 'a';
            cur = cur->child[x];
        }
        cur->cnt--;
        cur->wend.pop_back();
    }
};
