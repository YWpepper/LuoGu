/*
输入一个不小于 100 且小于 1000，同时包括小数点后一位的一个浮点数，例如 123.4 ，要求把这个数字翻转过来，变成 4.321 并输出。
*/

#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

int main()
{
    float n;
    char str[5];
    scanf("%f", &n);
    sprintf(str, "%.1f", n);
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    return 0;
}
