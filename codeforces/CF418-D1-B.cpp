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
const long long oo=4e18;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
long long dp[1<<20];
bool ok;
struct f{
    int k,pro,mm,x;
};
int n, m, b, kk;
f all[100];

int main(){
    scanf("%d%d%d",&n,&m,&b);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&all[i].x,&all[i].k,&all[i].mm);
        int foo;
        all[i].pro=0;
        for(int j=0;j<all[i].mm;j++){
            scanf("%d",&foo);
            foo--;
            all[i].pro|=1<<foo;
        }
    }
    long long ans=oo;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(all[i].k<all[j].k){
                swap(all[i],all[j]);
            }
        }
    }
    for(int i=0;i<(1<<m);i++){
        dp[i]=oo;
    }
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<m);j++){
            if(dp[j]==oo){continue;}
            dp[j|all[i].pro]=min(dp[j|all[i].pro],dp[j]+all[i].x);
        }
        if(dp[(1<<m)-1]!=oo){
            ok=1;
        }
        ans=min(ans,dp[(1<<m)-1]+(1LL*all[i].k*b));
    }
    if(!ok){
        printf("-1\n");
        return 0;
    }
    printf("%lld\n",ans);
    return 0;
}
