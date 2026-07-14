#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverseAQueue(queue<int> &q) {
    stack<int> s;

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    //Now the queue is empty
    //Push the stack data into it
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}