//
//  1027 MJ, Nowhere to Hide2.cpp
//  sicily
//
//  Created by 文标 朱 on 16/2/27.
//  Copyright © 2016年 文标 朱. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
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
        map<string,string> match;
        
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
                    //main_id.push_back(id1);
                    //majia_id.push_back(id2);)
                    match.insert(pair<string,string>(id1,id2+" is the MaJia of "+id1));
                    id.erase(id.begin()+j);
                    id.erase(id.begin());
                    ip.erase(ip.begin()+j);
                    ip.erase(ip.begin());
                    break;
                }
            }
        }
                                 
                                 
        map<string,string>::iterator iter;
        for(iter=match.begin();iter!=match.end();iter++){
            cout<<iter->second<<endl;
        }
        cout<<endl;
        cin>>N;
    }
    return 0;
}
