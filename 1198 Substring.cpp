//
//  1198 Substring.cpp
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
void Swap(string*, string*);s
void perm(vector<string>, int, int);
vector<string> temp;
int main(){
    int N;
    cin>>N;
    while (N--) {
        int num;
        vector<string> s;
        cin>>num;
        for (int i=0; i<num; i++) {
            string str;
            cin>>str;
            s.push_back(str);
        }
        perm(s, 0, num);
        sort(temp.begin(), temp.end());
        cout<<temp[0]<<endl;
        temp.clear();
    }
    return 0;
}


//全排列算法，利用递归
void perm(vector<string> s, int start, int end){
    if (start==end) {
        string res="";
        for (int i=0; i<s.size(); i++) {
            res += s[i];
        }
//        cout<<res<<" ";
        temp.push_back(res);
    }
    else{
        for (int i=start; i<end; i++) {
            swap(&s[start], &s[i]);
            perm(s, start+1, end);
            swap(&s[i], &s[start]);
        }
    }
}

void Swap(string* a, string* b){
    string m;
    m = *a;
    *a = *b;
    *b = m;
}