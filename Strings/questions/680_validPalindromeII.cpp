#include<iostream>
#include<unordered_map>
using namespace std;

bool checkPalindrome(string s, int i, int j) {
    while(i <= j) {
        if(s[i] != s[j]) return false;
        else {
            i++;
            j--;
        }
    }
    return true;
}
bool validPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;

    while (i<=j) {
        // match
        if(s[i] == s[j]) {
            i++;
            j--;
        }
        else {
            // If there is a mismatch then we will try to check
            // the remaining string for palindrome
            // one from 1+1 -> j and another from i -> j-1
            // so that we can see whether after skipping one character is the string is becoming a aplindrom or not
            // If any case retruns true then we can go ahead and can say, "yes it is possible"
            bool caseOneAns = checkPalindrome(s, i, j-1);
            bool caseTwoAns = checkPalindrome(s, i+1, j);
            bool finalAns = caseOneAns || caseTwoAns;
            return finalAns;
        }
    }
    // 0 removal case
    return true;
}