/**/

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
//const long long OO=4e18;
//const int MAX=100000<<2;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
int a , b,all;
long long solve(int x){
    long long cal=0;
    pair<int,int> op[3]={{100,2},{(10000-101)+1,3},{(1000000-10001)+1,5}};
    for(int i=0;i<3;i++){
        int mn=min(op[i].first,x);
        x-=mn;
        cal+=1LL*mn*op[i].second;
    }
    cal+=1LL*x*7;
    return cal;
}
bool ok(int x){
    long long cal=solve(x);
    if(cal==a){all=x;}
    return cal<a;
}
int main(){
    while(scanf("%d%d",&a,&b)==2 && a && b){
        int l=1,h=1e9;
        bool br=0;
        all=-1;
        while(l<=h&&!br){
            int mid=l+(h-l)/2;
            if(l==h){br=1;}
            if(ok(mid)){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        l=0,h=all;
        br=0;
        int ans=-1;
        while(l<=h&&!br){
            int mid=l+(h-l)/2;
            if(l==h){br=1;}
            long long A=solve(mid),B=solve(all-mid);
            if(abs(A-B)==b){ans=min(mid,all-mid);break;}
            if(abs(A-B)<b){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        cout<<solve(ans)<<endl;
    }
    return 0;
}
