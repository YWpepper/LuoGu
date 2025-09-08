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
class LinkClass
{
    // 定义一个循环链表类
private:
    Node<T> *first;

public:
    LinkClass() : first(nullptr) {}
    LinkClass(int arr[], int len)
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
    }
    void diaplay()
    {
        Node<T> *ptr = this->first;
        // 1. 链表为空
        if (!first)
            return;
        // 2. 只有一个节点
        if (ptr->next == nullptr)
        {
            cout << ptr->data << endl; // 打印第一个节点
            return;
        }
        // 3. 有多个节点
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next; // 递进遍历节点

        } while (ptr->next != nullptr); // 因为当前ptr应该是最后一个节点，最后一个节点不等于first节点
        cout << endl;
    }
    Node<T> *getFirst() { return first; }
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
        clear();
    }
    void clear();
    void display();
    void insert(int idx, T data);
    void deleteNode(int idx);
    bool get(int idx, T &retrunData);
    int length();
};

template <class T>
void CycleLinkClass<T>::clear()
{
    Node<T> *cur = first->next;
    Node<T> *cleanTarget;
    while (cur != first)
    {
        cleanTarget = cur;  // 用来指向删除节点
        cur = cur->next;    // 用来遍历
        delete cleanTarget; // 释放空间
    }
    delete first; // 删除头节点
    first = nullptr;
}

template <class T>
void CycleLinkClass<T>::display()
{
    if (!first)
        return; // 第一个节点为空
    Node<T> *ptr = this->first;
    cout << ptr->data << " "; // 打印第一个节点
    do
    {
        ptr = ptr->next; // 递进遍历节点
        cout << ptr->data << " ";
    } while (ptr->next != first); // 因为当前ptr应该是最后一个节点，最后一个节点不等于first节点
    cout << endl;
}

