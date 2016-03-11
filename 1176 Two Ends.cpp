//
//  1176 Two Ends.cpp
//  sicily
//
//  Created by 文标 朱 on 16/3/8.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

//本题是以first player为视角，分取两边的情况进行判断
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int num[1001];
int sum;
int f[1001][1001];
int dp(int beg, int end) {
    if(f[beg][end] == 0) {
        if(beg == end - 1)  //剩下两个数的时候真的要贪心了
            return f[beg][end] = max(num[beg], num[end]);
        //分情况讨论
        
        //取左边
        int tmp1 = num[beg];
        if(num[beg + 1] >= num[end])     //注意等号，如果两个边相等，则取左边
            tmp1 += dp(beg + 2, end);
        else
            tmp1 += dp(beg + 1, end - 1);
        
        //取右边
        int tmp2 = num[end];
        if(num[beg] >= num[end - 1])
            tmp2 += dp(beg + 1, end - 1);
        else
            tmp2 += dp(beg, end - 2);
        
        
        f[beg][end] = max(tmp1, tmp2);
        return f[beg][end];
    }
    return f[beg][end];
}
int main() {
    //freopen("1.txt", "r", stdin);
    int count = 1;
    while(scanf("%d", &n) != EOF && n != 0) {
        sum = 0;
        memset(f, 0, sizeof(f));
        for(int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
            sum += num[i];
        }
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", count++, 2 * dp(0, n - 1) - sum);  //得分相减
    }
    return 0;
}
