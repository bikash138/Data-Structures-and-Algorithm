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

Node* reverseLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* headOfLL(Node* &head) {
    //Reverse the LL in order to make the addition
    head = reverseLL(head);
    //Initialise the variables
    int carry = 1;
    Node* temp = head;

    //Traverse the LL
    while(temp != NULL) {
        //Get the data of the node
        int data = temp->data;
        //Add the 1 to it
        int sum = data + carry;
        //Get the carry if its there
        //Ex: 5/10 = 0; 10/10 = 1
        carry = sum / 10;
        //Get the digit for the node
        int digit = sum%10;
        //Insert the digit in the node
        temp->data = digit;

        //Condition for addign the carry node
        if(temp->next == NULL && carry != 0){
            //create a extra node
            Node * newNode = new Node(carry);
            temp->next = newNode;
            temp = newNode;
        }
        //Update the temp with the new node
        temp= temp->next;
    }
    //Now reverse the final result to get the answer
    head = reverseLL(head);

}