template <class T>
void CycleLinkClass<T>::insert(int idx, T target)
{
    Node<T> *prev = first;          // 用来遍历链表
    Node<T> *newNode = new Node<T>; // 初始化一个新的节点空间；但是这里初始化的方式错误，应该动态初始化。
    newNode->data = target;

    // 1. 空链表。
    if (first == nullptr)
    {
        first = newNode;
        return;
    }
    // 1. 插入作为头节点
    if (idx = 0)
    {

        Node<T> *last = first;
        while (last->next != first)
            last = last->next;
        // 找到最尾巴的元素
        newNode->next = first;
        first = newNode;
        last->next = newNode;
        return;
    }

    // 如果不是头节点。
    for (int i = 0; i < idx - 1; i++)
    {
        prev = prev->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
    return;
}

template <class T>
void CycleLinkClass<T>::deleteNode(int idx)
{
    if (!first)
        return;

    // 如果只有一个节点
    if (first->next == first)
    {
        delete first;
        first = nullptr;
        return;
    }

    // 如果是头节点,需要修改尾巴节点指针的指向
    if (idx == 0)
    {
        Node<T> *last = first;
        while (last->next != first)
            last = last->next;

        Node<T> *toDelete = first;
        first = first->next; // 重新优化头节点
        last->next = first;  // 指向新的头节点
        delete toDelete;     // 释放内存
    }
    else // 如果不是头节点
    {
        Node<T> *prev = first;
        for (int i = 0; i < idx - 1; i++)
        {
            prev = prev->next;
            if (prev == first)
                return; // 索引越界
        }
        Node<T> *toDelete = prev->next;
        prev->next = (toDelete)->next;
        delete toDelete; // 释放内存
    }
}

template <class T>
bool CycleLinkClass<T>::get(int idx, T &retrunData)
{
    // 如果链表为空
    if (first == nullptr)
        return false;
    Node<T> *cur = first;
    for (int i = 0; i < idx; i++)
    {
        cur = cur->next;
        if (cur == first)
            return false; //  超越了idx
    }
    retrunData = cur->data;
    return true;
}

template <class T>
class doubleLinkClass
{
private:
    // 内部节点类
    class Node2
    {
    private:
        Node2 *prev;
        T data;
        Node2 *next;

    public:
        Node2(T val) : prev(nullptr), data(val), next(nullptr) {}
        ~Node2() {}
        T &getdata() { return data; }
        void setData(const T &val) { data = val; }

        Node2 *&getNext() { return next; }
        void setNext(Node2 *n) { next = n; }

        Node2 *&getPrev() { return prev; }
        void setPrev(Node2 *p) { prev = p; }
    };

    Node2 *first; // 这是链表了；

public:
    doubleLinkClass() : first(nullptr) {}
    // 析构函数，用于释放对象占用的内存
    ~doubleLinkClass() {}
    void insert(int idx, T data);
    void display();
    void remove(int idx);
    void reverse();
};

template <class T>
void doubleLinkClass<T>::insert(int idx, T key)
{
    Node2 *newNode = new Node2(key);
    // 1. 如果链表一开始就是空的
    if (first == nullptr)
    {
        first = newNode;
        first->setNext(nullptr);
        first->setPrev(nullptr);
        return;
    }

    // 2. 插入作为头节点
    if (idx == 0)
    {
        newNode->setPrev(nullptr);
        newNode->setNext(first);
        first->setPrev(newNode);
        first = newNode;
        return;
    }
    // 3. 插入非头节点
    Node2 *cur = first;
    for (int i = 0; i < idx - 1; i++)
    {
        cur = cur->getNext();
        if (cur == nullptr)
        {
            cout << "idx is out of edge" << endl;
            delete newNode;
            return;
        }
    }

    newNode->setNext(cur->getNext());
    newNode->setPrev(cur);
    cur->setNext(newNode);
    return;
}

template <class T>
void doubleLinkClass<T>::display()
{
    int cnt = 10;
    if (first == nullptr)
        return;
    Node2 *cur = first;
    while (cur != 0 && cnt)
    {
        cnt--;
        cout << cur->getdata() << " ";
        cur = cur->getNext();
    }
    cout << endl;
    return;
}

template <class T>
void doubleLinkClass<T>::remove(int idx)
{
    if (first == nullptr)
        return;
    // 删除头节点
    if (idx == 0)
    {
        Node2 *toDelete;
        toDelete = first;
        first = first->getNext();
        first->setPrev(nullptr);
        delete toDelete;
        return;
    }
    // 如果不是头节点；
    Node2 *cur = first;
    for (int i = 0; i < idx - 1; i++)
    {
        cur = cur->getNext();
        if (cur->getNext() == nullptr)
            return;
    }
    Node2 *toDelete;
    toDelete = cur->getNext();
    if (toDelete->getNext()) // 如果删掉的不是最后一个节点；
    {
        cur->setNext(toDelete->getNext());
        (toDelete->getNext())->setPrev(cur);
        delete toDelete;
        return;
    }
    else // 如果删掉的是最后一个节点；
    {
        cur->setNext(nullptr);
        delete toDelete;
        return;
    }
}

template <class T>
void doubleLinkClass<T>::reverse() // 交换链表
{

    Node2 *cur;         // 用一个表示当前循环中在处理的节点
    Node2 *ptr = first; // 这个用来引领cur更新往下
    int cnt = 0;
    do
    {
        // cnt++;
        // cout << cnt << endl;
        cur = ptr;
        ptr = ptr->getNext();
        Node2 *temp = cur->getNext();
        cur->setNext(cur->getPrev());
        cur->setPrev(temp);
        if (ptr->getNext() == nullptr)
        {
            first = ptr;
        }
    } while (ptr->getNext() != nullptr);
    // 上述跳出的条件是ptr指向最后一个节点。
    ptr->setPrev(nullptr); // 手动处理最后一个节点
    ptr->setNext(cur);
}
