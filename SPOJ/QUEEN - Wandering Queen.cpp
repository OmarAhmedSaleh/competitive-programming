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
int n,m,t;
char g[1001][1003];
int dis[1003][1003];
int oo=1000000009;
bool vis[1003][1003][8];

vector<pair<int,int> > v;
int ans;
int sr,sc,er,ec;
int main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
     
        ans=-1;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dis[i][j]=oo;
            }
        }
        for(int i=0;i<n;i++){
            cin>>g[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(g[i][j]=='S'){
                    sr=i;sc=j;
                    continue;
                }
                
                if(g[i][j]=='F'){
                er=i;ec=j;
                continue;
                }
                
            }
        }
        memset(vis,0,sizeof(vis));
       queue<pair<int,int >> q;
        q.push(make_pair(sr,sc));
        dis[sr][sc]=0;
        for(int k=0;k<8;k++){
            vis[sr][sc][k]=1;
        }
        int curx;
        int cury;
        int d;
        int xx;
        int yy;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==er&&y==ec){
                ans=dis[er][ec];
                break;
            }
            for(int k=0;k<8;k++){
                 curx=x+dx[k];
                 cury=y+dy[k];
                 d=dis[x][y];
                 xx=dx[k];
                 yy=dy[k];
                    while(1){
                    if(curx>=n||curx<0||cury>=m||cury<0||g[curx][cury]=='X'){

                        break;
                    }
                    if(dis[curx][cury]>dis[x][y]+1){
                        dis[curx][cury]=d+1;
                        q.push(make_pair(curx,cury));
                    }else{
                        if(vis[curx][cury][k]){break;}
                    }
                    vis[curx][cury][k]=1;
                    curx+=xx;
                    cury+=yy;
                }
            }
            
        }
       
        printf("%d\n",ans);
    }
    
    return 0;
}
