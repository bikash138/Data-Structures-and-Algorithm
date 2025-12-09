#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class Info
{
public:
  char val;
  int count;
  Info(char ch, int cnt)
  {
    this->val = ch;
    this->count = cnt;
  }
};

class compare
{
public:
  bool operator()(Info a, Info b)
  {
    return a.count < b.count;
  }
};

class Solution
{
public:
  string longestDiverseString(int a, int b, int c)
  {
    // Create teh maxHeap with the custom comparator
    priority_queue<Info, vector<Info>, compare> maxHeap;

    // Now push the each of them in the maxHeap if the count is greater than 0
    if (a > 0)
    {
      Info temp('a', a);
      maxHeap.push(temp);
    }
    if (b > 0)
    {
      Info temp('b', b);
      maxHeap.push(temp);
    }
    if (c > 0)
    {
      Info temp('c', c);
      maxHeap.push(temp);
    }

    // Now our heap is ready
    string ans = "";

    // Process till maxHeap is left with one element
    while (maxHeap.size() > 1)
    {
      // Take out first two elements from the maxHeap with max freq
      Info first = maxHeap.top();
      maxHeap.pop();
      Info second = maxHeap.top();
      maxHeap.pop();

      // Now we have two options
      // 1. If the freq is more than 2 then we can use two char of it as 3 are not allowed
      // 2. If the free is less than 2 then we have to keep only 1 char in the ans
      if (first.count >= 2)
      {
        // Push double char
        ans.push_back(first.val);
        ans.push_back(first.val);
        first.count -= 2;
      }
      else
      {
        ans.push_back(first.val);
        first.count -= 1;
      }
      // Similarly do for the second element
      // If we use the second aggresvely tehn it might happen the count of first remain dominant
      // So we have used the greedy approach in the second condition
      // That ensures the balance in consumption of the characters
      if (second.count >= 2 && second.count >= first.count)
      {
        // Push
        ans.push_back(second.val);
        ans.push_back(second.val);
        second.count -= 2;
      }
      else
      {
        ans.push_back(second.val);
        second.count -= 1;
      }
      // Now push the updated state of both the nodes
      if (first.count > 0)
      {
        maxHeap.push(first);
      }
      if (second.count > 0)
      {
        maxHeap.push(second);
      }
    }
    // Now handle the last element
    if (maxHeap.size() == 1)
    {
      Info first = maxHeap.top();
      maxHeap.pop();

      if (first.count >= 2)
      {
        ans.push_back(first.val);
        ans.push_back(first.val);
        first.count -= 2;
      }
      else
      {
        ans.push_back(first.val);
        first.count -= 1;
      }
    }
    return ans;
  }
};