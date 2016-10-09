#include <iostream>
class Node
{
    int key;
    Node *left;
    Node *right;
public:
    Node()
    {
        left=NULL;
        right=NULL;
    }
    Node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
    Node* getLeft()
    {
        return left;
    }
    void setLeft(Node *l)
    {
        left=l;
    }
    Node* getRight()
    {
        return right;
    }
    void setRight(Node *r)
    {
        right=r;
    }
    int getKey()
    {
        return key;
    }
    void setKey(int k)
    {
        key=k;
    }
};
