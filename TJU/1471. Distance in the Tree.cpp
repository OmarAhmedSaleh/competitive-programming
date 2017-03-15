/*
it is about finding lca(u,v)
find LCA(u,v)
ans = distance from lca to u + distance from lca to v
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

pair<int,int > st[8*50001];
int n , m , u, v, w, d[2*50001], f[50001], l[2*50001];
vector<pair<int,int > > e[50001];
long long dis[50001];
//  distance from root to idx
void go(int idx,long long cur){
    dis[idx]=cur;
    int to;
    for(int i=0;i<e[idx].size();i++){
        to=e[idx][i].first;
        if(dis[to]==-1){
            go(to,cur+e[idx][i].second);
        }
    }
}
int sz;
 // dfs
void dfs(int idx,int p,int depth){
    f[idx]=sz;
    d[sz]=idx;
    l[sz++]=depth;
    int to;
    for(int i=0;i<e[idx].size();i++){
        to=e[idx][i].first;
        if(to!=p&&to!=idx){
            dfs(to,idx,depth+1);
            d[sz]=idx;
            l[sz++]=depth;
        }
    }
}
void build(int idx, int ll ,int rr){
    if(ll==rr){
        // level
        st[idx].first=l[ll];
        // get idx
        st[idx].second=d[ll];
        return ;
    }
    int le=idx<<1;
    int ri=le+1;
    int mid=(ll+rr)>>1;
    build(le,ll,mid);
    build(ri,mid+1,rr);
    st[idx]=st[le];
    if(st[idx].first>st[ri].first){
        st[idx]=st[ri];
    }
}
// Query
pair<int,int > get(int idx,int ll,int rr,int i,int j){
    pair<int,int> ret=make_pair(1e9,-1);
    // out
    if(ll>j||rr<i){
        return ret;
    }
    // in
    if(ll>=i&&rr<=j){
    return st[idx];
    }
    int le=idx<<1;
    int ri=le+1;
    int mid=(ll+rr)>>1;
    pair<int,int> getl=get(le,ll,mid,i,j);
    pair<int,int> getr=get(ri,mid+1,rr,i,j);
    if(getl.first<getr.first){
        ret=getl;
    }else{
        ret=getr;
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back(make_pair(v,w));
        e[v].push_back(make_pair(u,w));

    }
    memset(dis,-1,sizeof(dis));
    // root == 0
    go(0,0);
    dfs(0,-1,0);
    scanf("%d",&m);
    build(1,0,sz-1);
       for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
           //  mn->mx Not mx->mn
           int mn=min(f[u],f[v]);
           int mx=max(f[u],f[v]);
        int lca=get(1,0,sz-1,mn,mx).second;
        printf("%lld\n",dis[u]-dis[lca] + dis[v] - dis[lca]);
    }
    return 0;//rev Ab steps
}
