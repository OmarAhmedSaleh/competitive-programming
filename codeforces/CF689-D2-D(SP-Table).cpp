/*
 First of all it is easy to see that if we fix l then have
 max(from i=l, to r)ai - min(from i=l, to r) bi <= max(from i=l, to r+1)ai - min(from i=l, to r+1) bi
 
 . So we can just use binary search to find the smallest index rmin and biggest index rmax that satisfy the equality and add rmax - rmin + 1 to our answer. To find the min and max values on a segment [l, r] we can use Range-Minimum Query data structure.
 
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
int n , a[200000],b[200000],st[2][18][200000],low,high,ll,rr,mx,mn,lg[200001];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        lg[i]=log2(i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++){
        st[0][0][i]=a[i];
        st[1][0][i]=b[i];
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i<n;i++){
            st[0][j][i]=st[0][j-1][i];
            st[1][j][i]=st[1][j-1][i];
            if(i+(1<<(j-1))<n){
                st[0][j][i]=max(st[0][j][i],st[0][j-1][i+(1<<(j-1))]);
                st[1][j][i]=min(st[1][j][i],st[1][j-1][i+(1<<(j-1))]);
            }
            
        }
    }
    bool br=0;
    int idx[2];
    for(int i=0;i<n;i++){
        idx[0]=idx[1]=-1;
        ll=i,rr=n-1;
        br=0;
        while(!br&&ll<=rr){
            mx=-1,mn=1e9;
            int mid=ll+(rr-ll)/2;
            if(ll==rr){
                br=1;
            }
            int len=(mid-i)+1;
            mx=max(st[0][lg[len]][i],st[0][lg[len]][i+len-(1<<lg[len])]);
            mn=min(st[1][lg[len]][i],st[1][lg[len]][i+len-(1<<lg[len])]);
            if(mx>mn){
                rr=mid-1;
                continue;
            }
            if(mx<mn){
                ll=mid+1;
                continue;
            }
            if(mx==mn){
                idx[0]=mid;
                rr=mid-1;
            }
        }
        br=0;
        ll=i,rr=n-1;
        while(!br&&ll<=rr){
            mx=-1,mn=1e9;
            int mid=ll+(rr-ll)/2;
            if(ll==rr){
                br=1;
            }
            int len=mid-i+1;
            mx=max(st[0][lg[len]][i],st[0][lg[len]][i+len-(1<<lg[len])]);
            mn=min(st[1][lg[len]][i],st[1][lg[len]][i+len-(1<<lg[len])]);
            if(mx>mn){
                rr=mid-1;
                continue;
            }
            if(mx<mn){
                ll=mid+1;
                continue;
                
            }
            if(mx==mn){
                idx[1]=mid;
                ll=mid+1;
                continue;
                
            }
        }
        if(idx[0]==-1){continue;}
        ans+=idx[1]-idx[0]+1;
    }
    printf("%lld\n",ans);
    return 0;
}
