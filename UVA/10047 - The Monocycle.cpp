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
int dx[8]={-1,1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int n ,m ,dis[33][33][6][6];
struct state {
    int x,y,dir,w;
};
bool valid(int i,int j){
    return i>-1&&j>-1&&i<n&&j<m;
}
char g[33][33];
int tt=1;
int main(){
    while(scanf("%d%d",&n,&m)==2){
        if(!n&&!m){
            break;
        }
        if(tt>1){
            cout<<endl;
        }
        printf("Case #%d\n",tt++);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<5;k++){
                    for(int w=0;w<5;w++){
                        dis[i][j][k][w]=oo;
                    }
                }
            }
        }
        int sr=0,sc=0,er=0,ec=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
                if(g[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                if(g[i][j]=='T'){
                    er=i;
                    ec=j;
                }
            }
        }
        queue<state> q;
        state s;
        s.x=sr;
        s.y=sc;
        s.dir=0;
        s.w=0;
        dis[s.x][s.y][s.dir][s.w]=0;
        q.push(s);
        while(!q.empty()){
            s=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=dx[i]+s.x;
                int yy=dy[i]+s.y;
                if(valid(xx,yy)&&g[xx][yy]!='#'){
                    int ex=1;
                    if((s.dir==0&&i==1)||(s.dir==1&&i==0)){
                        ex+=2;
                    }
                    if((s.dir==2&&i==3)||(s.dir==3&&i==2)){
                        ex+=2;
                    }
                    if((s.dir<2&&i>1)||(s.dir>1&&i<2)){
                        ex++;
                    }
                    int new_w=(s.w+1)%5;
                    state new_s;
                    new_s.x=xx;new_s.y=yy;new_s.dir=i;new_s.w=new_w;
                    if(dis[xx][yy][i][new_w]>dis[s.x][s.y][s.dir][s.w]+ex){
                        dis[xx][yy][i][new_w]=dis[s.x][s.y][s.dir][s.w]+ex;
                        q.push(new_s);
                    }
                }
            }
        }
        int mn=oo;
        for(int i=0;i<5;i++){
        mn=min(dis[er][ec][i][0],mn);
        }
        if(mn==oo){
            puts("destination not reachable");
        }else{
            printf("minimum time = %d sec\n",mn);
        }
        
    }
    
    
    
    return 0;
}
