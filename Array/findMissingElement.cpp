#include"Array.h"
#include<iostream>
using namespace std;


template <class T>
class WorkArray:public ArrayClass<T>{
    
    public:
    // 作为derived class 必须首先构造基类部分
    WorkArray(int workL, int workS):ArrayClass<T>(workL,workS){}
    // 作为derived class 派生类通常不需要手动释放基类分配的内存
    // ~WorkArray();

    T sum(){
        T sum = 0;
        int n = ArrayClass<T>::getLength() ;
        sum = n*(ArrayClass<T>::getElement(0) + ArrayClass<T>::getElement(n-1)) / 2;   
        return sum;
    }

};


int main(){

    WorkArray<int> arr01(4,15);
    // 构建一个自然数列
    for(int i=0 ; i<arr01.getLength(); i++)
        arr01.initialArray(i,i+4);
    
    // 删除一个index = 3 对应的元素
    arr01.deleteArray(2);
    arr01.display();

//     // 找出missing-element
//     int  nowSum = arr01.sum();
//     int  rawSum = (arr01.getLength()+1)* (arr01.getElement(0) + arr01.getElement(arr01.getLength()-1))/2; 
//    cout << "missing:" << rawSum-nowSum << endl;
    int indexGap = arr01.getElement(0) ;
    for (int i=0; i < arr01.getLength() ; i++)
    {
        int tempGap = arr01.getElement(i)-i;
        if( tempGap > indexGap)
            cout << "missing : " << i+indexGap << endl;
    }




}

