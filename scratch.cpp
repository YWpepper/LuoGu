#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
    TreeNode* lchild;
    int data;
    TreeNode* rchild;
};

TreeNode* root;             // global variable

void CreateBT() {
    TreeNode *p, *tmp;
    int x;
    queue<TreeNode*> fifo;
    cout << "Enter root value : ";
    cin >> x;
    root = new TreeNode{nullptr, x, nullptr};
    fifo.push(root);
    while (!fifo.empty()) {
        p = fifo.front();
        fifo.pop();
        cout << "Enter lchild value, enter `-1` means you don't want this node to have lchild node : ";
        cin >> x;
        if(x != -1) {                                       // enter -1 means you want tempory node don't have left child
            tmp = new TreeNode{nullptr, x, nullptr};
            p->lchild = tmp;
            fifo.push(tmp);
        }
        cout << "Enter rchild value, enter `-1` means you don't want this node to have rchild node : ";
        cin >> x;
        if(x != -1) {                                       // enter -1 means you want tempory node don't have left child
            tmp = new TreeNode{nullptr, x, nullptr};
            p->rchild = tmp;
            fifo.push(tmp);
        }
    }
}

void PreOrder(TreeNode* node) {
    if(node != nullptr) {
        cout << node->data << " ";
        PreOrder(node->lchild);
        PreOrder(node->rchild);
    }
}

int main() {
    // queue<int> q;
    // q.push(100);
    // q.push(20);
    // q.push(1123);

    // cout << q.front() << endl;
    // cout << q.back() << endl;

    CreateBT();
    PreOrder(root);
    return 0;
}