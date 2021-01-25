#include "linkedlist.h"
#include <iostream>

// Constructor
LinkedList::LinkedList() {
    initialize();
}

// Initialize constructor call
void LinkedList::initialize() {}

// Get head of the list
LinkedList::Node* LinkedList::getHead() {
    return head;
}

// Get tail of the list
LinkedList::Node* LinkedList::getTail() {
    return tail;
}

// Set head node value
void LinkedList::setHead(LinkedList::Node* node) {
    head = node;
}

// Set tail node value
void LinkedList::setTail(LinkedList::Node* node) {
    tail = node;
}

// Default node constructor
LinkedList::Node* LinkedList::createEmptyNode(int value) {
    Node* temp = new Node;
    temp->next = nullptr;
    temp->value = value;

    return temp;
}

// Increase length call
void LinkedList::increaseLength() {
    ++length;
}

// Decrease length call
void LinkedList::decreaseLength() {
    --length;
}

// Print 'out of bound' error
void LinkedList::positionError(unsigned index) {
    std::cout << "Out of bound position (" << index << " -> len: " << length << ")" << std::endl;
}



// Check if the list is empty (head == nullptr)
bool LinkedList::isEmpty() {
    if (getHead() == nullptr) {
        return true;
    }

    return false;
}

// Push node at the end of the list
void LinkedList::insertNode(int value) {
    Node* temp = createEmptyNode(value);

    // If list is empty
    // Set tail and head to the new temp node
    if (isEmpty()) {
        setHead(temp);
        setTail(temp);

        increaseLength();
        return;
    }

    // Append new node at the end and set tail
    getTail()->next = temp;
    setTail(temp);

    increaseLength();
}

// Insert node in a specific position
void LinkedList::insertNode(unsigned index, int value) {
    // Check position index
    if (index > length) {
        positionError(index);
        return;
    }

    // Insert head (index == 0)
    if (index == 0) {
        insertHead(value);
        return;
    }


    Node* temp = createEmptyNode(value);

    Node* curr = getHead();
    // Set current index to position '1'
    unsigned currIndex = 1;

    // Reach node at requested position
    while (currIndex != index) {
        curr = curr->next;
        ++currIndex;
    }

    // If last position requested
    if (currIndex == length) {
        insertNode(value);
        return;
    }

    // Change pointers to insert node in
    temp->next = curr->next;
    curr->next = temp;

    increaseLength();
}

// Push node in the head of the list
void LinkedList::insertHead(int value) {
    Node* newHead = createEmptyNode(value);

    newHead->next = head;
    setHead(newHead);

    increaseLength();
}

// Remove head
void LinkedList::deleteHead() {
    setHead(getHead()->next);
    decreaseLength();
}

// Delete node in specific position
void LinkedList::deleteNode(unsigned index) {
    // Check position index
    if (index >= length) {
        positionError(index);
        return;
    }

    // Delete head (index == 0)
    if (index == 0) {
        deleteHead();
        return;
    }

    // Set curr node (head)
    Node* curr = getHead();
    unsigned currIndex = 1;

    // Stop when reach position OR the last element
    while (currIndex != index || currIndex != (length - 1)) {
        curr = curr->next;
        ++currIndex;
    }

    // Change tail if reached last element
    if (currIndex == (length - 1)) {
        setTail(curr);
        curr->next = nullptr;

        decreaseLength();
        return;
    }

    // Change next to remove element from list
    curr->next = curr->next->next;

    decreaseLength();
}

// Print list values
void LinkedList::printList() {
    Node* curr = head;

    if (head == nullptr) {
        std::cout << "Empty list" << std::endl;
        return;
    }

    while (curr->next != nullptr) {
        std::cout << curr->value << " ";
        curr = curr->next;
    }

    std::cout << curr->value << " | len = " << length << std::endl;
}

// Return node index if find value
// Return -1 if not find
int LinkedList::searchValue(int value) {
    Node* curr = getHead();
    int currIndex = 0;

    while(curr != nullptr) {
        if (curr->value == value) {
            return currIndex;
        }

        curr = curr->next;
        ++currIndex;
    }

    return -1;
}
