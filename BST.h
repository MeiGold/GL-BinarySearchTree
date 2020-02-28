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
    Node():left(nullptr),right(nullptr),value(0){}
    Node(int value):left(nullptr),right(nullptr),value(value){}
};

class BST {
private:
    Node *root;
    void addInTree(Node *node, int value);
    void deleteNode(Node *node);
public:
    BST();
    BST(Node *root);
    ~BST();
    void add(int value);
    void inOrderOutput(Node *node);
    Node *getRoot();
    void deleteFromTree(Node *node, int value);
    Node *max(Node *node);
    Node *min(Node *node);
};


#endif //BINARYSEARCHTREE_BST_H
