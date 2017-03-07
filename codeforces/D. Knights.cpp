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

const double EPS=1e-9;

typedef complex<int> point;
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
int n,m,k,x[1003],y[1003];
struct circle{
    point c;
    double r;

};
circle cr[1003];
int mask[1003][55];
bool ok(int i,int j){
  // point inside a circle
     long long xxx=x[i]-cr[j].c.X; xxx*=xxx;
     long long yyy=y[i]-cr[j].c.Y; yyy*=yyy;
     return xxx+yyy<1LL*cr[j].r*cr[j].r;
}
int cnt(int bin){
    int ret=0;
    while(bin){
        if(bin&1){ret++;}
        bin/=2;
    }
    return ret;
    }
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    int xx,rr,yy;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&rr,&xx,&yy);
        cr[i].r=rr;
        cr[i].c=point(xx,yy);
    }
    //  1000 = 50*20
    // 50 mask * 20 Bits
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ok(i,j)){
                mask[i][j/20]|=1<<(j%20);
            }
        }
    }
    int a,b;
    int ans;

    for(int i=0;i<k;i++){
        ans=0;
        scanf("%d%d",&a,&b);
        a--;b--;
        for(int j=0;j<51;j++){
            ans+=cnt(mask[a][j]^mask[b][j]);
        }
        printf("%d\n",ans);
    }
    return 0;//rev Ab steps
}
