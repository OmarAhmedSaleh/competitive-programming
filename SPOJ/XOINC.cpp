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

int n ,a[2001];
int b[2001];
pair<int , int> dp[2][2001][2001];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
        if(i){
            b[i]+=b[i-1];
        }
    }
    for(int i=n-1;i>-1;i--){
        for(int j=1;j<=n;j++){
        if(j + i -1 >=n){
        int qq=b[n-1];
        if(i){qq-=b[i-1];}
            for(int r=0;r<2;r++){
                dp[r][i][j]={qq,n-i};
                if(dp[r][i][j].first<dp[r][i][j-1].first){
                    dp[r][i][j]=dp[r][i][j-1];
                }
            }
        continue;
        }
        int k = j;
        for(int r=0;r<2;r++){
            int jum=dp[r^1][i+k][min(2*k,n)].second;
            int qq=b[i+k-1];
            if(i){
                qq-=b[i-1];
            }
            if(dp[r][i+k+jum][min(2*dp[r^1][i+k][min(2*k,n)].second,n)].first+qq>dp[r][i][j].first){
                dp[r][i][j].first=dp[r][i+k+jum][min(2*dp[r^1][i+k][min(2*k,n)].second,n)].first+qq;
                dp[r][i][j].second=k;
            }
            if(dp[r][i][j].first<dp[r][i][j-1].first){
                dp[r][i][j]=dp[r][i][j-1];
            }
        }
    }
}
    printf("%d\n",dp[0][0][2].first);
    return 0;
}
