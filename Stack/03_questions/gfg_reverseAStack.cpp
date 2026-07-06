#include<stack>
#include<iostream>
using namespace std;

void insertAtBottom(stack<int> &s, int value) {
    //Base Case: When the Stack becomes empty we need to stop and push the value
    if(s.empty()) {
        s.push(value);
        return;
    }

    int topElement = s.top(); //Keep the top element to return while backtracking
    s.pop(); //Pop it so that we can reach to the bottom of the stack

    //Recursion
    insertAtBottom(s, value);

    //While backtracking push back the elements back 
    s.push(topElement);
}

void reverseStack(stack<int> &s) {

    //Make the Stack empty using recursion
    if(s.empty()){
        return;
    }
    
    int topElement = s.top();
    s.pop();

    reverseStack(s);

    //While inserting back the values 
    //We need to insert at bottom because we want to reverse it 
    insertAtBottom(s, topElement);
}