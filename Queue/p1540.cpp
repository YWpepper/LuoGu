#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;

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
    QueueClass(){}
    QueueClass(int sz):size(sz),front(0),rear(0){
        Queue = new T[sz];
        for(int i = 0; i < sz; i++) {
            Queue[i] = T(); // 确保每个元素都被初始化
        }
    }
    ~QueueClass(){}


    int getSize(){return size;}
    int getFront(){return front;}
    int getRear(){ return rear;}
    T*  getQueue(){return Queue;}
    void display();
    bool isFull();
    bool isEmpty();
    void enQueue(T val);
    T deQueue();

 };

 
 template<class T>
 void QueueClass<T>::display(){

    for(int i=(front+1)%size ;i<=rear%size; i++)
    {
        cout << Queue[i] << endl;
    }
 }
 
 template<class T>
 bool QueueClass<T>::isFull(){
    if( (rear+1)%size == front )
    {
            return true;
    }
    return false;
 }

  template<class T>
 bool QueueClass<T>::isEmpty(){
    if(rear == front)
        return true;

    return false;
 }

template<class T>
void QueueClass<T>::enQueue(T val){

    if(isFull())
        return;
    
    rear = (rear + 1)%size;
    Queue[rear] = val;

}


template<class T>
T QueueClass<T>::deQueue(){
    if(isEmpty())
        return  0;
    
    front = (front + 1)%size;
    T toDelete = Queue[front];

    return toDelete;
}




int main(){

    /*
     测试：队列经典算法题目 机器翻译
    */
   int size=0; 
   int inputLen = 0;
   cin >> size >> inputLen;
   // 初始化队列，初始化数组
   QueueClass<int> myQue(size+1);
   int *req = new int[inputLen];
   memset(req,0,inputLen);
   // 初始化一个哈希表
    int hash[1005] ={0};
    // 初始化基数表
    int cnt=0;
   // 输入数组
   for(int i=0 ;i < inputLen ; i++)
   {
        
        cin >> req[i];
        int cinTemp = req[i];
        if(! hash[cinTemp])
        {
            // cout << "查找单词" << cinTemp << endl;
            // 如果没有出现过，才可以往里面push
            hash[cinTemp]=1;
            // 检查队列是否满了
            if(myQue.isFull())
            {
                // 满了需要pop出来再放入
                int temp = myQue.deQueue();
                // pop 的同时需要重新设置哈希表的编号
                hash[temp]=0;
                myQue.enQueue(cinTemp);
                // cout << "调入内存" << cinTemp << endl;
            }else{
                // 没有满则直接放入
                myQue.enQueue(cinTemp);
                // cout << "调入内存" << cinTemp << endl;
            }
            cnt++;
            // myQue.display();
        }
   }
   cout << cnt <<  endl;

}