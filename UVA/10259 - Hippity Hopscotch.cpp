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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int n , kk;
vector<pair<int,int > > e[101][101],ts;
int t, g[101][101], was[101][101];
long long best[101][101];
void dfs(int aa,int bb){
    was[aa][bb]=1;
    for(int i=0;i<e[aa][bb].size();i++){
        pair<int,int > to=e[aa][bb][i];
        if(!was[to.first][to.second]){
            dfs(to.first,to.second);
        }
    }
    ts.push_back(make_pair(aa,bb));
}
int main(){
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&n,&kk);
        memset(best,0,sizeof(best));
        memset(was,0,sizeof(was));
        ts.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&g[i][j]);
                e[i][j].clear();
                }
            }
    int a,b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a=g[i][j];
            for(int k=0;k<n;k++){
                if(!k&&!j){continue;}
                if(abs(i-k)>kk){continue;}
                b=g[k][j];
                if(b>a){
                    e[i][j].push_back(make_pair(k,j));
                    }
                }
            for(int k=0;k<n;k++){
                if(!k&&!i){continue;}
                if(abs(j-k)>kk){continue;}
                b=g[i][k];
                if(b>a){
                    e[i][j].push_back(make_pair(i,k));
                    }
                }
            }
        }
        dfs(0,0);
        pair<int,int > from,to;
        reverse(ts.begin(),ts.end());
        for(int i=0;i<ts.size();i++){
             from=ts[i];
            for(int k=0;k<e[from.first][from.second].size();k++){
                to=e[from.first][from.second][k];
                best[to.first][to.second]=max(best[to.first][to.second],best[from.first][from.second]+g[from.first][from.second]);
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                best[i][j]+=g[i][j];
                ans=max(best[i][j],ans);
            }
        }
        printf("%lld\n",ans);
        if(t){
            printf("\n");
        }
    }
    return 0;
}
