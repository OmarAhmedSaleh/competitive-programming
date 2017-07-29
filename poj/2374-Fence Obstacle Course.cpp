/*
 https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=774
    see Figure 1 to understand
 
 brute forces solution:
    you are at segment i , then you can move to point (l[i],i) or (r[i],i)
        then you can move down toward x-axis until you hit another segment
    let interval from a[i] to b[i] belong to segment i
 
 
 O(n^2)
 for(int i=1;i<=n;i++){
     int j=0;
     cin>>a[i]>>b[i];
     int x=b[i];
        j=seg[b[i]];
    // connect segment i with segment j
        j=seg[a[i]];
    // connect segment i with segment j
 for(int k=a[i];k<=b[i];k++){
        // cover
        seg[k]=i;
    }
 }
 optimization
 O(N*log(N))
    you can remove this loop and use segment tree to cover this interval
    for(int k=a[i];k<=b[i];k++){
            // cover
            seg[k]=j;
    }
 After connecting all segments try to get shortest path
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
const double EPS=1e-8;
const int N=200005;
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
const int R=100000;
int st[4*N];
int lazy[4*N];
int n , a[N], b[N], s;
int dis[N][2];
void build(int idx,int l ,int r){
    if(l==r){
        st[idx]=0;
        return ;
    }
    int le=idx<<1;
    int ri=le+1;
    int mid=(l+r)/2;
    build(le,l,mid);
    build(ri,mid+1,r);
}
int f;
void get(int idx,int l ,int r, int val){
    int le=idx<<1;
    int ri=le+1;
    int mid=(l+r)/2;
    if(lazy[idx]!=-1){
        st[idx]=lazy[ri]=lazy[le]=lazy[idx];
        lazy[idx]=-1;
    }
    if(l>val||r<val){
        return ;
    }
    if(val==l&&val==r){
        f=st[idx];
        return ;
    }
    get(le,l,mid,val);
    get(ri,mid+1,r,val);
}
void update(int idx,int l,int r,int i ,int j,int val){
    int le=idx<<1;
    int ri=le+1;
    int mid=(l+r)/2;
    if(lazy[idx]!=-1){
        st[idx]=lazy[ri]=lazy[le]=lazy[idx];
        lazy[idx]=-1;
    }
    if(l>j||r<i){
        return ;
    }
    if(l>=i&&r<=j){
        st[idx]=val;
        lazy[le]=val;
        lazy[ri]=val;
        return ;
    }
    
    update(le,l,mid,i,j,val);
    update(ri,mid+1,r,i,j,val);
}


int main(){
    scanf("%d%d",&n,&s);
    s+=R;
    memset(lazy,-1,sizeof(lazy));
    build(1,0,200005);
        for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        a[i]+=R;
        b[i]+=R;
        f=-1;
        get(1,0,200005,b[i]);
        if(!f){
            dis[i][1]=abs(b[i]-R);
        }
        if(f>0){
            dis[i][1]=min(dis[f][1]+abs(b[i]-b[f]),dis[f][0]+abs(b[i]-a[f]));
            
        }
        f=-1;
        get(1,0,200005,a[i]);
        if(!f){
            dis[i][0]=abs(a[i]-R);
        }
        if(f>0){
            dis[i][0]=min(dis[f][1]+abs(a[i]-b[f]),dis[f][0]+abs(a[i]-a[f]));
            
        }
        update(1,0,200005,a[i],b[i],i);
    }
    
    int ans=min(dis[n][1]+abs(s-b[n]),dis[n][0]+abs(s-a[n]));
    printf("%d\n",ans);
    return 0;//rev Ab steps
}
