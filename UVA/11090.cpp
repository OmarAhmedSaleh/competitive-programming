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
// ss
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

const int N=55;
const int M=1000006;
const int oo=500000008;
const double EPS=1e-8;
vector<int> e[N];
int n , m, t, a, b, c,from[M],to[M];
double dis[N],cost[N][N];
vector<pair<int,int> > all;

bool check(double x){
    bool ret=0;
    for(int i=0;i<all.size();i++){
        cost[all[i].first][all[i].second]-=x;
    }
    for(int i=1;i<=n;i++){
        dis[i]=0;
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<e[j].size();k++){
                int v=e[j][k];
                dis[v]=min(dis[v],dis[j]+cost[j][v]);
            }
        }
    }
    for(int j=1;j<=n;j++){
        for(int k=0;k<e[j].size();k++){
            int v=e[j][k];
            if(dis[v]>dis[j]+cost[j][v]){
                ret=1;
            }
        }
    }
    for(int i=0;i<all.size();i++){
        cost[all[i].first][all[i].second]+=x;
    }
    return ret;
}
int main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++){
            e[i].clear();
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cost[i][j]=oo;
            }
        }
        all.clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            from[i]=a;
            to[i]=b;
            all.push_back(make_pair(a,b));
            cost[a][b]=min((double)c,cost[a][b]);
        }
        if(all.size()){
            sort(all.begin(),all.end());
        }
        //unique(all.begin(),all.end());
        for(int i=1;i<all.size();i++){
            if(all[i].first==all[i-1].first&&all[i].second==all[i-1].second){
                all[i-1].first=0;
                all[i-1].second=0;
            }
        }
        for(int i=0;i<all.size();i++){
            if(all[i].first==all[i].second&&all[i].second==0){
                continue;
            }
            e[all[i].first].push_back(all[i].second);
        }
        double lo=0,hi=10000000;
        bool f=0;
        for(int i=0;i<70;i++){
            double mid=(hi+lo)/2;
            if(check(mid)){
                f=1;
                hi=mid;
            }else{
                lo=mid;
            }
        }
        printf("Case #%d: ",tt);
        if(!f){
            puts("No cycle found.");
        }else{
            printf("%.2lf\n",hi);
        }
        
    }
    
    return 0;//rev Ab steps
}
