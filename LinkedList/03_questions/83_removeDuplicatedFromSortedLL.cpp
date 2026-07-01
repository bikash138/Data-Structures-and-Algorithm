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

Node* headOfModifiedLL(Node* &head) {
    //As in the line 35 we are using next of head
    //So this dont forget to add this check
    if(head == NULL){
        return head;
    }
    Node*prev = head;
    Node* curr = head->next;

    while(curr != NULL) {
        if(prev->data == curr->data) {
            //delete curr node
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        } else {
            prev = curr;
            curr = curr->next;
        } 
    }
    return head;
}

//T.C: As we are tarversing to each node hence O(n)