#include<iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
  
    void solve(string s, int index, string output, vector<string> &ans) {
        // Base Case
        if(index >= s.length()) {
            // This tells:
            // When to stop
            // Here the subsequence becomes ready
            ans.push_back(output);
            return;
        }
        
        // Lets solve one case
        // Ek character ko pkad ke include and exclude kr dete hai
        char ch = s[index];
        
        //include
        output.push_back(ch);
        solve(s, index+1, output, ans);
        output.pop_back();
        //exclude
        solve(s, index+1, output, ans);
    }
    
    vector<string> powerSet(string &s) {
        // Code here
        vector<string> ans;
        int index = 0;
        string output = "";
        
        solve(s, index, output, ans);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};