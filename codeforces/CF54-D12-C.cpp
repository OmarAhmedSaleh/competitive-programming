/*
http://codeforces.com/blog/entry/1088
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
//const long long OO=4e18;
//const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
long long pt[20],cnt[1000],l[1000],r[1000];
int n ,k;
double memo[1000][1001];
bool seen[1000][1001];
double solve(int idx,int kk){
    if(idx==n){
        return 1LL*kk*100>=1LL*k*n;
    }
    if(seen[idx][kk]){
        return memo[idx][kk];
    }
    double prob=cnt[idx];
    prob/=(r[idx]-l[idx]+1);
    seen[idx][kk]=1;
    double ans=solve(idx+1,kk+1)*prob + solve(idx+1,kk)*(1-prob);
    return memo[idx][kk]=ans;
}
int main(){
    pt[0]=1;
    for(int i=1;i<19;i++){
        pt[i]=1LL*pt[i-1]*10;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&l[i],&r[i]);
        if(l[i]>r[i]){
            swap(l[i],r[i]);
        }
        for(int j=0;j<19;j++){
            long long k=pt[j]<<1;
            // i j
            if(pt[j]>r[i]){break;}
            if(pt[j]<=l[i]){
                if(k>l[i]&&k<=r[i]){
                    cnt[i]+=k-l[i];
                }
                if(k>r[i]){
                    cnt[i]+=r[i]-l[i]+1;
                }
            }
            if(pt[j]>l[i]){
                if(k>l[i]&&k<=r[i]){
                    cnt[i]+=pt[j];
                }
                if(k>r[i]){
                    cnt[i]+=r[i]-pt[j]+1;
                }
            }
        }
    }
    scanf("%d",&k);
    printf("%.9lf\n",solve(0,0));
    return 0;
}
