#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

class Node
{
public:
    char data;
    int freq;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char d)
    {
        freq = 1;
        data = d;
        terminal = false;
    }
};

class Trie
{
    Node *root;
    int cnt;

public:
    Trie() // constructor for trie
    {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(char *w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
                temp->freq += 1;
            }
            else
            {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
                temp->freq = 1;
            }
        }
        temp->terminal = true;
    }

    bool find(char *w)
    {
        Node *temp = root;
        for (int i = 0; w[i] != '\0'; i++)
        {
            char ch = w[i];
            if (temp->children.count(ch) == 0)
            {
                return false;
            }
            else
            {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }
};

int main()
{
}