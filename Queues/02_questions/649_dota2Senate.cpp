#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
    This question is simple where we are just seprating the Radient and Diers into a Queue
    Now we will run a loop until any of the loop gets emptied
    Make sure we are have pushed the postion of the senats
    So that we can compare the senat's position and ban the other accordingly
    As we want a circular nature:  
    The winning senat will be pushed back in the queue at (postion + 1) 
*/

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radientQ, dierQ;
        int position = 0;

        for(;position < senate.size(); position++) {
            char senator = senate[position];
            if(senator == 'R') radientQ.push(position);
            if(senator == 'D') dierQ.push(position);
        }

        while(!radientQ.empty() && !dierQ.empty()) {
            int rFront = radientQ.front();
            radientQ.pop();

            int dFront = dierQ.front();
            dierQ.pop();

            if(rFront < dFront) {
                // R will ban D
                radientQ.push(position++);
            }
            else {
                // D will ban R
                dierQ.push(position++);
            }
        }

        // At the end whicherver queue is empty that senant fails the game
        if(!radientQ.empty()) return "Radiant";
        return "Dire";
    }
};