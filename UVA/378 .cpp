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
//const int N=100005;
typedef complex<double> point;
#define X real()
#define Y imag()
#define cp(a,b) (conj(a)*(b)).imag()
#define dp(a,b) (conj(a)*(b)).real()
#define lengthsq(a)    dp(a,a)
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
bool l;
bool check(point a,point c,point d){
    return a.X>=min(c.X,d.X)&&a.X<=max(c.X,d.X)&&a.Y>=min(c.Y,d.Y)&&a.Y<=max(c.Y,d.Y);
    ;
}
/*
bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
    double d1 = cp(a-b, d-c), d2 = cp(a-c, d-c), d3 = cp(a-b, a-c);
    if(fabs(d1) < EPS) return false; // Parllel || identical
    double t1 = d2/d1, t2 = d3/d1;
    intersect = a+(b-a)*t1;
    if(t2 < -EPS || t2 > 1+EPS)
        return false;
    return true;
}
 */
bool lineintersect(point a,point b,point c,point d,point &intersect){
    point ab=b-a;
    point cd=d-c;
    point ac=c-a;
    // c-d Like V , a-b like u, ac like w
    // t1= cp(v,w)/cp(u,v)
    // t2=cp(u,w)/cp(u,v)
    double d1=cp(ab,cd);
    double d2=cp(ac,cd);
    //double d3=cp(ab,ac);
    
    if(fabs(d1)<EPS){
        // are parallel
        l|=fabs(cp(b-a,c-a))<EPS && fabs(cp(b-a,d-a))<EPS;
        return false;
    }
    double t1=d2/d1;
    intersect=a+((b-a)*t1);
    return true;
}
int tt;
int main(){
    scanf("%d",&tt);
    printf("INTERSECTING LINES OUTPUT\n");
    while(tt--){
        vector<point> pts;
        int x,y;
        pts.clear();
        for(int i=0;i<4;i++){
            scanf("%d %d",&x,&y);
            pts.push_back(point(x,y));
            
        }
        point out;
        l=0;
        if(lineintersect(pts[0],pts[1],pts[2],pts[3],out)){
            printf("POINT %.2lf %.2lf\n",out.X,out.Y);
            
        }else{
            if(l){
                printf("LINE\n");
            }else{
                printf("NONE\n");
            }
        }
    }
    printf("END OF OUTPUT\n");
    return 0;//rev Ab steps
}
