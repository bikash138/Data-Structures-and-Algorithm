#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> &arr) {
    // Sort the Array
    sort(arr.begin(), arr.end());

    vector<int> ans;

    int start = 0;
    int end = arr.size() - 1;

    // Take two pointers and start pushing to the answer array
    // If start passes end then simply break the loop
    while( start <= end) {
        ans.push_back(arr[start]);

        // For odd sized arrays we have added this condition
        if(start != end) {
            ans.push_back(arr[end]);
        }

        start++;
        end--;
    }
    return ans;
}

int main () {
    vector<int> arr{1,3,2,5,4};

    vector<int> ans = solution(arr);

    for( int x:ans) {
        cout << x << endl;
    }
}