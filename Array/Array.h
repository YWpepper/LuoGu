#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<random>
using namespace std;
static random_device rd;
static mt19937 gen(rd());



template<typename T>
class ArrayClass{

    private:
    T *p; 
    int length;
    int size;

    public:
    // 构造函数，无返回值
    ArrayClass(int ll, int sz) : length(ll),size(sz){
        p = new T[size];
    }
    // 析构函数,销毁对象时调用
    ~ArrayClass(){
        delete[] p ;
    };
    void display();
    int getSize() const;
    int getLength() const;
    T   getElement(int idx) const;
    void initialArray(int idx, T key); 
    void randomInit(); // 随机初始化单个数组；
    void swap(int index_1, int index_2);
    bool isSorted(); // 检查是否排序
    void bubbleSort(); // 给数组排序
    void Reverse(); // 数组顺序颠倒
    void reverseBySwap(int start, int end); // 通过交换进行数组倒置
    void insertArray(int index, int target); // 输入index插入一个值，并且返回数组
    void deleteArray(int index);
    int BinarySearch(int l, int r ,int target); // 使用二分查找法找到插入的index；
    static ArrayClass<T> mergeArray(const ArrayClass<T> &arr1 , const ArrayClass<T> &arr2);
};




template<class T>
void ArrayClass<T>::display(){
    T *temPtr = p;
    for(int i=0; i<length; i++)
    {
        cout <<  *temPtr << " " ;
        temPtr++;
    }
    cout << endl;
}

template<class T>
int ArrayClass<T>::getSize() const{
   return size;
}

template<class T>
int ArrayClass<T>::getLength() const{
   return length ;
}


template<class T>
T ArrayClass<T>::getElement(int idx) const{
    if(idx >=0 && idx <length)
        return p[idx];
}


template<class T>
void ArrayClass<T>::initialArray(int idx, T key){
    p[idx] = key;
}


// 随机初始化函数
template<class T>
void ArrayClass<T>::randomInit(){
    srand(time(nullptr)); // 设置随机种子；
    for(int i=0; i<length; i++)
    {
        std::uniform_int_distribution<int> dis(1,100);
        p[i] = dis(gen);
    }
}


template<class T>
void ArrayClass<T>::swap(int index_1, int index_2){
    int temp = p[index_1];
    p[index_1] = p[index_2];
    p[index_2] = temp;
}


template<class T>
bool ArrayClass<T>::isSorted(){
    for(int i=0; i<length-1; i++)
    {
        if ( p[i] > p[i+1] )
            return false;
    }
    return true;
}

template<class T>
void ArrayClass<T>::bubbleSort(){
    for(int i=0; i<length; i++)
        for(int j=0; j<length-i-1; j++)
        if(p[j] > p[j+1]){
            T temp = p[j];
            p[j] = p[j+1];
            p[j+1] = temp;
        }
}

template<class T>
int ArrayClass<T>::BinarySearch(int l, int r ,int target){

    int mid = floor( (l+r)/2 );
    if(l>=r) // 如果找不到目标，则返回mid,而不是-1
        return l; 
    if( p[mid] == target)
        return mid; // target_index
    if( p[mid] > target)
        return BinarySearch(l,mid-1,target);
    if ( p[mid] < target)
        return BinarySearch(mid+1, r,target);
}

template<class T>
void ArrayClass<T>::insertArray(int index, int target){
    if( this->length < this-> size )
    {
        for(int i=length;i>index; i--)
        {
            this->p[i] = this->p[i-1];
        }
        this->p[index] = target;
        length = length+1;
    }
}


template<class T>
void ArrayClass<T>::deleteArray(int index){
   
    if(index >0 && index < length)
    {
        if(length>0){
            for(int i=index; i<length-1; i++)
            {
                p[i]=p[i+1];
            }
            length--;
        }
    }
}





template<class T>
void ArrayClass<T>::Reverse(){
    // 方案1 ： 
    ArrayClass<T> temp(size,length);
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
void ArrayClass<T>::reverseBySwap(int start, int end){
    // 方案2 ： 
    if(start >= end)
    {
        return ;
    }
    ArrayClass<T>::swap(start++,end--);
    return ArrayClass<T>::reverseBySwap(start,end);
}


template<class T>
ArrayClass<T> ArrayClass<T>::mergeArray(const ArrayClass<T> &arr1 , const ArrayClass<T> &arr2){
    // initial firstly 记住这里初始化了一个临时变量；
    ArrayClass<T> merge(arr1.getSize() + arr2.getSize(),arr1.getLength()+arr2.getLength() ); 
    for(int i=0; i < arr1.getLength(); i++)
    {
        merge.p[i] = arr1.p[i];
    }
    for(int i = 0; i < arr2.getLength(); i++)
    {
        merge.p[i + arr1.getLength()] = arr2.p[i];
    }
    // 结束的时候注意会delete merge的空间。
    return merge;  
}