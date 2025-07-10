#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<random>
#include"Array.h"
using namespace std;
static random_device rd;
static mt19937 gen(rd());



int main(){
    int inputSZ = 10 ;
    int inputLL = 5;
    srand(time(nullptr));


    myArray<int> arr(inputSZ, inputLL);
    for(int i=0 ; i<inputLL ; i++)
    {
        int inputKey;
        arr.initialArray(i,(cin>>inputKey,inputKey));
    }
    arr.display();


    myArray<float> arr1(5,5);
    myArray<float> arr2(5,5);
    myArray<float> arr3(15,15);
    arr1.mergeArray(arr1, arr2);



}