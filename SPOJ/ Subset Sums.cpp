/*
 - i need to generate all subsets (2^n) , but n<=34
 - i can't solve it using DP (34*34*20,000,000) 
 - split array  into two parts
 - search space = n/2 (search space <=17)
 - generate all subsets from first part and try to merge it with valid subsets from second part
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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

int n ;
long long a,b,s[44];
vector<long long > lf,ri;
int main(){
    scanf("%d%lld%lld",&n,&a,&b);
    for(int i=0;i<n;i++){
        scanf("%lld",&s[i]);
    }
    int h=n/2,hh=h;
    if(n&1){hh++;}
    int ll=h;
    int rr=hh;
    for(int i=0;i<(1<<ll);i++){
        long long sum=0;
        for(int j=0;j<ll;j++){
            if(i&(1<<j)){
                sum+=s[j];
            }
        }
        lf.push_back(sum);
    }
    for(int i=0;i<(1<<rr);i++){
        long long sum=0;
        for(int j=0;j<rr;j++){
            if(i&(1<<j)){
                sum+=s[j+ll];
            }
        }
        ri.push_back(sum);
    }
    // Merge
    long long ans=0;
    sort(ri.begin(),ri.end());
    int st,e;
    for(int i=0;i<(1<<ll);i++){
        e=upper_bound(ri.begin(),ri.end(),b-lf[i])-ri.begin();
        st=lower_bound(ri.begin(),ri.end(),a-lf[i])-ri.begin();
        ans+=e-st;
    }
    printf("%lld\n",ans);
    return 0;//rev Ab steps
}
