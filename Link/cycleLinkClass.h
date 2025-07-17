#include <cstdio>
#include <cstdlib> // malloc func
#include <iostream>
using namespace std;

template <class T>
class Node
{

public:
    T data;
    Node<T> *next;
    Node() : next(nullptr) {}
    Node(T data) : data(data), next(nullptr) {}
    ~Node() {}
};

template <class T>
class CycleLinkClass
{
    // 定义一个循环链表类
private:
    Node<T> *first;

public:
    CycleLinkClass() : first(nullptr) {}
    CycleLinkClass(int arr[], int len)
    {
        Node<int> *ptr = first;
        int flag = 1;
        for (int i = 0; i < len; i++)
        {
            Node<int> *newNode = new Node<int>;
            newNode->data = arr[i];
            newNode->next = nullptr;
            if (flag == 1) // 如果本来链表为空
            {
                flag = 0;
                first = newNode;
                ptr = first; // 重新指向一次
            }
            else
            {
                ptr->next = newNode;
                ptr = ptr->next;
            }
        }
        ptr->next = first; // 由于是循环链表
    }
     // 构造函数，初始化指针为空
    // ~CycleLinkClass() {}
    ~CycleLinkClass() // 注意这是一个循环链表
    {
        if(!first) return; // 空链表直接返回

        // 循环链表需要先断开链表
        Node<T> *last = first;
        while(last->next !=first)
        {
            last = last->next;
        }
        // 遍历到链表的最后的时候--断开循环
        last->next = nullptr;

        Node<T> *p = first; // 用来指向链表的空间，因为如果用first然后delete掉first就无法继续往前了。
        // 要么多设计一个在后面的指针，删掉后面；或者设计一个在前面的指针，删掉当前；
        // 本思想是first在前，p在后；
        while (first) // 只要头节点不为空，一直让头节点走到最后一个节点
        {
            first = first->next; // first走在p的前一个
            free(p);            // 删掉当前p的空间
            p = first;           // 再次指向当前最新的first的位置
        }
    }

   
    void display();
    void insert(int idx, T data);
    void deleteNode(int idx);
    int getLength();

};

template <class T>
void CycleLinkClass<T>::display()
{
    if (!first) return; // 第一个节点为空
    Node<T> *ptr = this->first;
    cout << ptr->data << " "; // 打印第一个节点
    do
    {
        ptr = ptr->next; //递进遍历节点
        cout << ptr->data << " ";
    } while (ptr->next != first); // 因为当前ptr应该是最后一个节点，最后一个节点不等于first节点
    cout << endl;
}

template <class T>
void CycleLinkClass<T>::insert(int idx, T data)
{
    Node<T> ptr = first;   // 用来遍历链表
    Node<T> newNode(data); // 初始化一个新的节点空间；但是这里初始化的方式错误，应该动态初始化。
    if (ptr == nullptr || idx = 0)
    {
        newNode->next = ptr->next;
        ptr = newNode;
    }
}


template <class T>
void CycleLinkClass<T>::deleteNode(int idx)
{
    if(!first) return;

    // 如果只有一个节点
    if(first->next == first) {
        delete first;
        first = nullptr;
        return;
    }

    // 如果是头节点,需要修改尾巴节点指针的指向
    if(idx==0)
    {
        Node<T> *last = first;
        while(last->next != first)
            last = last->next;
        
        Node<T> *toDelete = first;
        first = first->next; // 重新优化头节点
        last->next = first; // 指向新的头节点
        delete toDelete;  // 释放内存
    }else // 如果不是头节点
    {
        Node<T> *prev = first;
        for(int i = 0; i < idx - 1; i++) 
        {
            prev = prev->next;
        if(prev == first)  return; // 索引越界
        }
        Node<T> *toDelete = prev->next;
        prev->next = (toDelete)->next; 
        delete toDelete;  // 释放内存
    }

}

 