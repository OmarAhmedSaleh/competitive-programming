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
int n, m, mark[101][101],cc,ans,p[101*101];
char g[101][101];
vector<pair<int,pair<int,int> > > all;
int get(int idx){
    if(p[idx]!=idx){
        return get(p[idx]);
    }
    return idx;
}
bool valid(int xx,int yy){
    return xx>-1&&yy>-1&&xx<n&&yy<m;
}
void dfs(int xx,int yy){
    mark[xx][yy]=cc;
    for(int i=0;i<8;i++){
        int xxx=xx+dx[i];
        int yyy=yy+dy[i];
        if(valid(xxx,yyy)&&mark[xxx][yyy]==0&&g[xxx][yyy]=='#'){
            dfs(xxx,yyy);
        }
    }
}
int tt=1;
void merge(int x,int y,int xx,int yy,int kk){
    if(g[xx][yy]=='#'&&mark[xx][yy]!=mark[x][y]){
        all.push_back(make_pair(kk,make_pair(mark[xx][yy],mark[x][y])));
    }

}
int main(){
    while(scanf("%d%d",&n,&m)==2){
        if(!n&&!m){
            break;
        }
        if(tt>1){
            cout<<endl;
        }
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
        all.clear();
    memset(mark,0,sizeof(mark));
    ans=cc=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='#'&&mark[i][j]==0){
                ++cc;
                dfs(i,j);
            }
        }
    }
    printf("City %d\n",tt++);
    if(cc<2){
        puts("No bridges are needed.");
        continue;
    }
    for(int i=0;i<=cc;i++){
        p[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='#'){
                for(int k=0;k<n;k++){
                    int ww=-1;
                    for(int w=0;w<3;w++){
                        if(valid(i+k,j+ww)){
                            merge(i,j,i+k,j+ww,k);
                        }
                        if(valid(i-k,j+ww)){
                            merge(i,j,i-k,j+ww,k);
                        }
                        ww++;
                    }
                }
                for(int k=0;k<m;k++){
                    int ww=-1;
                    for(int w=0;w<3;w++){
                        if(valid(i+ww,j+k)){
                            merge(i,j,i+ww,j+k,k);
                        }
                        if(valid(i+ww,j-k)){
                            merge(i,j,i+ww,j-k,k);
                        }
                        ww++;
                    }
                }
            }
        }
    }
        if(all.size()){
        sort(all.begin(),all.end());
        }
        int l=0;
        for(int i=0;i<all.size();i++){
            int px=get(all[i].second.first);
            int py=get(all[i].second.second);
            if(px!=py){
                ans++;
                l+=all[i].first-1;
                p[px]=py;
                cc--;
            }
        }
        if(ans>0){
            if(ans>1){
                printf("%d bridges of total length %d\n",ans,l);
            }
            if(ans==1){
                printf("%d bridge of total length %d\n",ans,l);
            }
        }
        if(ans==0){
            puts("No bridges are possible.");
        }
        if(cc>1){
            printf("%d disconnected groups\n",cc);
        }
    }
    return 0;
}
