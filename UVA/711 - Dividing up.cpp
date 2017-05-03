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
int s[7],h,memo[7][301];
int tt=1;
bool f,b,e;
int bt(int idx,int cur){
    if(cur>h){
        return 0;
    }
    if(cur==h){
        return 1;
    }
    if(idx>6){
        return 0;
    }
    if(memo[idx][cur]!=-1){
        return memo[idx][cur];
    }
    int ans=0;
    for(int i=0;i<=s[idx];i++){
        ans|=bt(idx+1,cur+(i*idx));
    }
    return memo[idx][cur]=ans;
    
  }
int main(){
    while(1){
        e=b=1;
        f=0;
        h=0;
        for(int i=1;i<=6;i++){
            scanf("%d",&s[i]);
            if(s[i]>8){
                if(s[i]&1){
                    s[i]=7;
                }else{
                    s[i]=8;
                }
            }
            h+=s[i]*i;
            if(s[i]){
                b=0;
            }
            if(s[i]&1){
                e=0;
            }
        }
        if(b){
            break;
        }
        printf("Collection #%d:\n",tt++);
        if(e){
            printf("Can be divided.\n\n");
            continue;
        }
        if(h%2==0){
            h/=2;
            memset(memo,-1,sizeof(memo));
            f=bt(1,0);
        }
        if(f){
            puts("Can be divided.");
        }else{
            puts("Can't be divided.");
        }
        cout<<endl;
    }
    
    return 0;
}
