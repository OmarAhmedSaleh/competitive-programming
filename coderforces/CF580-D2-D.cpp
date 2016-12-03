
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
using namespace std;
int n,m,a[19],c[19][19],k;
long long dp[1<<19][19];
const long long oo=1e19;
long long solve(int mask,int last,int take){
    if(take>m){return -oo;}
    if(take==m){return 0;}
    if(dp[mask][last]!=-1){
        return dp[mask][last];
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(mask&(1<<i)){continue;}
        ans=max(ans,a[i]+c[last][i]+solve(mask|(1<<i),i,take+1));
    }
    return dp[mask][last]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));

    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int x,y;
    for(int i=0;i<k;i++){
        scanf("%d %d",&x,&y);
        scanf("%d",&c[x][y]);
    }
    printf("%lld\n",solve(0,0,0));
    return 0;
}
