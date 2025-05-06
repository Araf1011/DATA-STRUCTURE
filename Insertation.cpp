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

    int search(int val) {
        Node* temp = head;
        int position = 0;
        while (temp != NULL) {
            if (temp->data == val) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1; // Value not found
    }

    void insert_at(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position: Position cannot be negative" << endl;
            return;
        }

        Node* newNode = new Node(val);

        if (pos == 0 || head == NULL) { // Insert at front or empty list
            if (head == NULL) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            return;
        }

        Node* temp = head;
        int currentPos = 0;

        // Traverse to the node before the insertion point
        while (temp->next != NULL && currentPos < pos - 1) {
            temp = temp->next;
            currentPos++;
        }

        // If temp->next is NULL and pos > currentPos + 1, append at end
        if (temp->next == NULL && pos > currentPos + 1) {
            temp->next = newNode;
            tail = newNode;
        } else { // Insert in middle or at end
            newNode->next = temp->next;
            temp->next = newNode;
            if (newNode->next == NULL) {
                tail = newNode; // Update tail if inserted at end
            }
        }
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

    cout << "Original list: ";
    ll.printLL(); // 3->2->1->NULL

    cout << "Insert 10 at position 1: ";
    ll.insert_at(10, 1); // Insert 10 after 3
    ll.printLL(); // 3->10->2->1->NULL

    cout << "Insert 20 at position 0 (front): ";
    ll.insert_at(20, 0); // Insert 20 at front
    ll.printLL(); // 20->3->10->2->1->NULL

    cout << "Insert 30 at position 5 (end): ";
    ll.insert_at(30, 5); // Insert 30 at end
    ll.printLL(); // 20->3->10->2->1->30->NULL

    cout << "Insert 40 at position 10 (beyond length, append): ";
    ll.insert_at(40, 10); // Append 40 at end
    ll.printLL(); // 20->3->10->2->1->30->40->NULL

    cout << "Insert 50 at position -1 (invalid): ";
    ll.insert_at(50, -1); // Invalid position
    ll.printLL(); // 20->3->10->2->1->30->40->NULL

    cout << "Search 10: Position = " << ll.search(10) << endl; // Position = 2

    return 0;
}
