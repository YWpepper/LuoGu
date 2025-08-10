#include <vector>
#include <stack>
#include <queue>
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
    TreeNode *createTree(vector<int> treeArray)
    {
        int curIdx = 1;
        queue<TreeNode *> treeQueue;                 // 存储树
        TreeNode *root = new TreeNode(treeArray[0]); // 初始化根节点
        TreeNode *cur = new TreeNode(-1);            // 用来存储当前的节点
        treeQueue.push(root);
        while (!treeQueue.empty() && curIdx < treeArray.size()) // 注意一定要防止数组的idx溢出
        {
            cur = treeQueue.front();                                  // 获取当前处理的树节点
            treeQueue.pop();                                          // 弹出表示已经处理了
            if (treeArray[curIdx] != -1 && curIdx < treeArray.size()) // 左子树
            {
                TreeNode *newLeft = new TreeNode(treeArray[curIdx]);
                cur->left = newLeft;
                treeQueue.push(newLeft);
            }
            curIdx++;
            if (treeArray[curIdx] != -1 && curIdx < treeArray.size())
            {
                TreeNode *newRight = new TreeNode(treeArray[curIdx]);
                cur->right = newRight;
                treeQueue.push(newRight);
            }
            curIdx++;
        }
        return root;
    }

    vector<int> deal(TreeNode *root, vector<int> &res)
    {
        if (!root)
        {
            return res;
        }
        deal(root->left, res);
        res.push_back(root->val);
        deal(root->right, res);
        return res;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        res = deal(root, res); // 学一下套娃递归
        return res;
    }
};

void disaply(vector<int> nums)
{
    for (auto &x : nums)
        cout << x << " ";
}

int main()
{
    vector<int> treeArray = {1, -1, 2, 3};
    vector<int> inorder;
    disaply(treeArray);
    Solution solu;
    TreeNode *root = solu.createTree(treeArray); // 调用createTree构建树
    inorder = solu.inorderTraversal(root);
    cout << endl;
    disaply(inorder);
    return 0;
}