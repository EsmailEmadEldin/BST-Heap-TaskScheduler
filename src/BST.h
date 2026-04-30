/// NAME: Esmail Emad El-Din Mohamed ///

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

// Node class representing a single task in the BST
class Node
{
public:
    string Description;
    int    Duration;
    string Category;
    Node*  left;
    Node*  right;

    Node(string Des, int Dur, string Cate, Node* l = nullptr, Node* r = nullptr)
        : Description(Des), Duration(Dur), Category(Cate), left(l), right(r) {}
};

// Binary Search Tree — keyed on task Duration
class BST
{
public:
    Node* root;

    BST() { root = nullptr; }

    // Insert a new task node in BST order (by duration)
    Node* INSERT(Node* n, string description, int duration, string category)
    {
        if (n == nullptr) return new Node(description, duration, category);

        if (duration <= n->Duration)
            n->left  = INSERT(n->left,  description, duration, category);
        else
            n->right = INSERT(n->right, description, duration, category);

        return n;
    }

    // Display all tasks in ascending duration order (in-order traversal)
    void INORDER(Node* n)
    {
        if (n == nullptr) return;
        INORDER(n->left);
        cout << "Description: " << n->Description
             << ", Duration: "  << n->Duration
             << ", Category: "  << n->Category << endl;
        INORDER(n->right);
    }

    // Search for all tasks matching a given duration
    void SEARCH(Node* n, int duration)
    {
        if (n == nullptr) return;

        if (n->Duration == duration)
        {
            cout << "Description: " << n->Description
                 << ", Duration: "  << n->Duration
                 << ", Category: "  << n->Category << endl;
            SEARCH(n->left, duration);  // duplicates may exist on the left
        }

        if (duration < n->Duration)
            SEARCH(n->left,  duration);
        else
            SEARCH(n->right, duration);
    }

    // Find the minimum-duration node in a subtree
    Node* ToFindMin(Node* n)
    {
        while (n->left != nullptr) n = n->left;
        return n;
    }

    // Remove the node with the given duration from the BST
    Node* REMOVE(Node* n, int duration)
    {
        if (n == nullptr) return nullptr;

        if (duration < n->Duration)
        {
            n->left  = REMOVE(n->left,  duration);
        }
        else if (duration > n->Duration)
        {
            n->right = REMOVE(n->right, duration);
        }
        else  // match found
        {
            if (n->left == nullptr)
            {
                Node* temp = n->right;
                delete n;
                return temp;
            }
            else if (n->right == nullptr)
            {
                Node* temp = n->left;
                delete n;
                return temp;
            }
            else  // two children — replace with in-order successor
            {
                Node* mini      = ToFindMin(n->right);
                n->Duration     = mini->Duration;
                n->Description  = mini->Description;
                n->Category     = mini->Category;
                n->right        = REMOVE(n->right, mini->Duration);
            }
        }
        return n;
    }

    // Display all tasks with duration >= given value
    void DISPLAYMORETHAN(Node* n, int duration)
    {
        if (n == nullptr) return;
        DISPLAYMORETHAN(n->left, duration);
        if (n->Duration >= duration)
        {
            cout << "Description: " << n->Description
                 << ", Duration: "  << n->Duration
                 << ", Category: "  << n->Category << endl;
        }
        DISPLAYMORETHAN(n->right, duration);
    }

    // Display all tasks with duration <= given value
    void DISPLAYLESSTHAN(Node* n, int duration)
    {
        if (n == nullptr) return;
        DISPLAYLESSTHAN(n->left, duration);
        if (n->Duration <= duration)
        {
            cout << "Description: " << n->Description
                 << ", Duration: "  << n->Duration
                 << ", Category: "  << n->Category << endl;
        }
        DISPLAYLESSTHAN(n->right, duration);
    }
};

#endif
