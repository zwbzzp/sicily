//
//  1151 魔板.cpp
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
#include <memory.h>
using namespace std;

struct qt{
    int x,y;//x:first line, y:second line
    string op;// operation
    int pre;
//    int step;
};

qt qm[8100];
char sop[300];
int fp,rp,m,n;
bool flag = true;
bool v = true;
int aa,bb;
int N;
bool isvisit[50000];
int fact[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320};

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
//void PrintOP(int rp){
//    cout<<qm[rp].step<<" ";
//    int j = 1;
//    int i = qm[rp].pre;
//    sop[j] = qm[rp].op;
//    while (i!=0) {
//        j = j+1;
//        sop[j] = qm[i].op;
//        i = qm[i].pre;
//    }
//    for (i = j-1; i>0; i--) {
//        cout<<sop[i];
//    }
//    cout<<endl;
//}

long cantor(long n){
    int tmp[8];
    int cnt;
    for (int i=7; i>=0; i--) {
        tmp[i] = n%10;
        n = n/10;
    }
    for (int i=0; i<7; i++) {
        cnt = 0;
        for (int j=i+1; j<8; j++) {
            if (tmp[i]>tmp[j]) {
                cnt++;
            }
        }
        n += fact[8-1-i]*cnt;
    }
    return n;
}


void comp(int &rp, char op){
    qt t;
    t.x = m;
    t.y = n;
    t.pre = fp;
    t.op = qm[fp].op+op;
    if (m==aa&&n==bb) {
        rp++;
        qm[rp] = t;
        flag=false;
        return;
    }
//    for (int i=1; i<=rp; i++) {
//        if (qm[i].x==m && qm[i].y == n) {
//            return;
//        }
//    }
    long temp = cantor(m*10000+n);

    if (!isvisit[temp]) {
        isvisit[temp]=true;
        rp = rp+1;
        qm[rp]=t;
    }
    
}

void PrintOP(int rp){
    cout<<qm[rp].op.size()<<" "<<qm[rp].op<<endl;
}


int main(){
    cin>>N;
    while (N!=-1) {
        memset(isvisit, false, sizeof(isvisit));
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
//        qm[1].step = 0;
        qm[1].op="";
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
            //此处改为0>N能通过
            if (qm[rp].op.length()>N) {
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
    return 0;
}