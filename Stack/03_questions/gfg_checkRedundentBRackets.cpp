#include<stack>
#include<iostream>
#include<string>
using namespace std;

bool checkRedundentParenthesis(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char c = s[i];
        //Push all the operators and starting bracket in the stack
        if(c == '(' || c == '+' || c == '-' || c == '/' || c == '*') {
            st.push(c);
        } 
        else if(c == ')') {
            /*
            If closing bracket comes then we need to make sure that
            At least operator lie between the last opening and this closing bracket
            Hence on every operator appearance we will maintain a count of it
            */ 
            int operatorCount = 0;
            //Keep popping the operator until '(' so that we can get the actaul operator count
            while(!st.empty() && st.top() != '(') {
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    operatorCount++;
                }
                st.pop();
            }
            //Now pop the opening bracket
            st.pop();

            //Now after popping the opening bracket if operator count is 0 then
            //redudency present 
            if(operatorCount == 0){
                return true;
            }
        }
    }
    //If we arrived here that means the stack becomes empty with no redundency
    return false;
}