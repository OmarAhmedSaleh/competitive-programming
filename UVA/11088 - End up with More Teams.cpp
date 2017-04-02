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
int n,a[15],memo[455][(1<<15)];
struct group{
    int aa,bb,cc;
};
vector<group> all;
int solve(int idx, int mask){
    if(idx==all.size()){
        return 0;
    }
    if(memo[idx][mask]!=-1){
        return memo[idx][mask];
    }
    int ans=solve(idx+1,mask);
    int gg[3]={all[idx].aa,all[idx].bb,all[idx].cc};
    bool ok=1;
    int cnt=0;
    for(int i=0;i<3;i++){
        if(mask&(1<<gg[i])){
            ok=0;
            break;
        }
    }
    if(ok){
        int nw_mask=mask;
        for(int i=0;i<3;i++){
            nw_mask|=1<<gg[i];
            cnt+=a[gg[i]];
        }
        int ex=0;
        if(cnt>=20){ex=1;}
        ans=max(ans,solve(idx+1,nw_mask)+ex);
    }
    
    return memo[idx][mask]=ans;
}
int tt=1;
int main(){
    while(scanf("%d",&n)==1){
        if(!n){
            break;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        all.clear();
        group g;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    g.aa=i;
                    g.bb=j;
                    g.cc=k;
                    if(a[i]+a[j]+a[k]<20){continue;}
                    all.push_back(g);
                }
            }
        }
        memset(memo,-1,sizeof(memo));
        printf("Case %d: %d\n",tt++,solve(0,0));
        
    }
    
    
    return 0;
}
