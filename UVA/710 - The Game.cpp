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
string s;
int w,h,sr,sc,er,ec,dis[79][79][6],g[77][77];
bool valid(int i,int j){
    return i>-1&&j>-1&&i<h&&j<w;
}
int tt=1;
int main(){
    while(scanf("%d%d",&w,&h)==2){
        if(!w&&!h){
            break;
        }
        memset(g,0,sizeof(g));
        cin.ignore();
        for(int i=1;i<=h;i++){
            getline(cin,s);
            for(int j=0;j<s.size();j++){
                if(s[j]=='X'){
                    g[i][j+1]=1;
                }
            }
        }
        h+=2;
        w+=2;
        int pp=1;
        printf("Board #%d:\n",tt++);
        while(scanf("%d%d%d%d",&sc,&sr,&ec,&er)==4){
            if(!sr&&!sc){
                break;
            }
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    for(int k=0;k<6;k++){
                        dis[i][j][k]=1e9;
                    }
                }
            }
            for(int k=0;k<6;k++){
            dis[sr][sc][k]=0;
            }
            queue<pair<pair<int,int>,int> > q;
            q.push(make_pair(make_pair(sr,sc),5));
            while(!q.empty()){
                int x=q.front().first.first;
                int y=q.front().first.second;
                int dir=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int xx=x+dx[k];
                    int yy=y+dy[k];
                    if(valid(xx,yy)){
                        if(g[xx][yy]&&(xx!=er||yy!=ec)){continue;}
                        int ex=0;
                        if(dir==5||(dir<2&&k>1)){
                            ex=1;
                        }
                        if(dir==5||(dir>1&&k<2)){
                            ex=1;
                        }
                        if(dis[xx][yy][k]>dis[x][y][dir]+ex){
                            dis[xx][yy][k]=dis[x][y][dir]+ex;
                            q.push(make_pair(make_pair(xx,yy),k));
                        }
                    }
                }
            }
            int mn=1e9;
            for(int k=0;k<4;k++){
                mn=min(dis[er][ec][k],mn);
            }
            printf("Pair %d: ",pp++);
            if(mn<1e9){
                printf("%d segments.\n",mn);
            }else{
                puts("impossible.");
            }
        }
        cout<<endl;
    }
    return 0;
}
