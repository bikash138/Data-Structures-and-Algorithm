#include<iostream>
#include<unordered_map>
using namespace std;

/*
    This question is actually a question of heaps but we can solve it with greedy approach
    - First build a frequency table of the characters in the string
    - For this we have build a array with all 0 values and by iterating on each 
      character we have increased the corresponding number.
    
    - Now we will find the most frequent cahracter in the string
    - For this we will iterate over the index between 'a' to 'z'
    - While iterating we will save the max frequency in the max_freq variable
      and the character in max_freq_char

    - Now in any case if the (max frequency) > (s.size() + 1) / 2 
      then rearrangement is not possible
    - This formula works because we can only put the max freq char at alternate 
      positions only
      
    - Now we will start rearranging the characters
      1. At first Rearrange the most frequent character:
         We will start filling the even positions and keep the frequency decreasing
         and increase the index by 2.
         After this update the original map to 0 as the character is filled
      2. Now start filling the rest of the characters:
          If we still have index left then continue filling in the even positions
          otherwise start with position 1 and start filling all the odd positions.
          As the index has already increase in the loop by 2 so the first case will
          be handled automatically.
*/

string reorganizeString(string s) {
    int map[256] = {0};

    // Create freq. map
    for(int i=0; s[i]; i++) {
        map[s[i]]++;
    }

    // find the most frequent cahracter
    char max_freq_char;
    int max_freq = INT_MIN;
    for(int i='a'; i<='z'; i++) {
        if(map[i] > max_freq) {
            max_freq = map[i];
            max_freq_char = i;
        }
    }

    // check possibility of reaarangement
    if(max_freq > (s.size() + 1) / 2 ) return "";

    // Lets rearrange
    // First rearrange the most freq character
    int index = 0;
    while (max_freq > 0 && index < s.size()) {
        s[index] = max_freq_char;
        max_freq--;
        index += 2;
    }

    map[max_freq_char] = 0;

    // fill the rest of the characters
    for(int i='a' ; i<='z'; i++) {
        while(map[i] > 0) {
            index = index >= s.size() ? 1 : index;
            s[index] = i;
            map[i]--;
            index += 2;
        }
        
    }
    return s;
}