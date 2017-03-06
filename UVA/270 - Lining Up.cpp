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
int t;
vector<point> pts;
map<pair<int,int> ,int > cnt;
int xx,yy,mx;
int gcd(int aa,int bb){
    while(aa&&bb){
        if(aa>bb){
            aa%=bb;
        }else{
            bb%=aa;
        }
    }
    return aa+bb;
}
void cal(point a,point b){
    point c=b-a;
    int aa=c.X;
    int bb=c.Y;
    int g=gcd(abs(aa),abs(bb));
    if(!g){g=1;}
    aa/=g;
    bb/=g;
    cnt[make_pair(aa,bb)]++;
    mx=max(cnt[make_pair(aa,bb)],mx);
}
string s;
int main(){
    scanf("%d",&t);
    cin.ignore();
    cin.ignore();
    while(t--){
        pts.clear();
        cnt.clear();
        while(getline(cin,s)){
            if(!s.size()){break;}
            stringstream ss(s);
            ss>>xx;
            ss>>yy;
            pts.push_back(point(xx,yy));
        }
        mx=1;
        for(int i=0;i<pts.size();i++){
            cnt.clear();
            for(int j=0;j<pts.size();j++){
                if(i==j){continue;}
                cal(pts[i],pts[j]);
            }
        }
        
        printf("%d\n",mx+1);
        if(t){printf("\n");}
    }
    return 0;//rev Ab steps
}
