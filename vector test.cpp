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
using namespace std;

int main(){
    vector<int> s;
    for (int i=0; i<10; i++) {
        s.push_back(i);
    }
    cout<<*(s.end()-1)<<endl;
//    vector<int>::iterator it;
//    it = s.begin()+4;
//    s.erase(it);
//    s.erase(it);
//    cout<<*it<<endl;
//    for (it=s.begin(); it!=s.end(); it++) {
//        cout<<*it<<" ";
//    }
//    cout<<*(s.end()-1)<<endl;
    return 0;
}