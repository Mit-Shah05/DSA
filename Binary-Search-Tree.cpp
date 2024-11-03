#include <iostream>

using namespace std;

class Node
{
public:
    Node *right;
    Node *left;
    double data;

public:
    Node(double element) : left(NULL), right(NULL), data(element) {}
};

class Tree
{
private:
    Node *root;

public:
    Tree() : root(NULL) {}
    void insert(double element);
    void insertLeaf(Node *temp, double element);
    void remove(double key);
    void removeLeaf(Node *&temp, double key);
    void updateLeaf(Node *&temp);
    void print(Node *root, int space);
    void display();
};

void Tree::insert(double element)
{
    Node *newnode = new Node(element);

    if (root == NULL)
    {
        root = newnode;
    }

    else
    {
        insertLeaf(root, element);
    }
}

void Tree::insertLeaf(Node *temp, double element)
{
    if (temp->data > element)
    {
        if (temp->left == NULL)
        {
            temp->left = new Node(element);
        }
        else
        {
            insertLeaf(temp->left, element);
        }
    }
    else if (temp->data < element)
    {
        if (temp->right == NULL)
        {
            temp->right = new Node(element);
        }
        else
        {
            insertLeaf(temp->right, element);
        }
    }
}

void Tree::remove(double key)
{
    if (root == nullptr)
    {
        cout << "Empty" << endl;
    }
    else
    {
        removeLeaf(root, key);
    }
}

void Tree::removeLeaf(Node *&temp, double key)
{
    if (temp == nullptr)
        return;

    if (key < temp->data)
    {
        removeLeaf(temp->left, key);
    }
    else if (key > temp->data)
    {
        removeLeaf(temp->right, key);
    }
    else
    {
        updateLeaf(temp);
    }
}

void Tree::updateLeaf(Node *&temp)
{

    if (temp->left == NULL && temp->right == NULL)
    {
        delete temp;
        temp = NULL;
    }
    else if (temp->left == NULL)
    {
        Node *delNode = temp;
        temp = temp->right;
        delete delNode;
    }
    else if (temp->right == NULL)
    {
        Node *delNode = temp;
        temp = temp->left;
        delete delNode;
    }
    else
    {
        Node *succParent = temp;
        Node *succ = temp->right;

        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        temp->data = succ->data;

        if (succParent->right == succ)
        {
            succParent->right = succ->right;
        }
        else
        {
            succParent->left = succ->right;
        }

        delete succ;
    }
}

void Tree::print(Node *root, int space)
{
    if (root == NULL)
        return;

    int COUNT = 5;
    space += COUNT;

    print(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    print(root->left, space);
}

void Tree::display()
{
    print(root, 0);
}

int main()
{
    Tree bst;
    int choice;
    double element;

    while (true)
    {
        cout << "\nBinary Search Tree Operations Menu:\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Display tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to insert: ";
            cin >> element;
            bst.insert(element);
            cout << "Element inserted.\n";
            break;

        case 2:
            cout << "Enter element to delete: ";
            cin >> element;
            bst.remove(element);
            cout << "Element deleted (if present).\n";
            break;

        case 3:
            cout << "Diagrammatic Representation of the Binary Search Tree:\n";
            bst.display();
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice, please try again.\n";
        }
    }
}
