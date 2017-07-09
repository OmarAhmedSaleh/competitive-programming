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
int n,r,c,x,y,dis[1001][1001],t;
bool mark[1001][1001];
bool bad[1001][1001];
bool valid(int i ,int j){
    return i>-1&&j>-1&&i<r&&j<c;
}
void fun(int d){
    queue<pair<int,int> > q;
    memset(dis,-1,sizeof(dis));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(bad[i][j]){
                q.push(make_pair(i,j));
                dis[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int xx=q.front().first;
        int yy=q.front().second;
        mark[xx][yy]=1;
        q.pop();
        for(int k=0;k<4;k++){
            int xxx=dx[k]+xx;
            int yyy=dy[k]+yy;
            if(valid(xxx,yyy)&&dis[xxx][yyy]==-1&&dis[xx][yy]+1<=d){
                dis[xxx][yyy]=dis[xx][yy]+1;
                //cout<<xxx<<" "<<yyy<<" "<<dis[xxx][yyy]<<endl;
                q.push(make_pair(xxx,yyy));
            }
        }
    }
    
}
int ans[2],sx,sy,ex,ey;
bool valid(int d){
    memset(mark,0,sizeof(mark));
    if(d>-1){
        fun(d);
    }
    if(mark[sx][sy]||mark[ex][ey]){
        return 0;
    }
    memset(dis,-1,sizeof(dis));
    queue<pair<int,int> > q;
    q.push(make_pair(sx,sy));
    dis[sx][sy]=0;
    while(!q.empty()){
        int xx=q.front().first;
        int yy=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int xxx=dx[k]+xx;
            int yyy=dy[k]+yy;
            if(valid(xxx,yyy)&&!mark[xxx][yyy]&&dis[xxx][yyy]==-1){
                dis[xxx][yyy]=dis[xx][yy]+1;
                q.push(make_pair(xxx,yyy));
            }
        }
    }
    if(mark[ex][ey]==0&&dis[ex][ey]!=-1){
        ans[0]=d+1;
        ans[1]=dis[ex][ey];
    }
    return dis[ex][ey]!=-1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&r,&c);
        memset(bad,0,sizeof(bad));
        memset(dis,-1,sizeof(dis));
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            bad[x][y]=1;
        }
        valid(-1);
        int l=0,h=1e9;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(l+1>=h){
                while(l<=h){
                    valid(l);
                    l++;
                }
                break;
            }
            if(valid(mid)){
                l=mid;
            }else{
                h=mid-1;
            }
        }
        if(!n){
            ans[0]=0;
        }
        printf("%d %d\n",ans[0],ans[1]);
    }
    
    return 0;
}
