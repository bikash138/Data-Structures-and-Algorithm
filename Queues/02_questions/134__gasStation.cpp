#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Brut Force Approach Says:
1. Simply go to every gas station 
2. Start counting the cost for each each value of gas station.
But this approach will take o(n^2) time because we are comparing n * n gas stations

Optimised Approach Says:
1. If we see in the example, gas = [3,4,1,5,2] and cost = [2,3,4,5,2]
2. So if someone starts from gas station 3 and wants to move to gas station 4,
   it gonna cost him 2l of gas and will be left with 1l of gas (3 - 2). 
   So it is not possible to move ahead
3. Now we have 1l gas + 4l of current station that is 5l and 3l gas is required. 
   Hence we can say we can move further and we will be left with 5-3 = 2l
4. Now we will have 2l + 1L of current station that is 3l but for the next
   station we need 4l of gas so its not possible.
4. Here our optimsiation comes into place. 
   We see clearly that it is not possible to travel from gas station 3 to
   gas station 5. So it would be obvious that travelling to gas station 5
   will not be possible even from station 4 and station 1. 
5. This logic works because every gas station adds up some gas before next
   leap, if we cannot reach the destination with that then there is no need
   of starting the check again from station from 4 and 1.
6. So to optimise the approach we can start directly from station 5.
IMP: If a starting point fails at station i, then every station between the 
     original starting point and i can also be eliminated as a possible starting point.
*/

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int start = 0; //Initially starting index is 0
    int balance = 0; //Fuel remaining after the hop
    int deficit = 0; //Fuel defecit to make the hop

    for(int i=0; i<gas.size(); i++) {
        // Case 1: Deficit
        if(balance + gas[i] < cost[i]) {
            // If there is a deficit, update the deficit
            deficit += balance + gas[i] - cost[i];
            // Move the start pointer by one that means starting from scratch
            start = i+1;
            // Balance becomes 0
            balance = 0;
        }
        // Case 2: Sufficient Gas is available for the hop
        else {
            // Find the left balanced on a successfull hop
            balance = balance + gas[i] - cost[i];
        }
    }
    // Loop ended means: we have reached the last gas station
    // And we have our starting point set

    /* 
    While returning back to complete the circle
    If the sumission of deficit and remaining balance is positive
    that means the remaing gas station can be hopped easily
    otherwise not possible to complete the circle.
    */ 
    if(balance + deficit >= 0){
        return start;
    }
    else {
        return -1;
    }
}