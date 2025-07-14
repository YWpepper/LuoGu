#include"Array.h"
#include<cstring> 
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

    // 初始化哈希映射
    static T hash_init(WorkArray<T> &hashArray ,const ArrayClass<T> &arr ,int maxNum, int lowNum );

    static T findinMisserInDisorder(ArrayClass<T> &arr){

        int maxNum = arr.getMaxValue();
        int lowNum = arr.getSmallValue();
        int arrlen = maxNum-lowNum+1;
        WorkArray<T> flagArray(arrlen,arrlen);
        WorkArray<T>::hash_init(flagArray,arr,maxNum,lowNum);
        for(int i=0; i < flagArray.getLength() ; i++ )
        {
            if( flagArray.getElement(i) != 1)
            {
                cout << "missing number is " << i+lowNum << endl;
            }
        }
    }

    static T find_pairs_with_sum( ArrayClass<T> &arr ,T sum);
    
};

template<class T>
T  WorkArray<T>::hash_init (WorkArray<T> &hashArray ,const ArrayClass<T> &arr,int maxNum, int lowNum ){

    if (maxNum - lowNum + 1 > 0 )
    {
        for(int i=0; i < hashArray.getLength() ; i++)
        {
            hashArray.setArray(i,0);
        }
        for(int i=0; i < arr.getLength() ; i++)
        {
            int value = arr.getElement(i);
            hashArray.setArray(value-lowNum,1);
        }
    }
}

template<class T>
T WorkArray<T>::find_pairs_with_sum(ArrayClass<T> &arr , T sum ){
    
    // 初始化一个哈希表 
    WorkArray<T> hashTable(arr.getMaxValue()-arr.getSmallValue()+1 , arr.getMaxValue()-arr.getSmallValue()+1 );
    hash_init(hashTable,arr, arr.getMaxValue(), arr.getSmallValue());
    for(int i=0 ;i <hashTable.getLength(); i++)
    {
        cout << hashTable.getElement(i) << " ";
    }
    cout << endl;

     // 初始化一个结果数组
    int cnt=0;
    int min = arr.getSmallValue(); // 4 
    int result[2][arr.getLength()]={{0}}; 
    memset(result, 0, sizeof(result));

    // 如果hashTable[sum-i]
    for(int i=0; i<arr.getLength() ; i++)
    {
        if (sum-arr.getElement(i)-min > 0)
        {
            if(hashTable.getElement(sum-arr.getElement(i)-min) == 1 && arr.getElement(i) < sum  )  // 10-0-4 10-1-4 10-2-4  10-3-4  
            {
                result[0][cnt] = arr.getElement(i);   
                result[1][cnt] = sum - arr.getElement(i);
                cnt++ ;
            }
        }
       
    }
    for (int i=0; i<arr.getLength() ; i++)
    {
        if (result[0][i] > 0 && result[0][i] >0 )
            cout << result[0][i] << " with " << result[1][i] << endl; 
    }
    

}




int main(){

    WorkArray<int> arr01(10,15);
    // arr01.randomInit();
    // 构建一个自然数列
    for(int i=0 ; i<arr01.getLength(); i++)
        arr01.setArray(i,i+4);
    


    // 删除一个index = 3 对应的元素
    cout << " this is arr01 : " << endl;
    arr01.display();

    /* function : 找出缺失的数值

    int indexGap = arr01.getElement(0) ;
    for (int i=0; i < arr01.getLength() ; i++)
    {
        int tempGap = arr01.getElement(i) - i;
        if (tempGap > indexGap ) 
        {
            cout << "missing : " << i+indexGap << endl;
            indexGap = tempGap;
        }
    }
    */


    // cout << "The max index is:  " << arr01.getMaxIndex() << endl;
    // cout << "The small index is:  " << arr01.getSmallIndex() << endl;
    WorkArray<int>:: find_pairs_with_sum(arr01, 10);

    








}

