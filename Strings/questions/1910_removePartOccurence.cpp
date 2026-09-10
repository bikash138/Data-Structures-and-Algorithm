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