
/*
 try all possible cuts , find area of two polygons
 */
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

vector<point> pts;
double xx[4],yy[4];
double polygonArea(vector<point>& points) {
    long double a = 0;
    for(int i=0;i<points.size();i++){
        a += cp(points[i], points[ (i+1) % points.size() ]);
    }
    return fabs(a/2.0);    // If area > 0 then points ordered ccw
}

bool intersectSegments(point a, point b, point c, point d, point & intersect) {
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;  // Parllel || identical
    
    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;
    
    if (t1>1+EPS||t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;
    return true;
}

pair<vector<point>, vector<point> > polygonCut(vector<point> &p,point A, point B) {
    vector<point> left, right;
    point intersect;
    for (int i = 0; i < p.size(); ++i) {
        point cur = p[i], nxt = p[(i + 1) % p.size()];
        
        if ( cp(B-A, cur-A) >= 0)
            right.push_back(cur);
        
       
        
        if ( cp(B-A, cur-A) <= 0)
            left.push_back(cur);
        
        if (intersectSegments(A, B, cur, nxt, intersect)) {
            right.push_back(intersect);
            left.push_back(intersect);
        }
        
    }
    return make_pair(left, right);
}

point mid(point a,point b){
    return point((a.X+b.X)/2.0,(b.Y+a.Y)/2.0);
}

int tt=1;
int main(){
    while(1){
        bool bk=1;
        pts.clear();
        for(int i=0;i<4;i++){
            scanf("%lf %lf",&xx[i],&yy[i]);
            pts.push_back(point(xx[i],yy[i]));
            if(fabs(xx[i])>0){bk=0;}
            if(fabs(yy[i])>0){bk=0;}
        }
        if(bk){
            break;
        }
        double mn=1e30;
        double ans[2]={-1,-1};
        double area[2];
        vector<point> allmid;
        for(int i=0;i<4;i++){
            allmid.push_back(mid(pts[i],pts[(i+1)%4]));
        }
        pair<vector<point> ,vector<point> > ret;
        for(int i=0;i<pts.size();i++){
            for(int j=i+1;j<pts.size();j++){
                ret=polygonCut(pts,pts[i],pts[j]);
                area[0]=fabs(polygonArea(ret.first));
                area[1]=fabs(polygonArea(ret.second));
                if(fabs(area[0]-area[1])<mn){
                    mn=fabs(area[0]-area[1]);
                    ans[0]=area[0];ans[1]=area[1];
                }
            }
        }
        for(int i=0;i<pts.size();i++){
            for(int j=0;j<allmid.size();j++){
                ret=polygonCut(pts,pts[i],allmid[j]);
                area[0]=fabs(polygonArea(ret.first));
                area[1]=fabs(polygonArea(ret.second));
                if(fabs(area[0]-area[1])<mn){
                    mn=fabs(area[0]-area[1]);
                    ans[0]=area[0];ans[1]=area[1];
                }
            }
        }
       
        for(int i=0;i<allmid.size();i++){
            for(int j=i+1;j<allmid.size();j++){
                ret=polygonCut(pts,allmid[i],allmid[j]);
                area[0]=fabs(polygonArea(ret.first));
                area[1]=fabs(polygonArea(ret.second));
                if(fabs(area[0]-area[1])<mn){
                    mn=fabs(area[0]-area[1]);
                    ans[0]=area[0];ans[1]=area[1];
                }
            }
        }
        printf("Cake %d: %.3lf %.3lf\n",tt++,min(ans[0],ans[1]),max(ans[0],ans[1]));
        
    }
    return 0;//rev Ab steps
}
