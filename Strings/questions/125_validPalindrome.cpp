#include<iostream>
using namespace std;

bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;

    while( i <= j ) {
        // For spaces and non alpha numeric characters just increment the index 
        while(i < j && !isalnum(s[i])) {
            i++;
        }

        while(i < j && !isalnum(s[j])) {
            j--;
        }

        // Compare the lower case value of the characters only
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }

        i++; j--; 
    }
return true;
}