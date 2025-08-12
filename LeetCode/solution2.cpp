#include <vector>
#include <stack>
#include <iostream> // 用于输出结果
using namespace std;

// 二叉树节点定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *current = root;

        while (current != nullptr || !stk.empty())
        {
            while (current != nullptr)
            {
                stk.push(current);
                current = current->left;
            }

            current = stk.top();
            stk.pop();
            result.push_back(current->val);

            current = current->right;
        }
        return result;
    }
};

// 添加 main 函数作为程序入口
int main()
{
    // 示例 1：构建二叉树 [1,null,2,3]
    // 结构：
    //     1
    //      \
    //       2
    //      /
    //     3
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // 调用中序遍历函数
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    // 输出结果（预期：1 3 2）
    cout << "中序遍历结果：";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // 释放动态分配的内存（避免内存泄漏）
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}