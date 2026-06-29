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

Node* reverseLLInGroupOfK(Node* &head, int k) {
  int count = 0;
  Node* temp = head;

  while(temp != NULL && count < k){
    count++;
    temp = temp->next;
  }
  //If group exists
  if(count == k){
    //reverse one group and rest will be handled by recursion
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int i = 0;
    //K group is reversed
    while (i < k) {
      forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;
      i++;
    }
    Node* recursionKaHead= reverseLLInGroupOfK(forward, k);
    head->next = recursionKaHead;
    //Return the head of modified list
    return prev;
  } 
  //If grou pdont exists
  else {
    return head;
  }
}