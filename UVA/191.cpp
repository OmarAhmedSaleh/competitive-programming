/* 
find intersections point or check if the line is inside the rectangle
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

const double EPS=1e-8;

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


int tc;

double x,y;

point line[2],rec[4];

bool intersectSegments(point a, point b, point c, point d, point & intersect) {
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;
    
    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;
    
    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS||t1> 1 + EPS)
        return false;
    
    return true;
}

int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%lf%lf",&x,&y);
        line[0]=point(x,y);
        scanf("%lf%lf",&x,&y);
        line[1]=point(x,y);
        
        scanf("%lf%lf",&x,&y);
        rec[0]=point(x,y);
        
        scanf("%lf%lf",&x,&y);
        rec[1]=point(x,y);
        
        rec[2]=point(rec[0].X,rec[1].Y);
        
        rec[3]=point(rec[1].X,rec[0].Y);
        bool ok=0;
        point ret;
        ok|=intersectSegments(line[0],line[1],rec[0],rec[2],ret);
        ok|=intersectSegments(line[0],line[1],rec[0],rec[3],ret);
        ok|=intersectSegments(line[0],line[1],rec[1],rec[2],ret);
        ok|=intersectSegments(line[0],line[1],rec[1],rec[3],ret);

        double xx[2],yy[2];
        xx[0]=xx[1]=rec[0].X;
        yy[0]=yy[1]=rec[0].Y;
        for(int i=0;i<4;i++){
            xx[0]=min(rec[i].X,xx[0]);
            xx[1]=max(rec[i].X,xx[1]);
            yy[0]=min(rec[i].Y,yy[0]);
            yy[1]=max(rec[i].Y,yy[1]);
        }
        
        ok|=(!(line[0].X < xx[0]) && !(line[0].X > xx[1]) && !(line[0].Y < yy[0]) && !(line[0].Y > yy[1]));
        
        ok|=(!(line[1].X < xx[0]) && !(line[1].X > xx[1]) && !(line[1].Y < yy[0]) && !(line[1].Y > yy[1]));

        if(ok){
            puts("T");
        }else{
            puts("F");

        }
        
    }
    return 0;//rev Ab steps
}
