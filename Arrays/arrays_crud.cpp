#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
        
    printVector(arr);
    arr.push_back(60);
    arr.push_back(70);
    printVector(arr);
    arr.pop_back();
    printVector(arr);
    arr.insert(arr.begin() + 1, 90);
    printVector(arr);
    arr.erase(arr.begin() + 4);
    printVector(arr);
}