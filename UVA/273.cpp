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

const int N=50;
const double EPS=1e-9;
struct point{
    double x,y;
};
struct line{
    double a,b,c;
};
struct segment{
    point st,ed;
};
int t,n;
segment segments[N];
line lines[N];
vector<int> e[N];
int mark[N];
int cc;
void dfs(int idx){
    mark[idx]=cc;
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i];
        if(!mark[to]){
            dfs(to);
        }
    }
}
void pointstoline(point p1,point p2, line&l){
    if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
        l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
        
    }
    
}
double cross(point a, point b){
    return (a.x*b.y) - (a.y*b.x);
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}


bool areIntersect(int i,int j, point &p) {
    line l1=lines[i];
    line l2=lines[j];
    if (areParallel(l1, l2)) {
        return false;
    }
  
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true;
}
bool check(segment a,point t){
    return t.x>=min(a.st.x,a.ed.x)&&t.x<=max(a.st.x,a.ed.x)&&t.y>=min(a.st.y,a.ed.y)&&t.y<=max(a.st.y,a.ed.y);
}
bool colllinear(point a,point b,point c){
    point ab,ac;
    ab.x=b.x-a.x;
    ab.y=b.y-a.y;
    ac.x=c.x-a.x;
    ac.y=c.y-a.y;
    return fabs(cross(ab,ac))<EPS;
    
}
int main(){
    scanf("%d",&t);
   while(t--){
       scanf("%d",&n);
        segment sg;
        for(int i=0;i<n;i++){
            scanf("%lf %lf %lf %lf",&sg.st.x,&sg.st.y,&sg.ed.x,&sg.ed.y);
            if(sg.st.x>sg.ed.x){
                swap(sg.st,sg.ed);
            }
            segments[i]=sg;
            pointstoline(sg.st,sg.ed,lines[i]);
        }
        for(int i=0;i<n;i++){
            e[i].clear();
        }
        memset(mark,0,sizeof(mark));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                point p;
                if(areIntersect(i,j,p)){
                    if(check(segments[i],p)&&check(segments[j],p)){
                        e[i].push_back(j);
                        e[j].push_back(i);
                        continue;
                    }
                }
                
                if(check(segments[i],segments[j].st)&&colllinear(segments[i].st,segments[i].ed,segments[j].st)){
                    e[i].push_back(j);
                    e[j].push_back(i);
                    continue;
                }
                if(check(segments[i],segments[j].ed)&&colllinear(segments[i].st,segments[i].ed,segments[j].ed)){
                    e[i].push_back(j);
                    e[j].push_back(i);
                    continue;
                }
                if(check(segments[j],segments[i].st)&&colllinear(segments[j].st,segments[j].ed,segments[i].st)){
                    e[i].push_back(j);
                    e[j].push_back(i);
                    continue;
                }
                if(check(segments[j],segments[i].ed)&&colllinear(segments[j].st,segments[j].ed,segments[i].ed)){
                    e[i].push_back(j);
                    e[j].push_back(i);
                    continue;
                }
                 
                
            }
        }
        cc=0;
        for(int i=0;i<n;i++){
            if(!mark[i]){
                ++cc;
                dfs(i);
            }
        }
        int first,second;
        while(scanf("%d%d",&first,&second)==2){
            if(!first&&!second){break;}
                --first;--second;
            if(mark[first]==mark[second]){
               cout << "CONNECTED" << endl;
            }else{
                cout << "NOT CONNECTED" << endl;
            }
        }
       if(t){
           cout<<endl;
       }
    }
    
    
    
    
    return 0;//rev Ab steps
}
