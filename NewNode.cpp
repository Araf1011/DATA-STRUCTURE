#incluude<iostream>
using namespace std;

class node
{
public:
    int val;
    node*next;
    node(int value)
    {
              this -> val =value;
              this -> next =nullptr;
    }
    node(node* next)
    {
              this -> next = next;
    }
};
class Linkedlist{
public:
          node*head;
          node*tail;
          Linkedlist()
          {
                    head = nullptr;
                    tail = nullptr;
          }
          void insertInFront(int value)
          {
                    node * newnode =new node(value);
                    id(head == null);
          }
          else{
                    newnode -> next = head;
                    head = newnode;
          }
};
int main()
{


    return 0;
}
