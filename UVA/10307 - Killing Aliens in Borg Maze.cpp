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
int n ,m, dis[50][50][50][50],t,p[102];
vector<pair<int,int> > all;
vector<pair<int,pair<int,int> > > ed;
string g[50];
bool valid(int i,int j){
    return i>-1&&j>-1&&i<n&&j<m;
}
int findp(int idx){
    if(p[idx]==idx){
        return idx;
    }
    return p[idx]=findp(p[idx]);
}


int main(){
  //  freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        memset(dis,-1,sizeof(dis));
        all.clear();
        ed.clear();
        cin.ignore();
        for(int i=0;i<n;i++){
            getline(cin,g[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]=='S'||g[i][j]=='A'){
                    all.push_back(make_pair(i,j));
                }
            }
        }
        int sz=(int)all.size();
        for(int i=0;i<=sz;i++){
            p[i]=i;
        }
        
        int x,y;
        for(int i=0;i<sz;i++){
            x=all[i].first;
            y=all[i].second;
            dis[x][y][x][y]=0;
            queue<pair<int,int> > q;
            q.push(make_pair(x,y));
            while(!q.empty()){
                int xx=q.front().first;
                int yy=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int n_x=dx[k]+xx;
                    int n_y=dy[k]+yy;
                    if(valid(n_x,n_y)&&g[n_x][n_y]!='#'&&(dis[x][y][n_x][n_y]>dis[x][y][xx][yy]+1||dis[x][y][n_x][n_y]==-1)){
                        dis[x][y][n_x][n_y]=dis[x][y][xx][yy]+1;
                        q.push(make_pair(n_x,n_y));
                    }
                }
            }
        }
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                ed.push_back(make_pair(dis[all[i].first][all[i].second][all[j].first][all[j].second],make_pair(i,j)));
            }
        }
        sort(ed.begin(),ed.end());
        int ans=0;
        for(int i=0;i<ed.size();i++){
            int xx=ed[i].second.first;
            int yy=ed[i].second.second;
            if(findp(xx)!=findp(yy)){
                ans+=ed[i].first;
                p[findp(xx)]=findp(yy);
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
