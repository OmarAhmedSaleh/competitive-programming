/*
 cost = time
 steps
 1- calculate min cost of tour that starts at 0 and ends at position i is dp[0][i][mask]
    ,min cost tour that starts at n-1 and ends at position i dp[1][i][mask]
 
 2- min cost memo[0][i][mask] <- start at i and end at 0
    min cost memo[1][i][mask] < start at i and end at n-1
 
 3-try all subset with size = h/2 or (h+1)/2 (odd, special case n==3) let call it mask1
    and remaining hotels mask2
 
 4- try to start at 0 and end at position P1 (mask1 & (1<<P1)) then start and P1 and visit the remaining hotels (mask2) and end at 0 "Keep min cost "call it c1" "
 
 5-try to start at n-1 and end at position P2 (mask1 & (1<<P2)) then start and P2 and visit the remaining hotels (mask2) and end at n-1 "Keep min cost "call it c2" "
 
 best=min(best,c1+c2);
 
 
 */
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
const int oo=1e9;
int memo[2][20][1<<20], n, m, dis[20][20],dp[2][20][1<<20];
int solve(int f,int idx,int mask){
    if(mask==(1<<n)-1){
        if(!f){
            return dis[idx][0];
        }
        return dis[idx][n-1];
    }
    if(memo[f][idx][mask]!=-1){
        return memo[f][idx][mask];
    }
    int ans=oo;
    for(int i=1;i<n-1;i++){
        if(!(mask&(1<<i))){
            ans=min(ans,solve(f,i,mask|(1<<i))+dis[idx][i]);
        }
    }
    return memo[f][idx][mask]=ans;
}
void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int tc;
int main(){
    while(scanf("%d%d",&n,&m)==2){
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=oo;
            }
        }
        int u , v, w;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            dis[u][v]=w;
            dis[v][u]=w;
        }
        floyd();
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<(1<<n);k++){
                    dp[i][j][k]=oo;
                }
            }
        }
        dp[0][0][1]=0;
        dp[1][n-1][1<<(n-1)]=0;
        for(int i=0;i<2;i++){
            for(int k=0;k<(1<<n);k++){
                for(int j=0;j<n;j++){
                    if(!((k&(1<<j)))){continue;}
                    for(int idx=0;idx<n;idx++){
                        if(!(k&(1<<idx))){
                            dp[i][idx][k|(1<<idx)]=min(dp[i][idx][k|(1<<idx)],dp[i][j][k]+dis[j][idx]);
                        }
                    }
                }
            }
        }
        int mask=0;
        int cnt=0,h=(n-2)/2,h2=(n-1)/2;
        int best=oo;
        for(int i=0;i<(1<<n);i++){
            mask=0;
            cnt=0;
            for(int j=1;j<n-1;j++){
                if(i&(1<<j)){
                    cnt++;
                    mask|=1<<j;
                }
            }
            if(cnt==h||cnt==h2){
                int a,b;
                a=b=oo;
                for(int j=1;j<n-1;j++){
                    if(!(mask&(1<<j))){
                        continue;
                    }
                    a=min(a,dp[0][j][mask|1]+solve(1,j,(mask|1)|(1<<(n-1))));
                }
                for(int j=1;j<n-1;j++){
                    if(!(mask&(1<<j))){
                        continue;
                    }
                    b=min(b,dp[1][j][mask|(1<<(n-1))]+solve(0,j,(mask|1)|(1<<(n-1))));
                }
                best=min(best,a+b);
            }
        }
        printf("Case %d: %d\n",++tc,best);
    }
    
    return 0;
}
