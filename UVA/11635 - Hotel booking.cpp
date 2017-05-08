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
int n , m, c, a,b,t,h[101],hh;
int dis[101][10001],day[10001];
vector<pair<int,int> > e[10001];
bool valid(int x){
    priority_queue<pair<int,int> >pq;
    memset(day,-1,sizeof(day));
    pq.push(make_pair(0,1));
    day[1]=0;
    while(pq.size()){
        int idx=pq.top().second;
        int dd=-pq.top().first;
        pq.pop();
        if(day[idx]<dd){continue;}
        for(int i=0;i<hh;i++){
            if((day[h[i]]==-1||day[h[i]]>day[idx]+1)&&dis[i][idx]>-1&&dis[i][idx]<=600){
                day[h[i]]=day[idx]+1;
                pq.push(make_pair(-day[h[i]],h[i]));
            }
        }
        if((day[n]==-1||day[n]>day[idx])&&dis[hh][idx]>-1&&dis[hh][idx]<=600){
            day[n]=day[idx];
            pq.push(make_pair(-day[n],n));
        }
    }

    return day[n]!=-1;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        if(!n){continue;}
        scanf("%d",&hh);
        for(int i=0;i<=n;i++){
            e[i].clear();
        }
        memset(dis,-1,sizeof(dis));
        for(int i=0;i<hh;i++){
            scanf("%d",&h[i]);
        }
        h[hh]=n;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&t);
            e[a].push_back(make_pair(b,t));
            e[b].push_back(make_pair(a,t));
        }
        for(int i=0;i<=hh;i++){
            dis[i][h[i]]=0;
            priority_queue<pair<int,int> > pq;
            pq.push(make_pair(0,h[i]));
            while(pq.size()){
                int idx=pq.top().second;
                int dd=-pq.top().first;
                pq.pop();
                if(dis[i][idx]<dd){continue;}
                for(int k=0;k<e[idx].size();k++){
                    int to=e[idx][k].first;
                    if(dis[i][to]==-1||dis[i][to]>dis[i][idx]+e[idx][k].second){
                        if(dis[i][idx]+e[idx][k].second>600){continue;}
                        dis[i][to]=dis[i][idx]+e[idx][k].second;
                        pq.push(make_pair(-dis[i][to],to));
                    }
                }
            }
        }
        if(!valid(0)){
            printf("-1\n");
        }else{
            printf("%d\n",day[n]);
        }
    }
   
    return 0;
}
