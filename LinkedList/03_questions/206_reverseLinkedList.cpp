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

//Reverse a Linked List USing Iterative Approach
void reverseLL (Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        //We need the next node so that we can keep the link of actual LL before updating curr
        Node* nextNode = curr->next;
        //1. Point the current node's next to the previous (in order to reverse it)
        curr->next = prev;
        //2. Shift the previois pointer forward
        prev = curr;
        //3. now use the next node to update the curr
        curr = nextNode;
    }
    //Dont forget to point the head to the prev at the end
    head = prev;
}

//Reverse LL using Recusrion
Node* reverseLLUsingRecursion(Node* &curr, Node* &prev){
    //In Recursion just solve the first case and else will be done by recursion
    //As we know when the current becomes NULL the prev lies on the last node
    if(curr == NULL) {
        return prev;
    }

    //Update the pointers for first node
    Node* nextNode = curr->next;
    curr->next = prev;

    //When it comes to second node in Recrsion:
    //nextNode becomes the new head while curr behaves as previous node 
    Node* reversedHead = reverseLLUsingRecursion(nextNode, curr);
    return reversedHead;
}

