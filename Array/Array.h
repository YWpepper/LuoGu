#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<random>
using namespace std;
static random_device rd;
static mt19937 gen(rd());



template<typename T>
class myArray{

    private:
    T *p; 
    int size;
    int length;

    public:
    // 构造函数，无返回值
    myArray(int sz, int ll) : size(sz),length(ll){
        p = new T[size];
    }
    // 析构函数,销毁对象时调用
    ~myArray(){
        delete[] p ;
    };
    void display();
    int getSize() const;
    int getLength() const;
    void initialArray(int idx, T key);
    bool isSorted();
    void Reverse(); // 数组顺序颠倒
    void swap(int index_1, int index_2);
    void reverseBySwap(int start, int end);
    void leftShift(); // 将数组的元素向左移动n位，并且空出来的用default数值填充
    void leftRotate(); //将数组的元素向左旋转，
    void rightShift();
    void rightRotate();
    void randomInit();
    static myArray<T> mergeArray(const myArray<T> &arr1 , const myArray<T> &arr2);
    
};




template<class T>
void myArray<T>::display(){
    for(int i=0; i<length; i++)
    {
        cout <<  p[i] << " " ;
    }
    cout << endl;
}

template<class T>
int myArray<T>::getSize() const{
   return size;
}

template<class T>
int myArray<T>::getLength() const{
   return length ;
}


template<class T>
bool myArray<T>::isSorted(){
    for(int i=0; i<length-1; i++)
    {
        if ( p[i] > p[i+1] )
            return false;
    }
    return true;
}


template<class T>
void myArray<T>::Reverse(){
    // 方案1 ： 
    myArray<T> temp(size,length);
    for(int i=0; i<length;i++)
    {
        temp.p[i] = p[i];  
    }
    for(int i=0,j=length-1; j>=0; i++,j--)
    {
        p[i] = temp.p[j];
    }
}

template<class T>
void myArray<T>::swap(int index_1, int index_2){
    int temp = p[index_1];
    p[index_1] = p[index_2];
    p[index_2] = temp;
}



template<class T>
void myArray<T>::reverseBySwap(int start, int end){
    // 方案2 ： 
    if(start >= end)
    {
        return ;
    }
    myArray<T>::swap(start++,end--);
    return myArray<T>::reverseBySwap(start,end);
}

template<class T>
void myArray<T>::initialArray(int idx, T key){
    p[idx] = key;
}


// 随机初始化函数
template<class T>
void myArray<T>::randomInit(){
    srand(time(nullptr)); // 设置随机种子；
    for(int i=0; i<length; i++)
    {
        std::uniform_int_distribution<int> dis(1,100);
        p[i] = dis(gen);

    }
}

template<class T>
myArray<T> myArray<T>::mergeArray(const myArray<T> &arr1 , const myArray<T> &arr2){
    // initial firstly
    myArray<T> merge(arr1.getSize() + arr2.getSize(),arr1.getLength()+arr2.getLength() ); 
    // merge.p = (T*)malloc(sizeof(T) * merge.size);
    for(int i=0; i < arr1.getLength(); i++)
    {
        merge.p[i] = arr1.p[i];
    }
    for(int i = 0; i < arr2.getLength(); i++)
    {
        merge.p[i + arr1.getLength()] = arr2.p[i];
    }
    return merge;

}