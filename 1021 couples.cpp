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
    while (N>0) {
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
        vector<int>::iterator is;
        //    for (it=s.begin(); it!=s.end(); it++) {
        //        cout<<*it<<" ";
        //    }
        //    cout<<endl;
        int num;
        it = s.begin();
        while (!s.empty() && it!=s.end()) {
            num = s.size();
            if (it==s.end()-1) {
                if (*s.begin()==*(s.end()-1)) {
                    s.pop_back();
                    s.erase(s.begin());
                    it = s.begin();
                }
                else if (num==s.size())
                    break;
                else
                    it = s.begin();
            }
            
            if (*it==*(it+1)) {
                s.erase(it);
                s.erase(it);
            }
            else
                it++;
            
            if (it==s.end()) {
                if (num==s.size()) {
                    break;
                }
                else
                    it = s.begin();
            }
            
            
        }
        //    for (it=s.begin(); it!=s.end(); it++) {
        //        cout<<*it<<" ";
        //    }
        //    cout<<endl;
        if (s.empty()) {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
        s.clear();
        cin>>N;
    }
    return 0;
}