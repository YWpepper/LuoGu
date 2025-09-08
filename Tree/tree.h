#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;



template<class T>
struct TreeNode {

    T data; // 节点数据
    TreeNode* left; // 左子树
    TreeNode* right;

    TreeNode(T val): data(val), left(nullptr), right(nullptr) {}
};

template<class T>
class TreePointerQueue {

private:
    queue< TreeNode<T> * > baseQueue; //  首先是一个数组，这个数组是TreeNode格式，而且还是队列形状；

public:
    // 入队操作（添加树节点指针）
    void enqueue( TreeNode<T> * node) {
        baseQueue.push(node);
    }

    //  出队操作 (返回并移除队列前端的树节点指针)
    TreeNode<T> * dequeue(TreeNode<T> * node )
    {
        if(baseQueue.empty())
            return nullptr;
        TreeNode<T> * frontNode  = baseQueue.front();
        baseQueue.pop();
        return  frontNode ;
    }

    // 查看队首元素(不删除)
    TreeNode<T>* peek() const {
        if(baseQueue.empty()) return nullptr;
        return baseQueue.front();
    }

    void display() const {
        queue< TreeNode<T>* > temp = baseQueue;
        cout << "Queue Contents : " << endl;
        while(!temp.empty())
        {
            cout << temp.front()->data << " ";
            temp.pop();
        }
        cout <<endl;
        cout << "hello";
    }

};
