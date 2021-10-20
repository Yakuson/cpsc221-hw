#include "chain.h"

#include <cmath>
#include <iostream>

#include "chain_given.cpp"

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain() {
	clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block& ndata) {
	// Your code here
    
    Node* n_node = new Node(ndata);
    Node* tail = head_->prev;

    n_node->prev = tail_->prev;
    n_node->next = tail_;
    tail_->prev->next = n_node;
    tail_->prev = n_node;

    length_++;
    height_ = ndata.height();
    width_ = ndata.width();
}

/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 *
 */
void Chain::swap(int i, int j) {
	Node* iNode = walk(head_, i);
    Node* jNode = walk(head_, j);

    Node* iPrev = iNode->prev;
    Node* iNext = iNode->next;

    iNode->next = jNode->next;
    iNode->prev = jNode->prev;
    jNode->next->prev = iNode;
    jNode->prev->next = iNode;

    jNode->next = iNext;
    jNode->prev = iPrev;
    iPrev->next = jNode;
    iNext->prev = jNode;
}

/**
 * Reverses the chain
 */
void Chain::reverse() {
	Node* curr = head_;
    Node* tempNext;

    while (curr != NULL) {
        tempNext = curr->next;

        curr->next = curr->prev;
        curr->prev = tempNext;

        if (tempNext == NULL) {
            tail_ = head_;
            head_ = curr;
        }

        curr = tempNext;
    }
}

/*
 * Modifies the current chain by "rotating" every k nodes by one position.
 * In every k node sub-chain, remove the first node, and place it in the last
 * position of the sub-chain. If the last sub-chain has length less than k,
 * then don't change it at all.
 * Some examples with the chain a b c d e:
 *   k = 1: a b c d e
 *   k = 2: [b a] [d c] e
 *   k = 3: [b c a] d e
 *   k = 4: [b c d a] e
 * 			1 2 3 4 5
 */
void Chain::rotate(int k) {
	if (k > 1) {
        for (int i = 1; i < length_; i += k) {

            if ((i + (k - 1)) > length_) {
                break;
            }

            Node* start = walk(head_, i);
            Node* end = walk(head_, (i + (k - 1)));

            Node* startPrev = start->prev;
            Node* startNext = start->next;
            Node* endNext = end->next;

            start->prev->next = startNext;
            start->next->prev = startPrev;

            end->next->prev = start;
            end->next = start;

            start->next = endNext;
            start->prev = end;
        }
    }
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear() {

    Node* curr;
    while (head_ != NULL) {
        curr = head_->next;
        delete head_;
        head_ = curr;
    }
    head_ = NULL;
    tail_ = NULL;
    length_ = 0;
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const& other) {
	// Your code here!

    numCols_ = other.numCols_;
    numRows_ = other.numRows_;
    width_ = other.width_;
    height_ = other.height_;
    length_ = other.size();

    head_ = new Node();
    tail_ = new Node();
    head_->next = tail_;
    tail_->prev = head_;
    
    Node* temp = other.head_->next;
    while (temp != other.tail_ && temp != NULL) {
        
        insertBack(temp->data);
        temp = temp->next;
    }



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
    for (int y = 0; y < numRows_; y++) {
        swap(i + (y * numCols_), j + (y * numCols_));
    }
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
    for (int x = 0; x < numCols_; x++) {
        swap(x + (1 + (numCols_ * (i - 1))), x + (1 + (numCols_ * (j - 1))));
    }
}