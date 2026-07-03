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

Node* segregatePlace(Node *head) {
    Node* temp = head;

    //We are at first creating the containers for each of 1s, 2s and 0s
    //We are using the tail pointer too in order to attach these three sets of nodes later
    Node* zerosHead = NULL, *zerosTail = NULL;
    Node* onesHead  = NULL, *onesTail  = NULL;
    Node* twosHead  = NULL, *twosTail  = NULL;

    while (temp != NULL) {
        //We will isolate the Node hence temp is forwarded at first
        //After tehat we made the current node isolated
        Node* current = temp;
        temp = temp->next;
        current->next = NULL;

        if (current->data == 0) {
            if (zerosHead == NULL) zerosHead = zerosTail = current;
            else { zerosTail->next = current; zerosTail = current; }
        }
        else if (current->data == 1) {
            if (onesHead == NULL) onesHead = onesTail = current;
            else { onesTail->next = current; onesTail = current; }
        }
        else {
            if (twosHead == NULL) twosHead = twosTail = current;
            else { twosTail->next = current; twosTail = current; }
        }
    }

    Node* newHead = NULL;
    Node* newTail = NULL;

    Node* parts[3] = { zerosHead, onesHead, twosHead };
    Node* tails[3] = { zerosTail, onesTail, twosTail };

    for (int i = 0; i < 3; i++) {
        if (parts[i] == NULL) continue;
        if (newHead == NULL) {
            newHead = parts[i];
            newTail = tails[i];
        } else {
            newTail->next = parts[i];
            newTail = tails[i];
        }
    }

    return newHead;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);

    Node printer;
    cout << "Before: ";
    printer.print(head);

    Node* newHead = segregatePlace(head);
    cout << "After:  ";
    printer.print(newHead);

    return 0;
}