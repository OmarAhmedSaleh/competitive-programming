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
// ss
using namespace std;

typedef complex<double> point;
#define X real()
#define Y imag()
#define cp(a,b)                 ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )


const double EPS=1e-7;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

int n;
bool segmentintersect(point a,point b,point c,point d,point &intersect){
    // v= cd , u= ab , w= ac
    double d1=cp(a-b,d-c),d2=cp(a-c,d-c),d3=cp(a-b,a-c);
    if(fabs(d1)<EPS){
        return false;
    }
    double t1=d2/d1;
    double t2=d3/d1;
    intersect=a+(b-a)*t1;
    //out of segment
    if(t2>1+EPS ||t2<-EPS){
        return false;
    }
    
    return true;}
vector<point> cutpolygon(point a, point b, vector<point> &p){
    vector<point> up,down;
    point intersect;
    for(int i=0;i<p.size();i++){
        point cur=p[i];
        point nxt=p[(i+1)%p.size()];
        if(cp(b-a,cur-a)<=0){
            up.push_back(cur);
        }
        if(segmentintersect(a,b,cur,nxt,intersect)){
            up.push_back(intersect);
            down.push_back(intersect);
        }
        if(cp(b-a,cur-a)>=0){
            down.push_back(cur);
        }
    }
    
    return up;
}
int t;
int main(){
    while(scanf("%d",&n)==1){
        if(!n){break;}
        int x,y;
        vector<point> pts;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            pts.push_back(point(x,y));
        }
        vector<point> out=pts;
        for(int i=0;i<n;i++){
            out=cutpolygon(pts[i],pts[(i+1)%n],out);
        }
        printf("Floor #%d\n",++t);
        if(out.empty()){
            cout<<"Surveillance is impossible.\n";
        }else{
            cout<<"Surveillance is possible.\n";
            
        }
        cout<<endl;
        
    }
    //4 0 0 0 1 1 1 1 0 8 0 0 0 2 1 2 1 1 2 1 2 2 3 2 3 0 0
    
    
    return 0;//rev Ab steps
}
