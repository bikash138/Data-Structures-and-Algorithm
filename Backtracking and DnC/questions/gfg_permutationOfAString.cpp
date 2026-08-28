#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(string &s, int i, vector<string> &ans) {
    //base case
    if( i >= s.length()) {
        ans.push_back(s);
        return;
    }
    
    // First case
    for (int j=i; j<s.length(); j++) {
        /* 
        The algorithm says:
        - Fix the elemnets as you go ahead
        - For a string like "ABC"
        - Try all the permuations at index 0 then index 1 then index 2
        - We are using j for iterating on all the remaing cahracters
        - As we move the the i index, we are actually fixing the left side and permutating the right side
        */
        swap(s[i], s[j]);
        solve(s, i+1, ans);
        swap(s[i], s[j]);
    }
}    

vector<string> permutation(string s) {
    // code here
    vector<string> ans;
    int i = 0;
    solve(s, i, ans);
    // As the question asked that the answer should be lexicographically sorted
    sort(ans.begin(), ans.end());

    return ans;
}