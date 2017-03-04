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
int l,w,h,o;
double dgtord(double x){
    return (x/180)*PI;
}
int main(){
    while(scanf("%d%d%d%d",&l,&w,&h,&o)==4){
        double a=l*w*h;
        double ans;
        double s1=sin(dgtord(o));
        double s2=sin(dgtord(90-o));
        double hh=l*s1/s2;
        double b=.5*w*l*hh;
        ans=a-b;
        if(hh>h){
            ans=.5*h*h*s2*w/s1;
        }
        printf("%.3lf mL\n",ans);
        
        }
    return 0;//rev Ab steps
}
