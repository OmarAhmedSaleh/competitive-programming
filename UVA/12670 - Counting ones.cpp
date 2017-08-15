/*
 
 
 */

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
//const long long OO=4e18;
//const int MAX=100000<<2;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
long long a,b,memo[66][66][66][2];
vector<int> all[2];
long long solve(int i , int j , int lv,int kk){
    if(kk<0){return 0;}
    if(!kk&&j==(int)all[1].size()){return 1;}
    if(i==all[0].size()){
        return 0;
    }
    if(memo[i][j][kk][lv]!=-1){return memo[i][j][kk][lv];}
    long long cnt=0;
    // take
    int new_j=j;
    if(all[0][i]>0||lv){
        if(j<(int)all[1].size()&&all[1][j]==abs(all[0][i])){
            new_j++;
        }
        if(j<(int)all[1].size()&&all[1][j]<abs(all[0][i])){
            new_j=(int)all[1].size();
        }
        cnt+=solve(i+1,new_j,lv,kk-1);
    }
    new_j=j;
    // ignore
    if(j==all[1].size() || abs(all[0][i])>all[1][j]){
        cnt+=solve(i+1,new_j,lv|(all[0][i]>0),kk);
    }
    return memo[i][j][kk][lv]=cnt;
}
int main(){
    while(scanf("%lld%lld",&a,&b)!=EOF){
        all[0].clear();all[1].clear();
        if(a>b){swap(a,b);}
        memset(memo,-1,sizeof(memo));
        for(int i=log2(b);i>-1;i--){
            if(a&((long long)1<<i)){
                all[1].push_back(i+1);
            }
            if(b&((long long)1<<i)){
                // One
                all[0].push_back(i+1);
            }else{
                if(all[0].size()){
                    // zero
                    all[0].push_back(-i-1);
                }
            }
        }
        long long ans=0;
        for(int i=log2(b)+1;i>0;i--){
            long long ret=solve(0,0,0,i);
            ans+=1LL*ret*i;
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}
