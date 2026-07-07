#include<stack>
#include<iostream>
#include<string>
using namespace std;

bool isValidParenthesis(string s) {
    stack<char> st;
     
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        //Push all the starting brackets in the stack
        //If the corresponding closing bracket not found then simply return false
        if(c == '(' || c == '{' || c == '[' ){
            st.push(c);
        }
        else {
            //As we are accessing the top element we need to check its existence
            //Check the string starting from closing brackets like '){}'
            if(st.empty()) return false; 

            if( st.top() == '(' && c == ')' ) st.pop();
            else if(st.top() == '{' && c == '}') st.pop();
            else if(st.top() == '[' && c == ']') st.pop();
            else return false;
        }
    }
    //THis is very Important step which I forgot 
    //Always check if the stack is empty otherwise presence of brackets will make it invalid parenthesis 
    return st.empty();
}

int main() {
    string tests[] = { "()", "(", ")", "([)]", "{[()]}", "((()))", "{[}]" };

    for(string &t : tests) {
        cout << "\"" << t << "\" -> " << (isValidParenthesis(t) ? "Valid" : "Invalid") << endl;
    }
}
