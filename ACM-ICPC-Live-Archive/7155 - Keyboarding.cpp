
/*
Step #1
 1. For each of the four direction buttons, there is an edge to (i, j, k) where (nxt[i][j][dir].first, nxt[i][j][dir].second) is the
 position on the virtual keyboard reached from (i, j) by pressing that direction button.
 
 2. If the character at position (i, j) on the keyboard equals the k’th character in the text, there
 is an edge to (i, j, k + 1).
 The number of keys required is now the minimum distance from (0, 0, 0) to any node of the
 form (i, j, n + 1). This can be computed with Dijkstra (or BFS) – the number of nodes in the graph is |V| =
 r· c · n ≤ 50 · 50 · 10 000 = 25 000 000, and the number of edges is at most 5|V|
 
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
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
int r,c,sz;
pair<int,int> nxt[50][50][4];
string g[51],s;
bool valid(int x,int y){
    return x>-1&&y>-1&&x<r&&y<c;
}
int  d[10002][50][50];

int main(){
    while(scanf("%d%d",&r,&c)==2){
        memset(nxt,-1,sizeof(nxt));
        for(int i=0;i<r;i++){
            cin>>g[i];
        }
        // left , up
        //next step (Edge)
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i){
                    if(g[i][j]==g[i-1][j]){
                        nxt[i][j][2]=nxt[i-1][j][2];
                    }else{
                        nxt[i][j][2]=make_pair(i-1,j);
                    }
                }
                if(j){
                    if(g[i][j]==g[i][j-1]){
                        nxt[i][j][1]=nxt[i][j-1][1];
                    }else{
                        nxt[i][j][1]=make_pair(i,j-1);
                    }
                }
            }
        }
        // Right , Down
        //next step , (Edge)
        for(int i=r-1;i>-1;i--){
            for(int j=c-1;j>-1;j--){
                if(j+1<c){
                    if(g[i][j]==g[i][j+1]){
                        nxt[i][j][3]=nxt[i][j+1][3];
                    }else{
                        nxt[i][j][3]=make_pair(i,j+1);
                    }
                }
                if(i+1<r){
                    if(g[i][j]==g[i+1][j]){
                        nxt[i][j][0]=nxt[i+1][j][0];
                    }else{
                        nxt[i][j][0]=make_pair(i+1,j);
                    }
                }
            }
        }
        
        cin>>s;
        s+='*';
        sz=(int)s.size();
        
        memset(d,-1,sizeof(d));
      // Dijkstra ,shortest path
        priority_queue<pair<pair<int,int>,pair<int,int> > > pq;
        pq.push(make_pair(make_pair(0,0),make_pair(0,0)));
        d[0][0][0]=0;
        // (cost,idx),(x,y)
        bool b=0;
        while(!pq.empty()){
            int c=-pq.top().first.first;
            int idx=pq.top().first.second;
            int xx=pq.top().second.first;
            int yy=pq.top().second.second;
            pq.pop();
            if(d[idx][xx][yy]<c){
                continue;
            }
            if(idx==sz){
                b=1;
                printf("%d\n",c);
                break;
            }
            if(g[xx][yy]==s[idx]){
                if(d[idx+1][xx][yy]==-1||d[idx+1][xx][yy]>c+1){
                    d[idx+1][xx][yy]=c+1;
                    pq.push(make_pair(make_pair(-(c+1),idx+1),make_pair(xx,yy)));
                }
            }
            for(int i=0;i<4;i++){
                int new_x=nxt[xx][yy][i].first;
                int new_y=nxt[xx][yy][i].second;
                if(new_x==-1){
                    continue;
                }
                int dd=(g[new_x][new_y]==s[idx]);
                if(d[idx+dd][new_x][new_y]==-1||d[idx+dd][new_x][new_y]>c+dd+1){
                    d[idx+dd][new_x][new_y]=c+dd+1;
                    pq.push(make_pair(make_pair(-(c+dd+1),idx+dd),make_pair(new_x,new_y)));
                }
            }
        }
    }
    
    
    return 0;
    
}
