#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* prev;
        Node* next;

    Node() {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next= NULL;
    }

    ~Node(){
        cout << "Destructor called";
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    //DLL is empty
    if(head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    } 
    else{ 
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    //DLL is empty
    if(head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

int getLengthOfDLL(Node* &head, Node* &tail){
    //We staring the count from 0 because
    //We need to consider the condtion of empty DLL where 
    //Both head and tail are NULL
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertNodeAnywhere(Node* &head, Node* &tail, int data, int position){
    int length = getLengthOfDLL(head, tail);
    if(position < 1 || position > length + 1){
        cout << "Invalid postions";
        return;
    }
    else if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }
    else if(position == length+1) {
        insertAtTail(head, tail, data);
        return;
    }
    Node* newNode = new Node(data);
    int i=1;
    Node* temp = head;
    while(i < position - 1){
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

bool searchInDDL(Node* &head, Node* &tail, int target){
    Node* front = head;
    Node* back = tail;
    //Odd no.of node: front will collide with back at same node hence first condition
    //Even no.of node: back will cross the front hence we writen fron->prev != back
    while(front != back && front->prev != back){
        if(front->data == target || back->data == target){
            return true;
        }
        front = front->next;
        back = back->prev;
    }
    //The front != NULL handles the empty DLL edge case
    return front != NULL && front->data == target;
}

void deleteNodeInDLL(Node* &head, Node* &tail, int position) {
    int length = getLengthOfDLL(head, tail);
    if(position < 1 || position > length) {
        cout << "Invalid position";
        return;
    }

    //Empty DLL
    if(head == NULL && tail == NULL){
        cout << "DLL is empty";
        return;
    }
    //Single node DLL
    if(head == tail) {
        //delete the heap memory
        delete head;
        //remove the dangling pointer
        head = NULL;
        tail = NULL;
        return;
    }
    //Deletion of head Node
    if(position == 1) {
        Node* temp = head;
        Node* secondNode = temp->next;

        //isolate the inital head node
        secondNode->prev = NULL;
        temp->next = NULL;
        head = secondNode;

        //delte the heap memory
        delete temp;
        return;
    }
    //Deletion of Tail Node
    if(position == length) {
        Node* lastNode = tail;
        Node* secondLastNode = tail->prev;

        //Isolate the the tail node
        secondLastNode->next = NULL;
        lastNode->prev = NULL;
        tail = secondLastNode;

        //delete the heap
        delete lastNode;
    } 
    //Random position 
    else {
        int i = 1;
        Node* curr = head;
        //Traverse to the node to be deleted
        while(i < position) {
            curr = curr->next;
            i++;
        }
        //Isolate the node to be delted
        Node* prev = curr->prev;
        prev->next = curr->next;
        curr->next->prev = prev;

        //clear heap
        delete curr;
    }
    
}

//Walk forward from head using ->next
void printForward(Node* head) {
    cout << "Forward : NULL <-> ";
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//Walk backward from tail using ->prev
//If this prints the same list reversed, the prev links are correct
void printBackward(Node* tail) {
    cout << "Backward: NULL <-> ";
    Node* temp = tail;
    while(temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    //Empty DLL: head and tail MUST start as NULL
    Node* head = NULL;
    Node* tail = NULL;

    cout << "Length of empty DLL: " << getLengthOfDLL(head, tail) << endl;

    // ---------- insert at head ----------
    cout << "\n=== insertAtHead ===" << endl;
    cout << "Inserting 10 at HEAD" << endl;
    insertAtHead(head, tail, 10);   // [10]
    cout << "Inserting 20 at HEAD" << endl;
    insertAtHead(head, tail, 20);   // [20, 10]
    cout << "Inserting 30 at HEAD" << endl;
    insertAtHead(head, tail, 30);   // [30, 20, 10]
    printForward(head);
    printBackward(tail);

    // ---------- insert at tail ----------
    cout << "\n=== insertAtTail ===" << endl;
    cout << "Inserting 40 at TAIL" << endl;
    insertAtTail(head, tail, 40);   // [30, 20, 10, 40]
    cout << "Inserting 50 at TAIL" << endl;
    insertAtTail(head, tail, 50);   // [30, 20, 10, 40, 50]
    printForward(head);
    printBackward(tail);
    cout << "Length now: " << getLengthOfDLL(head, tail) << endl;

    // ---------- insert anywhere ----------
    cout << "\n=== insertNodeAnywhere ===" << endl;
    cout << "Inserting 99 at POSITION 3 (middle)" << endl;
    insertNodeAnywhere(head, tail, 99, 3);  // middle: lands at position 3
    printForward(head);
    printBackward(tail);

    cout << "\nInserting 1 at POSITION 1 (routes to head insert)" << endl;
    insertNodeAnywhere(head, tail, 1, 1);   // position 1 -> acts as head insert
    printForward(head);
    printBackward(tail);

    int len = getLengthOfDLL(head, tail);
    cout << "\nInserting 100 at POSITION " << len + 1
         << " (length+1 -> append at tail)" << endl;
    insertNodeAnywhere(head, tail, 100, len + 1); // append at length+1
    printForward(head);
    printBackward(tail);

    // ---------- invalid position ----------
    cout << "\n=== invalid position ===" << endl;
    cout << "Trying to insert 777 at POSITION 0 (< 1): ";
    insertNodeAnywhere(head, tail, 777, 0);   // position < 1
    cout << endl;
    cout << "Trying to insert 888 at POSITION 999 (> length+1): ";
    insertNodeAnywhere(head, tail, 888, 999); // position > length+1
    cout << endl;

    cout << "\nFinal length: " << getLengthOfDLL(head, tail) << endl;

    // ---------- delete node ----------
    // List at this point: [1, 30, 99, 20, 10, 40, 50, 100]
    cout << "\n=== deleteNodeInDLL ===" << endl;
    printForward(head);

    cout << "\nDeleting HEAD (position 1)" << endl;
    deleteNodeInDLL(head, tail, 1);
    printForward(head);
    printBackward(tail);

    cout << "\nDeleting TAIL (position " << getLengthOfDLL(head, tail) << ")" << endl;
    deleteNodeInDLL(head, tail, getLengthOfDLL(head, tail));
    printForward(head);
    printBackward(tail);

    cout << "\nDeleting MIDDLE (position 3)" << endl;
    deleteNodeInDLL(head, tail, 3);
    printForward(head);
    printBackward(tail);

    cout << "\nDeleting invalid position 0: ";
    deleteNodeInDLL(head, tail, 0);
    cout << endl;

    cout << "Deleting invalid position 999: ";
    deleteNodeInDLL(head, tail, 999);
    cout << endl;

    // delete until single node remains, then delete it
    int remaining = getLengthOfDLL(head, tail);
    cout << "\nDeleting down to last node (" << remaining << " nodes remaining)" << endl;
    while(getLengthOfDLL(head, tail) > 1)
        deleteNodeInDLL(head, tail, 1);
    printForward(head);
    cout << "Deleting the single remaining node" << endl;
    deleteNodeInDLL(head, tail, 1);
    printForward(head);
    cout << "head = " << head << ", tail = " << tail << endl;

    return 0;
}