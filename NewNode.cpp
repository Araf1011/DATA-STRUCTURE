#include <bits\stdc++.h>
using namespace std;


class node{
 public:
    int val;
    node* next;
    node(int value)
    {
        this->val = value;
        this->next = nullptr;
    }
    node(node* next)
    {
        this->next = next;
    }
};
class Linkedlist{
  public:
    node* head;
    node* tail;
    Linkedlist()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertInFront(int value)
    {
        node* newnode = new node(value);
        if(head==NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }



};

void solve()
{
    Linkedlist myList;
    myList.insertInFront(5);
    cout<<myList.head->val;
}
int main()
{

    cout<<"Here is the usage of Linked List: \n";
    solve();

    return 0;
}
