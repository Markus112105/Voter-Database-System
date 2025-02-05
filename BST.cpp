#include "BST.h"
#include <iostream>
using namespace std;

// Constructor
BST::BST() {
    root = nullptr;
}

// Destructor
BST::~BST() {
    destroy(root);
}

BST::tNode* BST::getRoot() {
    return root;
}

BST::tNode* BST::insert(Voter* voter, int heapIndex) {
    tNode** current = &root; // pointer to root pointer
    while (*current != nullptr) {
        if (compareVoters(voter, (*current)->voter)) {
            current = &((*current)->left);
        } else if (compareVoters((*current)->voter, voter)) {
            current = &((*current)->right);
        } else {
            return nullptr;
        }
    }
    *current = new tNode(voter, heapIndex);
    return *current;
}

// Helper function to search for a voter by name in the BST
BST::tNode* BST::search(tNode* node, const string& first, const string& last) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->voter->getLastName() == last && node->voter->getFirstName() == first) {
        return node;
    }

    if (last < node->voter->getLastName() || 
        (last == node->voter->getLastName() && first < node->voter->getFirstName())) {
        return search(node->left, first, last);
    } else {
        return search(node->right, first, last);
    }
}

// Public function to search for a voter by name
BST::tNode* BST::search(const std::string& first, const std::string& last) {
    return search(root, first, last);
}


// Helper function to perform an inorder traversal and print the voters
void BST::inorder(tNode* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << "Name: " << node->voter->getFirstName() << " " 
                 << node->voter->getLastName() 
                 << ", Heap Index: " << node->heapIndex << endl;
        inorder(node->right);
    }
}

// Public function to traverse and show voters in sorted order
void BST::inorder() {
    inorder(root);
}

// Helper function to delete all nodes in the tree
void BST::destroy(tNode* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}