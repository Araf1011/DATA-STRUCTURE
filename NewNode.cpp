#include <iostream>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int value)
    {
        this->val = value;
        this->next = nullptr;
    }
};
class linked_list
{
public:
    node *head;
    node *tail;
    linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insetinFront(int value)
    {
        node *newNode = new node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insertinBack(int value)
    {
        node *newNode = new node(value);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertinPos(int value, int pos)
    {
        node *newNode = new node(value);
        int cnt = 1;
        while (cnt!= pos-1)
        {
            head= head->next;
            cnt++;
        }
        newNode->next = head->next;
        head->next = newNode;
    }
};
 
void printList(linked_list lst){
    node* temp = lst.head;
    while (temp!= nullptr)
    {
        cout<<temp->val<<' ';
        temp = temp->next;
    }
 
}
 
    int main()
    {
        linked_list list;
        list.insetinFront(5);
        list.insetinFront(10);
        list.insertinBack(8);
        list.insertinBack(9);
        list.insertinPos(51, 2);
 
        printList(list);
 
 
    }
