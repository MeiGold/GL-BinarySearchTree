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