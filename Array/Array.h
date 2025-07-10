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
        delete []p ;
    };
    void display();
    void initialArray(int idx, T key);
    bool isSorted();
    void randomInit();
    myArray<T> mergeArray(const myArray<T> &arr1 , const myArray<T> &arr2);
    
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
bool myArray<T>::isSorted(){
    for(int i=0; i<length; i++)
    {
        if ( p[i] > p[i+1] )
            return false;
    }
    return true;
}

template<class T>
void myArray<T>::initialArray(int idx, T key){
    p[idx] = key;
}

template<class T>
void myArray<T>::randomInit(){
    srand(time(nullptr)); // 设置随机种子；
    for(int i=0; i<length; i++)
    {
        p[i] = dis(gen);

    }
}



template<class T>
myArray<T> myArray<T>::mergeArray(const myArray<T> &arr1 , const myArray<T> &arr2){
// 访问私有成员问题：arr1.size 和 arr1.length 无法直接访问
    // initial firstly
    myArray<T> merge(arr1.size+arr2.size,arr1.length+arr2.length ); 
    for(int i=0; i < arr1.length; i++)
    {
        merge.p[i] = arr1.p[i];
    }
    for(int i = 0; i < merge.length; i++)
    {
        merge.p[i + arr1.length] = arr2.p[i];
    }
    return merge;

}