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
//const int md=1000000007;
int dx[8]={-1,1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
int n ,m,dis[20][20][20][20];
int memo[16][1<<16];
char g[20][20];
bool valid(int i,int j){
    return i>-1&&j>-1&&i<n&&j<m;
}
vector<pair<int,int> > all;
int solve(int idx,int mask){
    if(mask==(1<<all.size())-1){
        return dis[all[idx].first][all[idx].second][all[0].first][all[0].second];
    }
    
    if(memo[idx][mask]!=-1){
        return memo[idx][mask];
    }
    int ans=1e9;
    for(int i=0;i<all.size();i++){
        if(!(mask&(1<<i))){
            ans=min(ans,solve(i,mask|(1<<i))+dis[all[idx].first][all[idx].second][all[i].first][all[i].second]);
        }
    }
    return memo[idx][mask]=ans;
}
int main(){
    while(scanf("%d%d",&n,&m)==2){
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<n;i++){
            cin>>g[i];
            for(int j=0;j<m;j++){
                for(int ii=0;ii<n;ii++){
                    for(int jj=0;jj<m;jj++){
                        dis[i][j][ii][jj]=1e9;
                    }
                }
            }
        }
        all.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]=='L'){
                    all.push_back(make_pair(i,j));
                }
                dis[i][j][i][j]=0;
                if(g[i][j]=='.'){continue;}
                queue<pair<int,int> > q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int k=0;k<8;k++){
                        int xx=dx[k]+x;
                        int yy=dy[k]+y;
                        if(valid(xx,yy)&&dis[i][j][xx][yy]>dis[i][j][x][y]+1){
                            dis[i][j][xx][yy]=dis[i][j][x][y]+1;
                            q.push(make_pair(xx,yy));
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]=='#'){
                    all.push_back(make_pair(i,j));
                }
            }
        }
        printf("%d\n",solve(0,1));
    }
    return 0;
}
