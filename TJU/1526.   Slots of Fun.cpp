
/*
find shortest path 
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
char c;
int x,y,n,dis[26][26][26][26];
vector<pair<int,int> > sf[13],let[26];
bool valid(int xx,int yy){
    return xx>-1&&yy>-1&&xx<26&&yy<26;
}
int d(pair<int,int> a,pair<int,int> b){
    return dis[a.first][a.second][b.first][b.second];
}

int main(){
    sf[1].push_back(make_pair(13,13));
    for(int i=2;i<=12;i++){
        sf[i].push_back(make_pair(sf[i-1][0].first+1,sf[i-1][0].second-1));
        for(int j=0;j<sf[i-1].size();j++){
            sf[i].push_back(make_pair(sf[i-1][0].first+1,sf[i-1][j].second+1));
        }
    }
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<13;i++){
        for(int j=0;j<sf[i].size();j++){
            x=sf[i][j].first,y=sf[i][j].second;
            queue<pair<int,int> > q;
            q.push(make_pair(x,y));
            dis[x][y][x][y]=0;
            while(!q.empty()){
               int xxx=q.front().first;
               int yyy=q.front().second;
                q.pop();
                int r=xxx-12;
                int cur=dis[x][y][xxx][yyy];
                if(r>0&&r<13){
                    int pos=lower_bound(sf[r].begin(),sf[r].end(),make_pair(xxx,yyy))-sf[r].begin();
                    if(pos){
                        if(dis[x][y][sf[r][pos-1].first][sf[r][pos-1].second]>cur+1||dis[x][y][sf[r][pos-1].first][sf[r][pos-1].second]==-1){
                            q.push(make_pair(sf[r][pos-1].first,sf[r][pos-1].second));
                            dis[x][y][sf[r][pos-1].first][sf[r][pos-1].second]=cur+1;
                        }

                    }
                    if(pos+1<sf[r].size()){
                        if(dis[x][y][sf[r][pos+1].first][sf[r][pos+1].second]>cur+1||dis[x][y][sf[r][pos+1].first][sf[r][pos+1].second]==-1){
                            q.push(make_pair(sf[r][pos+1].first,sf[r][pos+1].second));
                            dis[x][y][sf[r][pos+1].first][sf[r][pos+1].second]=cur+1;
                        }
                    }
                }
                for(int k=0;k<8;k++){
                   int nw_x=dx[k]+xxx;
                    int nw_y=dy[k]+yyy;
                    if(valid(nw_x,nw_y)&&(dis[x][y][nw_x][nw_y]>cur+1||dis[x][y][nw_x][nw_y]==-1)){
                        q.push(make_pair(nw_x,nw_y));
                        dis[x][y][nw_x][nw_y]=cur+1;
                    }
                }
            }
        }
    }
    while(scanf("%d",&n)==1){
        if(!n){break;}
        for(int i=0;i<26;i++){
            let[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                cin>>c;
                let[c-'a'].push_back(sf[i][j]);
            }
        }
        bool ok=0;
        for(int i=0;i<26;i++){
            if(let[i].size()<3){continue;}
            pair<int,int> p1=let[i][0];
            pair<int,int> p2=let[i][1];
            pair<int,int> p3=let[i][2];
            if(d(p1,p2)==d(p1,p3)&&d(p1,p2)==d(p2,p3)){
                cout<<char(i+'a');
                ok=1;
            }
        }
        if(!ok){
            cout<<"LOOOOOOOOSER!";
        }
        cout<<endl;
        }
  
    return 0;
}
