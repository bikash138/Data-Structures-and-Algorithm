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

    return 0;
}