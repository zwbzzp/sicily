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
using namespace std;

int main(){
    vector<int> s;
    int N;
    cin>>N;
    for (int i=0; i<2*N; i++) {
        s.push_back(0);
    }
    int a, b;
    for (int i=0; i<N; i++) {
        cin>>a>>b;
        s[a-1] = i;
        s[b-1] = i;
    }
    vector<int>::iterator it;
    for (it=s.begin(); it!=s.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    while (!s.empty()) {
        int num = s.size();
        cout<<num<<endl;
        for (it=s.begin(); it!=s.end()-1; it++) {
            if (*it==*(it+1)) {
                s.erase(it);
                s.erase(it);
                it--;
            }
        }
        if (*s.begin()==*s.end()) {
            s.pop_back();
            s.erase(s.begin());
        }
        if (num==s.size()) {
            cout<<s.size();
            break;
        }
    }
    for (it=s.begin(); it!=s.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    if (s.empty()) {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
    return 0;
}