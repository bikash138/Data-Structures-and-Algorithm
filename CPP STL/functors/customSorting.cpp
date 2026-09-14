#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class comparator {
    public: 
        bool operator()(int a, int b) {
            // descending order 
            // if a > b -> true, then a should be placed before b
            // hence this creates the descedning order
            return a > b;
        }
};

int main() {

    vector<int> arr;
    arr.push_back(20);
    arr.push_back(10);
    arr.push_back(25);

    // By default is ascedning order
    sort(arr.begin(), arr.end(), comparator());

    for( int a: arr) {
        cout << a  << " ";
    }

    return 0;

}