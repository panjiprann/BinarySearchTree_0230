#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    string info;
    Node* leftchild;
    Node* rightchild;

    Node(string i, Node* l, Node* r)
    {
        info=i;
        leftchild=l;
        rightchild=r;
    }
};

class BinaryTree
{
    public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // initializing ROOT to null
    }

    void insert(string element) // insert a node in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); // Allocate memory for the new node
        newNode->info = element; // Assign value to the data field of the new code
        newNode->leftchild = nullptr; // Make the left child of the new node point to null

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); // Locate the node which will be the parent of the node to be insert

        if (parent == nullptr) // if the parent is NULL (Tree is empty)
        {
            ROOT = newNode; // mark the new node as ROOT
            return; // exit
        }

        if (element < parent->info) // if the value in the data field of the new node is less thean that of the
        {
            parent->leftchild = newNode; // Make the left child of the parent point to the new point
        }
        else if (element > parent->info) // if the value in the data field of the new node is greater than
        {
            parent->rightchild = newNode; // Make the right child of the parent point to the new node
        }
    }
}