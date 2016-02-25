//
//  1021 couples.cpp
//  sicily
//
//  Created by 文标 朱 on 16/2/23.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int couples[200002];
    int N;
    cin>>N;
    while (N>0) {
        int a, b;
        stack<int> s;
        for (int i=0; i<N; i++) {
            cin>>a>>b;
            couples[a-1] = i;
            couples[b-1] = i;
        }
        for (int i=0; i<2*N; i++) {
            if (s.empty()) {
                s.push(couples[i]);
            }
            else{
                if (s.top()==couples[i]) {
                    s.pop();
                }
                else
                    s.push(couples[i]);
            }
        }
        if (s.empty()) {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
        cin>>N;
    }
    return 0;
}