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


int main(){
    double x,y;
    while(scanf("%lf %lf",&x,&y)!=EOF){
        point a(x,y);
        scanf("%lf %lf",&x,&y);
        point bb(x,y);
        scanf("%lf %lf",&x,&y);
        point b(x,y);
        scanf("%lf %lf",&x,&y);
        point c(x,y);
        if(fabs(bb.X-a.X)<EPS&&fabs(bb.Y-a.Y)<EPS){
            swap(a,b);
        }
        if(fabs(b.X-a.X)<EPS&&fabs(b.Y-a.Y)<EPS){
            swap(a,bb);
        }
        if(fabs(c.X-a.X)<EPS&&fabs(c.Y-a.Y)<EPS){
            swap(a,b);
            swap(c,bb);
        }
        if(fabs(c.X-b.X)<EPS&&fabs(c.Y-b.Y)<EPS){
            swap(c,bb);
        }
        if(fabs(c.X-bb.X)<EPS&&fabs(c.Y-bb.Y)<EPS){
            swap(c,b);
        }
        point ab=b-a;
        point bc=c-b;
        point out=b+(bc-ab);
        printf("%.3lf %.3lf\n",out.X,out.Y);
        
        
    }
    
    
    
    
    return 0;//rev Ab steps
}
