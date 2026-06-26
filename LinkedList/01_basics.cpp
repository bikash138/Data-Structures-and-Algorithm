#include <iostream>
#include <vector>
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

void insertNodeAtHead(Node* &head, Node* &tail, int data){
  //Check if the LL in empty or not
  if(head == NULL && tail == NULL) {
    //If empty then head + tail will be same
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    //If non empty the head will shifted to the new node
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }
}

void insertNodeAtTail(Node* &head, Node* &tail, int data) {
  //Check if the LL in empty or not
  if(head == NULL && tail == NULL) {
    //If empty then head + tail will be same
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    //If non empty the tail will shifted to the new node
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
  }
}

int getLengthofLinkedList(Node* head) {
  int count = 0;
  Node* temp = head;
  while(temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

void insertAtAnyPosition(Node* &head, Node* &tail, int data, int position) {
  int length = getLengthofLinkedList(head);

  //Handle the Invalid Position
  if(position < 1 || position > length){
    cout << "Invalid Position";
    return;
  }

  //Inserting at head
  if(position == 1) {
    insertNodeAtHead(head, tail, data);
    return;
  }

  //Inserting at tail
  if(position == length){
    insertNodeAtTail(head, tail, data);
    return;
  }

  //Insert at middle
  Node* newNode = new Node(data);
  Node* temp = head; 

  int i = 1;
  //Traverse the LL till one postion prior
  //And after each increament shift the temp pointer
  //That means temp is ahead of i hence we used postion - 1
  while( i < position - 1) {
    temp = temp->next;
    i++;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteNodeFromLL(Node* &head, Node* &tail, int position) {
  //Empty LL check
  if(head == NULL){
    cout << "Empty LL";
    return;
  }

  int length = getLengthofLinkedList(head);

  //For deletion of any node, the order is what keeps it safe:
  //1. RE-LINK: fix the list so no live node points into the victim
  //   (e.g. head = head->next, or prev->next = curr->next).
  //2. KEEP a copy of the victim in a temp BEFORE re-linking,
  //   otherwise you lose the address and leak the node.
  //3. DELETE temp -> frees the heap memory (runs destructor).
  //4. NULL only long-lived pointers (head/tail) so they don't dangle.
  //   Local temps are about to go out of scope, so nulling them is pointless.
  //Note: delete only frees memory; it does NOT change the pointer variable.

  //Check for single node
  if(head == tail) {
    delete head;
    head = NULL; //We pointed the nodes to null just because 
    tail = NULL; //they are the original passed pointers that needs to handled
    return;
  }

  //Delete the head node
  if(position == 1){
    Node* temp = head;
    head = head->next;
    delete temp;
  } //Delte the tail node
  else if(position == length) {
    Node* prev = head;
    while(prev->next->next != NULL){
      prev = prev->next;
    }
    Node* temp = tail;
    prev->next = NULL;
    tail = prev;
    delete temp;
  } //Delete the middle node
  else{
    Node* prev = head;
    int i = 1;
    //Go to the node just before the node whcih needs to be delted
    while(i < position - 1){
      prev = prev->next;
      i++;
    }
    Node* curr = prev->next;

    prev->next = curr->next;
    delete curr;
  }
}

//Small helper so we don't repeat the print/length lines everywhere
void show(Node* head, const string& label) {
  cout << label << " (length " << getLengthofLinkedList(head) << "): ";
  if(head == NULL) {
    cout << "empty" << endl;
    return;
  }
  head->print(head);
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  // ---------- CREATE ----------
  cout << "=== CREATE ===" << endl;
  insertNodeAtHead(head, tail, 10);   // [10]
  insertNodeAtHead(head, tail, 20);   // [20, 10]
  show(head, "After insert at head");

  insertNodeAtTail(head, tail, 30);   // [20, 10, 30]
  insertNodeAtTail(head, tail, 40);   // [20, 10, 30, 40]
  show(head, "After insert at tail");

  insertAtAnyPosition(head, tail, 99, 3); // insert 99 at position 3
  show(head, "After insert at position 3");

  // ---------- READ ----------
  cout << "\n=== READ ===" << endl;
  show(head, "Current list");
  cout << "Length is " << getLengthofLinkedList(head) << endl;

  // ---------- DELETE ----------
  cout << "\n=== DELETE ===" << endl;
  deleteNodeFromLL(head, tail, 1);    // delete head
  show(head, "After delete head (pos 1)");

  int len = getLengthofLinkedList(head);
  deleteNodeFromLL(head, tail, len);  // delete tail
  show(head, "After delete tail (last pos)");

  deleteNodeFromLL(head, tail, 2);    // delete a middle node
  show(head, "After delete middle (pos 2)");

  // ---------- CLEANUP (also tests single-node + empty cases) ----------
  cout << "\n=== CLEANUP (delete until empty) ===" << endl;
  while(head != NULL) {
    deleteNodeFromLL(head, tail, 1);
    cout << endl;            // destructor prints without a newline
    show(head, "After delete");
  }

  deleteNodeFromLL(head, tail, 1);    // delete on empty list
  cout << endl;

  return 0;
}

