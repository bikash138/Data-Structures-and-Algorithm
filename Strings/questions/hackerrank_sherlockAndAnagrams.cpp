#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int serlockAndAnagram (string s) {
    unordered_map<string, int> substring_count;
    // anagramatic pair count
    int ans = 0;

    // genrate all substring
    for(int i=0; i<s.size(); i++) {
        for(int j=1; j<=s.size() - i; j++) {
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