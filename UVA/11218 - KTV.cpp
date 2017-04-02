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
int n,c[82][4];
int memo[82][1<<9];
int solve(int idx,int mask){
    if(mask==(1<<9)-1){
        return 0;
    }
    if(idx==n){
        return -1e9;
    }
    if(memo[idx][mask]!=-1){
        return memo[idx][mask];
    }
    int ans=solve(idx+1,mask);
    bool ok=1;
    for(int i=0;i<3;i++){
        if(mask&(1<<c[idx][i])){
            ok=0;
        }
    }
    if(ok){
        int nmask=mask;
        for(int i=0;i<3;i++){
            nmask|=1<<c[idx][i];
        }
        ans=max(ans,solve(idx+1,nmask)+c[idx][3]);
    }
    return memo[idx][mask]=ans;}
int main(){
    int tt=1;
    while(scanf("%d",&n)==1){
        if(!n){
            break;
        }
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&c[i][j]);
                
            }
            for(int j=0;j<3;j++){
                c[i][j]--;
            }
        }
        int ret=solve(0,0);
        if(ret<0){
            ret=-1;
        }
        printf("Case %d: %d\n",tt++,ret);
    
    }
    
    
    return 0;
}
