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

bool checkFOrCycle(Node* head) {

    //We will be using two pointers here
    //1. Fast Pointer: It will move two steps forward if the node exists
    //2. If fast pointer lies on a valid node then move the slow pointer to 1 step
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        //As we are trying to access the next to next node 
        //fast->next needs to be a valid node hence we kept the chekc in the while condition
        fast = fast->next->next;  
        //If a both fast and slow matches that means cycle exists
        if(slow == fast) return true;
    }
    return false;
}

/*
This algo works because after entering the loop 
fast pointer closes the gap by exactly after each step
whcih make both the pointer to collide insde the loop

T.C:
- For no cycle fast pointer is travelling at max n/2 times -> O(n)
- So max the gap between the fast node and slow is can be L(obsiously less than the cycle length)
  After every iteration the gap decreses by 1 between them

  Lets say the the length of list before the cycle starts is s(linear length of LL)
  hence at max total time will me O(s+L) = O(n)

S.C: O(1) we are using only two pointers
*/