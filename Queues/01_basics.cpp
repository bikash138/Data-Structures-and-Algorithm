#include<iostream>
using namespace std;

class Queue {
    public:
        int *arr;
        int front;
        int rear;
        int capacity;

    Queue(int size) {
        arr = new int[capacity];
        capacity = size;
        front = -1;
        rear = -1;
    }

    void push(int data) {
        // Overflow
        if(rear == capacity-1) {
            cout << "Queue is Full" << endl;
            return;
        } 
        // First Element
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = data;
        } 
        //Normal Insert
        else {
            rear++;
            arr[rear] = data;
        }
    }

    void pop() {
        // Underflow
        if(front == -1 && rear == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }
        // Case of first element and last element
        if(front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        } 
        // Normal pop
        else {
            arr[front] = -1;
            front++;
        }
    }

    int size() {
        if(front == -1 && rear == -1) return 0;
        return rear - front + 1; 
    }

    int getFrontElment() {
        //Check for empty queue
        if(front == -1) {
            cout << "Queue in empty" << endl;
            return -1;
        }
        int value = arr[front];
        return value;
    }

    int getBackElment() {
        //Check for empty queue
        if(rear == -1) {
            cout << "Queue in empty" << endl;
            return -1;
        }
        int value = arr[rear];
        return value;
    }

    ~Queue () {
        delete[] arr;
    }
};

class Dequeue {
    public:
        int *arr;
        int size;
        int front;
        int rear;
    
    Dequeue(int capacity) {
        arr = new int[capacity];
        size = capacity;
        front = -1;
        rear = -1;
    }

    void pushFront(int data) {
        // Empty Dequeu
        if(front == -1 && rear == -1) { 
            front++; rear++; 
            arr[front] = data; 
            return; 
        }
        // Dequeue is full
        if(rear - front + 1 == size){
            cout << "Dequeue is Full"  << endl;
            return;
        }
        if(front == 0) {
            cout << "No space at front" << endl;
            return;
        }
        // Normal Case
        front--;
        arr[front] = data;
    }

    void pushBack(int data) {
        // Overflow
        if(rear == size-1){
            cout << "Dequeue is Full" << endl;
            return; 
        }
        // Inserting first element
        if(front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = data;
        } 
        // Normal Case
        else {
            rear++;
            arr[rear] = data;
        }
    }

    void popFront() { 
        //Empty Dequeue
        if(front == -1 && rear == -1) {
            cout << "Dequeue is Empty" << endl;
            return;
        }
        // One element in the dequeue
        if(front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        } 
        // Normal Case
        else {
            arr[front] = -1;
            front++;
        }
    }

    void popBack() {
        //Empty Dequeue
        if(front == -1 && rear == -1) {
            cout << "Dequeue is Empty" << endl;
            return;
        }
        // One element in the dequeue
        if(front == rear) {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        } 
        // Normal Case
        else {
            arr[rear] = -1;
            rear--;
        }
    }

    ~Dequeue() {
        delete[] arr;
    }
};

class CircularQueue {
    public:
        int *arr;
        int size;
        int front;
        int rear;

    CircularQueue(int capacity) {
        arr = new int[capacity];
        size = capacity;
        front = -1;
        rear = -1;
    }

    void push(int value) {
        // Overflow
        // two cases
        if((front == 0 && rear == size - 1) || (rear == front -1)) {
            cout << "Overflow" << endl;
        }
        // q is empty
        else if(front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = value; 
        }
        // circular nature
        // rear at end should move to first only if front is not at 0
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = value;
        }
        // normal case
        else { 
            rear++;
            arr[rear] = value;
        }
    }

    void pop() {
        // underflow
        if(front == -1 && rear == -1) {
            cout << "Queue is empty" << endl;
        }
        // single element
        else if(front == rear) {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // circular nature
        else if(front == size-1) {
            arr[front] = -1;
            front = 0;
        }
        //normal case
        else {
            arr[front] = -1;
            front++;
        }
    }

    int getFront() {
        if(front == -1) {
            return -1;
        }
        return arr[front];
    }

    bool checkEmpty() {
        if(front == -1 && rear == -1){
            return true;
        } else {
           return false;
        }
    }

    int getSize() {
        if(front == -1 && rear == -1) {
            return 0;
        }
        // DOnt forget to handle the case of single element using <=
        else if (front <= rear) {
            return rear - front + 1;
        }
        else{
            return size - front + rear + 1;
        }
    }

    ~CircularQueue() { delete[] arr; }
};

void printDq(Dequeue &dq) {
    cout << "   front=" << dq.front << " rear=" << dq.rear << "  [";
    if(dq.front != -1) {
        for(int i = dq.front; i <= dq.rear; i++) {
            cout << dq.arr[i];
            if(i < dq.rear) cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Queue q(5);

    cout << "--- Empty queue ---" << endl;
    cout << "size: " << q.size() << endl;
    q.pop();                    // should say "Queue is Empty"
    q.getFrontElment();         // should say "Queue in empty"

    cout << "\n--- Pushing 10 20 30 ---" << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "size : " << q.size() << endl;
    cout << "front: " << q.getFrontElment() << endl;
    cout << "back : " << q.getBackElment() << endl;

    cout << "\n--- Popping once ---" << endl;
    q.pop();
    cout << "size : " << q.size() << endl;
    cout << "front: " << q.getFrontElment() << endl;
    cout << "back : " << q.getBackElment() << endl;

    cout << "\n--- Filling to capacity (5) ---" << endl;
    q.push(40);
    q.push(50);
    q.push(60);                 // rear hits capacity-1 -> "Queue is Full"
    cout << "size : " << q.size() << endl;

    cout << "\n--- Draining everything ---" << endl;
    while(q.size() > 0) {
        cout << "popping front = " << q.getFrontElment() << endl;
        q.pop();
    }
    cout << "size: " << q.size() << endl;
    q.pop();                    // underflow again


    /* ================= DEQUEUE ================= */
    cout << "\n\n========== DEQUEUE ==========" << endl;
    Dequeue dq(5);

    cout << "\n--- Empty dequeue ---" << endl;
    printDq(dq);
    dq.popFront();              // "Dequeue is Empty"
    dq.popBack();               // "Dequeue is Empty"

    cout << "\n--- pushBack 10, 20, 30 ---" << endl;
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    printDq(dq);

    cout << "\n--- pushFront 5 (front is at 0 -> no room) ---" << endl;
    dq.pushFront(5);            // "No space at front"
    printDq(dq);

    cout << "\n--- popFront once, then pushFront 5 ---" << endl;
    dq.popFront();              // front moves to 1, freeing slot 0
    printDq(dq);
    dq.pushFront(5);            // now front==1, so this DOES fit at slot 0
    printDq(dq);

    cout << "\n--- popBack once ---" << endl;
    dq.popBack();
    printDq(dq);

    cout << "\n--- Filling to capacity ---" << endl;
    dq.pushBack(40);
    dq.pushBack(50);
    dq.pushBack(60);            // exactly fills all 5 slots
    printDq(dq);
    dq.pushBack(70);            // now rear == size-1 -> "Dequeue is Full"

    cout << "\n--- Draining from both ends ---" << endl;
    dq.popFront();  printDq(dq);
    dq.popBack();   printDq(dq);
    dq.popFront();  printDq(dq);
    dq.popBack();   printDq(dq);
    dq.popFront();  printDq(dq);   // removes last element -> empty
    dq.popFront();                 // now truly empty -> "Dequeue is Empty"

    return 0;
}