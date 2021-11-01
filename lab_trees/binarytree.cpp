/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file, as well as binarytree.h.
 */

#include <iostream>

using namespace std;

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function, with an additional
 * Node* parameter to allow for recursive calls. NOTE: use this as an example
 * for writing your own private helper functions.
 * @param subRoot
 * @return The height of the subtree.
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Your code here

    printLeftToRightsubroot(root);

    // Do not remove this line - used for correct print output
    cout << endl;
}

template <typename T>
void BinaryTree<T>::printLeftToRightsubroot(const Node* subroot) const
{
    // Your code here

    if (!subroot) {
        return;
    }

    //left
    printLeftToRightsubroot(subroot->left);
    cout << subroot->elem << " ";
    //right
    printLeftToRightsubroot(subroot->right);


//MY DUMB ATTEMPT THAT DOESN'T EVEN FUCKING WORK STUPID FUCKING 
//IDIOT
    // if (subroot->left != NULL) {
    //     printLeftToRightsubroot(subroot->left);
    // } else {
    //     cout << to_string(subroot->elem);
        
    //     //print the root here
    //     if (subroot->right != NULL) {
    //         printLeftToRightsubroot(subroot->right);
    //     } 
    // }
    
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 * (i.e. not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror(Node* subroot)
{
    if (!subroot) {
        return;
    }

    Node* originalLeft = subroot->left;
    Node* originalRight = subroot->right;

    subroot->left = originalRight;
    subroot->right = originalLeft;

    mirror(subroot->left);
    mirror(subroot->right);

}


/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards,
 * ending at a leaf node. Paths ending in a left node should be printed before
 * paths ending in a node further to the right.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{
    printAllPaths(root, "Path:");


}

template <typename T>
void BinaryTree<T>::printAllPaths(Node *subroot, string path) const
{
    // Your code here
    if (subroot == NULL) {
        return;
    }

    path = path + " " + to_string(subroot->elem);

    if (!subroot->left && !subroot->right) {
        cout << path << endl;
    }

    printAllPaths(subroot->left, path);
    printAllPaths(subroot->right, path);

}

/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root.
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // Your code here
    int count = 0;
    return sumAllDistances(root, count);
}

template <typename T>
int BinaryTree<T>::sumAllDistances(Node* subroot, int count) const
{
    // Your code here
    if (!subroot) {
        return 0;
    }

    return sumAllDistances(subroot->left, count + 1) + sumAllDistances(subroot->right, count + 1) + count;

}
/**
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
    // Your code here
    return isOrdered(root, NULL, NULL);
}

template <typename T>
bool BinaryTree<T>::isOrdered(Node* subroot, Node* min, Node* max) const
{

    if (!subroot) {
        return true;
    }

    bool subrootIsOrdered = true;

    if (min && subroot->elem < min->elem) {
        subrootIsOrdered = false;
    }

    if (max && subroot->elem > max->elem) {
        subrootIsOrdered = false;
    }

    bool isRightOrdered = isOrdered(subroot->right, subroot , max);
    bool isLeftOrdered = isOrdered(subroot->left, min , subroot);

    return isRightOrdered && isLeftOrdered && subrootIsOrdered;
}
