#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
The formula is: HCF * LCM = a * b
=> LCM = a * b / HCF;
*/

int findHCF(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

int lcm(int a, int b) {
    
    int hcf = findHCF(a,b);
    
    int lcm = a * b / hcf;
    
    return lcm;
}