#include<stack>
#include<iostream>
using namespace std;

void printMiddleFromStack(stack<int> &s, int count, int totalSize) {
    //base case
    if(count == totalSize/2){
        cout << s.top() << endl;
        return;
    }

    int topElement = s.top();
    s.pop();
    count++;
    //Recursive Call
    printMiddleFromStack(s, count, totalSize);

    s.push(topElement);
}