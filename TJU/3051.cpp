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
using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

const int N=222;
double memo[N+N][N+N];
bool cal[N+N][N+N];
double w,d,l;
int n ,p,a[3],t,rem;
double solve(int cur,int po){
    if(cur==n){
        if(po<p){return 0;}
        return 1;
    }
    if(cal[cur][po]){
        return memo[cur][po];
    }
    double ans=solve(cur+1,po+3)*w;
    ans+=solve(cur+1,po+1)*d;
    ans+=solve(cur+1,po)*l;
    cal[cur][po]=1;
    return memo[cur][po]=ans;
}
int main(){
    while(scanf("%d%d",&n,&p)==2){
        if(!n&&!p){break;}
        t=0;
    for(int i=0;i<3;i++){
        scanf("%d",&a[i]);
        t+=a[i];
    }
    memset(cal,0,sizeof(cal));
    w=(double)a[0]/t;
    d=(double)a[1]/t;
    l=(double)a[2]/t;
    printf("%.1lf\n",(double)solve(0,0)*100);
    
    }
    return 0;//rev Ab steps
}
