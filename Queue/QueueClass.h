#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;



/**
 * 1  使用一个pointer 初始化队列
 * 2. 使用一个font and rear 初始化：
 *      双指针的时候，font 需要before 第一个元素，防止删除以后需要往后走，导致f走到r后面了
 * 3. 使用数组作为队列的坏处: 当删除元素的时候需要批量向前移动
 *                          需要shift Array
 *                          delete-o(1) / shift-o(n)
 *
 */

template<class T>
class QueueClass
{
private:
    /* data */
    int size;
    int front;
    int rear;
    T* Queue;

public:
    // 构造函数，用于初始化QueueClass对象
    QueueClass() {}
    QueueClass(int sz):size(sz),front(0),rear(0) {
        Queue = new T[sz];
        for(int i = 0; i < sz; i++) {
            Queue[i] = T(); // 确保每个元素都被初始化
        }
    }
    ~QueueClass() {}

    int getSize() {
        return size;
    }
    int getFront() {
        return front;
    }
    int getRear() {
        return rear;
    }
    T*  getQueue() {
        return Queue;
    }
    void display();
    bool isFull();
    bool isEmpty();
    void enQueue(T val);
    T deQueue();

};

template<class T>
void QueueClass<T>::display() {

    for(int i=(front+1)%size ; i<=rear%size; i++)
    {
        cout << Queue[i] << endl;
    }
}

template<class T>
bool QueueClass<T>::isFull() {
    if( (rear+1)%size == front )
    {
        cout << " Queue is full ." << endl;
        return true;
    }
    return false;
}

template<class T>
bool QueueClass<T>::isEmpty() {
    if(rear == front)
    {
        cout << " Queue is empty ." << endl;
        return true;
    }

    return false;
}

template<class T>
void QueueClass<T>::enQueue(T val) {

    if(isFull())
        return;

    rear = (rear + 1)%size;
    Queue[rear] = val;
    cout << " push " << val <<  endl;


}


template<class T>
T QueueClass<T>::deQueue() {
    if(isEmpty())
        return  0;

    front = (front + 1)%size;
    T toDelete = Queue[front];
    cout << " pop " << toDelete <<  endl;

    return toDelete;
}




template<class T>
class Node {
public:
    T data;
    Node* next;

    Node():next(nullptr) {}
    Node(T val):data(val),next(nullptr) {}
    ~Node() {}
    T getVal() {
        return data;
    }
    Node* getNode() {
        return next;
    }


};


template<class T>
class QueueLinkClass
{
private:
    /* data */
    int size;
    Node<T>* front;
    Node<T>*  rear;

public:
    // 构造函数，用于初始化QueueClass对象
    QueueLinkClass(): size(0),front(nullptr),rear(nullptr) {}
    QueueLinkClass(int sz):size(sz),front(nullptr),rear(nullptr)  {}
    ~QueueLinkClass() {}

    int getSize() {
        return size;
    }
    Node<T>*  getFront() {
        return front;
    }
    T getFrontVal() {
        if(isEmpty()) return NULL;
        return front->data;
    }
    Node<T>*  getRear() {
        return rear;
    }
    void display();
    bool isFull();
    bool isEmpty();
    void enQueue(T val);
    T deQueue();

};


template<class T>
bool QueueLinkClass<T>::isEmpty() {
    if(front == nullptr)
        return true;
    return false;
}

template<class T>
void QueueLinkClass<T>::enQueue(T val) {

    Node<T>* newNode = new Node<T>(val);
    if( isEmpty() )
    {
        front = rear  = newNode;
    } else
    {
        // 队列的尾巴节点的next指向新的节点
        rear->next = newNode;
        // 队列尾巴移动到新节点
        rear = newNode;
    }

}



template<class T>
T QueueLinkClass<T>::deQueue() {
    if (isEmpty()) {
        throw underflow_error("Cannot dequeue from empty queue");
    }

    // 保存要删除的节点和数据
    Node<T>* toDelete = front;
    T getData = toDelete->data;

    // 更新队头指针
    front = front->next;

    // 如果队列已空，尾指针也置空
    if (front == nullptr) {
        rear = nullptr;
    }

    delete toDelete;
    return getData;
}


template<class T>
void QueueLinkClass<T>::display() {

    if(isEmpty())
        return ;  // 如果是空的；
    Node<T> *ptr = front;
    while(ptr->next != nullptr)
    {
        cout << ptr->data << " " ;
        ptr = ptr->next;
    }
    cout << endl;
}