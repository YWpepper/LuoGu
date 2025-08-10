#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void display(const vector<int> &nums)
{
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;
}

void swap(int &num1, int &num2)
{
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

class Solution
{

public:
  virtual void moveZeroes(vector<int> &nums); // 将0放在最后

  int getMin(int a, int b); // 返回两个数之间的最小值

  int maxArea(vector<int> &height); //  盛最多水的容器

  // vector<int> twoSum(vector<int> &nums, int target); //  两数之和
};

// vector<int> Solution::twoSum(vector<int> &nums, int target) {

//   int MAXSIZE = 10005;
//   vector<int> res = {-1,-1};
//   int len = nums.size();
//   int hash[MAXSIZE] = {-1}; // 用哈希表存储数值的index，而不是单一出现次数
//   memset(hash, -1, MAXSIZE); // 避免与0有关系

//   int a = target;
//   for(int i=0 ; i<len ; i++)
//   {
//       int b  = target - nums[i]; // 算出缺的b是多少
//       if( hash[b]!=-1 ) // 首先b正常 + hash[b] 存在
//       {
//         cout << hash[b] << " " << i << endl;
//         res[0] = hash[b];
//         res[1] = i;
//         return res;
//       }
//       hash[ nums[i] ] = i;
//   }

// }

// vector<int> Solution::twoSum(vector<int> &nums, int target)
// {

//   unordered_map<int, int> hash;
//   for (int i = 0; i < nums.size(); i++)
//   {
//     auto it = hash.find(target - nums[i]);
//     if (it != hash.end()) // 如果都遍历到最后了，就说明不存在
//     {
//       cout << it->second << " " << i << endl;
//       return {it->second, i};
//     }
//     hash[nums[i]] = i;
//   }
// }

// 返回两个数之间的最小值
int Solution::getMin(int a, int b) { return a > b ? b : a; }

void Solution::moveZeroes(vector<int> &nums)
{
  int len = nums.size();
  cout << len << endl;
  int cnt = 0;
  for (size_t i = 0; i < len - cnt; i++)
  {
    // 左移；
    if (nums[i] == 0 && (len - cnt) > 1)
    {
      for (int j = i; j < len - cnt; j++)
      {
        nums[j] = nums[j + 1];
      }
      nums[len - cnt] = 0;
      cnt++;
    }
  }
}

// // 这个超时了
// int Solution::maxArea(vector<int>& height) {
//     int res = 0;
//     int len = height.size();
//     int iPtr=0, jPtr=len-1;
//     for(int i = iPtr; i<jPtr; i++)
//     {
//         for( int j= jPtr; j>i; j--)
//         {
//             int gap = j-i;
//             int max = getMin(height[i], height[j]) * gap ;
//             if(max > res) res = max;
//         }

//     }
//     cout << res  << endl;
//     return res;
// }

// 盛最多水的容器 , 这里面有数学问题；
int Solution::maxArea(vector<int> &height)
{

  int res = 0;
  int rp = 0, lp = height.size() - 1;

  while (rp < lp)
  {
    int curS = getMin(height[rp], height[lp]) * (lp - rp);
    if (curS > res)
    {
      res = curS;
    }
    if (height[rp] < height[lp])
      rp++;
    else
      lp--;
  }
  cout << res << endl;
  return res;
}



