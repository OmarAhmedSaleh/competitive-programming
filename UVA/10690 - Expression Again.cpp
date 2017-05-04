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
const int oo=1e9;
int dx[8]={-1,1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int n , m ,a[101],sum;
int memo2[101][5002][51];
int sz;
int solve2(int idx,int s1,int k){
    if(idx==sz){
        if(!k){
            return memo2[idx][s1][k]=1;
        }
        return memo2[idx][s1][k]=0;
    }
    if( memo2[idx][s1][k]!=-1){
        return memo2[idx][s1][k];
    }
    int ans=0;
    ans|=solve2(idx+1,s1+a[idx],k-1);
    ans|=solve2(idx+1,s1,k);
    return memo2[idx][s1][k]=ans;

}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
    memset(memo2,-1,sizeof(memo2));
    sum=0;
    sz=n+m;
    for(int i=0;i<sz;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
        int mn=oo;
        int mx=-oo;
        solve2(0,2500,m);
        for(int i=0;i<=sz;i++){
            for(int j=0;j<5001;j++){
                if(memo2[i][j][0]==1){
                    mn=min(mn,(j-2500)*(sum-j+2500));
                    mx=max(mx,(j-2500)*(sum-j+2500));
                }
            }
        }
        printf("%d %d\n",mx,mn);
    }
    return 0;
}
