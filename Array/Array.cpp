#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<random>
#include"Array.h"
using namespace std;

int main(){
    int inputSZ = 10 ;
    int inputLL = 5;
    srand(time(nullptr));

    // myArray<int> arr(inputSZ, inputLL);
    // for(int i=0 ; i<inputLL ; i++)
    // {
    //     int inputKey;
    //     arr.initialArray(i,(cin>>inputKey,inputKey));
    // }
    // arr.display();


    /*   测试两个数组合并

    myArray<int> arr1(5,5);
    arr1.randomInit();
    arr1.display();

    myArray<int> arr2(5,5);
    arr2.randomInit();
    arr2.display();

    // 注意不要先建立一个arr3，然后让 arr3 = merge，因为merge会被释放；
    myArray<int> arr3  = myArray<int>::mergeArray(arr1, arr2);
    arr3.display();
    
    */



}