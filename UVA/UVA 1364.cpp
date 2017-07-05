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
int n ,m, low[1000],vis[1000], cnt, CC, color[1000], mark[1000] ,ok[1000];
vector<int> e[1000],CYC[1000];
vector<pair<int,int> > st;
bool hate[1000][1000];
void dfs(int idx,int p){
    vis[idx]=low[idx]=++cnt;
    int to;
    for(int i=0;i<e[idx].size();i++){
        to=e[idx][i];
        if(!vis[to]){
            st.push_back(make_pair(idx,to));
            dfs(to,idx);
            low[idx]=min(low[idx],low[to]);
            if(low[to]>=vis[idx]){
                pair<int,int> pp;
                CYC[++CC].clear();
                while(1){
                    pp=st.back();st.pop_back();
                    if(mark[pp.first]!=CC){
                        mark[pp.first]=CC;
                        CYC[CC].push_back(pp.first);
                    }
                    if(mark[pp.second]!=CC){
                        mark[pp.second]=CC;
                        CYC[CC].push_back(pp.second);
                    }
                    if(pp.first==idx&&pp.second==to){
                        break;
                    }
                }
            }
        }
        low[idx]=min(low[idx],vis[to]);
    }
}

bool iSB(int idx){
    int to;
    for(int i=0;i<e[idx].size();i++){
        to=e[idx][i];
        if(!ok[to]){continue;}
        if(color[idx]==color[to]){
            return 0;
        }
        if(color[to]==-1){
            color[to]=1-color[idx];
            if(!iSB(to)){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    while(scanf("%d%d",&n,&m)==2){
        if(!n&&!m){
            break;
        }
        int a,b;
        memset(low,0,sizeof(low));
        memset(vis,0,sizeof(vis));
        memset(mark,0,sizeof(mark));
        memset(hate,0,sizeof(hate));
        cnt=CC=0;
        for(int i=0;i<=n;i++){
            e[i].clear();
            
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            hate[a][b]=hate[b][a]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!hate[i][j]){
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        st.clear();
        int ans=n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt=0;
                dfs(i,-1);
            }
        }
        memset(mark,0,sizeof(mark));
        for(int i=1;i<=CC;i++){
            memset(ok,0,sizeof(ok));
            int idx=-1;
            for(int j=0;j<CYC[i].size();j++){
                ok[CYC[i][j]]=1;
                idx=CYC[i][j];
            }
            if(idx==-1){continue;}
            memset(color,-1,sizeof(color));
            color[idx]=0;
            if(!iSB(idx)){
                for(int j=0;j<CYC[i].size();j++){
                    mark[CYC[i][j]]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(mark[i]){
                ans--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
