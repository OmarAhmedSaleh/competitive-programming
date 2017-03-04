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
// ss
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

const int N=100005;
int l , r, ql, qr, n, w[N];
long long ll[N],rr[N];


int main(){
    scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    ll[0]=rr[0]=0;
    ll[1]=l*w[0];
    rr[1]=r*w[n-1];
    for(int i=1;i<n;i++){
        ll[i+1]+=(w[i]*l)+ll[i];
    }
    int cnt=1;
    for(int i=n-2;i>-1;i--){
        rr[cnt+1]+=(w[i]*r)+rr[cnt];
        cnt++;
    }
    long long ans=900090009000;
    for(int i=0;i<=n;i++){
        int fl=i;
        int fr=n-i;
        int df=abs(fl-fr);
        int ex=0;
        df--;
        if(fr>fl){
            ex=df*qr;
        }
        if(fl>fr){
            ex=df*ql;
        }
        ans=min(ll[i]+rr[n-i]+ex,ans);
    }
    printf("%lld\n",ans);
    return 0;//rev Ab steps
}
