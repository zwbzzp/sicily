//
//  1198 Substring2.cpp
//  sicily
//
//  Created by 文标 朱 on 16/3/1.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
bool vis[10];
vector<string> s;
string minstr;
int num;

void perm(int deep, string a){
    if (deep==num) {
        if (a<minstr) {
            minstr = a;
        }
    }
    else{
        for (int i=0; i<num; i++) {
            if (!vis[i]) {
                vis[i]=true;
                perm(deep+1, a+s[i]);
                vis[i]=false;
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    while (N--) {
        string str;
        cin>>num;
        minstr="";
        for (int i=0; i<num; i++) {
            cin>>str;
            minstr+=str;
            s.push_back(str);
        }
        perm(0, "");
        s.clear();
        cout<<minstr<<endl;
    }
    return 0;
}