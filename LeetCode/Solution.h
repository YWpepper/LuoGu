#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <iterator>

using namespace std;

void display(const vector<int> &nums)
{
    for(int i=0; i < nums.size(); i++ )
    {
        cout << nums[i] << " " ;
    }
    cout << endl;
}



void swap(int &num1, int &num2)
{
    int temp=num1;
    num1 = num2;
    num2 = temp;
}


class Solution {
public:
    virtual void moveZeroes(vector<int> &nums) {
        int len = nums.size();
        cout << len << endl;
        int cnt = 0;
        for(int i=0; i<len-cnt; i++)
        {
            // 左移；
            if(nums[i]==0 &&  (len-cnt) > 1 )
            {
                for(int j=i; j<len-cnt; j++)
                {
                    nums[j] = nums[j+1];
                }
                nums[len-cnt] = 0;
                cnt++;
            }
        }
    }
};



class Solution2 :public Solution {

public:
    void moveZeroes(vector<int> &nums) override {
        int len=nums.size();
        int l=0,r=0;
        // 使用r作为快指针，如何l作为边界[0,L] 表示已经处理好的序列
        while(r < len)
        {
            if(nums[r] != 0) // 这个地方其实放的是条件，根据题目来定
            {
                swap(nums[l], nums[r]);
                l++; // 表示把符合条件的数放到[0,L] 中
            }
            r++; // R 指针只是用来迭代遍历直到最后；
        }
        // [L,R]区域的数字，其实是不满足if（xx） 后面条件的变量
    }
};