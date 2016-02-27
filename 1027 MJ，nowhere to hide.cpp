//
//  1027 MJ，nowhere to hide.cpp
//  sicily
//
//  Created by 文标 朱 on 16/2/26.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    while (N>0) {
        string a,b;
        vector<string> id;
        vector<string> ip;
        vector<string> main_id;
        vector<string> majia_id;
        for (int i=0; i<N; i++) {
            cin>>a>>b;
            id.push_back(a);
            ip.push_back(b);
        }
        //先根据ip匹配id，分别存入main_id和majia_id
        vector<string>::iterator temp;
        for (int i=0; i<N/2; i++) {
            temp = ip.begin();
            for (int j=1; j<ip.size(); j++) {
                if (ip[j]==*temp) {
                    string id1 = *id.begin();
                    string id2 = *(id.begin()+j);
                    main_id.push_back(id1);
                    majia_id.push_back(id2);
                    
                    id.erase(id.begin()+j);
                    id.erase(id.begin());
                    ip.erase(ip.begin()+j);
                    ip.erase(ip.begin());
                    break;
                }
            }
        }
        //从main_id中寻找最小值，对应找到majia_id中的对应值
        for (int i=0; i<N/2; i++) {
            string min = *main_id.begin();
            int num=0;
            for (int j=1; j<main_id.size(); j++) {
                if (main_id[j]<min) {
                    min = main_id[j];
                    num = j;
                }
            }
            cout<<majia_id[num]<<" is the MaJia of "<<main_id[num]<<endl;
            main_id.erase(main_id.begin()+num);
            majia_id.erase(majia_id.begin()+num);
        }
        cout<<endl;
        cin>>N;
    }
    return 0;
}