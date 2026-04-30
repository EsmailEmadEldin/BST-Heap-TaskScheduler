/// NAME: Esmail Emad El-Din Mohamed ///

#include <iostream>
#include <fstream>
#include "BST.h"
#include "Heap.h"
using namespace std;

// Convert a string to all lowercase
string tolowercase(string str)
{
    for (int i = 0; i < (int)str.length(); i++)
        str[i] = tolower(str[i]);
    return str;
}

// Recursively search the BST for a task matching duration + partial description.
// If found: print it, move it to the heap, and remove it from the BST.
bool Find_And_Remove(Node*& n, int duration, string PartialDescription, Heap& h)
{
    if (n == nullptr) return false;

    string inputLower       = tolowercase(PartialDescription);
    string descriptionLower = tolowercase(n->Description);

    if (n->Duration == duration && descriptionLower.find(inputLower) != string::npos)
    {
        cout << "(" << n->Description << ", " << n->Duration << ", " << n->Category << ")" << endl;
        cout << "Task marked as completed and moved to heap." << endl;
        h.Insert(n->Description, n->Duration, n->Category);

        BST temp;
        n = temp.REMOVE(n, duration);
        return true;
    }

    if (Find_And_Remove(n->left,  duration, PartialDescription, h)) return true;
    return Find_And_Remove(n->right, duration, PartialDescription, h);
}

int main()
{
    BST  tree;
    Heap heap;

    // Load initial tasks from file
    ifstream infile("../data/tasks.txt");
    if (!infile)
    {
        cout << "Cannot open file tasks.txt" << endl;
        return 1;
    }

    int n;
    infile >> n;
    infile.ignore();

    for (int i = 0; i < n; i++)
    {
        string Des, Cate;
        int    Dur;
        getline(infile, Des);
        infile >> Dur;
        infile.ignore();
        getline(infile, Cate);
        tree.root = tree.INSERT(tree.root, Des, Dur, Cate);
    }
    infile.close();

    // Interactive menu
    int option;
    do
    {
        cout << "\n--------- MENU ---------" << endl;
        cout << "1. Insert a task (BST)"    << endl;
        cout << "2. Display all tasks (BST)" << endl;
        cout << "3. Search for a task (BST)" << endl;
        cout << "4. Remove a task (BST)"     << endl;
        cout << "5. Display tasks with duration MORE THAN (BST)" << endl;
        cout << "6. Display tasks with duration LESS THAN (BST)" << endl;
        cout << "7. Mark a task as completed (Heap)"             << endl;
        cout << "8. Display completed tasks and report (Heap)"   << endl;
        cout << "0. Exit"                   << endl;
        cout << "Select an option: ";
        cin >> option;
        cin.ignore();

        string Des, Cate;
        int    Dur;

        if (option == 1)
        {
            cout << "Enter the Description: ";
            getline(cin, Des);
            cout << "Enter the Duration: ";
            cin >> Dur;
            cin.ignore();
            cout << "Enter the Category: ";
            getline(cin, Cate);
            tree.root = tree.INSERT(tree.root, Des, Dur, Cate);
            cout << "Task added successfully." << endl;
        }
        else if (option == 2)
        {
            tree.INORDER(tree.root);
        }
        else if (option == 3)
        {
            cout << "Enter the Duration to search: ";
            cin >> Dur;
            cin.ignore();
            tree.SEARCH(tree.root, Dur);
        }
        else if (option == 4)
        {
            cout << "Enter the Duration to remove: ";
            cin >> Dur;
            cin.ignore();
            tree.root = tree.REMOVE(tree.root, Dur);
            cout << "Task removed." << endl;
        }
        else if (option == 5)
        {
            cout << "Enter the minimum Duration: ";
            cin >> Dur;
            cin.ignore();
            tree.DISPLAYMORETHAN(tree.root, Dur);
        }
        else if (option == 6)
        {
            cout << "Enter the maximum Duration: ";
            cin >> Dur;
            cin.ignore();
            tree.DISPLAYLESSTHAN(tree.root, Dur);
        }
        else if (option == 7)
        {
            cout << "Enter the Duration of the task to complete: ";
            cin >> Dur;
            cin.ignore();
            cout << "Enter part of the Description: ";
            getline(cin, Des);
            if (!Find_And_Remove(tree.root, Dur, Des, heap))
                cout << "No matching task found." << endl;
        }
        else if (option == 8)
        {
            heap.DisplayCompleteTasks();
        }
        else if (option == 0)
        {
            cout << "Exiting program." << endl;
        }
        else
        {
            cout << "Invalid option. Please try again." << endl;
        }

    } while (option != 0);

    return 0;
}
