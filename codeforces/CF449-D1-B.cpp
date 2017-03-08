#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <stdio.h>
using namespace std;
const int N= 100005;
const long long INF=1e18;
int n,m,k;
int u,v,c;
int x,y;
int ans;
vector<pair<pair<int,int>,int >  > e[N];
priority_queue<pair<long long,int> > pq;
pair<int,int>  r[N];
long long dis[N];
inline void dij(){
    while(!pq.empty()){
        long long w=-pq.top().first;
        int qq=pq.top().second;
        pq.pop();
        if(dis[qq]<w){continue;}
        for(int i=0;i<e[qq].size();i++){
            int ee=e[qq][i].first.second;
            long long ww=e[qq][i].first.first;
            if(ww+w<dis[ee]){
                dis[ee]=ww+w;
                pq.push(make_pair(-dis[ee],ee));
                
            }
        }
    }
    }
int take[N];
int main(){
    scanf("%d %d %d",&n,&m,&k );
    for(int i=0;i<=n;i++){dis[i]=INF;}
        for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&c);
        e[u].push_back(make_pair(make_pair(c,v),0));
        e[v].push_back(make_pair(make_pair(c,u),0));
    }
    dis[1]=0;
    pq.push(make_pair(0,1));
    for(int i=0;i<k;i++){
        scanf("%d %d",&x,&y);
        e[1].push_back(make_pair(make_pair(y,x),1));
        r[i].first=y;
        r[i].second=x;
    }
    dij();
    for(int i=0;i<k;i++){
        x=r[i].second;
        y=r[i].first;
        int ok=1;
        if(!take[x]&&dis[x]==y){
            ok=0;
            for(int j=0;j<e[x].size();j++){
                long long ww=e[x][j].first.first;
                int ee=e[x][j].first.second;
                int id=e[x][j].second;
                if(id==0&&ww+dis[ee]==dis[x]){ok=1; break;}
                
            }
        }
        if(!ok){
            if(take[x]){ok=1;}else{
                take[x]=1;
            }
        }
        ans+=ok;        
    }
    printf("%d\n",ans);
    return 0;
    
}
