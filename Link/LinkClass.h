#include <iostream>
using namespace std;

/**
 * 检查链表是否为空
 * if(p==NULL)
 * if(p==0)
 * if(!p)
 * if(p->next == NULL)
 * */

/**
 * 检查链表是否不为空
 * if(p!=NULL)
 * if(p!=0)
 * if(p)
 * */

/* --- c style --- */
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
void createLinkedList(T *arr, int len)
{
    struct Node<T> *temp, *last;
    Node<T> *first = new Node<T>();
    first->data = arr[0];
    first->next = nullptr;
    last = first;
    for (int i = 0; i < len; i++)
    {
        temp->data = arr[i];
        temp->next = nullptr;
        last = temp;
        last->next = temp;
        last = temp;
    }
}

template <class T>
void DisplayLinkedList(struct Node<T> *ptr)
{
    while (ptr != nullptr)
    {
        cout << ptr->data << endl;
    }
}

/* --- c++ style --- */

// template <class T>
// class Node
// {
// public:
//     T data;
//     Node<T> *next;
//     Node(T val) : data(val), next(nullptr) {}
//     // 构造函数，初始化指向一个空的地方
// };

// template <class T>
// class LinkedList
// {
// public:
//     Node<T> *head;
//     // 构造函数，初始化头指针为空
//     LinkedList() : head(nullptr) {}

//     // 添加节点到链表头部
//     void push_front(T val);
// };

// template <class T>
// void LinkedList<T>::push_front(T val)
// {
// }