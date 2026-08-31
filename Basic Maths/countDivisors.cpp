#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
    For a integer which is between [2, infinity], it will definitely have 2 divisors
    - These two divisiors are the number itself and 1
    - For 1 the divisor is only one that is 1 iteself.
*/

int countDivisor(int n) {
    // Handle the edge case of 1
    if(n == 1) return 1;
    // Every number will have atleast 2 divisors
    int count = 2;
    // Loop should before n
    for(int i=2; i<n; i++) {
        if(n % i == 0) {
            count++;
        }
    }
    return count;
}