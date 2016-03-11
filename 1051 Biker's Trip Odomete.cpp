//
//  1051 Biker's Trip Odomete.cpp
//  sicily
//
//  Created by 文标 朱 on 16/2/29.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    float dia;
    int revol;
    float time;
    float pi = 3.1415927;
    cin>>dia>>revol>>time;
    int i=1;
    while (revol!=0) {
        float dis=0, MPH=0;
        dis = dia*pi*revol/(12*5280);
        MPH = dis*(3600/time);
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<"Trip #"<<i++<<": "<<dis<<" "<<MPH<<endl;
        cin>>dia>>revol>>time;
    }
    return 0;
}