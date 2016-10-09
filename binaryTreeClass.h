#include <queue>
using namespace std;
class BinaryTree
{
    Node *root;
    queue<Node*> inserted;
    void dispTree(Node*);
    void delTree(Node*);
public:
    BinaryTree()
    {
        root=NULL;
    }
    void insertNode(Node*);
    void displayTree()
    {
        dispTree(root);
    }
    void deleteTree()
    {
        delTree(root);
    }
    int getRoot()
    {
        if(root==NULL)
        {
            return 0;
        }
        return root->getKey();
    }
    queue<Node*> getLeftExtremes();
    queue<Node*> getRightExtremes();
};
void BinaryTree::insertNode(Node *nnode)
{
    if(root==NULL)
    {
        root=nnode;
        inserted.push(nnode);
        return;
    }

    if(inserted.front()->getLeft()!=NULL && inserted.front()->getRight()!=NULL)
    {
        inserted.pop();
    }
    if(inserted.front()->getLeft()==NULL)
    {
        inserted.front()->setLeft(nnode);
        inserted.push(nnode);
    }
    else
    {
        inserted.front()->setRight(nnode);
        inserted.push(nnode);
    }
}
void BinaryTree::dispTree(Node *root)
{
    if(root!=NULL)
    {
        dispTree(root->getLeft());
        cout<<root->getKey()<<" ";
        dispTree(root->getRight());
    }
}
void BinaryTree::delTree(Node *del)
{
    if(del!=NULL)
    {
        delTree(del->getLeft());
        delTree(del->getRight());
        delete del;
    }
}
queue<Node*> BinaryTree::getLeftExtremes()
{
    queue<Node*> l;
    Node *traverse=root->getLeft();
    while(traverse!=NULL)
    {
        l.push(traverse);
        traverse=traverse->getLeft();
    }
    return l;
}
queue<Node*> BinaryTree::getRightExtremes()
{
    queue<Node*> r;
    Node *traverse=root->getRight();
    while(traverse!=NULL)
    {
        r.push(traverse);
        traverse=traverse->getRight();
    }
    return r;
}
