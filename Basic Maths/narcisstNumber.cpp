#include<iostream>
#include <numeric>
using namespace std;

bool isNarcissistic(int n) {
    int originalNum = n;
    
    int temp = n;
    int digits = 0;
    
    while( temp !=0 ) {
        digits++;
        temp /= 10;
    }
    
    int sum = 0;
    int num = n;
    while( num != 0) {
        int lastDigit = num%10;
        sum += pow(lastDigit, digits);
        num  = num/10;
    }
    
    if(sum == n) {
        return true;
    } else {
        return false;
    }
}