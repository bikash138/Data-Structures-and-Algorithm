#include <iostream>
using namespace std;
#include <functional>
#include<vector>
#include <queue>
#include <cmath>

//So the Questions says, remove the stones such that minimum number of stones left behind
//So to do this we should remove the pile with the maximum stones then only we can find the minimum stones
//This maximum pile number can be found easily using max heap
//Before pushing to the max heap we should do the processing(given in the question)
//This will run till k!=0

//This question tells about the pattern where we get the element from the heap process it and then again push it into the heap

int minStoneSum(vector<int>&piles, int k){
  priority_queue<int> maxHeap;
  
  //Initiallly push each piles to the heap
  for(int i=0; i<piles.size(); i++){
    int element = piles[i];
    maxHeap.push(element);
  }

  //Now start the loop for processing
  while(k!=0){
    int topElement = maxHeap.top();
    maxHeap.pop();

    //Process the piles with max number of stones
    topElement = topElement - floor(topElement/2);
    //Now we have updated and reduced the max pile
    //Now push the piles again into the heap for further processing
    maxHeap.push(topElement); 

    k--;
  }

  int sum = 0;
  //Now start adding the elements in the heap to get the final answer
  while(!maxHeap.empty()){
    int top = maxHeap.top();
    sum = sum + top;
    maxHeap.pop();
  }

  return sum;
}