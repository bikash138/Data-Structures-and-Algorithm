#include<iostream>
#include<unordered_map>
using namespace std;

string addStrings(string num1, string num2) {
    long long i = num1.size() - 1;
    long long j = num2.size() - 1;
    long long carry = 0;
    string ans = "";

    // This while condition makes sure even if the length of the numbers are different the loop will continue
    // If carry remained at the end then also it will continue
    while ( i >= 0 || j >= 0 || carry > 0 ){
        long long csum = 0;
        if(i >= 0 ) {
            //num1 has digits left
            csum += num1[i] - '0';
            i--;
        }
        if( j >= 0 ) {
            //num2 has digits left
            csum += num2[j] - '0';
            j--;
        }
        csum += carry;
        // Get the lat digit of the sun
        long long lastDigit = csum % 10;
        // Convert it to character
        char lastDigitChar = lastDigit + '0';
        // Push it to answer
        ans.push_back(lastDigitChar);
        // Update the carry with first integers of the number
        carry = csum / 10;
    }
    // As we have prepared the answer in reverse order
    reverse(ans.begin(), ans.end());
    return ans;
}

// T.C -> If the length of longest number is N hence it will be O(N) and 
//        reversing the answer will take at maz O(N+1) hence 
//        total => O(N) + O(N+1) = O(N)