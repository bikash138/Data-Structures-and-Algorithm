#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

int derangeCount(int n) {
    if(n == 1) {
        return 0;
    }
    
    if(n == 2) {
        return 1;
    }
    /*
     -------n is the size of the array---------
     1. Lets shift the first element is some random position so 
        the total positions available for frist element to shift will be n-1
     2. Now take the second elemnt which can move to any position except the 
        one hecne it will be f(n-1).
     3. As we have swapped the position of first element hence the total ways 
        for the other elements after fixing the positions of two elements will be
        f(n-2).
    */
    int ans = (n-1) * (derangeCount(n-1) + derangeCount(n-2));
    
    return ans;

}