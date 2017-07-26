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
/*
const long long OO=4e18;
const int oo=1e9;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
*/
int n , l , k , a[200],p[200];
double memo[200][201][201];
bool seen[200][201][201];

double solve(int idx,int kk, int ll){
    // cout<<idx<<" "<<kk<<" "<<ll<<endl;
    if(kk<0){return 0;}
    if(idx==n){
        return ll>=l;
    }
    if(seen[idx][kk][ll]){return memo[idx][kk][ll];}
    double prob=p[idx];prob/=100;
    double ans=solve(idx+1,kk,ll)*(1-prob);
    ans+=solve(idx+1,min(a[idx]+kk,200),ll+1)*prob;
    seen[idx][kk][ll]=1;
    return memo[idx][kk][ll]=ans;
}
int main(){
    scanf("%d%d%d",&n,&l,&k);
    for(int i=0;i<n;i++){scanf("%d",&p[i]);}
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
                swap(p[i],p[j]);
            }
        }
    }
    printf("%.6lf\n",solve(0,k,0));
    return 0;
}
