#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
    In this question we will first find all the substring of the string:
    - To find all the substring of a string its a predefined loop.
    - As the substr(a, b) funtions takes two values: 
      a -> starting letter, b -> unto which length
    - Start the outer loop on the size of the string 
    - The nested loop will start from 1 and will go till s.size() - i
    - Before putting the string in the map we are sorting it so that 
      each anagram looks exactly same in the map. Ex: ab -> ab , ba -> ab
    - So now our consists of anagrams and their frequencies
    - Now in the second loop we will find the pairs for each anagram group:
      We are required to choose 2 pairs among 'count' indentities
      there count! / 2! (count - 2)! => count(count - 1) / 2
*/

int serlockAndAnagram (string s) {
    unordered_map<string, int> substring_count;
    // anagramatic pair count
    int ans = 0;

    // genrate all substring
    for(int i=0; i<s.size(); i++) {
        for(int j=1; j<= s.size() - i; j++) {
            string substring = s.substr(i, j);
            sort(substring.begin(), substring.end());
            substring_count[substring]++;
        }
    }

    // calculate the number of pairs
    for( auto it:substring_count) {
        int count = it.second;
        // count > 1 is already handled in the below formula
        ans += (count * (count - 1) / 2);
    }

    return ans;
}