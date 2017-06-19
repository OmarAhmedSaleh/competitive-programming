/*
 steps:
 1-Concatenate strings
 
 2-extract points from string
 
 3-Determine starting- ending point for each segment
    - '-' means that prev.. and next point are start-end point for new segment
 
 4-check if there is a stand-alone point ( without connection )
 
 5- Merge all segments that belong to same polylines "Merge -> same picture"

 6- check if segment[i] intersect with segment[j] "belong to the same picture"
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

const double EPS=1e-7;

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
class PolylineUnion{
public:
    struct seg{
        point p[2];
    };
    // max_Length = 50
    // Max number of elemntes = 50
    // 50*50/4 +1
    bool inv[626];
    int cc[626];
    int ccw(point a, point b, point c) {
        point v1(b - a), v2(c - a);
        double t = cp(v1, v2);
        
        if (t > +EPS)
            return +1;
        if (t < -EPS)
            return -1;
        if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
            return -1;
        if (norm(v1) < norm(v2) - EPS)
            return +1;
        return 0;
    }
    bool intersect(point p1, point p2, point p3, point p4) {
        // special case handling if a segment is just a point
        bool x = (p1 == p2), y = (p3==p4);
        if(x && y)  return p1 == p3;
        if(x)   return ccw(p3, p4, p1) == 0;
        if(y)   return ccw(p1, p2, p3) == 0;
        
        return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
        ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
    }
    int get(int idx){
        if(cc[idx]==idx){
            return idx;
        }
        return cc[idx]=get(cc[idx]);
    }
    int countComponents(vector <string> polylines){
        int ret=0;
        string s="";
        for(int i=0;i<(int)polylines.size();i++){
            s+=polylines[i];
        }
        vector<point>pts;
        vector<pair<int,int> > dash;
        int xx,yy,temp;
        xx=yy=temp=0;
        bool gx=0;
        for(int i=0;i<(int)s.size();i++){
            if(s[i]==' '){
                // cout<<xx<<" , "<<temp<<endl;
                pts.push_back(point(xx,temp));
                gx=0;xx=0,temp=0;
                continue;
            }
            if(s[i]>='0'&&s[i]<='9'){
                temp*=10;
                temp+=s[i]-'0';
                continue;
            }
            if(s[i]==','){
                gx=1;
                xx=temp;
                temp=0;
                continue;
            }
            if(s[i]=='-'){
                //cout<<xx<<" , "<<temp<<endl;
                dash.push_back(make_pair(pts.size(),pts.size()+1));
                pts.push_back(point(xx,temp));
                gx=0;xx=0,temp=0;
                continue;
            }
        }
        if(temp!=-1&&gx){
            pts.push_back(point(xx,temp));
        }
        for(int i=0;i<=pts.size();i++){
            cc[i]=i;
        }
        vector<seg>all;
        seg sg;
        for(int i=0;i<dash.size();i++){
            inv[dash[i].first]=1;
            inv[dash[i].second]=1;
            //merge
            // cout<<dash[i].first<<" Merge "<<dash[i].second<<endl;
            sg.p[0]=pts[dash[i].first];
            sg.p[1]=pts[dash[i].second];
            all.push_back(sg);
            
        }
        for(int i=0;i<pts.size();i++){
            if(!inv[i]){
                sg.p[0]=pts[i];
                sg.p[1]=pts[i];
                all.push_back(sg);
            }
        }
        for(int i=0;i<all.size();i++){
            for(int j=i+1;j<all.size();j++){
                if(intersect(all[i].p[0],all[i].p[1],all[j].p[0],all[j].p[1])){
                    cc[get(i)]=cc[get(j)];
                }
            }
        }
        for(int i=0;i<all.size();i++){
            ret+=(cc[i]==i);
        }
        return ret;
    }
    
};
