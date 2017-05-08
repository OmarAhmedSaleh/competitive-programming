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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int n,l[8],r[8],a[8];
bool valid(double x){
    double cur=l[a[0]];
    for(int i=1;i<n;i++){
        double nw=(double)x+cur;
        if(nw<l[a[i]]){
            nw=l[a[i]];
        }
        if(nw>r[a[i]]){
            return 0;
        }
        cur=nw;
    }
    return 1;
}
int tt=1;
int main(){
    while(scanf("%d",&n)==1){
        if(!n){break;}
        for(int i=0;i<n;i++){
            scanf("%d%d",&l[i],&r[i]);
            a[i]=i;
            l[i]*=60;
            r[i]*=60;
        }
        double ans=-1;
        do{
            double lo=0,hi=100000;
            int it=0;
            while(it<50){
                it++;
                double mid=(hi+lo)/2.0;
                if(valid(mid)){
                    ans=max(ans,mid);
                    lo=mid;
                }else{
                    hi=mid;
                }
            }
        }while(next_permutation(a,a+n));
        ans+=.5;
        int ti=ans;
        printf("Case %d: %d:%.2d\n",tt++,ti/60,ti%60);
    }
    return 0;
}
