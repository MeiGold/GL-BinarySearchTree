//
// Created by golde on 2/26/2020.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

class Node {
public:
    Node *left;
    Node *right;
    int value;
    Node() {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
private:
    Node *root;
    void addInTree(Node *node, int value);
public:
    BST();
    BST(Node *root);
    Node *getRoot();
    void add(int value);
    void inorderOutput(Node *node);
};


#endif //BINARYSEARCHTREE_BST_H
