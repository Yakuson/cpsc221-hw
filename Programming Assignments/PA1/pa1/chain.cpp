#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
    // Your code here -- hint: this one is a single line!
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
    // Your code here
}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
    // Your code here!
}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
    // Your code here!
}

/*
* Modifies the current chain by "rotating" every k nodes by one position.
* In every k node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
    // Your code here!
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
    // Your code here!
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
    // Your code here!
}

/***********************************
 * swapColumns
 * parameters: 1 <= i <= numCols_
 *              1 <= j <= numCols_
 *
 * Swaps the positions of columns i and j
 * in the original grid of blocks by
 * moving nodes in the chain.
 *
 ***********************************/

void Chain::swapColumns(int i, int j) {

    // Your code here
}

/***********************************
 * swapRows
 * parameters: 1 <= i <= numRows_
 *              1 <= j <= numRows_
 *
 * Swaps the positions of rows i and j
 * in the original grid of blocks by
 * moving nodes in the chain.
 *
 ***********************************/
void Chain::swapRows(int i, int j) {

    // Your code here
}

