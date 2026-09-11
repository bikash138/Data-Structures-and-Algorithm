#include<iostream>
#include<unordered_map>
using namespace std;

/*
    Main concept of this question is:
    - We need to normalise the give pattern into our vocab
    - Then we can compare that with the input using frequencies 
    - If the normlised values matches then pattern got matched 
      otherwise it will not match
*/

void normalisedString(string &str) {
    unordered_map<char, char>mapping;

    char start = 'a';
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        if(mapping.find(ch) == mapping.end()){
            mapping[ch] = start;
            start++;
        }
    }

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        char mappedCharacter = mapping[ch];
        str[i] = mappedCharacter;
    }
}
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    normalisedString(pattern);

    for(int i=0; i<words.size(); i++) {
        string currentWord = words[i];
        normalisedString(currentWord);
        if(pattern == currentWord) ans.push_back(words[i]);
    }
return ans;
}