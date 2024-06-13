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

    void search(string element, Node*& parent, Node*& currentNode)
    {
        // This function searches the currentNode of the specified Node as well as the current Node of its parent
        currentNode = ROOT;
        parent = NULL;
        while ((currentNode != NULL) && (currentNode->info != element))
        {
            parent = currentNode;
            if(element < currentNode->info)
               currentNode = currentNode->leftchild;
            else
               currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }
    void preorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }
    void postorder(Node* ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            x.insert(word);
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {
            x.preorder(x.ROOT);
            break;
        }
        case '4' :
        {
            x.postorder(x.ROOT);
            break;
        }
        case '5' :
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}