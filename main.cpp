#include <iostream>
#include "BST.h"

int main() {
    std::cout << "Input elements which would be added to BST ending with \"0\" element:" << std::endl;
    BST tree;
    int elem;
    std::cin >> elem;
    while (elem != 0) {
        tree.add(elem);
        std::cin >> elem;
    }
    std::cout << "InOrder output of the tree:" << std::endl;
    if (tree.getRoot())
        tree.inOrderOutput(tree.getRoot());
    tree.deleteFromTree(tree.getRoot(), 7);
    std::cout << "After deletion:" << std::endl;
    tree.inOrderOutput(tree.getRoot());
}
