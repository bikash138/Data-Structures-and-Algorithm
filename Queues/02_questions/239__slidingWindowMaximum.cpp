#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> ans;

    // Process the first Window
    for(int i=0; i<k; i++){
        /*
            1. We need to store the current element's index in the queue *always*
            2. But before pushing the element just check 
            whether the *last pushed* element is greater than or less than this current element
            3. If it is greater then do nothing and push the current element
            4. But if it is smaller then *pop_back* the elemnets from the queue until
            we get a greater element or queue becomes empty.
        */
       while(!dq.empty() && nums[dq.back()] < nums[i]){
        dq.pop_back();
       }

       dq.push_back(i);
    }

    // Answer of first window
    int element = nums[dq.front()];
    ans.push_back(element);

    //Remaining Window
    for(int index=k; index<nums.size(); index++) {
        //Removal
        if(!dq.empty() && index - dq.front() >= k){
            dq.pop_front();
        }

        // Addition
        while(!dq.empty() && nums[dq.back()] < nums[index]){
            dq.pop_back();
        }
        dq.push_back(index);

        // Answer
        int element = nums[dq.front()];
        ans.push_back(element);
    }

    return ans;
}

// T.C -> O(n)