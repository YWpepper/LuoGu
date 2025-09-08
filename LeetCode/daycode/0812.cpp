#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool checkExist(vector<vector<int>> res, vector<int> path)
    {
        for (auto &x : res)
        {
            if (x == path)
                return false;
        }
        return true;
    }

    void dfs(vector<int> &nums, vector<int> &used, vector<vector<int>> &res, vector<int> &path)
    {
        if (path.size() == nums.size())
        {
            if (checkExist(res, path))
            {
                res.push_back(path);
            }

            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == 1)
                continue; // 已使用则跳过

            used[i] = 1;
            path.push_back(nums[i]);

            dfs(nums, used, res, path);

            // 回溯
            used[i] = 0;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> used(nums.size(), 0);
        vector<vector<int>> res;
        vector<int> path;

        dfs(nums, used, res, path);
        return res;
    }
};

// 打印二维向量
void printResult(const vector<vector<int>> &result)
{
    cout << "[" << endl;
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << "  [";
        for (size_t j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j];
            if (j != result[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != result.size() - 1)
        {
            cout << ",";
        }
        cout << endl;
    }
    cout << "]" << endl;
}

int main()
{
    // 测试样例1: 基本测试,当前测试的都是不考虑重复元素的
    vector<int> nums1 = {1, 1, 3};
    Solution sol;
    vector<vector<int>> result1 = sol.permute(nums1);
    cout << "测试样例1: [1, 2, 3] 的全排列为：" << endl;
    printResult(result1);
    cout << "预期排列数: 6，实际排列数: " << result1.size() << endl
         << endl;

    // // 测试样例2: 含两个元素
    // vector<int> nums2 = {0, 1};
    // vector<vector<int>> result2 = sol.permute(nums2);
    // cout << "测试样例2: [0, 1] 的全排列为：" << endl;
    // printResult(result2);
    // cout << "预期排列数: 2，实际排列数: " << result2.size() << endl
    //      << endl;

    // // 测试样例3: 单个元素
    // vector<int> nums3 = {5};
    // vector<vector<int>> result3 = sol.permute(nums3);
    // cout << "测试样例3: [5] 的全排列为：" << endl;
    // printResult(result3);
    // cout << "预期排列数: 1，实际排列数: " << result3.size() << endl;

    return 0;
}
