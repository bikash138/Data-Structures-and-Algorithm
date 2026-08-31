#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
    Euclidean Formula: gcd(a,b) = gcd(a-b, b) where a > b OR gcd(b-a, a)  where b > a
    If (a == b) then a is the GCD of the initial numbers
*/

int gcd(int a, int b) {
    // So we need to stop when both a and b becomes same
    while( a != b ) {
        if(a > b) {
            a = a - b;
        } 
        else {
            b = b - a;
        }
    }
    return a;
}

// T.C => O(max(a,b))

// We can optimise it using modulo based Euclidean Algirithm
// The formula says: gcd(a,b) = gcd(b, a%b)
int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}
// T.C => O(log(min(a,b)))