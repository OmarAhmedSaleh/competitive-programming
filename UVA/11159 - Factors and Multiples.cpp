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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int n,m,a[222],t,vis[222], match[222];
vector<int> e[222];
int aug(int idx){
    if(vis[idx]){
        return 0;
    }
    vis[idx]=1;
    int to;
    for(int i=0;i<(int)e[idx].size();i++){
        to=e[idx][i];
        if(match[to]==-1 || aug(match[to])){
            match[to]=idx;
            return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            e[i].clear();
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            e[i+101].clear();
            scanf("%d",&a[i+101]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[j+101]&&!a[i]){continue;}
                if(a[j+101]==a[i]||(a[j+101]%a[i]==0)){
                    e[i].push_back(j+101);
                    e[101+j].push_back(i);
                }
            }
        }
        memset(match,-1,sizeof(match));
        int ans=0;
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
            ans+=aug(i);
        }
        printf("Case %d: %d\n",tt,ans);
    }
    return 0;//rev Ab steps
}
