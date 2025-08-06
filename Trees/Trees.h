#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <class T>
struct treeNode
{
    treeNode<T> *lTree;
    T data;
    treeNode<T> *rTree;
    treeNode(T val) : data(val), lTree(nullptr), rTree(nullptr) {}
};

template <class T>
class treeNodeQueue : public queue<T>
{
private:
    // 存储树节点的指针
    queue<treeNode<T> *> *treeQueue;

public:
    // 构造函数，初始化一个空的二叉树节点队列
    treeNodeQueue()
    {
        treeQueue = new queue<treeNode<T> *>(); // 首先是一个数组，用一个* 然后这个数组里指向是一个队列；
    }

    // 析构函数，用于释放对象占用的内存
    ~treeNodeQueue() {}
    treeNode<T> *deQueue()
    {
        if (treeQueue->empty())
            return nullptr;
        treeNode<T> *queFront = treeQueue->front();
        treeQueue->pop();
        return queFront;
    }

    //
    void enQueue(treeNode<T> *newNode)
    {
        treeQueue->push(newNode);
    }

    // 获取队列大小
    int getSize() { return treeQueue->size(); }
    void clearQueue()
    {
        if (!treeQueue->empty())
        {
            treeQueue->pop();
        }
    }
};