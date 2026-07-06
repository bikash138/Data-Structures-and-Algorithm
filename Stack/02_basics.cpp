#include<iostream>
#include<stack>
using namespace std;

//Reversing is super easy using Stack
void reverseSomething() {
    string name = "bikash";
    stack<char> s;

    for(int i=0; i<name.length(); i++){
        s.push(name[i]);
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    reverseSomething();

    return 0;
}