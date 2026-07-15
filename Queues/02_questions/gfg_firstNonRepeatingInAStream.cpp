#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

string firstNonRepeating (string &s) {
    deque<char> dq;
    string ans;
    unordered_map<char, int> freq;

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        // As soon as element enters increase the frequency and push the character to the queue
        freq[ch]++;
        dq.push_back(ch);

        // Keep checking the answers in the deque
        // 1. For the element whose freq is more than 1, pop it form the queue as it has already appeared
        // 2. Otherwise keep the element in the queue and store it in the answer string
        // 3. If deque is empty then push '#' in the ans string. 

        while(!dq.empty()){
            char frontElement = dq.front();
            //check whether front element in answer or not
            if(freq[frontElement] == 1) {
                //If its the answer then store in teh answer
                //and break the loop because this character is solved
                //we need to move to next character
                ans.push_back(frontElement);
                break;
            }
            else {
                //here it means character is repeated 
                //thats why pop that character form the queue
                //and continue the loop
                dq.pop_front();
            }
        }
        //If dq empty is empty then push '#'
        if(dq.empty()) {
            ans.push_back('#');
        }
    }
    return ans;
}