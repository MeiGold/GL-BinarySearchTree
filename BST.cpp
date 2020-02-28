//
// Created by golde on 2/26/2020.
//

#include "BST.h"
#include <iostream>

BST::BST():root(nullptr){}

BST::BST (Node* root):root(root){}

Node* BST::getRoot(){
    return root;
}

BST::~BST() {
    deleteNode(root);
}

void BST::add(int value){
    if(!root){
        root = new Node(value);
    }
    else addInTree(root,value);
}

void BST::inOrderOutput(Node* node){
    if(!node)return;
    if(node->left)inOrderOutput(node->left);
    std::cout<<node->value<<std::endl;
    if(node->right)inOrderOutput(node->right);
}

void BST::addInTree(Node* node, int value){
    if(node->value == value){
        return;
    }
    if(value < node->value){
        if(!node->left){
            node->left = new Node(value);
        }
        else{
            addInTree(node->left, value);
        }
    }
    else if(value > node->value){
        if(!node->right){
            node->right = new Node(value);
        }
        else{
            addInTree(node->right, value);
        }
    }
}

void BST::deleteNode(Node *node) {
    if(node){
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
    }
}

void BST::deleteFromTree(Node *node, int value) {
    if(!node)return;
    Node *parent = nullptr;
    while (node->value != value) {// find element to delete
        if (value < node->value) {
            if (node->left) {
                parent = node;
                node = node->left;
            } else break;
        } else if (value > node->value) {
            if (node->right) {
                parent = node;
                node = node->right;
            } else break;
        }
    }
    if (node->value == value) {// will be executed only if there is such element in the tree
        if (!node->left && !node->right) {// case 0: deleted node has 0 children
            if (parent->left == node) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete node;
            return;
        }

        if (node->left && node->right) {// case 2: deleted node has 2 children
            /* 1) We should find min from right subtree of deleted element (successor),
             * 2) set parent of the successor to nullptr
             * 3) then we replace node which will be deleted with successor
             * 4) connect parent of deleted element with successor
             * 5) set left and right nodes to newly placed successor
             */

            Node *minimum = node->right;
            Node *parentMinimum = nullptr;
            if (minimum->left)// find successor
                while (minimum->left) {
                    parentMinimum = minimum;
                    minimum = minimum->left;

                }
            if (parentMinimum)// set parent of successor to null
                if (parentMinimum->left == minimum) {
                    parentMinimum->left = nullptr;
                } else {
                    parentMinimum->right = nullptr;
                }
            if (parent) {
                if (parent->left == node) {// connect parent of deleted with successor
                    parent->left = minimum;
                } else { //(parent->right==node)
                    parent->right = minimum;
                }
            }

            minimum->left = node->left;// set children of new node
            if (node->right != minimum)
                minimum->right = node->right;
            else minimum->right = nullptr;

            if (!parent) root = minimum;// if deleted element is root
            delete node;
            return;
        } else {// case 1: deleted node has 1 child
            if (node->left) {
                if (parent->left == node) {
                    parent->left = node->left;
                } else {
                    parent->right = node->left;
                }
            } else {
                if (parent->left == node) {
                    parent->left = node->right;
                } else {
                    parent->right = node->right;

                }
            }
            delete node;
        }
        return;
    }

}

Node *BST::max(Node *node) {
    if(!node)return nullptr;
    Node *maximum = node;
    while (node->right) {
        maximum = node->right;
        node = node->right;
    }
    return maximum;
}

Node *BST::min(Node *node) {
    if(!node)return nullptr;
    Node *minimum = node;
    if(node->left)
    while (node->left) {
        minimum = node->left;
        node = node->left;
    }
    return minimum;
}