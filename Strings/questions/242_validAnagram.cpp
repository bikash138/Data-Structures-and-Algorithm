#include<iostream>
#include<unordered_map>
using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length()) {
        return false;
    }
    
    unordered_map<char, int> map;

    /* 
     For each character in string s will have count as 1
     While the checking the second string make those cahracters to 0
     Now check whether the map has all the values 0 or not
     If zero then its a valid anagram
    */

    for(int i=0; i<s.length(); i++) {
        map[s[i]]++;
    }

    for(int i=0; i<t.length(); i++) {
        map[t[i]]--;
    }

    for (auto x : map) {
        if (x.second != 0) {
            return false;
        }
    }
    return true;
}