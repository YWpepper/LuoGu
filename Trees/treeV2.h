#include <iostream>
#include "../Array/Array.h" // 如果Array文件夹与Trees在同级目录
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

// class Queue
// {

// private:
//     int front;
//     int rear;
//     int size;
//     int *queue; // 指向一个队列的指针
// public:
//     Queue()
//     {
//         front = rear = -1;
//         size = 10;
//         queue = new int[size];
//     }
//     Queue(int sz)
//     {
//         front = rear = -1;
//         size = sz;
//         queue = new int[size];
//     }

//     void enqueue(int x);
//     int dequeue();
//     void Display();
// };

// void Queue::enqueue(int x)
// {
// }

class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void createTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    void Height(Node *p);
};

void Tree::createTree()
{
    Node *p, *t;
    int x;
    queue<Node *> myQue;
    cout << myQue.size() << endl;
    cout << " Entering root value " << endl;
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    myQue.push(root);
    cout << myQue.size() << endl;
}