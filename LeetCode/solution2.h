#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <vector>

using namespace std;

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
    void inorderTraversal(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return;
        inorderTraversal(root->left);
        cout << root->val << endl;
        inorderTraversal(root->right);
    }
};