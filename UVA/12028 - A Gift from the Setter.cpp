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
const int md=1000007;
int n,k,c,t,a[100005];
long long b[100005];
int tt=1;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&k,&c,&n,&a[0]);
        for(int i=1;i<n;i++){
            a[i]=(1LL*a[i-1]*k+c)%md;
        }
        b[n-1]=0;
        sort(a,a+n);
        long long ans=0;
        for(int i=n-2;i>-1;i--){
            b[i]=b[i+1]+(1LL*(a[i+1]-a[i])*(n-i-1));
            ans+=b[i];
        }
        printf("Case %d: %lld\n",tt++,ans);
    }
    return 0;
}
