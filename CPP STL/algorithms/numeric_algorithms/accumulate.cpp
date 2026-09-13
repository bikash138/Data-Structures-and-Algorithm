#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main () {
    vector<int> arr(6);

    arr[0] = 10;
    arr[1] = 70;
    arr[2] = 30;
    arr[3] = 90;
    arr[4] = 60;
    arr[5] = 80;


    // It takes the range and the initial value of the sum variabel
    int sum = accumulate(arr.begin(), arr.begin(), 0);

    cout << "Sum: " << sum << "\n";

    for(int a: arr) {
        cout << a << " ";
    }
    
    return 0;
}