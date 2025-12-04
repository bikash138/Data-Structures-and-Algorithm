#include <iostream>
#include <queue>
#include <functional>
#include <climits>
#include <vector>
using namespace std;

class Info {
  public:
    int data;
    int rowIndex;
    int colIndex;
    Info(int data, int row, int col){
      this->data = data;
      this->colIndex = col;
      this->rowIndex = row;
    }
};

class compare{
  public:
    bool operator()(Info* a, Info* b){
      return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>> &nums) {
  //We will be using out own custom datatype which is storing the row and col indexes and our custom comparator
  priority_queue<Info*, vector<Info*>, compare> pq;
  
  //First initialise the maxi and mini to keep the track 
  int maxi = INT_MIN;
  int mini = INT_MAX;

  //We have to process the first elements of each of k lists
  for(int i=0; i<nums.size(); i++){
    int element = nums[i][0];
    int row = i;
    int col = 0;
    //Creating the data before inserting to the min heap
    Info* temp = new Info(element, row, col);
    pq.push(temp);
    //****Now update the maxi and mini so that the range can be tracked****
    maxi = max(maxi, element);
    mini = min(mini, element);
  }
  //Now keep a track of the answer start and end because maxi and mini will be changing
  int ansStart = mini;
  int ansEnd = maxi;

  while(!pq.empty()){
    //Retrieve the top element(min element) and get its all details by destructuring it
    Info *topNode = pq.top();
    int topNode = topNode->data; 
    int topCol = topNode->colIndex;
    int topRow = topNode->rowIndex;
    pq.pop();

    //Store the min el in that particular range
    mini = topNode->data;

    //So if the range is smaller than the previous one then we will update the ans
    if((maxi-mini) < (ansEnd - ansStart)){
      ansStart = mini;
      ansEnd = maxi;
    }
    //Push the next element to the element if it is available
    if(topCol + 1 < nums[topRow].size()){
      //take the next element from which array the element has been popped
      int newElement = nums[topRow][topCol+1];
      //****Dont forget to update the maxi with the new max */
      maxi = max(maxi, newElement);
      Info *newInfo = new Info(newElement, topRow, topCol+1);
      pq.push(newInfo);
    }else{
      //If any array gets ended then its 100% that we cannot find the common range so break the loop and show the last answer
      break;
    }
  }
}