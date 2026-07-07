#include<stack>
#include<iostream>
#include<climits>
using namespace std;

void insertNumberInSortedStack(stack<int> &s, int data) {
    //base case
    //As the stack is already sorted so
    //Whenever a larger number arrives we need to stop checking
    if(s.empty() || data <= s.top()){ 
        s.push(data);
        return;
    }
    int top = s.top();
    s.pop();

    insertNumberInSortedStack(s, data);

    s.push(top);
}

//T.c -> O(n) as in worse case we need to pop all the elements from the stack