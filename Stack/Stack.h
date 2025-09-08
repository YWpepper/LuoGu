#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;

/*
data:
    1. space for stacking eleements
    2. top point
operating: 
    1. push
    2. POP
    3. peek(index)
    4. stackTop
    5. isEmpty()
    6. isFull()
*/
template<class T>
class stackArrayClass{

    private:
        int size;
        T* top;
        T* s ;
    public: 
    stackArrayClass():size(0),top(nullptr),s(nullptr){}
    stackArrayClass(int sz):size(sz){
        T *arr= new T[size];
        s = arr;
        top = s-1;
    }
    ~stackArrayClass(){}

    int getSize(){
        return size;
    }
     T* getTop(){
        return top;
    }

    T* getStack(){
        return s;
    }

    bool isEmpty();
    bool isFull();
    bool push(T val);
    bool pop();
    bool display();
    T peak(int posIdx);


};

template<class T>
 bool stackArrayClass<T>::isEmpty(){

        if(top == s-1)
        return true;
        else
        return false;
 }


 template<class T>
 bool stackArrayClass<T>::isFull(){
        if( top == s + size)
        return true;
        else
        return false;
 }


  template<class T>
 bool stackArrayClass<T>::push(T val){
    // 插入的时候需要先判断是否已经满栈了
        if(isFull()) {
        return false;  // 栈已满，无法插入
    }
    top++;  // 先增加 top
    *top = val ; // 通过指针赋值
    return true;
}

  template<class T>
bool stackArrayClass<T>::pop(){
    if(isEmpty()){
        cout << "it is already empty" << endl;
        return false;
    }
    cout << "the top is " << *top << endl;
    *top = NULL;
    top--; 
    return true;
}

  template<class T>
 bool stackArrayClass<T>::display(){
    if(top == s-1 ){
        cout << "stack is empty" << endl;
        return false;
    }
    T* ptr = s;
    while(ptr <= top )
    {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;
    return true;
}


template<class T>
T stackArrayClass<T>::peak(int posIdx)
{
    if( top - posIdx + 1 < s )
    {
        cout << "ilegal index" << endl;
        return 0;
    }
    cout << "*(top-posIdx) is " << *(top - posIdx + 1) << endl;
    return *(top - posIdx + 1);
}


template<class T>
class Node{
    public:
    T data;
    Node* next;

    Node():next(nullptr){}
    Node(T val):data(val),next(nullptr){}
    ~Node(){}
    T getVal(){return data;}
    T getNode(){return next;}
    

};


template<class T>
class stackLinkClass{

private:

    Node<T>* top;
    Node<T>* s;
    int size;

public:

    stackLinkClass():top(nullptr),s(nullptr),size(0){}
    stackLinkClass(int sz):top(nullptr),s(nullptr),size(sz){
        cout << "initial successfuly" << endl;
    }

    int getSize(){return size;}
    Node<T>* getTop(){return top;}
    Node<T>* getSatck(){return s;}

    void creatStackInLink(Node<T>* head)
    {
        s = head;
        Node<T>* ptr = head;
        // while(ptr)
        top =s;
    }

    bool isEmpty(){
        if(top == nullptr || top == s-1 )
            return true;
        return false;
    }

    bool isFull(){
        if(top -size + 1 == s )
        return true;
        return false;
    }


    void push(T val){
        if(isFull())
            return;
        
        // 一定要动态开辟空间
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty())
        {
            s = top = newNode;
            cout << "push " << newNode->data << endl;
            return;
        }
        
        // 正常含有数值的情况的话
        cout << "push " << newNode->data << endl;
        newNode->next = top;
        top =  newNode;
    }


    void display(){

        Node<T>* ptr = top ; 
        if(ptr==nullptr)
        {
             cout << "without element" << endl;
             return ;
        }
        
        while(ptr!=nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
        return ;
    }

    T pop(){

        Node<T>* ptr = top ; 
        if (ptr == nullptr)
            return NULL;
        Node<T>* toDelete = ptr;
        T DeleteData = toDelete->data;
        cout << "POP: " << toDelete->data << endl;
        top = top->next;
        delete toDelete;
        return DeleteData;
        }


};