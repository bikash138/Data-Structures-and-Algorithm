#include <iostream>
#include <queue>
#include <functional>
using namespace std;

//So in this problem we are given with k sorted arrays and we have to merge them in a single sorted array.
//So the first approach that we can think of is to use the merge function of the merge sort.
//So we can merge the first two arrays and then merge the third array with the merged array and so on.
//So the T.C of this approach will be O(nk^2) where n is the number of elements in each array and k is the number of arrays.
//So we can optimize this approach by using the min heap.
//So we can insert the first element of each array in the min heap.
//So the T.C of this approach will be O(nk log k) where n is the number of elements in each array and k is the number of arrays.

//Approach:
//So we can insert the first element of each array in the min heap.
//We will pop the top element of the min heap and insert it in the merged array(answer arrat).
//We will insert the next element of the array from which the top element is popped in the min heap.
//We will continue this process until the min heap is empty.

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

void mergeKSortedArray(int arr[][4], int k, int n, vector<int> &ans){
  //So to insert the next element from the popped array we will in need of the index so we have to create a custom datatype
  //So to make our own custom datatype we have to make our own class
  //As computer dont know about the Info datatype hence we have to write our own comparator defining the lements to be compared
  priority_queue<Info*, vector<Info*>, compare> pq;

  //1st Step: Process the first element(0th element) of each array(row) -> Push them to min Heap
  for(int row = 0; row < k; row++) {
    int element = arr[row][0];
    //Create the Info object to pass it to pq
    Info* temp = new Info(element, row, 0);
    pq.push(temp);
  }

  //2nd Step: Process the further elementes until the pq gets empty
  while(!pq.empty()){
    Info* temp = pq.top();
    pq.pop();
    int topData = temp->data;
    int topRow = temp->rowIndex;
    int topCol = temp->colIndex;

    //Store this top data in the answer's array
    ans.push_back(topData);

    //Same row ke next element jisse abhi pop hua hai usse insert bhi krna hai
    //next index should be a valid index then only we will go further
    if(topCol+1 < n){
      //If its a valid index then create the object of it
      Info* newInfo = new Info(arr[topRow][topCol+1], topRow, topCol+1);
      pq.push(newInfo);
    }
    delete temp;
  }
}

int main(){
  int arr[3][4] = {
    {1, 4, 8, 10},
    {2, 3, 6, 9},
    {5, 7, 11, 12},
  };
  int k = 3;
  int n = 4;
  //Answe array
  vector<int> ans;
  mergeKSortedArray(arr, k, n, ans);
  cout << "Printing Array" << endl;
  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }
  return 0;
}