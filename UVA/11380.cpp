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
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
using namespace std;
const int N=33;
const int M=3*N*N;
const int oo=100003;
int dx[4]={-1,1,0,0};
int dy[4]={0, 0, 1,-1};
vector<int> e[M];
int dis[M], ff[M], flow[M][M], res[M][M];
int mark[N][N], out[N][N], t, x, y, p;
char a[N][N];

bool valid(int a,int b){
    return a>0&&b>0&&a<=x&&b<=y;
}
int dfs(int idx, int mn){
    if(idx==t){
        return mn;
    }
    for(int &i=ff[idx];i<e[idx].size();i++){
        int to=e[idx][i];
        if(flow[idx][to]>=res[idx][to]){continue;}
        if(dis[to]==dis[idx]+1){
        int df=dfs(to,min(mn,res[idx][to]-flow[idx][to]));
        
        if(df>0){
            flow[idx][to]+=df;
            flow[to][idx]-=df;
            return df;
        
        }
        }
    }

    return 0;
}
int aug(int idx,int mn){
    if(dis[idx]==0){
        return mn;
    }
    int df=aug(dis[idx],min(mn,res[dis[idx]][idx]));
    if(df>0){
        res[dis[idx]][idx]-=df;
        res[idx][dis[idx]]+=df;
        return df;
    }
    return 0;
}
int main(){
    while(scanf("%d%d%d",&x,&y,&p)==3){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>a[i+1][j+1];
        }
    }
        memset(res,0,sizeof(res));
        memset(flow,0,sizeof(flow));
        int cnt=1;
        for(int i=0;i<3*N*N;i++){
            e[i].clear();
        }
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                mark[i][j]=cnt++;
                out[i][j]=mark[i][j]+(31*31)+1;
                if(a[i][j]=='~'){continue;}
                if(a[i][j]=='*'){
                    e[mark[i][j]].push_back(out[i][j]);
                    e[out[i][j]].push_back(mark[i][j]);
                    e[mark[0][0]].push_back(mark[i][j]);
                    e[mark[i][j]].push_back(mark[0][0]);
                    res[mark[0][0]][mark[i][j]]=1;
                    res[mark[i][j]][out[i][j]]=1;
                    continue;
                }
                if(a[i][j]=='@'){
                    e[mark[i][j]].push_back(out[i][j]);
                    e[out[i][j]].push_back(mark[i][j]);
                    res[mark[i][j]][out[i][j]]=oo;
                    continue;
                }
                if(a[i][j]=='.'){
                    e[mark[i][j]].push_back(out[i][j]);
                    e[out[i][j]].push_back(mark[i][j]);
                    res[mark[i][j]][out[i][j]]=1;
                    continue;
                }
                if(a[i][j]=='#'){
                    e[mark[i][j]].push_back(out[i][j]);
                    e[out[i][j]].push_back(mark[i][j]);
                    e[mark[0][1]].push_back(out[i][j]);
                    e[out[i][j]].push_back(mark[0][1]);
                    res[mark[i][j]][out[i][j]]=oo;
                    res[out[i][j]][mark[0][1]]=p;
                }
                
                
            }
        }
    
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(a[i][j]=='~'){continue;}
                for(int k=0;k<4;k++){
                    int xx=dx[k]+i;
                    int yy=dy[k]+j;
                    if(valid(xx,yy)&&a[xx][yy]!='~'){
                        e[out[i][j]].push_back(mark[xx][yy]);
                        e[mark[xx][yy]].push_back(out[i][j]);
                        int c=oo;
                        if(a[xx][yy]=='.'){c=1;}
                        if(a[xx][yy]=='*'){c=1;}
                        res[out[i][j]][mark[xx][yy]]=c;
                    }
                }
            
            }
        }
        int ans=0;
        
        while(1){
            queue<int> q;
            q.push(mark[0][0]);
            t=mark[0][1];
            memset(ff,0,sizeof(ff));
            memset(dis,-1,sizeof(dis));
            dis[mark[0][0]]=0;
            while(!q.empty()){
                int vv=q.front();
                q.pop();
                for(int i=0;i<e[vv].size();i++){
                    int to=e[vv][i];
                    if(dis[to]==-1&&flow[vv][to]<res[vv][to]){
                        q.push(to);
                        dis[to]=dis[vv]+1;
                    }
                }
            
            }
            //cout<<dis[t]<<endl;
            if(dis[t]==-1){break;}
            while(int ret =dfs(mark[0][0],oo)){ans+=ret;}
        
        
        
        }
        /*
        while(1){
            queue<int> q;
            q.push(mark[0][0]);
            t=mark[0][1];
           // memset(ff,0,sizeof(ff));
            memset(dis,-1,sizeof(dis));
            dis[mark[0][0]]=0;
            while(!q.empty()){
                int vv=q.front();
                q.pop();
                if(vv==t){break;}
                for(int i=0;i<e[vv].size();i++){
                    int to=e[vv][i];
                    if(dis[to]==-1&&res[vv][to]>0){
                        q.push(to);
                        dis[to]=vv;
                    }
                }
                
            }
            //cout<<dis[t]<<endl;
            if(dis[t]==-1){break;}
           int f=aug(t,oo);
            ans+=f;
            if(!f){break;}
            
            
            
        }
        */
        printf("%d\n",ans);
    
    }
    return 0;//rev Ab steps
}
