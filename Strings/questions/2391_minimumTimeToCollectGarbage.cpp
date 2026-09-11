#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // P truck
        int pickP = 0;
        int lastHouseP = 0;
        // G truck
        int pickM = 0;
        int lastHouseM = 0;
        // M truck
        int pickG = 0;
        int lastHouseG = 0;

        //Start travelling the road
        for(int i=0; i<garbage.size(); i++) {
            // Now we are at the any one house
            string currentHouseGarbage = garbage[i];
            // Now get each garbage from each house
            for(int j=0; j<currentHouseGarbage.length(); j++) {
                char garbageType = currentHouseGarbage[j];

                // Now update the pickup time
                // Also keep updating the last house index to get the total distance afterwards
                if(garbageType == 'P') {
                    pickP++;
                    lastHouseP = i;
                }
                else if(garbageType == 'M') {
                    pickM++;
                    lastHouseM = i;
                }
                else if(garbageType == 'G') {
                    pickG++;
                    lastHouseG = i;
                }
            }
        }
        int travelP = 0;
        int travelM = 0;
        int travelG = 0;

        // Now calcualte the toal distance using the last house index
        // And keep adding the distance to it 

        for(int i=0; i<lastHouseP; i++) {
            travelP += travel[i];
        }

        for(int i=0; i<lastHouseG; i++) {
            travelG += travel[i];
        }

        for(int i=0; i<lastHouseM; i++) {
            travelM += travel[i];
        }

        int totalTime = (pickP + pickM + pickG) + (travelP + travelM + travelG);
        return totalTime;
    }
};