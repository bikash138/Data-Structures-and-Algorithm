#include<iostream>
using namespace std;

class Stack {
    public:
        int *arr;
        int size;
        int top;

    Stack(int size) {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data) {
        if(top == size - 1) {
            cout << "Stack Overflow";
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop() {
        if(top == -1) {
            cout << "Stack Underflow";
            return;
        }
        arr[top]=-1  ;
        top--;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        } 
        else {
            return false;
        }
    }

    int getTop() {
        if(isEmpty()) { cout << "Stack Empty"; return -1; }
        return arr[top];
    }

    int getSize() {
        return top+1;
    }

    ~Stack(){
        cout << "Destructor Called";
    }
};