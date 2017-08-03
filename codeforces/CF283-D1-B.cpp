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
int it;
int cal[200000][2];
long long dp[200000][2];
int a[200000],n;
void dfs(int idx,int cmd){
    cal[idx][cmd]=it;
    int new_idx=idx;
    // 0 add , 1 sub
    if(cmd){
        new_idx-=a[idx];
    }else{
        new_idx+=a[idx];
    }
    // base Case
    dp[idx][cmd]=a[idx];
    if(new_idx<0||new_idx>=n){
        return ;
    }
    if(cal[new_idx][cmd^1]>0 && cal[new_idx][cmd^1]!=it){
        if(dp[new_idx][cmd^1]==-oo){
            dp[idx][cmd]=-oo;
        }else{
            dp[idx][cmd]+=dp[new_idx][cmd^1];
        }
        return ;
    }
    if(cal[new_idx][cmd^1]==it){
        // cycle
        dp[idx][cmd]=-oo;
        return ;
    }
    dfs(new_idx,cmd^1);
    if(dp[new_idx][cmd^1]==-oo){
        dp[idx][cmd]=-oo;
    }else{
        dp[idx][cmd]+=dp[new_idx][cmd^1];
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        a[0]=i;
        it=i;
        cal[0][1]=cal[0][0]=it;
        dfs(0,0);
        dp[0][0]=max(dp[0][0],(long long)-1);
        printf("%lld\n",dp[0][0]);
    }
    return 0;
}
