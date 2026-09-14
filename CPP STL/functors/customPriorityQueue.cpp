#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Student {
    public: 
        int marks;
        string name;
        Student() {

        }
        Student (int m, string n) {
            this->marks = m;
            this->name = n;
        }
};

class StudentComparator {
    public:
        bool operator()(Student a, Student b) {
            // This keeps the student with less marks at high priority
            return a.marks < b.marks;
        }
};

int main() {
    
    //max-heap
    priority_queue<int> pq;
    priority_queue<int, vector<int>, less<int> > pq2;
    // min-heap
    priority_queue<int, vector<int>, greater<int> > pq3;

    // Student priority queue
    priority_queue<Student, vector<Student>, StudentComparator> spq;

    return 0;

}