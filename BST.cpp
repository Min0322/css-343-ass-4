#include "BST.h"
#include <stack>
#include <unordered_set>

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    clearHelper(root);
}

bool BST::insert (Book* ins)
{
    return insertHelper(root, ins);
}

bool BST::remove(Book*rem)
{
    return removeHelper(root, rem);
}

bool BST::getBook(const Book& findB, Book*& returnB) const
{
    return retrieveHelper(findB, returnB, root);
}

ostream& operator<< (ostream& out, const BST& tree)
{
    tree.printHelper(tree.root, out);
    cout << endl;
    return out;
}

void BST::clearHelper(Node* &cur)
{
    while (cur) {
        clearHelper(cur->left);
        clearHelper(cur->right);
        
        delete cur->b;
        cur->b = nullptr;
        delete cur;
        cur = nullptr;
    }
}


void BST::resetCounted()
{
    resetHelper(root);
}


bool BST::retrieveHelper(const Book& book1, Book*& found, Node* cur) const
{
    while (cur) {
        if (*cur->b == book1) {
            found = cur->b;
            return true;
        }
        else if (*cur->b > book1) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    return false;
}

bool BST::insertHelper(Node*& cur, Book* newBook)
{
    Node** temp = &cur;

    while (*temp) {
        if (*(*temp)-> b == *newBook) {
            // Duplicate exists, data not inserted
            return false;
        }
        else if (*(*temp)-> b > *newBook) {
            temp = &(*temp)->left;
        }
        else {
            temp = &(*temp)->right;
        }
    }

    *temp = new Node;
    (*temp)->b = newBook;
    (*temp)->left = nullptr;
    (*temp)->right = nullptr;

    return true;
}

void BST::printHelper(Node* cur, ostream& out) const
{
    if (cur != NULL)
    {
        printHelper(cur->left, out);
        out << cur->b->getTitle() << endl;
        printHelper(cur->right, out);
    }
}

bool BST::removeHelper(Node* &cur, Book* rem)
{
    if (cur == NULL) // book not found
        return false;
    else if (*cur->b == *rem) // book found
    {
        if (cur->left == NULL && cur->right == NULL) // no children
        {
            delete cur->b;
            cur->b = NULL;
            delete cur;
            cur = NULL;
        }
        else if (cur->left == NULL) // only right child
        {
            Node* temp = cur;
            cur = cur->right;
            delete temp->b;
            temp->b = NULL;
            delete temp;
        }
        else if (cur->right == NULL) // only left child
        {
            Node* temp = cur;
            cur = cur->left;
            delete temp->b;
            temp->b = NULL;
            delete temp;
        }
        else // both children
        {
            Node* temp = cur->right;
            while (temp->left != NULL)
                temp = temp->left;
            cur->b = temp->b;
            return removeHelper(cur->right, temp->b);
        }
        return true;
    }
    else if (*cur->b > *rem)
        return removeHelper(cur->left, rem);
    else
        return removeHelper(cur->right, rem);
}

void BST::resetHelper(Node* cur)
{
    if (cur != NULL)
    {
        resetHelper(cur -> left);
        cur -> b -> setCounted(false);
        resetHelper(cur -> right);
    }
}