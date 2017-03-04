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
const double EPS=1e-8;
const int N=222;
typedef complex<double> point;
#define X real()
#define Y imag()
#define cp(a,b) (conj(a)*b).imag()
#define dp(a,b) (conj(a)*b).real()
#define lengthsq(a)    dp(a,a)
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

int n , bag[N], l, k;
double wp[N],lp[N],memo[N][N][N];
bool cal[N][N][N];
double solve(int idx,int w,int kk){
    if(kk>n){kk=n;}
    if(idx==n){
        return (w>=l)&&(kk>=0);
    }
    if(cal[idx][w][kk]){return memo[idx][w][kk];}
    double ret=lp[idx]*solve(idx+1,w,kk);
    ret+=wp[idx]*solve(idx+1,w+1,kk+bag[idx]);
    cal[idx][w][kk]=1;
    return memo[idx][w][kk]=ret;
}


int main(){
    cin>>n>>l>>k;
    for(int i=0;i<n;i++){
        cin>>wp[i];
        wp[i]/=100.0;
        lp[i]=1-wp[i];
    }
    for(int i=0;i<n;i++){
        cin>>bag[i];
       
    }
    printf("%.6lf\n",solve(0,0,k));
    
    return 0;//rev Ab steps
}
