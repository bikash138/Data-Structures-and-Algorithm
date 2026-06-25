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

