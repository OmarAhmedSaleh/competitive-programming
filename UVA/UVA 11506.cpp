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
int w , m , dc;
struct edge{
    int to,cap,flow,rev;
};
vector<edge> e[111];
void addedge(int i ,int j , int c){
    edge g;
    g.to=j;g.cap=c;g.rev=(int)e[j].size();g.flow=0;
    e[i].push_back(g);
    g.to=i;g.rev=(int)e[i].size()-1;g.cap=0;
    e[j].push_back(g);
}
int dis[111], work[111];
int dfs(int idx,int mn){
    if(idx==m+49){
        return mn;
    }
    for(int &i=work[idx];i<e[idx].size();i++){
        edge g=e[idx][i];
        if(dis[g.to]!=dis[idx]+1){continue;}
        if(g.flow>=g.cap){continue;}
        int df=dfs(g.to,min(mn,g.cap-g.flow));
        if(df){
            e[idx][i].flow+=df;
            e[g.to][g.rev].flow-=df;
            return df;
        }
    }
    return 0;
}
long long ans;
bool mark[111];
void dfs2(int idx){
    mark[idx]=1;
    for(int i=0;i<e[idx].size();i++){
        edge g=e[idx][i];
        if(!mark[g.to]&&g.flow<g.cap){
            dfs2(g.to);
        }
    }
}
int main(){
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&m,&w)==2){
        if(!w&&!m){break;}
        for(int i=0;i<111;i++){
            e[i].clear();
        }
        for(int i=0;i<m-2;i++){
            int id;
            scanf("%d",&id);
            id--;
            scanf("%d",&dc);
            addedge(id,id+50,dc);
        }
        addedge(0,50,1e9);
        addedge(m-1,m+49,1e9);
        
        int u,v,d;
        for(int i=0;i<w;i++){
            scanf("%d%d%d",&u,&v,&d);
            u--;v--;
            if(u>v){swap(u,v);}
            // if(u!=m-1){u+=50;}
            addedge(u+50,v,d);
            addedge(v+50,u,d);
        }
        long long mf=0;
        //int it=0;
        while(1){
            queue<int> q;
            q.push(0);
            memset(dis,-1,sizeof(dis));
            dis[0]=0;
            memset(work,0,sizeof(work));
            while(!q.empty()){
                int f=q.front();
                q.pop();
                if(dis[m+49]!=-1){break;}
                for(int i=0;i<e[f].size();i++){
                    edge g=e[f][i];
                    if(dis[g.to]==-1 && g.flow<g.cap){
                        dis[g.to]=dis[f]+1;
                        q.push(g.to);
                    }
                }
            }
            if(dis[m+49]==-1){
                break;
            }
            while(int f=dfs(0,1e9)){mf+=f;}
        }
        ans=0;
        memset(mark,0,sizeof(mark));
        dfs2(0);
        for(int i=0;i<111;i++){
            if(!mark[i]){continue;}
            for(int j=0;j<e[i].size();j++){
                edge g=e[i][j];
                if(!mark[g.to]){
                    ans+=g.cap;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
