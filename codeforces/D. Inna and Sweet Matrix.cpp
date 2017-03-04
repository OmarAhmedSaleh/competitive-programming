#include <math.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <stdio.h>
using namespace std;
const int N=55;
int n,m;
queue<int> q;
queue<pair<int,int> > pos;
int dirx[2]={1,0};
int diry[2]={0,1};
bool valid(int a,int b){
    return a>-1&&a<n&&b>-1&&b<m;
}
int kk;
int g[N][N];
vector<pair<int,int> > path[N*N];
vector<pair<int,int> > v;
bool vis[N][N];
int t;
void dfs(int aa,int bb){
    path[g[aa][bb]]=v;
    t+=v.size();
    vis[aa][bb]=1;
    for(int k=0;k<2;k++){
        int xx=aa+dirx[k];
        int yy=bb+diry[k];
        if(valid(xx,yy)&&g[xx][yy]&&!vis[xx][yy]){
            v.push_back(make_pair(xx,yy));
            dfs(xx,yy);
            v.pop_back();
        }
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&kk);
    for(int i=2;i<=kk;i++){
        q.push(i);
    }
    g[0][0]=1;
    pos.push(make_pair(0,0));
    while(!pos.empty()&&!q.empty()){
        int xx=pos.front().first;
        int yy=pos.front().second;
        pos.pop();
        int p=q.front();
        for(int k=0;k<2;k++){
            int aa=xx+dirx[k];
            int bb=yy+diry[k];
            if(valid(aa,bb)&&!g[aa][bb]){
                g[aa][bb]=p;
                q.pop();
                pos.push(make_pair(aa,bb));
                if(q.empty()){break;}
                p=q.front();
            }
        }
    }
    v.push_back(make_pair(0,0));
    dfs(0,0);
    printf("%d\n",t);
    for(int i=kk;i>0;i--){
        for(int j=0;j<path[i].size();j++){
            if(j){printf(" ");}
            printf("(%d,%d)",path[i][j].first+1,path[i][j].second+1);
        }
        printf("\n");
    }
    
    
    return 0;
}
