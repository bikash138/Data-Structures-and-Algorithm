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

Node* reverseKGroup(Node* head, int k) {
  //First Check if group of k available or not
  //Use simple LL traversal for this
  Node* temp = head;
  int count = 0;

  while(temp != NULL && count < k) {
    temp = temp->next;
    count++;
  }

  //If count is equals to k then group is available
  if(count == k) {
    //Reverse the group 
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    
    //Now we need to traverse the group again
    //But this time we will traverse to reverse the group
    int i = 0;
    while(i < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }
    //Now first group has been revered
    //Further work will be doen by recursion

    //forward becomes the new head of unmodified list
    Node* headReturnedBYRecursion = reverseKGroup(forward, k);

    //Now the head of each retunred group should be attached to the list
    head->next = headReturnedBYRecursion;

    //Now prev will remain as the head of the modified LL
    return prev;
  }
  //If the group was not availbale then this count would be less than k
  else{
    //Simply we can return the head because it dont need any modification
    return head;
  }
}