#include<iostream>
#include<unordered_map>
using namespace std;

string removeOccurrences(string s, string part) {
    // Find part and erase it 
    while(s.find(part) != -1) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

// T.C -> O(n) for finding the part in the while loop 
//        O(n/k) for again finding the same part but 
//        this time the string is getting reduced by k(length of part)
//        So T.C becomes -> O(n*n/k)