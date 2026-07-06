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

class TwoStack {
     public:
        int *arr;
        int size;
        int top1;
        int top2;

    TwoStack(int size) {
        arr = new int[size];
        this->size = size;
        this->top1 = -1; //Not defined index
        this->top2 = size; //Not defined index
    }

    void push1(int data) {
        if(top2 - top1 == 1 ) {
            cout << "Stack Overflow";
            return;
        }
        top1++;
        arr[top1] = data;
    }

    void push2(int data) {
        if(top2 - top1 == 1) {
            cout << "Stack Overflow";
            return;
        }
        top2--;
        arr[top2] = data;
    }

    void pop1() {
        if(top1 == -1) {
            cout << "Stack Underflow";
            return;
        }
        arr[top1] = 0;
        top1--;
    }

    void pop2() {
        if(top2 == size) {
            cout << "Stack Underflow";
            return;
        }
        arr[top2] = 0;
        top2++;
    }

    bool isEmpty() {
        if(top1 == -1 && top2 == size) {
            return true;
        } 
        else {
            return false;
        }
    }

    ~TwoStack(){
        cout << "Destructor Called";
    }
};