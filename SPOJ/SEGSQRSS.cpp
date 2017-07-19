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
//const int oo=1e9;
const int MAX=100000<<2;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
struct node{
    int x,sum,set_same;
    long long sum_sq;
    void def(){
        x=sum=set_same=sum_sq=0;
        set_same=1111;
    }
};
node st[MAX];
int a,s,e,xx,same,ty,tc,n,m;
void pull(node &a, node &b,node &c){
    c.sum=a.sum+b.sum;
    c.sum_sq=a.sum_sq+b.sum_sq;
}
void push(int &idx,int &l,int &r){
    if(st[idx].x!=0){
        st[idx].sum_sq+=1LL*2*st[idx].x*st[idx].sum;
        st[idx].sum_sq+=1LL*st[idx].x*st[idx].x*(r-l+1);
    }
    if(st[idx].set_same!=1111){
        st[idx].sum=(r-l+1)*st[idx].set_same;
        st[idx].sum_sq=1LL*st[idx].set_same*st[idx].set_same*(r-l+1);
    }
    if(idx<<1<MAX){
        st[idx<<1].x+=st[idx].x;
        st[idx<<1].set_same=st[idx].set_same;
    }
    if((idx<<1)+1<MAX){
        st[(idx<<1)+1].x+=st[idx].x;
        st[(idx<<1)+1].set_same=st[idx].set_same;
    }
    st[idx].x=0,st[idx].set_same=1111;
}
void build(int idx,int l,int r){
    st[idx].def();
    if(l==r){
        scanf("%d",&a);
        st[idx].sum=a;
        st[idx].sum_sq=1LL*a*a;
        return ;
    }
    build((idx<<1),l,(l+r)>>1);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
long long get(int idx,int l ,int r){
    if(st[idx].x||st[idx].set_same!=1111){
        push(idx,l,r);
    }
    if(l>e||r<s){
        return 0;
    }
    if(l>=s&&r<=e){
        return st[idx].sum_sq;
    }
    return get((idx<<1),l,(l+r)>>1)+get((idx<<1)+1,(l+r)/2+1,r);
}
void up(int idx,int l,int r){
    if(st[idx].x||st[idx].set_same!=1111){
        push(idx,l,r);
    }
    if(l>e||r<s){
        return ;
    }
    if(l>=s&&r<=e){
        st[idx].x+=xx;
        if(same!=1111){
            st[idx].set_same=same;
        }
        push(idx,l,r);
        return ;
    }
    up(idx<<1,l,(l+r)>>1);
    up((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}

int main(){
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++){
        printf("Case %d:\n",tt);
        scanf("%d%d",&n,&m);
        build(1,0,n-1);
        for(int i=0;i<m;i++){
            xx=0;same=1111;
            scanf("%d%d%d",&ty,&s,&e);
            if(s>e){swap(s,e);}
            s--;e--;
            if(ty==2){
                printf("%lld\n",get(1,0,n-1));
                continue;

            }
            if(!ty){
                scanf("%d",&same);
            }else{
                scanf("%d",&xx);
            }
            up(1,0,n-1);
        }
    }
    return 0;
}
