/*
 
 rotate a point counter clockwise 90 degrees

 (x,y) = (-y,x)
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
const int oo=1e9;
const double EPS=1e-9;

typedef complex<double> point;
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
vector< pair<int,int> > all[4];
int x,y,a,b,n;
void fun(int idx){

    while(all[idx].size()<5){
        all[idx].back().first-=a;
        all[idx].back().second-=b;
        all[idx].push_back(make_pair(-all[idx].back().second,all[idx].back().first));
        all[idx].back().first+=a;
        all[idx].back().second+=b;
        
    }
    for(int i=0;i<4;i++){
        all[idx][i].first+=a;
        all[idx][i].second+=b;
    }
}
int ans=oo;
int dot(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    // same point
    if(a.first==b.first && a.second==b.second){
        return 1;
    }
    if(a.first==c.first && a.second==c.second){
        return 1;
    }
    if(c.first==b.first && c.second==b.second){
        return 1;
    }
    return (b.first-a.first)*(c.first-a.first)+(b.second-a.second)*(c.second-a.second);
}
long long dis(pair<int,int> a, pair<int,int> b){
    return 1LL*(b.first-a.first)*(b.first-a.first)+1LL*(b.second-a.second)*(b.second-a.second);
}
void get(){
    // u-l , d-l , u-r , d-r
    vector< pair<int,pair<int,int> > > v;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                for(int l=0;l<5;l++){
                    v.clear();
                    v.push_back(make_pair(i,all[0][i]));
                    v.push_back(make_pair(j,all[1][j]));
                    v.push_back(make_pair(k,all[2][k]));
                    v.push_back(make_pair(l,all[3][l]));
                    sort(v.begin(),v.end());
                    do{
                        bool br=0;
                        long long d[4];
                            for(int w=0;w<4;w++){
                                d[w]=dis(v[w].second,v[(w+1)%4].second);
                                if(dot(v[w].second,v[(w+3)%4].second,v[(w+1)%4].second)!=0){
                                    br=1;
                                }
                            }
                       
                        if(br){continue;}
                        sort(d,d+4);
                        if(d[3]!=d[0]){
                           continue;
                        }
                        ans=min(ans,v[0].first+v[1].first+v[2].first+v[3].first);
                    }while(next_permutation(v.begin(),v.end()));
                }
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            all[j].clear();
            scanf("%d%d%d%d",&x,&y,&a,&b);
            all[j].push_back(make_pair(x,y));
            fun(j);
        }
        ans=oo;
        get();
        if(ans==oo){
            ans=-1;
        }
        printf("%d\n",ans);
    }
    return 0;//rev Ab steps
}
