//
//  1046 Plane Spotting.cpp
//  sicily
//
//  Created by 文标 朱 on 16/2/29.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;


struct Segment
{
    int start, length;
    int total_plane;
};

bool operator < (const Segment &lhs, const Segment &rhs)
{
    if (lhs.total_plane*rhs.length != rhs.total_plane*lhs.length) {
        return lhs.total_plane*rhs.length>rhs.total_plane*lhs.length;
    }
//    if (lhs.total_plane/lhs.length!=rhs.total_plane/rhs.length) {
//        return lhs.total_plane/lhs.length > rhs.total_plane/rhs.length;
//    }
    if (lhs.length!=rhs.length) {
        return lhs.length>rhs.length;
    }
    return lhs.start < rhs.start;
}


vector<Segment> planeSpotting(int n, int p[], int min_quarter)
{
    vector<Segment> vec;
    for (int i=0; i<n; i++) {
        int total_plane = 0;
        for (int j=i; j<n; j++) {
            total_plane += p[j];
            Segment seg;
            seg.start = i;
            seg.length = j-i+1;
            seg.total_plane = total_plane;
            if (seg.length>=min_quarter) {
                vec.push_back(seg);
            }
        }
    }
    sort(vec.begin(),vec.end());
    return vec;
}
int main(){
    int N;
    scanf("%d",&N);
    int count = 1;
    while (N--) {
        int nq, np, mq;
        cin>>nq>>np>>mq;
        int *p = new int[nq];
        int n;
        for (int i=0; i<nq; i++) {
            cin>>n;
            p[i] = n;
        }
        vector<Segment> vec;
        vec = planeSpotting(nq,p,mq);
        cout<<"Result for run "<<count<<":"<<endl;
        for (int i=0; i<np&&i<vec.size(); i++) {
            cout<<vec[i].start+1<<"-"<<vec[i].start+vec[i].length<<endl;
        }
        count++;
    }
    return 0;
}