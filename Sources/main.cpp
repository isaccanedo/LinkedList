#include <iostream>
#include <linkedlist.h>

using namespace std;

int main() {
    LinkedList list;
    list.printList();

    // 2 3 4
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.printList();

    // 1 2 3 4
    list.insertNode(0, 1);
    list.printList();

    // 1 1 2 3 4
    list.insertNode(1, 1);
    list.printList();

    // 1 1 2 3 4 1 7
    list.insertNode(5, 1);
    list.insertNode(7);
    list.printList();

    // 1 2 3 4 1 7
    list.deleteHead();
    list.printList();

    // 2 3 4 1 7
    list.deleteNode(0);
    list.printList();

    // 2 3 4 1
    list.deleteNode(4);
    list.insertNode(12);
    list.deleteHead();
    list.printList();

    cout << "Search for 4: " << list.searchValue(4) << endl;
    cout << "Search for 3: " << list.searchValue(3) << endl;
    cout << "Search for 12: " << list.searchValue(12) << endl;
    return 0;
}
