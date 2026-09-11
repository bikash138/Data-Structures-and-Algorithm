#include<iostream>
#include<unordered_map>
using namespace std;

/*
    Here we are expanding from center towards outwards

    - For odd length palindrom: we are keeping both the 
      pointers at the same center and trying to expand
      towards right and left.

    - For the even length palindrome: we are keeping the
      j one step ahead of i and whenever the character
      matches we start expanding. 

    Doing this we are maintaing a count which will be our answer.
*/

int checkPalindrome( string s, int i, int j ) {
    int count = 0;
    while ( i>=0 && j<s.length() && s[i] == s[j] ){
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstrings(string s) {
    int count = 0;
    for(int center=0; center<s.length(); center++) {
        //odd
        int i = center;
        int j = center;
        int oddLengthPalindromeCount = checkPalindrome(s, i, j);

        //even
        i = center;
        j = center + 1;
        int evenLenPalindromeCount = checkPalindrome(s, i, j);

        count = count + oddLengthPalindromeCount + evenLenPalindromeCount;
    }
    return count;
}

/*
 T.C -> We might have come across the brute force approach where:
        we would iterating on all the possibilies of string and check 
        the palindrome for them making the T.C to be O(n^3)

        But if we start cosidering that every palindrome will have a center
        then we can literally move outwards and check the palindrome for each 
        character making the T.C to be O(n^2)
*/