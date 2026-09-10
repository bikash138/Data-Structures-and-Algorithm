#include<iostream>
using namespace std;

string toggleCase(string &s) {
    for(int i=0; i<s.length(); i++) {
        // Remember this formula
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        } else {
            s[i] = s[i] - 'A' + 'a'; 
        }
    }
    return s;
}