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
// ss
using namespace std;
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

const int N=500005;
const double EPS=1e-8;
struct point{
    double x,y;
};
struct segment{
    point st,ed;
};
struct line{
    // ax+by+c=0;
    double a,b,c;
};
bool isparallel(line l1, line l2){
    return fabs(l1.a-l2.a)<EPS && fabs(l1.b-l2.b)<EPS;
}
bool areSame(line l1, line l2){
    return fabs(l1.c-l2.c)<EPS
    && fabs(l1.a-l2.a)<EPS
    && fabs(l1.b-l2.b)<EPS;
}
void pointsToLine(point p1, point p2,line &l)
{
    // l is a vertial line.
    if (p1.x == p2.x)
    {
        l.a = 1.0;
        l.b = 0;
        l.c = -p1.x;
    }
    else
    {
        l.a = -(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(l.a * p1.x) - p1.y;
    }
}
point t;
int isinter(segment a,segment b){
    line l1,l2;
    pointsToLine(a.st,a.ed,l1);
    pointsToLine(b.st,b.ed,l2);
    if(areSame(l1,l2)){
        return 2;
    }
    if(isparallel(l1,l2)){
        return 0;
    }
    t.x=(l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    
    if (fabs(l1.b) > EPS)
        t.y = -(l1.a * t.x + l1.c);
    else
        t.y = -(l2.a * t.x + l2.c);
    int cnt=0;
    //if(t.x>=min(a.st.x,a.ed.x)&&t.x<=max(a.st.x,a.ed.x)&&t.y>=min(a.st.y,a.ed.y)&&t.y<=max(a.st.y,a.ed.y)){
        cnt++;
   // }
   // if(t.x>=min(b.st.x,b.ed.x)&&t.x<=max(b.st.x,b.ed.x)&&t.y>=min(b.st.y,b.ed.y)&&t.y<=max(b.st.y,b.ed.y)){
        cnt++;
   // }
    return cnt==2;
}

int main(){
    int tc;
    scanf("%d",&tc);
    puts("INTERSECTING LINES OUTPUT");
    for(int tt=1;tt<=tc;tt++){
        segment s1,s2;
        scanf("%lf%lf",&s1.st.x,&s1.st.y);
        scanf("%lf%lf",&s1.ed.x,&s1.ed.y);
        scanf("%lf%lf",&s2.st.x,&s2.st.y);
        scanf("%lf%lf",&s2.ed.x,&s2.ed.y);
        int ret=isinter(s1,s2);
        if(ret==2){
            puts("LINE");
            continue;
        }
        if(ret==0){
            puts("NONE");
            continue;
        }
        printf("POINT %.2lf %.2lf\n",t.x,t.y);
    
    }
    puts("END OF OUTPUT");
    return 0;//rev Ab steps
}
