#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList {
public:
    LinkedList();
    struct Node {
        Node* next;
        int value;
    };

    Node* getHead();
    Node* getTail();
    void setHead(Node*);
    void setTail(Node*);
    bool isEmpty();
    void insertNode(int);
    void insertNode(unsigned, int);
    void deleteHead();
    void deleteNode(unsigned);
    void printList();

    int searchValue(int);

private:
    void initialize();
    void insertHead(int);
    void positionError(unsigned);
    void increaseLength();
    void decreaseLength();
    Node* createEmptyNode(int);

    Node* head = nullptr;
    Node* tail = nullptr;
    unsigned length = 0;
};

#endif // LINKEDLIST_H
