#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty, cannot pop front" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL; // List becomes empty
        }
        delete temp; // Free memory
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is empty, cannot pop back" << endl;
            return;
        }
        if (head == tail) { // Single node
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) { // Find second-to-last node
            temp = temp->next;
        }
        delete tail; // Free last node
        tail = temp; // Update tail
        tail->next = NULL;
    }

    void delete_val(int val) {
        if (head == NULL) {
            cout << "List is empty, cannot delete" << endl;
            return;
        }
        if (head->data == val) { // Delete head
            pop_front();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Value " << val << " not found" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete == tail) {
            tail = temp; // Update tail if last node is deleted
        }
        delete toDelete; // Free memory
    }

    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~List() { // Destructor to free memory
        while (head != NULL) {
            pop_front();
        }
    }
};

int main() {
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);

    cout << "Original list: ";
    ll.printLL(); // 5->4->3->2->1->NULL

    cout << "After pop_front: ";
    ll.pop_front(); // Removes 5
    ll.printLL(); // 4->3->2->1->NULL

    cout << "After pop_back: ";
    ll.pop_back(); // Removes 1
    ll.printLL(); // 4->3->2->NULL

    cout << "After deleting 3: ";
    ll.delete_val(3); // Removes 3
    ll.printLL(); // 4->2->NULL

    cout << "After deleting 10 (not in list): ";
    ll.delete_val(10); // Value not found
    ll.printLL(); // 4->2->NULL

    return 0;
}
