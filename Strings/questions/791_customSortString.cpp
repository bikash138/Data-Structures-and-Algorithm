#include<iostream>
#include<algorithm>
using namespace std;

string orderCopy;
class Solution {
public:
    static bool cmp(char ch1, char ch2) {
        /* 
         If ch1 is present before ch2 in order string
         then place ch1 before ch2 in the string s
         and vice versa
        */
        return (orderCopy.find(ch1) < orderCopy.find(ch2));
    }

    string customSortString(string order, string s) {
        orderCopy = order;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};