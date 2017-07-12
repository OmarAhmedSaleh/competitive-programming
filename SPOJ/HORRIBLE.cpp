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
const long long OO=4e18;
const int oo=1e9;
const int MAX=100000<<2;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
int n,c,foo,ty,p,q,v,t;
long long st[100000<<2],lazy[100000<<2];
void pull(long long &a,long long &b,long long &c){
    c=a+b;
}
struct node{
    int ll,rr,id;
};
void push(node aa){
    if(aa.rr>=n){
        aa.rr=n-1;
    }
    if(aa.ll>=n){
        return;
    }
    int len=(aa.rr-aa.ll)+1;
    st[aa.id]+=1LL*len*lazy[aa.id];
    if((aa.id<<1)<MAX){
        lazy[aa.id<<1]+=lazy[aa.id];
        if((aa.id<<1)+1<MAX){
            lazy[(aa.id<<1)+1]+=lazy[aa.id];
        }
    }
    lazy[aa.id]=0;
}
void build(int idx,int l,int r){
    if(l==r){
        st[idx]=0;
        return;
    }
    build((idx<<1),l,(l+r)>>1);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
void update(int idx,int l,int r){
    node nn;nn.id=idx;nn.ll=l;nn.rr=r;
    if(lazy[idx]!=0){
        push(nn);
    }
    if(l>q||r<p){
        return ;
    }
    if(l>=p&&r<=q){
        lazy[idx]+=v;
        push(nn);
        return ;
    }
    update(idx<<1,l,(l+r)>>1);
    update((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
long long get(int idx,int l,int r){
    node nn;nn.id=idx;nn.ll=l;nn.rr=r;
    if(lazy[idx]!=0){
        push(nn);
    }
    if(l>q||r<p){
        return 0;
    }
    if(l>=p&&r<=q){
        return st[idx];
    }
    long long ret=0;
    long long ll=get(idx<<1,l,(l+r)>>1);
    long long rr=get((idx<<1)+1,(l+r)/2+1,r);
    ret=ll+rr;
    return ret;
}
int main(){
    scanf("%d",&t);
    while(t-->0){
        memset(lazy,0,sizeof(lazy));
        memset(st,0,sizeof(st));
        scanf("%d%d",&n,&c);
        build(1,0,n-1);
        while(c--){
            scanf("%d%d%d",&ty,&p,&q);
            if(p>q){swap(p,q);}
            p--;q--;
            if(ty){
                printf("%lld\n",get(1,0,n-1));
            }else{
                scanf("%d",&v);
                update(1,0,n-1);
            }
        }
    }
    return 0;
}
