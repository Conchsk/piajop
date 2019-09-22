// link https://leetcode-cn.com/problems/implement-trie-prefix-tree/
#include <iostream>
using namespace std;

class Trie
{
public:
    struct TrieNode
    {
        bool leaf;
        TrieNode *children[26];

        TrieNode(bool leaf) : leaf(leaf)
        {
            for (int i = 0; i < 26; ++i)
                children[i] = NULL;
        }
    };

    TrieNode head;

    /** Initialize your data structure here. */
    Trie() : head(false)
    {
    }

    void helper(TrieNode *p)
    {
        for (int i = 0; i < 26; ++i)
            if (p->children[i])
                helper(p->children[i]);
        delete p;
    }

    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
            if (head.children[i])
                helper(head.children[i]);
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *p = &head;
        for (auto it = word.begin(); it != word.end(); ++it)
        {
            if (!p->children[*it - 'a'])
                p->children[*it - 'a'] = new TrieNode(false);
            p = p->children[*it - 'a'];
        }
        p->leaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *p = &head;
        for (auto it = word.begin(); it != word.end(); ++it)
        {
            if (!p->children[*it - 'a'])
                return false;
            p = p->children[*it - 'a'];
        }
        return p->leaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *p = &head;
        for (auto it = prefix.begin(); it != prefix.end(); ++it)
        {
            if (!p->children[*it - 'a'])
                return false;
            p = p->children[*it - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
