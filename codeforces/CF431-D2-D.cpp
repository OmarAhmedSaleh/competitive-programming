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
//const long long OO=4e18;
//const int oo=1e9;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
int k;
long long ans,m,th;
long long c[66][66];
long long solve(int idx,int r){
    if(r==1){return idx;}
    if(idx==r||!r){return 1;}
    if(r>idx){return 0;}
    if(c[idx][r]!=-1){return c[idx][r];}
    return c[idx][r]=solve(idx-1,r-1)+solve(idx-1,r);
}
vector<int> all;
long long memo[66][66];
long long get(int idx,int rem){
    if(rem<0){
        return 0;
    }
    if(!rem){
        return 1;
    }
    if(idx==all.size()){
        return 0;
    }
    if(memo[idx][rem]!=-1){
        return memo[idx][rem];
    }
    // take or No
    long long ans=get(idx+1,rem-1)+solve(all[idx],rem);
    return memo[idx][rem]=ans;
}
bool check(long long n){
    th=n<<1;
    long long cnt=0;
    long long nn=n+1;
    while(nn+(nn&(-nn))<=th){
        int dig=0;
        for(int i=0;i<64;i++){
            if(nn&((long long)1<<i)){
                dig++;
            }
        }
        int lg=log2(nn&(-nn));
        int df=k-dig;
        if(df>-1){
            cnt+=solve(lg,df);
        }
        nn+=(nn&(-nn));
    }
    long long df=th-nn;
    all.clear();
    memset(memo,-1,sizeof(memo));
    int dig=0;
    for(int i=0;i<64;i++){
        if(df&((long long)1<<i)){
            dig++;
            all.push_back(i);
        }
    }
    reverse(all.begin(),all.end());
  //  cout<<cnt<<" "<<n<<" "<<nn<<endl;
    cnt+=get(0,k-1);
    if(cnt==m){
        ans=n;
    }
   // cout<<cnt<<" "<<n<<" "<<nn<<endl;
    return cnt>=m;
}


int main(){
    memset(c,-1,sizeof(c));
    scanf("%lld%d",&m,&k);
    long long ll=1,rr=1e18;
    bool br=0;
    while(!br && ll<=rr){
        long long mid=ll+(rr-ll)/2;
        if(rr==ll){
            br=1;
        }
        if(check(mid)){
            rr=mid-1;
        }else{
            ll=mid+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
