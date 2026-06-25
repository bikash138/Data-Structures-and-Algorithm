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
}

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
  if(position < 1 || position > length){
    cout << "Invalid Position";
    return;
  }
  if(position == 1) {
    insertNodeAtHead(head, tail, data);
    return;
  }
  if(position == length){
    insertNodeAtTail(head, tail, data);
    return;
  }
  Node* newNode = new Node(data);
  Node* temp = head; 

  int i = 1;
  //Traverse the LL till one postion prior
  //And after each increament shift the temp pointer
  //That means temp is ahead of i hence we used postion - 1
  while( i < postition - 1) {
    temp = temp->next;
    i++;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

