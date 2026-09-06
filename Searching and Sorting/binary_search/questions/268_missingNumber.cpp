#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int missingNumber(vector<int>& nums) {
    // Sort the array so that we can use Binary Search 
    sort(nums.begin(), nums.end());

    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e-s) / 2;
    // We have initialised this this size 
    // Because if the missing number if the last element
    // THe while loop will not cater it
    // Therefore if start passes end and still there is no missing elemnt
    // we will return the last number 
    int missingElement = nums.size();

    // For a range 0->n in a n sized array one number will be missing
    // So the index will match the element until any number gets missing
    // If index and element is not matching then that index might be the missing element

    while( s <= e ){
        if( nums[mid] == mid ){
            // Everything is correct until mid,
            // so missing number must be on right
            s = mid + 1;
        }
        else {
            // mid could be missing,
            // or missing number is before mid
            missingElement = mid;
            e = mid - 1;
        }
        mid = s + (e-s) / 2;
    }

    return s;
}