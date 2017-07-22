/*
 pre: the best sum you can obtain provided the subarray starts from the leftmost index in the interval.
 suf: the best sum you can obtain provided the subarray ends at the rightmost index in the interval.
 mx: The largest subarray sum you can have in an interval.
 sum: Sum of all elements in the interval.
 
 
  https://www.quora.com/What-is-the-approach-for-solving-GSS1-and-GSS3-on-SPOJ-using-segment-trees
 

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
const int oo=1e7;
int n, a[50000],ty,x,y,ans;
struct node{
    int sum,pre,suf,mx;
};
node st[4*50001];
inline void pull(node&a,node&b,node&c){
    c.sum=a.sum+b.sum;
    c.mx=max(max(a.mx,c.sum),b.mx);
    c.mx=max(c.mx,a.suf+b.pre);
    c.mx=max(a.sum+b.pre,max(c.mx,b.sum+a.suf));
    c.mx=(max(a.pre,b.suf),max(max(c.mx,a.suf),b.pre));
    c.pre=max(a.pre,a.sum);
    c.pre=max(c.pre,max(a.sum+b.pre,c.sum));
    c.suf=max(b.suf,b.sum);
    c.suf=max(c.suf,max(b.sum+a.suf,c.sum));
}
void build(int idx,int l ,int r){
    if(l==r){
        st[idx].mx=st[idx].sum=st[idx].suf=st[idx].pre=a[l];
        return ;
    }
    build(idx<<1,l,(l+r)/2);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
void modify(int idx,int l,int r){
    if(l>x||r<x){
        return ;
    }
    if(l==x&&l==r){
        st[idx].mx=st[idx].sum=st[idx].suf=st[idx].pre=y;
        return ;
    }
    modify(idx<<1,l,(l+r)/2);
    modify((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
node get(int idx,int l,int r){
    if(l>y||r<x){
        node nn;
        nn.mx=nn.sum=nn.suf=nn.pre=-oo;
        return nn;
    }
    if(l>=x&&r<=y){
        return st[idx];
    }
    node ret;
    node lf=get(idx<<1,l,(l+r)/2);
    node ri=get((idx<<1)+1,(l+r)/2+1,r);
    pull(lf,ri,ret);
    return ret;
}


int main(){
    scanf("%d",&n);
    for(int i=0;i<n<<2;i++){
        st[i].mx=st[i].sum=st[i].pre=st[i].suf=-oo;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    build(1,0,n-1);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&ty,&x,&y);
        x--;
        if(ty){
            y--;
            if(x>y){
                swap(x,y);
            }
            node ret=get(1,0,n-1);
            printf("%d\n",ret.mx);
        }else{
            modify(1,0,n-1);
        }
    }
    return 0;
}
