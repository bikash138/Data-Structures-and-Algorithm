#include <iostream>
using namespace std;
#include <functional>
#include<vector>
#include <queue>
#include <cmath>

//So according to the question we have to find create the string with repeatation
//So what would be the ideal approach that comes first in the mind:
//1. We can keep the frequencies of each character
//2. Now lets think of taking a min heap to get the the character with minimum freq
//    So if we start creating the string with the characters of min freq, doing this in the end we will be 
//    left with characters with max freq and filling it in the string will cause greater probability of repeatation
//3. So rather using that we can use max heap where the character with max freq will be first fetched and filled so that at the 
//   end we will be left with those chaacter with min freq and fillin those will not cause repeatation.
//4. Here we can see another problem, if we get the element with the max freq and push it into the string then in the next iteration
//   it might happen that freq of that character is still max and if we do this then we will be pushing that element again into the string causing repeatation.
//5. So to solve this we can take two cahrcter at a time to avoid this type of repaeatation.
//6. While doing this we will keep decreasing the freq of the character which we are using.


//So lets first create the custom data type which will store the character and its count
class Info {
  public:
    char val;
    int count;
  Info(char ch, int cnt){
    this->val = ch;
    this->count = cnt;
  }
};

//Now we have to create our own custom comparator which will be maxHeap
class compare {
  public:
    bool operator()(Info a, Info b){
      //Condition for max heap
      return a.count < b.count;
    }
};


string reorganisedString(string s){
  //First create a freq array which initial frequencies of 0
  int freq[26] = {0};
  //Now store the frequencies
  for(int i=0; i<s.size(); i++){
    char ch = s[i];
    freq[ch-'a']++;
  }
  //Now push all the elements to the heap to get the character with max freq
  priority_queue<Info, vector<Info>, compare> maxHeap;

  //Now push all the character to the maxHeap
  for(int i=0; i<26; i++){
    if(freq[i] > 0){
      //Any character with frea greater than 0 should be pushed to the max heap
      //Create the Info object to push it into the heap
      Info temp(i+'a', freq[i]);
      maxHeap.push(temp);
    }
  }
  string ans = "";
  //We will be popping the element from the heap till there is atleast 2 elment
  while(maxHeap.size() > 1){
    //Get the top two elments from the heap
    Info first = maxHeap.top();
    maxHeap.pop();
    Info second = maxHeap.top();
    maxHeap.pop();
    //Now push the element to ans vector
    ans.push_back(first.val);
    first.count--;
    ans.push_back(second.val);
    second.count--;

    //Now push the first and second with the updated count back to the heap
    if(first.count > 0){
      maxHeap.push(first);
    }
    if(second.count > 0){
      maxHeap.push(second);
    }
  }
  //Now if we reach here therefore we have only single element left
  //This element can be inserted in the answer only one time
  //So if its count is greater than 1 then string formation is not possible because repetation will occur
  if(maxHeap.size() == 1){
    //First store the occurence
    Info first = maxHeap.top();
    maxHeap.pop();
    ans.push_back(first.val);
    first.count--;
    //If after decrement the count is still not 0 then string is not possible then return the emoty string
    if(first.count != 0){
      return "";
    }
  }
  return ans;
}