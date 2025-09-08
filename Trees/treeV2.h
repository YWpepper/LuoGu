#include <iostream>
#include <queue>
using namespace std;

class Tree
{
public:
    class Node
    {
    public:
        int data;
        Node *lchild;
        Node *rchild;
        Node() : data(0), lchild(nullptr), rchild(nullptr) {}
        // 正确的 Node 构造函数（必须确保指针初始化）
        Node(int data) : data(data), lchild(nullptr), rchild(nullptr) {}
    };

    Node *root;
    Tree() { root = nullptr; }
    void createTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    // void Height(Node *p);
};

void Tree::createTree()
{
    // ---- 初始化树的结构 ---
    Node *ptr;  // 队列中节点
    Node *temp; // 存储输入左右树结构
    int x;
    queue<Node *> myQue;
    // ----- endl ------

    cout << "请输入根节点的值: ";
    cin >> x;
    root = new Node(x); // 只要把根节点处理好了就可以了
    myQue.push(root);
    cout << myQue.size() << endl;

    // 输入规则：
    cout << "提示：输入-1表示该方向无节点" << endl;
    while (!myQue.empty())
    {
        ptr = myQue.front(); //  先获取队首元素
        myQue.pop();         // 再弹出队首元素

        // 处理左子节点
        cout << "请输入" << ptr->data << "的左子节点值: "; // 队列
        cin >> x;
        if (x != -1)
        {
            temp = new Node(x);
            ptr->lchild = temp;
            myQue.push(temp);
        }

        // 处理右子节点
        cout << "请输入" << ptr->data << "的右子节点值: "; // 队列
        cin >> x;
        if (x != -1)
        {
            temp = new Node(x);
            ptr->rchild = temp;
            myQue.push(temp);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if (p != nullptr)
    {
        cout << p->data << " "; // 访问根节点
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if (p != nullptr)
    {
        Preorder(p->lchild);
        cout << p->data << " "; // 访问根节点
        Preorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if (p != nullptr)
    {
        Preorder(p->lchild);
        Preorder(p->rchild);
        cout << p->data << " "; // 访问根节点
    }
}