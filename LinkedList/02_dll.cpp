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