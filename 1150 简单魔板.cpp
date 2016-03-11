//
//  1150 简单魔板.cpp
//  sicily
//
//  Created by 文标 朱 on 16/3/8.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

struct qt{
    int x,y;//x:first line, y:second line
    char op;// operation
    int pre;
    int step;
};

qt qm[8100];
char sop[300];
int fp,rp,m,n;
bool flag = true;
bool v = true;
int aa,bb;
int N;

//A方法
void OPA(int &fp){
    m = qm[fp].y;
    n = qm[fp].x;
}

//B方法
void OPB(int &fp){
    m = (qm[fp].x%10)*1000 + qm[fp].x/10;
    n = (qm[fp].y%10)*1000 + qm[fp].y/10;
}

//C方法
void OPC(int &fp){
    int i = (qm[fp].x/1000)*1000;
    int j = qm[fp].x-i;
    int a = j/100;
    int b = (j-a*100)/10;
    int i1 = (qm[fp].y/1000)*1000;
    int j1 = qm[fp].y-i1;
    int c = j1/100;
    int d = (j1-c*100)/10;
    m = i+c*100+a*10+(qm[fp].x%10);
    n = i1+d*100+b*10+(qm[fp].y%10);
}

//打印操作数
void PrintOP(int rp){
    cout<<qm[rp].step<<" ";
    int j = 1;
    int i = qm[rp].pre;
    sop[j] = qm[rp].op;
    while (i!=0) {
        j = j+1;
        sop[j] = qm[i].op;
        i = qm[i].pre;
    }
    for (i = j-1; i>0; i--) {
        cout<<sop[i];
    }
    cout<<endl;
}


void comp(int &rp, char op){
    if (m==aa&&n==bb) {
        rp++;
        qm[rp].x = m;
        qm[rp].y = n;
        qm[rp].op = op;
        //    qm[rp].step = ++count;
        qm[rp].pre = fp;
        qm[rp].step = qm[qm[rp].pre].step+1;
        flag=false;
        return;
    }
    for (int i=1; i<=rp; i++) {
        if (qm[i].x==m && qm[i].y == n) {
            return;
        }
    }
    rp = rp+1;
    qm[rp].x = m;
    qm[rp].y = n;
    qm[rp].op = op;
//    qm[rp].step = ++count;
    qm[rp].pre = fp;
    qm[rp].step = qm[qm[rp].pre].step+1;
}


int main(){
    cin>>N;
    while (N!=-1) {
        flag = true;
        v = true;
        int s[8];
        for (int i=0; i<8; i++) {
            cin>>s[i];
        }
        aa = s[0]*1000 + s[1]*100 + s[2]*10 + s[3];
        bb = s[4]*1000 + s[5]*100 + s[6]*10 + s[7];
        if (aa==1234 && bb==8765) {
            v = false;
            flag = false;
        }
        else if(N==0){
            v = false;
            flag = false;
        }
        fp = rp = 1;
        qm[1].x = 1234;
        qm[1].y = 8765;
        qm[1].pre = 0;
        qm[1].step = 0;
        while (flag) {
            
            //A操作
            OPA(fp);
            comp(rp, 'A');
            
            //B操作
            if (flag) {
                OPB(fp);
                comp(rp, 'B');
            }
            
            //C操作
            if (flag) {
                OPC(fp);
                comp(rp, 'C');
            }
            if (qm[rp].step>N) {
                v = false;
                flag = false;
            }
            fp++;
        }
        if (v) {
            PrintOP(rp);
        }
        else{
            cout<<-1<<endl;
        }
        cin>>N;
    }
}