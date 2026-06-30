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

Node* reverseLL (Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
      Node* nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }
    head = prev;
    return head;
}

Node* middleOfTheLinkedList(Node* &head){
    Node* fast = head;
    Node* slow = head;

    //Empty LL
    if(head == NULL) return NULL;

    while(fast != NULL && fast->next != NULL){
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
}

bool checkPalindromeLL(Node* &head) {
  //1. Get the middlenode of the Linked List
    Node* middlenode = middleOfTheLinkedList(head);

  /*2.Reverse the LL from the middlenode so that it become like:
    1 -> 2 -> 3 <- 2 <- 1 [For ODD length]
    1 -> 2 -> 2 <- 1 [For EVEN length]
   */
    Node* headOfReversedLL = reverseLL(middlenode);
  
  //3. Now simply compare the data for each of the LL to give the result
    while(headOfReversedLL != NULL) {
      if(head->data != headOfReversedLL->data) return false;
      head = head->next;
      headOfReversedLL = headOfReversedLL->next;
    }
    return true;
}