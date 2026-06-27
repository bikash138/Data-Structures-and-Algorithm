#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node() {
      this->next = NULL;
    }
    Node(int data) {
      this->data = data;
      this->next = NULL;
    }
    void print(Node* head) {
      Node* temp = head;
      while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
      }
      cout << endl;
    }
    ~Node(){
      cout << "Destructor Called";
    }
};

//Q. We need to find the middle of the Linked List but without simple iterative appraoch.

/*
Brute Force Approach says:
1. Simply iterate over the nodes.
2. Get the length of the LL.
3. Then divide it by 2 to get the middle position.
4. Then again iterate to that middle posistion to get the value.

Here T.C = O(n+n/2) = O(3n/2)
*/

/*
So for this we have a pattern called: Fast and Slow Pointers
This is also called Totoise Algorithm
*/

/*
Fast and Slow pointer approach says:
1. Move the fast pointer by 2 steps.
2. After moving if the fast pointer lands on valid node.
3. Then move the slow pointer by 1 node.
4. This way when the fast pointer lands on the last node the slow pointer will be on the middle of the LL.

This happens because if fast pointer moves 2 times faster than slow poiter
then of course slower one will covers half distnace than faster one. 
THis appraoch takes T.C = O(n/2)
*/

int middleOfTheLinkedList(Node* &head){
    Node* fast = head;
    Node* slow = head;

    //Empty LL
    if(head == NULL) return 0;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}