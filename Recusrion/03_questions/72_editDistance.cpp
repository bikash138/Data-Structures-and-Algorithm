#include<iostream>
#include <vector>
#include <numeric>
using namespace std;


int solve(string &word1, string &word2, int i, int j) {
    // Base Case
    if(i >= word1.length()) {
        // This means word1 has ended
        // word1's length may be less than word2 hence return the left cahracters from the word2
        // as only possible way to match is to add those extra cahracters
        return word2.length() - j;
    }
    if(j >= word2.length()) {
        // This means word2 has ended
        // word2's length may be less than word1 hence return those extra cahracters needs to be removed
        return word1.length() - i;
    }
    int ans = 0;

    if(word1[i] == word2[j]) {
        //match: no operation needs to be done
        // Just move the index forward
        ans = 0 + solve(word1, word2, i+1, j+1);
    }
    else {
        // Insert: This will only increase the j's index
        int option1 = 1 + solve(word1, word2, i, j+1);
        // Remove 
        int option2 = 1 + solve(word1, word2, i+1, j);
        // Replace 
        int option3 = 1 + solve(word1, word2, i+1, j+1);

        ans = min(option1, min(option2, option3));
    }
    return ans;
}

int minDistance(string word1, string word2) {
    int i = 0;
    int j = 0;
    int ans = solve(word1, word2, i, j);
    return ans;
}
