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
int n,m,t,vis[44][44];
pair<int,int >  match[44][44];
int mark[44][44];
string a[100];
bool valid(int i ,int j){
    return i>-1&&j>-1&&i<n&&j<m;
}
vector<pair<int,int > > e[44][44];
int aug(int i,int j){
    if(vis[i][j]){
        return 0;
    }
    vis[i][j]=1;
    for(int k=0;k<e[i][j].size();k++){
        pair<int,int> to=e[i][j][k];
        if(match[to.first][to.second].first==-1||aug(match[to.first][to.second].first,match[to.first][to.second].second)){
            match[to.first][to.second]=make_pair(i,j);
            return 1;
        }
    }
    return 0;
}
void dfs(int i,int j,int col){
    vis[i][j]=1;
    mark[i][j]=col;
    for(int k=0;k<4;k++){
        int xx=dx[k]+i;
        int yy=dy[k]+j;
        if(valid(xx,yy)&&a[xx][yy]=='*'&&mark[xx][yy]==-1){
            dfs(xx,yy,mark[i][j]^1);
        }
    }
    
}
int main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d%d",&n,&m);
        memset(mark,-1,sizeof(mark));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int xx,yy;
        int ans=0;
        int all=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                e[i][j].clear();
                if(a[i][j]=='*'){
                    if(mark[i][j]==-1){
                        mark[i][j]=0;
                        dfs(i,j,0);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='*'){
                    all++;
                    for(int k=0;k<4;k++){
                        xx=dx[k]+i;
                        yy=dy[k]+j;
                        if(valid(xx,yy)&&a[xx][yy]=='*'){
                            e[i][j].push_back(make_pair(xx,yy));
                            
                        }
                    }
                }
            }
        }
        
        
        memset(match,-1,sizeof(match));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mark[i][j]||a[i][j]!='*'){continue;}
                memset(vis,0,sizeof(vis));
                ans+=aug(i,j);
            }
        }
        
        
        cout<<all-ans<<endl;
        
    }
    
    return 0;//rev Ab steps
}
