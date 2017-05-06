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
const int oo=1000000009;
int n , m ,a , b, c,dis[1003];
long long dp[1003];
bool was[1003];
vector<int> top;
vector<pair<int,int> > e[1003];
void dfs(int idx){
    was[idx]=1;
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i].first;
        if(!was[to]&&dis[idx]>dis[to]){
            dfs(to);
        }
    }
    top.push_back(idx);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        if(!n){
            break;
        }
        scanf("%d",&m);
        for(int i=0;i<=n;i++){
            e[i].clear();
            dis[i]=oo;
        }

        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            e[a].push_back(make_pair(b,c));
            e[b].push_back(make_pair(a,c));

        }
        memset(dp,0,sizeof(dp));
        memset(was,0,sizeof(was));
        top.clear();
        priority_queue<pair<int,int> > pq;
        dis[2]=0;
        pq.push(make_pair(0,2));
        while(!pq.empty()){
            a=pq.top().second;
            c=-pq.top().first;
            pq.pop();
            if(dis[a]<c){continue;}
            for(int i=0;i<e[a].size();i++){
                b=e[a][i].first;
                if(dis[b]>dis[a]+e[a][i].second){
                    dis[b]=dis[a]+e[a][i].second;
                    pq.push(make_pair(-dis[b],b));
                }
            }
        }
        dp[1]=1;
        dfs(1);
        for(int i=(int)top.size()-1;i>-1;i--){
            int from=top[i];
            for(int j=0;j<e[from].size();j++){
                int to=e[from][j].first;
                if(dis[from]>dis[to]){
                    dp[to]+=dp[from];
                }
            }
        }
        printf("%lld\n",dp[2]);
    }
    
    return 0;
}
