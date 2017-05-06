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
const double oo=1000000009;
int n , m, s,d;
struct edge{
    int to ;
    double tp,wt;
};
vector<edge> e[101];
double dis[101],mx,mntp[101];
edge ed;
int p[101];
void path(int idx){
    if(idx==s){
        printf("%d",idx);
        return ;
    }
    mx=max(mx,mntp[idx]);
    path(p[idx]);
    printf(" %d",idx);
}
bool valid(double x){
    for(int i=0;i<=n;i++){
        dis[i]=oo;
        mntp[i]=oo;
    }
    priority_queue<pair<double,int> > pq;
    pq.push(make_pair(0,s));
    dis[s]=0;
    while(!pq.empty()){
        int from=pq.top().second;
        double ds=-pq.top().first;
        pq.pop();
        if(dis[from]<ds){
            continue;
        }
        for(int i=0;i<e[from].size();i++){
            ed=e[from][i];
            if(ed.tp>x){
                continue;
            }
            if(dis[ed.to]>dis[from]+ed.wt||(fabs(dis[ed.to]-dis[from]-ed.wt)<1e-1 && ed.tp<mntp[ed.to])){
                dis[ed.to]=dis[from]+ed.wt;
                p[ed.to]=from;
                mntp[ed.to]=ed.tp;
                pq.push(make_pair(-dis[ed.to],ed.to));
            }
        }
    }
    return dis[d]<oo;
}
int main(){
  //  freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<=n;i++){
            e[i].clear();
        }
        int a;
        scanf("%d%d",&s,&d);
        double low=1000,hi=0;
        for(int i=0;i<m;i++){
            scanf("%d%d%lf%lf",&a,&ed.to,&ed.tp,&ed.wt);
            e[a].push_back(ed);
            swap(ed.to,a);
            e[a].push_back(ed);
            hi=max(hi,ed.tp);
            low=min(low,ed.tp);
        }
        double ans=100;
        for(int k=0;k<30;k++){
            double mid=(hi+low)/2;
            if(valid(mid)){
                hi=mid;
                ans=mid;
            }else{
                low=mid;
            }
        }
        mx=0;
        valid(ans);
        path(d);
        printf("\n");
        printf("%.1lf %.1lf\n",dis[d],mx);
        
    }
    return 0;
}
