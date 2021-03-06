/*
 (1)build Min-spanning Tree
 (2)find Max_Edge between u,v
    - let  lowest common ancestor  of two node u,v is lca
    - find Max_Edge_U = max Edge from lca to U
    - find Max_Edge_V = max Edge from lca to V
    - Max_Edge = max(Max_Edge_U,Max_Edge_V)
 (3) ANS=MST - Max_Edge + Edge(u,v)
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
int n , m , a, b , w, cc[200000],pr[200000][22],dep[200000],cost[200000][22];
long long sp,out[200000];
vector<pair<pair<int,int> ,pair<int,int> > > ed;
vector<pair<int,int> > e[200000];
int merge(int idx){
    return cc[idx]= cc[idx]==idx ? idx : merge(cc[idx]);
}
void dfs(int idx,int p,int depth,int cur){
    int to;
    dep[idx]=depth;
    pr[idx][0]=p;
    cost[idx][0]=cur;
    for(int i=0;i<e[idx].size();i++){
        to=e[idx][i].second;
        if(to!=p&&to!=idx){
            dfs(to,idx,depth+1,e[idx][i].first);
        }
    }
}
int LCA(int x,int y){
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    int df=dep[x]-dep[y];
    int bit=0;
    while(df){
        if(df&1){
            x=pr[x][bit];
        }
        bit++;
        df>>=1;
    }
    if(x==y){
        return x;
    }
    int log=1;
    while(1<<log <=dep[x]){log++;}
    log--;
    for(int i=log;i>-1;i--){
        if(pr[x][i]==-1||pr[y][i]==-1){continue;}
        if(pr[x][i]==pr[y][i]){continue;}
        x=pr[x][i];
        y=pr[y][i];
    }
    return pr[x][0];
}
int cal(int &x,int &y){
    int q=0;
    int bit=0;
    int df=dep[x]-dep[y];
    while(df){
        if(df&1){
            q=max(q,cost[x][bit]);
            x=pr[x][bit];
        }
        bit++;
        df/=2;
    }
    return q;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        cc[i]=i;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&w);
        a--;b--;
        ed.push_back(make_pair(make_pair(w,i),make_pair(a,b)));
    }
    if(m){
        sort(ed.begin(),ed.end());
    }
    for(int i=0;i<m;i++){
        int xx=merge(ed[i].second.first);
        int yy=merge(ed[i].second.second);
        if(xx!=yy){
            cc[xx]=yy;
            sp+=ed[i].first.first;
            e[ed[i].second.first].push_back(make_pair(ed[i].first.first,ed[i].second.second));
            e[ed[i].second.second].push_back(make_pair(ed[i].first.first,ed[i].second.first));
        }
    }
    memset(pr,-1,sizeof(pr));
    memset(cost,-1,sizeof(cost));
    dfs(0,-1,0,-1);
    for(int j=1;j<22;j++){
        for(int i=0;i<n;i++){
            if(pr[i][j-1]==-1){continue;}
            pr[i][j]=pr[pr[i][j-1]][j-1];
            cost[i][j]=max(cost[i][j-1],cost[pr[i][j-1]][j-1]);
        }
    }
    for(int i=0;i<m;i++){
        int lca=LCA(ed[i].second.first,ed[i].second.second);
        int q=cal(ed[i].second.first,lca),r=cal(ed[i].second.second,lca);
        out[ed[i].first.second]=sp-max(r,q)+ed[i].first.first;
    }
    for(int i=0;i<m;i++){
        printf("%lld\n",out[i]);
    }
    return 0;
}
