//
//  1036 crypto columns.cpp
//  sicily
//
//  Created by 文标 朱 on 16/3/9.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    string keyword;
    string ctext;
    cin>>keyword;
    while (keyword!="THEEND") {
        cin>>ctext;
        int len = keyword.length();
        if (len<=10) {
            int seq[len];
//            char isvisit[len];
            //获得密文排序顺序
            for (int i=0; i<len; i++) {
                char min='z';
                for (int j=0; j<len; j++) {
                    if (keyword[j]<min&&keyword[j]!='a') {
                        min = keyword[j];
                        seq[i]=j;
                    }
                }
                keyword[seq[i]]='a';
            }
            //        for (int i=0; i<len; i++) {
            //            cout<<seq[i];
            //        }
            //        cout<<endl;
            
            int col = len;
            int row = ctext.length()/col;
            char s[row][col];
            for (int j=0; j<col; j++) {
                for (int i=0; i<row; i++) {
                    s[i][seq[j]] = ctext[i+row*j];
                }
            }
            
            for (int i=0; i<row; i++) {
                for (int j=0; j<col; j++) {
                    cout<<s[i][j];
                }
            }
            cout<<endl;
        }
        
        cin>>keyword;
    }
    return 0;
}
