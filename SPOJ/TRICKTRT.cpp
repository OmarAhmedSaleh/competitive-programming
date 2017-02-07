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
using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

const int N=50002;
const double EPS=1e-9;
double x[N],y[N];
int n;
double dis(double xx,int i){
    
    return sqrt((xx-x[i])*(xx-x[i])+(0-y[i])*(0-y[i]));
}
double cal(double q){
    double ret=-1;
    for(int i=0;i<n;i++){
        // cout<<dis(q,i)<<endl;
        ret=max(ret,dis(q,i));
    }
    return ret;
}
int main(){
    while(scanf("%d",&n)==1){
        if(!n){
            break;
        }
        double l=20000001;
        double r=-20000001;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&x[i],&y[i]);

            l=min(l,x[i]);
            r=max(r,x[i]);
        }
        double ans[2]={r+r,r+r};
        for(int i=0;i<60;i++){
            double each=(r-l)/3;
            double lf=l+each;
            double ri=r-each;
            double ret1=cal(lf);
            double ret2=cal(ri);
            if(ret1<ret2){
                if(ret1<ans[1]){
                    ans[0]=lf;
                    ans[1]=ret1;
                }
                r=ri;
            }else{
                if(ret2<ans[1]){
                    ans[1]=ret2;
                    ans[0]=ri;
                }
                l=lf;
            }
            
            
        }
        
        printf("%.5lf %.5lf\n",ans[0],ans[1]);
    }
    
    
    
    
    return 0;//rev Ab steps
}
