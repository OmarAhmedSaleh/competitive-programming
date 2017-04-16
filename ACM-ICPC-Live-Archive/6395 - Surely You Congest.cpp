
/*
 First, we need to figure out which streets can possibly be used (and in which direction), i.e.,
 those which are part of some shortest path to the downtown node. This is standard and can be
 done by running Dijkstra’s algorithm from the downtown node. Writing d(u) for the distance
 from the downtown for intersection u, an edge (u, v, t) can be used from u to t if and only if
 d(u) = d(v) + t.
 Checking this for all edges gives a directed acyclic graph consisting of all edges that can be
 used by the commuters. Next, we observe that two commuters that are at two nodes that have
 a different distance to downtown can never interfere with each other. This means that we can
 group the commuter based on their distance to downtown, and process each group separately.
 Processing such a group of commuters is again a fairly standard task, namely finding edgedisjoint
 paths. Add a dummy node s and connect it to all the starting nodes of the commuters
 in the group (with multiplicities, so you allow parallel edges). Then, the maximum number
 of commuters that can go simultaneously within this group equals the maximum number of
 edge-disjoint paths from s to downtown, which equals the max-flow from s to downtown if
 you put unit capacities on all the (directed) edges.
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
const int oo=1e9;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
struct edge{
    int to, inv, cap;
};
edge g;
int n, m, c, a, b, v, ci, p[25004], cnt[25004], st, f, dis[25004], xx[500001], yy[500001], tt[500001], ans;
vector<pair<int,int> > e[25004];
vector<vector<edge> >cpy;
void addedge(int i,int j,int cp){
    g.to=j;g.inv=(int)cpy[j].size();g.cap=cp;
    cpy[i].push_back(g);
    g.to=i;g.inv=(int)cpy[i].size()-1;g.cap=0;
    cpy[j].push_back(g);
    
}
edge ep[25004];
void aug(int idx){
    if(idx==st){
        return ;
    }
    f=min(f,ep[idx].cap);
    aug(p[idx]);
    edge gg=ep[idx];
    cpy[idx][gg.inv].cap+=f;
    cpy[cpy[idx][gg.inv].to][cpy[idx][gg.inv].inv].cap-=f;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        scanf("%d%d",&m,&c);
        for(int i=0;i<=n;i++){
            e[i].clear();
            dis[i]=oo;
        }
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&xx[i],&yy[i],&tt[i]);
            e[xx[i]].push_back(make_pair(yy[i],tt[i]));
            e[yy[i]].push_back(make_pair(xx[i],tt[i]));
        }
        priority_queue<pair<int,int> > pq;
        pq.push(make_pair(0,1));
        dis[1]=0;
        while(!pq.empty()){
            int from=pq.top().second;
            int w=-pq.top().first;
            pq.pop();
            if(dis[from]<w){continue;}
            for(int i=0;i<e[from].size();i++){
                int to=e[from][i].first;
                int ww=e[from][i].second;
                if(1LL*(dis[from]+ww)<dis[to]){
                    dis[to]=1LL*(dis[from]+ww);
                    pq.push(make_pair(-dis[to],to));
                }
            }
        }
        ans=0;
        vector<pair<int,int> > cv;
        for(int i=0;i<c;i++){
            scanf("%d",&ci);
            cnt[ci]++;
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]){
                cv.push_back(make_pair(dis[i],i));
            }
        }
        if(c){
            sort(cv.begin(),cv.end());
        }
         st=n+3;
        for(int i=0;i<cv.size();i++){
            if(cv[i].first==0){
                ans+=cnt[cv[i].second];
                continue;
            }
            int ww=cv[i].first;
            cpy.clear();
            cpy.resize(n+4);
            while(i<cv.size()&&cv[i].first==ww){
                addedge(st,cv[i].second,cnt[cv[i].second]);
                i++;
            }
            i--;
            for(int j=0;j<m;j++){
                if(dis[xx[j]]+tt[j]==dis[yy[j]]){
                    addedge(yy[j],xx[j],1);
                }
                if(dis[yy[j]]+tt[j]==dis[xx[j]]){
                    addedge(xx[j],yy[j],1);
                }
            }

            while(1){
                queue<int> q;
                memset(p,-1,sizeof(p));
                q.push(st);
                p[st]=0;
                while(!q.empty()){
                    int from=q.front();
                    q.pop();
                    if(from==1){
                        break;
                    }
                    for(int j=0;j<cpy[from].size();j++){
                        g=cpy[from][j];
                        if(p[g.to]==-1&&cpy[from][j].cap>0){
                            q.push(g.to);
                            ep[g.to]=cpy[from][j];
                            p[g.to]=from;
                        }
                    }
                }
                if(p[1]==-1){
                    break;
                }
                f=1e9;
                aug(1);
                if(!f){
                    break;
                }
                ans+=f;
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
    
}
