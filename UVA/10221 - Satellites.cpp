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
const int N=100005;
typedef complex<double> point;
const double PI=acos(-1);
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
double s, g;
string c;
double dgtord(double x){
    return (x/180)*PI;
}
double ans[2];

int main(){
    while(scanf("%lf%lf",&s,&g)==2){
        cin>>c;
        g=dgtord(g);
        if(c[0]=='m'){g/=60;}
        s+=6440;
        g=min(g,2*PI-g);
        ans[0]=s*g;
        ans[1]=2*s*sin(g/2);
        printf("%.6lf %.6lf\n",ans[0],ans[1]);
    
    }
    return 0;//rev Ab steps
}
