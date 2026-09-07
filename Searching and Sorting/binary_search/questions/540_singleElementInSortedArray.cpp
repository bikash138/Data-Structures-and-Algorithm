#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
    If we notice in the array 1,1,2,2,3,3,4,8,8
                    Index ->  0 1 2 3 4 5 6 7 8
    IF we observe that  
    - right side of non duplicate element has pair 
      starting index is even. Ex - 0,2,4
    - while the left side of the element has pair
      starting index is odd. Ex - 7
    - another obeservation is that the right and left
      index of this non repeating element is different

    So using this three condition we can use binary search 
    to select which side we need to choose
*/

int singleNonDuplicate(vector<int>& nums) {
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e ){ 
        if( s == e) return nums[s];
        int mid = s + (e-s) / 2;

        int currentElement = nums[mid];
        int leftElement = -1;
        int rightElement = -1;

        if(mid - 1 >= 0) {
            leftElement = nums[mid - 1];
        }

        if(mid + 1 < nums.size()) {
            rightElement = nums[mid + 1];
        }

        if(currentElement != leftElement && currentElement != rightElement) {
            return currentElement;
        }

        // Standing on a pair's ending index
        if (currentElement == leftElement && currentElement != rightElement) {
            // so pair's starting index will be mid - 1
            int pairStartingIndex = mid - 1;
            // if the starting index is odd then our answer will lie on the left
            if(pairStartingIndex & 1) e = mid - 1;
            else s = mid + 1;
        }

        // Standing on a pair's starting index
        if (currentElement == rightElement && currentElement != leftElement){
            // so pair's starting index  will be the mid itself
            int pairStartingIndex = mid;
            // same condition will be here to evaluate the pai's starting index
            if(pairStartingIndex & 1) e = mid - 1;
            else s = mid + 1;
        }
        
    }
    return -1;
}