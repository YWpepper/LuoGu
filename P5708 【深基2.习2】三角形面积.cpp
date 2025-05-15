/*
题目描述
一个三角形的三边长分别是 a、b、c，那么它的面积为  
p(p−a)(p−b)(p−c)
​
 ，其中 p= 
2
1
​
 (a+b+c)。输入这三个数字，计算三角形的面积，四舍五入精确到 1 位小数。

输入格式
第一行输入三个实数 a,b,c，以空格隔开。

输出格式
输出一个实数，表示三角形面积。精确到小数点后 1 位。

输入输出样例
输入 #1复制

3 4 5
输出 #1复制

6.0
说明/提示
数据保证能构成三角形，0≤a,b,c≤1000，每个边长输入时不超过 2 位小数。

*/

#include <stdio.h>
#include <iostream>
#include <cmath>


int main()
{
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    // printf("%f",a);
    // printf("%f",b);
    // printf("%f",c);
    float p = (a+b+c) / 2.0;

    printf("%.1f", sqrt(p*(p-a)*(p-b)*(p-c)));
}