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
    while(all[idx].size()<4){
        all[idx].back().first-=a;
        all[idx].back().second-=b;
        all[idx].push_back(make_pair(-all[idx].back().second,all[idx].back().first));
        all[idx].back().first+=a;
        all[idx].back().second+=b;
        
    }
    for(int i=0;i<3;i++){
        all[idx][i].first+=a;
        all[idx][i].second+=b;
    }
    for(int i=0;i<4;i++){
        all[idx][i].first*=4;
        all[idx][i].second*=4;
    }
}
int ans=oo;
int dot(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    return (b.first-a.first)*(c.first-a.first)+(b.second-a.second)*(c.second-a.second);
}
int cross(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}
long long dis(pair<int,int> a, pair<int,int> b){
    return 1LL*(b.first-a.first)*(b.first-a.first)+1LL*(b.second-a.second)*(b.second-a.second);
}
void get(){
    // mid point
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    if(i+j+k+l>ans){break;}
                    vector<pair<int,int> >v;
                    v.push_back(all[0][i]);
                    v.push_back(all[1][j]);
                    v.push_back(all[2][k]);
                    v.push_back(all[3][l]);
                    int mx=(all[0][i].first+all[1][j].first+all[2][k].first+all[3][l].first)/4;
                    int my=(all[0][i].second+all[1][j].second+all[2][k].second+all[3][l].second)/4;
                    long long d0=dis(make_pair(mx,my),v[0]);
                    bool br=0;
                    for(int kk=0;kk<4;kk++){
                        if(d0!=dis(make_pair(mx,my),v[kk])){
                            br=1;
                            break;
                        }
                    }
                    // same point
                    for(int kk=0;kk<4;kk++){
                        for(int jj=kk+1;jj<4;jj++){
                            if(dis(v[kk],v[jj])==0){
                                br=1;
                                break;
                            }
                        }
                    }
                    for(int kk=0;kk<4;kk++){
                        for(int jj=kk+1;jj<4;jj++){
                            // 90 or 180
                            if(dot(make_pair(mx,my),v[kk],v[jj])!=0 && cross(make_pair(mx,my),v[kk],v[jj])!=0 ){
                                    br=1;
                                    break;
                                    
                            }
                        }
                    }
                    if(br){continue;}
                    ans=min(ans,i+j+k+l);
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
