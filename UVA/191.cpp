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
const double EPS=1e-9;
struct point{
    double x,y;
   
};
struct line{
    double a,b,c;
};
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
bool aresame(line l1,line l2){
    return fabs(l1.a-l2.a)<EPS &&fabs(l1.b-l2.b)<EPS&&fabs(l1.c-l2.c)<EPS;
}
bool ispar(line l1,line l2){
    return fabs(l1.a-l2.a)<EPS &&fabs(l1.b-l2.b)<EPS;
}
struct seg{
    point st,ed;
};
int tc;
bool isinter(seg a,seg b){
    line l1,l2;
    pointsToLine(a.st,a.ed,l1);
    pointsToLine(b.st,b.ed,l2);
    if(ispar(l1,l2)){
        return 0;
    }
    point t;
    t.x=(l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
   
    if (fabs(l1.b) > EPS)
        t.y = -(l1.a * t.x + l1.c);
    else
        t.y = -(l2.a * t.x + l2.c);
    int cnt=0;
    if(t.x>=min(a.st.x,a.ed.x)&&t.x<=max(a.st.x,a.ed.x)&&t.y>=min(a.st.y,a.ed.y)&&t.y<=max(a.st.y,a.ed.y)){
        cnt++;
    }
    if(t.x>=min(b.st.x,b.ed.x)&&t.x<=max(b.st.x,b.ed.x)&&t.y>=min(b.st.y,b.ed.y)&&t.y<=max(b.st.y,b.ed.y)){
        cnt++;
    }
    //cout<<a.st.x<<" "<<a.st.y<<" "<<a.ed.x<<" "<<a.ed.y<<endl;
   // cout<<b.st.x<<" "<<b.st.y<<" "<<b.ed.x<<" "<<b.ed.y<<endl;
    
    //cout<<t.x<<" "<<t.y<<endl;
    //cout<<cnt<<endl;
    return cnt==2;
}
string out="FT";
bool isInsideRectangle(point p1, point p2, point p3)
{
    if (p3.x <= max(p1.x, p2.x)
        && p3.x >= min(p1.x, p2.x)
        && p3.y <= max(p1.y, p2.y)
        && p3.y >= min(p1.y, p2.y))
        return true;
    
    return false;
}
int main(){
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++){
    seg s;
    scanf("%lf%lf%lf%lf",&s.st.x,&s.st.y,&s.ed.x,&s.ed.y);
    double ux,uy,lx,ly;
    scanf("%lf%lf%lf%lf",&ux,&uy,&lx,&ly);
    vector<seg> rec;
    seg d;
    d.st.x=ux;
    d.st.y=uy;
    d.ed.x=ux;
    d.ed.y=ly;
    rec.push_back(d);
    d.st.x=lx;
    d.st.y=uy;
    d.ed.x=lx;
    d.ed.y=ly;
    rec.push_back(d);
    d.st.x=ux;
    d.st.y=ly;
    d.ed.x=lx;
    d.ed.y=ly;
    rec.push_back(d);
    d.st.x=ux;
    d.st.y=uy;
    d.ed.x=lx;
    d.ed.y=uy;
    rec.push_back(d);
        point up;
        up.x=ux;
        up.y=uy;
        point lo;
        lo.x=lx;
        lo.y=ly;
        int ok=0;
        for(int i=0;i<rec.size();i++){
            if(isinter(s,rec[i])||isInsideRectangle(up,lo,s.st)||isInsideRectangle(up,lo,s.ed)){
                ok=1;
            }
            
        }
        cout<<out[ok]<<endl;
    
    }
    return 0;//rev Ab steps
}
