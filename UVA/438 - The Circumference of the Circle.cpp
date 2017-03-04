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

const double EPS=1e-9;

typedef complex<double> point;
const double PI=acos(-1);
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

double dgtord(double x){
    return (x/180)*PI;
}


/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
const int N=100005;
double xx,yy;
point p[3];
bool intersectSegments(point a, point b, point c, point d, point & intersect) {
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;  // Parllel || identical
    
    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;
    
   // if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
    //    return false;  //e.g ab is ray, cd is segment ... change to whatever
    return true;
}
pair<double, point> findCircle(point a, point b, point c) {
    //create median, vector, its prependicular
    point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
    point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(v2.Y, -v2.X);
    point end1 = m1+pv1, end2 = m2+pv2, center;
    intersectSegments(m1, end1, m2, end2, center);
    return make_pair( length(a-center), center );
}

int main(){
    while(scanf("%lf%lf",&xx,&yy)!=EOF){
        p[0]=point(xx,yy);
        scanf("%lf%lf",&xx,&yy);
        p[1]=point(xx,yy);
        scanf("%lf%lf",&xx,&yy);
        p[2]=point(xx,yy);
        double r=findCircle(p[0],p[1],p[2]).first;
        printf("%.2lf\n",2*r*PI);
    
    }
    return 0;//rev Ab steps
}
