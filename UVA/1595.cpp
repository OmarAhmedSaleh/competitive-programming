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
const int N=100005;
typedef complex<double> point;
#define X real()
#define Y imag()
#define cp(a,b) (conj(a)*b).imag()
#define dp(a,b) (conj(a)*b).real()
#define lengthsq(a)    dp(a,a)
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int t,n,x,y;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<point> pts;
        int mn=100000001;
        int mx=-mn;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            mn=min(mn,x);
            mx=max(mx,x);
            pts.push_back(point(x,y));
        }
        map<pair<int,int> ,int> mp;
        int dmid=mn+mx;
        for(int i=0;i<n;i++){
            mp[make_pair((int)(2*pts[i].X-dmid),pts[i].Y)]=1;
        }
        bool bad=0;
        for(int i=0;i<n;i++){
            if(!mp.count(make_pair(-(2*pts[i].X-dmid),pts[i].Y))){
                bad=1;
                break;
            }
        }
        if(bad){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        
    }
    
    
    
    
    return 0;//rev Ab steps
}
