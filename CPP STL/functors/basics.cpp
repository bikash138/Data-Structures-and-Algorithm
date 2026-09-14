#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class functorOne {
    public: 
        bool operator()(int a, int b) {
            // descending order 
            // if a > b -> true, then a should be placed before b
            // hence this creates the descedning order
            return a > b;
        }
};

int main() {

    functorOne cmp;

    if(cmp(10,5) == true ) {
        cout << "10 is greater than 5";
    } else {
        cout << "10 is less than 5";
    }

    return 0;

}