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
const long long OO=4e18;
const int oo=1e9;
const int md=1e9 + 7;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
int r , g , all, rol , h;
long long dp[2][200001];
int main(){
    scanf("%d%d",&r,&g);
    all=r+g;
    memset(dp,0,sizeof(dp));
    if(r){
        dp[0][g]++;
    }
    if(g){
        dp[0][g-1]++;
    }
    h=2;
    long long hh=1;
    long long rr=0;
    bool br=0;
    long long mx=0;
    while(!br){
        br=1;
        mx=0;
        for(int i=0;i<=g;i++){
            if(dp[rol][i]==0){continue;}
            rr=hh-(g-i);
            // cout<<rr<<endl;
            if(rr<0){continue;}
            if(r-rr>=h){
                // cout<<r<<" "<<rr<<" "<<h<<" "<<i<<endl;
                dp[rol^1][i]+=dp[rol][i];
                if(dp[rol^1][i]>md){
                    dp[rol^1][i]-=md;
                }
                br=0;
            }
            if(i>=h){
                //cout<<i<<" "<<h<<" "<<endl;
                dp[rol^1][i-h]+=dp[rol][i];
                if(dp[rol^1][i-h]>md){
                    dp[rol^1][i-h]-=md;
                }
                br=0;
            }
            mx+=dp[rol][i];
            if(mx>md){mx-=md;}
            dp[rol][i]=0;
        }
        hh+=h;
        h++;
        rol^=1;
    }
    printf("%lld\n",mx);
    return 0;
}
