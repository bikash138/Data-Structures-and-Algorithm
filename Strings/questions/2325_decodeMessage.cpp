#include<iostream>
#include<unordered_map>
using namespace std;

void createMapping(unordered_map<char, char> &mapping, string key) {
    char start = 'a';

    for(int i=0; i<key.length(); i++) {
        char ch = key[i];
        // Insert the mapping if and only if it is not present otherwise 
        // repeatation of characters will update the mapping with some other character
        if(mapping.find(ch) == mapping.end()) {
            mapping[ch] = start;
            start++;
        }
    }
}

string useMapping(unordered_map<char, char> &mapping, string message) {
    string s = "";
    for(int i=0; i<message.length(); i++) {
        char ch = message[i];
        char mappedCharacter = mapping[ch];
        s.push_back(mappedCharacter);
    }
    return s;
}

string decodeMessage(string key, string message) {
    // Create the Mapping
    unordered_map<char, char> mapping;
    char space = ' ';
    mapping[space] = space;

    createMapping(mapping, key);

    // Use the Mapping
    string ans = useMapping(mapping, message);
    return ans;
}