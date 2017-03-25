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



/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

int t,n,ans;
double lat[1003],lon[1003];
double gcDistance(double pLat, double pLong,double qLat, double qLong, double radius) {
    pLat *= PI / 180; pLong *= PI / 180;
    qLat *= PI / 180; qLong *= PI / 180;
    return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
                         cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) + sin(pLat)*sin(qLat));
}
int main(){
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&lat[i],&lon[i]);
        }
        double mn,mx;
        ans=0;
        mn=1e33;
        for(int i=0;i<n;i++){
            mx=0;
            for(int j=0;j<n;j++){
                if(i==j){continue;}
                mx=max(mx,gcDistance(lat[i],lon[i],lat[j],lon[j],6378));
            }
            if(mn>mx||fabs(mn-mx)<EPS){
                mn=mx;
                ans=i;
            }
        }
        printf("%.2lf %.2lf\n",lat[ans],lon[ans]);
    }
    return 0;//rev Ab steps
}
