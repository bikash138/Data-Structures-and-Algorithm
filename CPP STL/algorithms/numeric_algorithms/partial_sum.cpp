#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main () {
    vector<int> arr(6);
    arr[0] = 1;
    arr[1] = 7;
    arr[2] = 3;

    vector<int> ans(arr.size());

    partial_sum(arr.begin(), arr.end(), ans.begin());
    
    return 0;
}