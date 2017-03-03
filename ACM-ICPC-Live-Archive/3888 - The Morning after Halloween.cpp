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
int dx[9]={0,1,-1,0,0,1,-1,1,-1};
int dy[9]={0,0,0,-1,1,1,-1,-1,1};
const int N=17;
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
struct node{
    int x[3];
    int y[3];
};
char g[N][N];
node s,d;
int n , w, h, dis[N][N][N][N][N][N];
int vis[N][N][N][N][N][N];


bool isok(node pre,node nxt){
    bool ret=1;
    if(n==1){return ret;}
    ret&=((pre.x[0]!=nxt.x[1])||(pre.y[0]!=nxt.y[1])||(pre.x[1]!=nxt.x[0])||(pre.y[1]!=nxt.y[0]));
    ret&=((nxt.x[0]!=nxt.x[1])||(nxt.y[0]!=nxt.y[1]));
    if(n==2){return ret;}
    ret&=((pre.x[0]!=nxt.x[2])||(pre.y[0]!=nxt.y[2])||(pre.x[2]!=nxt.x[0])||(pre.y[2]!=nxt.y[0]));
    ret&=((nxt.x[0]!=nxt.x[2])||(nxt.y[0]!=nxt.y[2]));
    ret&=((pre.x[1]!=nxt.x[2])||(pre.y[1]!=nxt.y[2])||(pre.x[2]!=nxt.x[1])||(pre.y[2]!=nxt.y[1]));
    ret&=(nxt.x[1]!=nxt.x[2])||(nxt.y[1]!=nxt.y[2]);
    return ret;
}
int ans;
int main(){
    while(scanf("%d%d%d",&w,&h,&n)&&n){
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<3;i++){
            s.x[i]=d.x[i]=h;
            s.y[i]=d.y[i]=w;
        }
        int limb=5;
        int limc=5;
        if(n<2){limb=1;}
        ans=-1;
        if(n<3){limc=1;}
        getchar();
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                char c=getchar();
                g[i][j]=c;
                if(g[i][j]>='a'&&g[i][j]<='c'){
                    s.x[g[i][j]-'a']=i;
                    s.y[g[i][j]-'a']=j;
                }
                if(g[i][j]>='A'&&g[i][j]<='C'){
                    d.x[g[i][j]-'A']=i;
                    d.y[g[i][j]-'A']=j;
                }
            }
            getchar();
        }
        queue<node> q;
        q.push(s);
         q.push(d);
        dis[s.x[0]][s.y[0]][s.x[1]][s.y[1]][s.x[2]][s.y[2]]=0;
        dis[d.x[0]][d.y[0]][d.x[1]][d.y[1]][d.x[2]][d.y[2]]=0;
        vis[s.x[0]][s.y[0]][s.x[1]][s.y[1]][s.x[2]][s.y[2]]=2;
    vis[d.x[0]][d.y[0]][d.x[1]][d.y[1]][d.x[2]][d.y[2]]=1;
        while(ans==-1&&!q.empty()){
            node cur=q.front();
            q.pop();
            int st=dis[cur.x[0]][cur.y[0]][cur.x[1]][cur.y[1]][cur.x[2]][cur.y[2]];
            int dir=vis[cur.x[0]][cur.y[0]][cur.x[1]][cur.y[1]][cur.x[2]][cur.y[2]];
            node nw;
            for(int ak=0;ans==-1&&ak<5;ak++){
                int ax=dx[ak]+cur.x[0];
                int ay=dy[ak]+cur.y[0];
                if(ax<0||ay<0||ax>=h||ay>=w||g[ax][ay]=='#'){continue;}
                for(int bk=0;ans==-1&&bk<limb;bk++){
                    int bx=dx[bk]+cur.x[1];
                    int by=dy[bk]+cur.y[1];
                    if(n>1&&(bx<0||by<0||bx>=h||by>=w||g[bx][by]=='#')){continue;}
                    for(int ck=0;ck<limc;ck++){
                        int cx=dx[ck]+cur.x[2];
                        int cy=dy[ck]+cur.y[2];
                        if(n>2&&(cx<0||cy<0||cx>=h||cy>=w||g[cx][cy]=='#')){continue;}
                        nw.x[0]=ax;
                        nw.y[0]=ay;
                        nw.x[1]=bx;
                        nw.y[1]=by;
                        nw.x[2]=cx;
                        nw.y[2]=cy;
                        if(!isok(cur,nw)){
                            continue;
                        }
                        if(vis[nw.x[0]][nw.y[0]][nw.x[1]][nw.y[1]][nw.x[2]][nw.y[2]]==0){
                            q.push(nw);
                            vis[nw.x[0]][nw.y[0]][nw.x[1]][nw.y[1]][nw.x[2]][nw.y[2]]=dir;
                            if(dir==1){
                                dis[nw.x[0]][nw.y[0]][nw.x[1]][nw.y[1]][nw.x[2]][nw.y[2]]=st-1;
                            }
                            if(dir==2){
                                dis[nw.x[0]][nw.y[0]][nw.x[1]][nw.y[1]][nw.x[2]][nw.y[2]]=st+1;
                            }
                        }
                        if(vis[nw.x[0]][nw.y[0]][nw.x[1]][nw.y[1]][nw.x[2]][nw.y[2]]!=dir){
                            ans=abs(dis[nw.x[0]][nw.y[0]][nw.x[1]][nw.y[1]][nw.x[2]][nw.y[2]]) + abs(st)+1;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;//rev Ab steps
}
