#include "nodeClass.h"
#include "binaryTreeClass.h"
#include<stdlib.h>
#include<conio.h>
#include <array>

Node* createNode(int key)
{
    Node *n=new Node(key);
    return n;
}
int main()
{
    int choice;
    int key;
    Node *nnode=NULL;
    bool oddLeftSize=true;
    queue<Node*> leftExtremes,rightExtremes;
    BinaryTree b;
    do
    {
        system("cls");
        cout<<"1. Insert into Binary Tree"<<endl;
        cout<<"2. Display Tree"<<endl;
        cout<<"3. Alternate Nodes"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<endl<<"Enter choice :";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter key :";
            cin>>key;
            nnode=createNode(key);
            b.insertNode(nnode);
            cout<<"Node Inserted.";
            getch();
            break;

        case 2:
            if(!b.getRoot())
            {
                cout<<"The tree is empty!";
                getch();
                break;
            }
            cout<<"The tree now is:\n";
            b.displayTree();
            getch();
            break;

        case 3:
                if(!b.getRoot())
                {
                    cout<<"The tree is empty!";
                    getch();
                    break;
                }
                cout<<endl;
                leftExtremes=b.getLeftExtremes();

                if((leftExtremes.size()%2)==0)
                {
                    oddLeftSize=false;
                }
                rightExtremes=b.getRightExtremes();
                if(rightExtremes.size()>0 && leftExtremes.back()!=nnode && rightExtremes.back()!=nnode)
                {
                    rightExtremes.push(nnode);
                }
                cout<<"Left\tRight"<<endl;
                cout<<b.getRoot()<<"\t"<<b.getRoot()<<endl;
                for(int i=0;i<rightExtremes.size();i+=2)
                {
                    cout<<leftExtremes.front()->getKey()<<"\t"<<rightExtremes.front()->getKey()<<endl;
                    leftExtremes.pop();
                    rightExtremes.pop();
                    if(!rightExtremes.empty())
                    {
                        cout<<rightExtremes.front()->getKey()<<"\t"<<leftExtremes.front()->getKey()<<endl;
                        leftExtremes.pop();
                        rightExtremes.pop();
                    }
                }
                if(!leftExtremes.empty() && oddLeftSize)
                {
                    cout<<leftExtremes.front()->getKey();
                    leftExtremes.pop();
                }
                else if(!leftExtremes.empty())
                {
                    cout<<"\t"<<leftExtremes.front()->getKey();
                    leftExtremes.pop();
                    oddLeftSize=true;
                }
                getch();
                break;

        case 4:
            break;

        default:
            cout<<"Wrong choice!";
            getch();
        }
    }while(choice!=4);
    b.deleteTree();
}

