//
//  1020 big integer.cpp
//  sicily
//
//  Created by 文标 朱 on 16/2/23.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int b[101];
string x;

int div(int b){
    int res = 0;
    for(int i=0; i<x.size(); i++){
        res = res*10 + x[i]-'0';
        res = res%b;
    }
    return res;
}

int main(){
    int T;
    //cout<<"Enter the number of test case:"<<endl;
    cin>>T;
    for(int i=0; i<T; i++){
        int n;
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>b[j];
        }
        cin>>x;
        cout<<"(";
        cout<<div(b[0]);
        for(int k=1; k<n; k++){
            cout<<","<<div(b[k]);
        }
        cout<<")"<<endl;

    }
    return 0;
}