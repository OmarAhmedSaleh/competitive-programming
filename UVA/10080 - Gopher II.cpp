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
int n, m, v, match[222], ans;
double x[222], y[222], s;
bool vis[222];
vector<int> e[222];
double dis(int i,int j){
    double ret=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    
    return sqrt(ret);
}
bool ok(int i,int j){
    double d=dis(i,j);
    d/=v;
    if(d>s){
    return 0;
    }
    return 1;
}
int aug(int idx){
    if(vis[idx]){
        return 0;
    }
    vis[idx]=1;
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i];
        if(match[to]==-1||aug(match[to])){
            match[to]=idx;
            return 1;
        }
    }
    return 0;
}
int main(){
    while(scanf("%d %d %lf %d",&n,&m,&s,&v)==4){
        ans=0;
        for(int i=0;i<n;i++){
            e[i].clear();
            scanf("%lf%lf",&x[i],&y[i]);
        }
        for(int i=0;i<m;i++){
            e[i+101].clear();
            scanf("%lf%lf",&x[i+101],&y[i+101]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ok(i,j+101)){
                    e[i].push_back(j+101);
                    e[j+101].push_back(i);
                }
            }
        }
        memset(match,-1,sizeof(match));
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
            ans+=aug(i);
        }
        printf("%d\n",n-ans);
    }
    return 0;//rev Ab steps
}
