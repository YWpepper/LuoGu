#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<random>
#include"Array.h"
using namespace std;

int main(){

    /*
    // function： 测试初始化数组函数    
    
    int inputSZ = 10 ;
    int inputLL = 5;
    srand(time(nullptr));

    ArrayClass<int> arr(inputSZ, inputLL);
    for(int i=0 ; i<inputLL ; i++)
    {
        int inputKey;
        arr.initialArray(i,(cin>>inputKey,inputKey));
    }
    arr.display();
    */


    /*   检验fucntion :  两个数组合并函数 mergeArray()
    ArrayClass<int> arr1(5,5);
    arr1.randomInit();
    arr1.display();

    ArrayClass<int> arr2(5,5);
    arr2.randomInit();
    arr2.display();

    // 注意不要先建立一个arr3，然后让 arr3 = merge，因为merge会被释放；
    ArrayClass<int> arr3  = ArrayClass<int>::mergeArray(arr1, arr2);
    arr3.display();
    */

     ArrayClass<int> arr1(5,5);
    arr1.randomInit();
    arr1.display();

    ArrayClass<int> arr2(5,5);
    arr2.randomInit();
    arr2.display();

    // 注意不要先建立一个arr3，然后让 arr3 = merge，因为merge会被释放；
    ArrayClass<int> arr3  =  ArrayClass<int>::mergeArray(arr1, arr2);
    arr3.display();

    
    /* 检验fucntion : BinarySearch(),insertArray()

    ArrayClass<int> arr1(10,5);
    arr1.randomInit();
    cout << "randomInit as follow: " << endl;
    arr1.display();


    if(!arr1.isSorted()){
        cout << "it's not sorted" << endl;
        arr1.bubbleSort();
        cout << "after sorted:" << endl;
        arr1.display();
    }

    cout << "BinarySearch: " << endl;
    int insertTarget = 20 ; 
    int index = arr1.BinarySearch(0,arr1.getLength(),insertTarget);
    cout << "we want to insert "<< insertTarget << ",the index is : "<< index << endl;
    
    cout <<  "insertArray: " <<endl ;
    arr1.insertArray(index,insertTarget);
    arr1.display();
    */



}