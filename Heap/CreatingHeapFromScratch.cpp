#include <iostream>
using namespace std;

//NOTE: So the insertion of the element in the simple array is O(1)

//T.C of Heapification: The heapification of the array is taking O(log n) where n is the height of the tree 
//because the element which gets added at the end of the tree. 
//So each time the swapping is done it is actually going one level up in the tree and binary tree has the height of log n.

//T.C of finding MAX and MIN element: Depending of the max and min heap it can be found in O(1) becasue the arr[1] or the
//topmost element of the tree will be the max or min element.

//In opposite scenario (max element in MIN HEAP) we have to check all the elments so it will be O(n).

class Heap{
  public:
    int *arr;
    int size;
    int capacity;
    
    //Ctor for the class
    Heap(int capacity){
      this->capacity = capacity;
      this->arr = new int[capacity];
      this->size = 0;
    }

    void insert(int val){
      //First check if the size of the array
      if(size == capacity){
        cout << "Heap is Full" << endl;
        return;
      }
      //Now if the if is not full then val will be inserted at the end of the array
      size++;
      int index = size;
      arr[index] = val;
      //Now the element is in the last index of the aray
      //Heapification
      while(index > 1){
        //Get the parent index by using 1 based indezing formula
        int parentIndex = index/2;
        //Condition for MAX HEAP
        if(arr[index] > arr[parentIndex]){
          swap(arr[index], arr[parentIndex]);
          //Now update the index for further checking
          index = parentIndex;
        }
        else{
          //The array is already is in the max heap position
          break;
        }
      }
    }
    
    //Deletion of Root(we delete the root only)
    //The T.C is -> For deletion of max el in a max heap and min el in min heap is O(log n)
    //Because here after deletion of the root we are coming one level down of the binary tree.
    void deleteMax(){
      //First check whether the heap is empty or not
      if(size == 0 ){
        cout << "Heap is empty to remove any element" << endl;
        return;
      }

      //Now get the root element and make its value of the last element
      arr[1] = arr[size];
      //As we have removed the actual root element we need to decrease the size of the heap
      size--;
      int index = 1;

      while(true){
        //Now the process of heapification will be done
        //First get the left and right indexes of the root for the comparisons
        int leftIndex = 2*index;
        int rightIndex = 2*index + 1;
        //Keep a index of largest variable which we will find during heapification
        int largestIndex = index;
        //Now first check whether the left index is valid or not
        //If yes then if left el is greater than root el then save the index of left el to largestIndex
        if(leftIndex <= size && arr[leftIndex] > arr[largestIndex]){
          largestIndex = leftIndex;
        }
        if(rightIndex <= size && arr[rightIndex] > arr[largestIndex]){
          largestIndex = rightIndex;
        }
        //If the largestIndex is not equals to root index then there is some any element which larger than it
        if(largestIndex != index){
          swap(arr[index], arr[largestIndex]);
          index = largestIndex;
        }else{
          break;
        }
      }
    }
};
