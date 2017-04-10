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
const long long oo=1e18;
struct edge{
    int cost, cap, v, inv;
};
vector<edge>e[66];
long long dis[66];
pair<int,int> p[66];
int n,m,s,t;

edge ed;

void addedge(int aa,int bb,int cc){
    ed.cost=cc;
    ed.v=bb;
    ed.cap=1;
    ed.inv=(int)e[bb].size();
    e[aa].push_back(ed);
    ed.cost=-cc;
    ed.v=aa;
    ed.cap=0;
    ed.inv=(int)e[aa].size()-1;
    e[bb].push_back(ed);
}
void bellman(){
    fill (dis,dis+n,oo);
    dis[s]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<e[j].size();k++){
                ed=e[j][k];
                if(ed.cap>0&&dis[ed.v]>dis[j]+ed.cost){
                    dis[ed.v]=dis[j]+ed.cost;
                    p[ed.v]=make_pair(j,k);
                }
            }
        }
    }
}
int tc;
int main(){

    while(scanf("%d%d",&n,&m)==2){
    if(!n&&!m){
        break;
    }
    int a,b,c;
    t=n-1;
    for(int i=0;i<=n;i++){
            e[i].clear();
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        addedge(a,b,c);
   
    }
    int mf=0;
    long long ans=0;
    while(1){
        bellman();
        if(dis[t]==oo){
            break;
        }
        vector< pair<int,int> > path;
        int cur=t;
        while(cur!=s){
            path.push_back(p[cur]);
            cur=p[cur].first;
        }
        reverse(path.begin(),path.end());
        long long ct=0;
        for(int i=0;i<path.size();i++){
            ct+=e[path[i].first][path[i].second].cost;
        }
        mf++;
        ans+=ct;
        if(mf==2){
            break;
        }
        for(int i=0;i<path.size();i++){
            e[path[i].first][path[i].second].cap--;
            int vv=e[path[i].first][path[i].second].v;
            int invv=e[path[i].first][path[i].second].inv;
            e[vv][invv].cap++;
        }
        
    }
    printf("Instance #%d:  ",++tc);
    if(mf!=2){
        printf("Not possible\n");
    }else{
        printf("%lld\n",ans);
    }
    }
    return 0;
}
