#include<stack>
#include<iostream>
#include<climits>
using namespace std;

bool checkSortedStack(stack<int> &s, int prev) {
    //base case
    if(s.empty()){
        return true;
    };

    //Solve 1 case
    int top = s.top();
    if(prev > top){
        return false;
    } 
    else {
        s.pop();
        return checkSortedStack(s, top);
    }
     
}

int main () {
    stack<int> s;
    s.push(0);
    s.push(3);
    s.push(1);

    int prev = INT_MIN;
    cout << (checkSortedStack(s, prev) ? "Sorted" : "Not Sorted");
}