#include<iostream>
#include<unordered_map>
using namespace std;

/*
    We will push the characters in the answer string
    We will check whtehr the last cahracter in the answer array
    equals the current character of the string.
    If it equals then remove that character fro the string 
    and skip that character
*/

string removeDuplicates(string s) {
    string ans = "";

    for(int i=0; i<s.length(); i++) {
        // Make sure to check the string for empty before accessing the back
        if(!ans.empty() && s[i] == ans.back()) {
            ans.pop_back();
            continue;
        }
        else {
            ans.push_back(s[i]);
        }
    }
    return ans;
}