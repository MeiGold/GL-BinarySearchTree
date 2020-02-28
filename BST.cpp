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
    while (node->value != value) {
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
    if (node->value == value) {
        if (!node->left && !node->right) {
            if (parent->left == node) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete node;
        }

        if (node->left && node->right) {
            Node *deleted = node;
            deleted = deleted->right;
            Node *minimum = deleted;
            Node *parentMinimum = nullptr;
            if (deleted->left)
                while (deleted->left) {
                    minimum = deleted->left;
                    parentMinimum = deleted;
                    deleted = deleted->left;
                }
            if (parentMinimum)
                if (parentMinimum->left == deleted) {
                    parentMinimum->left = nullptr;
                } else {
                    parentMinimum->right = nullptr;
                }
            if (parent->left == node) {
                parent->left = minimum;
            } else { //(parent->right==node)
                parent->right = minimum;
            }
            delete node;
        } else {
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