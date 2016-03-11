//
//  1007.cpp
//  sicily
//
//  Created by 文标 朱 on 16/3/9.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;


int main(){
    int col;
    int row;
    cin>>col;
    while (col!=0) {
        string str;
        cin>>str;
        row = str.length()/col;
//        cout<<row;
        char s[row][col];
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (i%2==0) {
                    //从右至左
                    s[i][j] = str[i*col+j];
                }
                else{
                    //从左至右
                    s[i][j] = str[(i+1)*col-1-j];
                }
            }
        }
//        for (int i=0; i<row; i++) {
//            for (int j=0; j<col; j++) {
//                cout<<s[i][j];
//            }
//        }
        for (int i=0; i<col; i++) {
            for (int j=0; j<row; j++) {
                cout<<s[j][i];
            }
        }
        cout<<endl;
        cin>>col;
    }
    return 0;
}