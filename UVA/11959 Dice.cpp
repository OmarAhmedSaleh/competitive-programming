#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#include <complex>

using namespace std;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int t,f;
string s1,s2,s4;
map<string,int> mp;
void bk(string s3){
    if(s3==s2){
        f=1;
        return ;
    }
    if(mp.count(s3)){
        return ;
    }
    mp[s3]=1;
    if(f){return ;}
    s4=s3;
    string temp;
    string cur=s3;
    for(int i=0;i<4;i++){
    temp=cur;
    s4=cur;
    temp[0]=s4[2];
    temp[2]=s4[1];
    temp[1]=s4[4];
    temp[4]=s4[0];
    cur=temp;
    if(temp==s2){
        f=1;
        return ;
    }
    bk(temp);
    if(f){return ;}

    }
    cur=s3;
    for(int i=0;i<4;i++){
    temp=cur;
    s4=cur;
    temp[2]=s4[3];
    temp[3]=s4[4];
    temp[4]=s4[5];
    temp[5]=s4[2];
    cur=temp;
        if(temp==s2){
            f=1;
            return ;
        }
    bk(temp);
    if(f){return ;}
    }
    cur=s3;
    for(int i=0;i<4;i++){
    temp=cur;
    s4=cur;
    temp[0]=s4[3];
    temp[3]=s4[1];
    temp[1]=s4[5];
    temp[5]=s4[0];
    if(temp==s2){
        f=1;
        return ;
    }
    cur=temp;
    bk(temp);
    if(f){return ;}
    }
}
int main(){
    scanf("%d",&t);
    while(t-->0){
        mp.clear();
        cin>>s1>>s2;
        f=0;
        bk(s1);
        if(f){
            cout<<"Equal"<<endl;
        }else{
            cout<<"Not Equal"<<endl;
        }
    }
   
    return 0;
}
