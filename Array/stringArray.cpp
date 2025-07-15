#include"Array.h"
#include<string>
#include <bitset>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;


void lower2upper(char* arr){
    for(int i=0 ;arr[i] !='\0' ; i++)
    {
        if( arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] =  arr[i] - ('a'-'A') ; 
        }
    }
}

// 函数用于显示字符数组
void display(char* arr){
  
    for(int i=0 ;i<strlen(arr) ; i++)
    {
       cout << arr[i] ;
    }
    cout << endl;
}






char* reverse_func1(char* str)
{
    int len = strlen(str);
    char*  rever_str = (char*)malloc(len*sizeof(str));
    for(int i = 0; i < len; i++)
    {
        rever_str[i] = str[len - 1 - i];
    }
    rever_str[len] = '\0';
    strcpy(str,rever_str);
    free(rever_str);
    return str;
}


char* swapChar(char* str,int idx1,  int idx2)
{
    char tempChar = str[idx1];
    str[idx1] = str[idx2];
    str[idx2] = tempChar;
    return str;
}



char* reverse_func2(char* str)
{
    int len = strlen(str);
    for (int i = 0; i <= len/2; i++)
    {
        swapChar(str, i, (len-i-1) );
    }
    return str;
}


int* findDpInString(char* str, int* hash)
{
    // 遍历字符串
    for(int i=0; i < strlen(str); i++)
    {
        int gap = abs(str[i] - 'a'); 
        hash[gap] += 1;
        if(hash[gap]>1)
        {
            cout << str[i]  << " was dupilicate in "  << hash[gap] << " times" << endl;
        }
    }
    return hash;
}



void findDpInStringBit(char* str)
{
    long int h_tag=0,x=1 ; // 本身就是32位的二进制存储空间
    long int printed = 0; 
    for( int i=0 ;i <strlen(str) ; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            x = 1; // 注意每一轮都需要重新设置x为1；
            x = x << abs(str[i]-'A') ;
            if ( (x & h_tag) == 0) // 首次出现
            {
                h_tag =  h_tag|x;  // 设置为1
                cout << "my hash is : " <<  bitset<32>(h_tag) << endl;
            }else
            {
                if ((x & printed) == 0) 
                {
                    // cout << str[i] << " is duplicated" << endl;
                    printed |= x; // 标记为已输出
                }
            }
        }   
    }    
 
}




long int createBitHash(char* str)
{
    long int x=0;
    long int h_tag=0;
    for(int i=0; i<strlen(str); i++)
    {
        x = 1;
        x = x << abs(str[i] - 'A') ; 
        if( (x & h_tag) == 0 )
        {
            h_tag |=x ;
        }
    }
    cout << "Bit hash (binary): " << bitset<32>(h_tag) << endl;
    return h_tag;
}

void findDpInStringBit_simple(char* str)
{
    long int hash_flag = createBitHash(str);
    // 把hash_flag输出为二进制
    cout << "Bit hash (binary): " << bitset<32>(hash_flag) << endl;
    //根据hash_flag来打印出现过的字母，不能计算出现过几次。
    for (int i = 0; i < 26; i++) {
        if (hash_flag & (1 << i)) {
            cout << (char)('a' + i) << " ";
        }
    }
}

bool isAnagram(char* arr1, char * arr2)
{
    int len = 'a'-'A';
    cout << "len is " << len << endl;
    int *hash_tab = new int[len];
    memset(hash_tab,0,len);
    for(int i=0; i< strlen(arr1) ; i++)
    {
        if(arr1[i]>='a'&& arr1[i] <= 'z')
            hash_tab[arr1[i]-'a'] +=1;
    }
    for(int i=0; i< strlen(arr2) ; i++)
    {
        if(arr2[i] >= 'a'&& arr2[i] <= 'z')
            hash_tab[arr2[i]-'a'] -=1;
    }
    for(int i=0; i<len ; i++)
    {
        if(hash_tab[i]!=0)
        {
            cout << "it is not anagram" << endl;
            return false ;
        }
    }
    cout << "it is anagram" << endl;
    return true;
}


int permutation(char *str, char *res, int used[],int idx ){
    int mylen = strlen(str); 
    if(idx >= mylen)
    {
        for(int i=0; i < mylen;i++) cout << res[i] << " " ;
        cout << endl; 
        return 0;
    }
    for ( int j=0 ; j < mylen; j++ ) // 控制选择abc的哪一个
    {
        if( used[j]!=0 )
            continue;
        res[idx] = str[j];
        used[j] = 1;  
        permutation(str,res,used,idx+1); 
        used[j] = 0;
    }
}



int main(){

    // string str = "hellooaimlowas";
    // char cstr1[] = "silentt";
    // char cstr2[] = "listen";
    // lower2upper(cstr);
    // display(cstr);

    // int hash_len= 'a'-'A'+ 1 ;
    // int* resultOfHash = new int[hash_len];
    // memset(resultOfHash,0,hash_len);
    // resultOfHash = findDpInString(cstr,resultOfHash);
    // for(int i =0 ;i<hash_len; i++)
    // {
    //     cout << resultOfHash[i] << " " ;
    // }

    // findDpInStringBit_simple(cstr);
    // findDpInStringBit_simple(cstr);
    
    // isAnagram(cstr1,cstr2);

    char str[4] = {'a','b','c','\0'};
    char res[4] = "";
    int used[4] = {0};
    int mylen = strlen(str);
    memset(res,'a',mylen);
    memset(used,0,mylen);  
    int idx = 0;
    permutation(str,res,used,idx);
    return 0;

}


