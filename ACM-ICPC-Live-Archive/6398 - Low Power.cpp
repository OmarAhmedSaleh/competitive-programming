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
int n,k,a[1000006],sz;
bool valid(int d){
    int cur=0;
    int done=0;
    for(int i=0;i<sz;i++){
        if(i<sz&&a[i+1]-a[i]<=d){
            i++;
            cur+=2*(k-1);
            done++;
            if(done==n){return 1;}
        }else{
            if(!cur){
                return 0;
            }
            cur--;
        }
    }
    return 1;
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        sz=2*n*k;
        for(int i=0;i<sz;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+sz);
        int ans=0;
        int lo=0,hi=1e9;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(valid(mid)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
