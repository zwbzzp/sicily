//
//  vector test.cpp
//  sicily
//
//  Created by 文标 朱 on 16/2/24.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define pi 3.1415926
#define a 6



int main(){
//    static int b[2]={1,2};
    int *ptr[5];
    int p=5,p2=6,*page,*page2;
    int Test[2][3] = {{1,2,3},{4,5,6}};
    int Test2[3] = {1,2,3};
    int (*A)[3],(*B)[3];
    A = &Test[1];
    B = &Test2;
    page = &p;
    page2 = &p2;
    ptr[0] = &p;
    ptr[1] = page2;
//    cout<<*ptr[0]<<endl;
    cout<<*page<<endl;
    cout<<(*A)[0]<<endl;
//    cout<<*ptr[1]<<endl;
    cout<<(*B)[0]<<endl;
    return 0;
}

//一个指向整数型的指针
int *a;
//一个指向指针的指针
int **a;
//一个有10个指针的数组，该指针是指向一个整形数
int *a[10];
//一个指向有10个整形数数组的指针
int (*a)[10];
//一个指向函数的指针，该函数有一个整形参数并返回一个整形数
int (*a)(int);
//一个有10个指针的数组，该指针指向一个函数，该函数有一个整形参数并返回一个整形数
int (*a[10])(int);










