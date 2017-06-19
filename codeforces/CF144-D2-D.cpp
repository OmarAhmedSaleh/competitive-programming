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
int n, m, u , v, w, s;
vector<pair<int,int> > e[100005];
long long dis[100005];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back(make_pair(w,v));
        e[v].push_back(make_pair(w,u));
    }
    for(int i=1;i<=n;i++){
        dis[i]=1e18;
    }
    priority_queue<pair<long long,int> > pq;
    pq.push(make_pair(0,s));
    dis[s]=0;
    while(!pq.empty()){
        int idx=pq.top().second;
        long long dd=-pq.top().first;
        pq.pop();
        if(dis[idx]<dd){continue;}
        for(int i=0;i<e[idx].size();i++){
            int to=e[idx][i].second;
            if(dis[to]>dd+e[idx][i].first){
                dis[to]=dd+e[idx][i].first;
                pq.push(make_pair(-dis[to],to));
            }
        
        }
    }
    int ans=0;
    int l;
    scanf("%d",&l);
    set<pair<pair<int,int> , int> > st;
    for(int i=1;i<=n;i++){
        if(dis[i]==l){ans++;}
        if(dis[i]>=l){continue;}
        int rq=l-(int)dis[i];
        for(int j=0;j<e[i].size();j++){
            if(e[i][j].first<=rq){continue;}
            int s=e[i][j].first-rq;
            if(dis[e[i][j].second]+s<l){continue;}
            int mm=rq;
            if(e[i][j].second<i){mm=s;}
            st.insert(make_pair(make_pair(min(i,e[i][j].second),max(i,e[i][j].second)),mm));
        }
    }
   
    //cout<<endl;
    printf("%d\n",ans+(int)st.size());
    return 0;
}
