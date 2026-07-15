#include<iostream>
#include<queue>
#include<stack>
using namespace std;

vector<int> firstNegInt(vector<int> &arr, int k) {
    deque<int> dq;
    vector<int> ans;
    
    // Process the first window manually
    for(int i=0; i<k; i++) {
        int element = arr[i];
        if(element < 0) {
            dq.push_back(i); //Push the **index** not the element
        }
    }

    // Push the answer of the current window
    if(dq.empty()) {
        ans.push_back(0);
    }
    // Remove the answer from the queue from previous window 
    else {
        int index = dq.front();
        // Never pop the index here because it might the part of next window
        ans.push_back(arr[index]); 
    }

    // Process remaining window

    // As 0 to k-1 elements are already processed above
    // Now we can move ahead with Kth elements till last element
    for(int index=k; index<arr.size(); index++){
        // Removal of element which is not in the window
        // Before removal check whether the index is in the window or not
        // Formula: currIndex - checkingElement's index (dq.front) should be >= K
        if(!dq.empty() && index - dq.front() >= k) {
            dq.pop_front();
        }
    
        //Addition of next element 
        if(arr[index] < 0) {
            dq.push_back(index);
        }

        // answer
        if(dq.empty()) {
            ans.push_back(0);
        } 
        else {
            ans.push_back(arr[dq.front()]); 
        }
    } 

    return ans;
}

/* 
T.C -> Each element in the array is getting accessed two times at max
       1. For deletion of element
       2. For addition of element
       Dequeue is taking O(1) fo pushing and popping so:
       Total T.C becomes O(2n) = O(n)
*/