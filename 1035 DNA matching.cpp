//
//  1035 DNA matching.cpp
//  sicily
//
//  Created by 文标 朱 on 16/2/29.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
string getPair(string);
int main(){
    int N;
    cin>>N;
    while (N--) {
        vector<string> s;
        int total = 0;
        int num;
        cin>>num;
        for (int i=0; i<num; i++) {
            string strand;
            cin>>strand;
            s.push_back(strand);
        }
        while (true) {
            if (s.size()==0 || s.size()==1) {
                cout<<total<<endl;
                break;
            }
            else{
                vector<string>::iterator iter;
                int temp = s.size();
                string begin = getPair(*s.begin());
                //cout<<begin<<endl;
                for (iter=s.begin()+1; iter!=s.end(); iter++) {
                    if (begin==*iter) {
                        total++;
                        s.erase(iter);
                        iter--;
                        s.erase(s.begin());
                        break;
                    }
                }
                if (s.size()==temp) {
                    s.erase(s.begin());
                }
            }
        }
    }
}

string getPair(string s){
    string res ="";
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='A') {
            res+='T';
        }
        else if (s[i]=='T'){
            res+='A';
        }
        else if (s[i]=='G'){
            res+='C';
        }
        else if (s[i]=='C'){
            res+='G';
        }
    }
    //cout<<res<<endl;
    return res;
}