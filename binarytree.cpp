#include <iostream>
#include <string>
using namespace std;

class node
{
    public:
    string info;
    node* leftchild;
    node* rightchild;

    node(string i, node* l, node* r)
    {
        info=i;
        leftchild=l;
        rightchild=r;
    }
};

class BinaryTree
{
    public:
    node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // initializing ROOT to null
    }
}