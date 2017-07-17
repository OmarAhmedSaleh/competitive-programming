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
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
const int MAX=100000<<2;
struct node{
    int mx,mn;
};
node st[MAX];
int lazy[MAX];
void pull(node &a,node &b,node &c){
    c.mn=min(a.mn,b.mn);
    c.mx=max(a.mx,b.mx);
}
void push(int idx){
    st[idx].mx=st[idx].mn=lazy[idx];
    if(idx<<1 < MAX){
        lazy[idx<<1]=lazy[idx];
    }
    if((idx<<1)+1<MAX){
        lazy[(idx<<1)+1]=lazy[idx];
    }
    lazy[idx]=0;
}
void build(int idx,int l,int r){
    if(l==r){
        st[idx].mn=st[idx].mx=0;
        return ;
    }
    build((idx<<1),l,(l+r)/2);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
int ans,s,e,h,tc,n;
void modify(int idx,int l, int r){
    if(lazy[idx]!=0){
        push(idx);
    }
    if(l>e||r<s){
        return ;
    }
    if(l>=s&&r<=e&&st[idx].mx<h){
        lazy[idx]=h;
        push(idx);
        return ;
    }
    if(l>=s&&r<=e&&st[idx].mn>=h){
        return ;
    }
    modify((idx<<1),l,(l+r)/2);
    modify((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
void get(int idx,int l, int r){
    if(lazy[idx]!=0){
        push(idx);
    }
    if(l>e||r<s){
        return ;
    }
    if(l>=s&&r<=e&&st[idx].mx<=h){
        ans+=r-l+1;
        return ;
    }
    if(l>=s&&r<=e&&st[idx].mn>h){
        return ;
    }
    get((idx<<1),l,(l+r)/2);
    get((idx<<1)+1,(l+r)/2+1,r);
}

int main(){
    scanf("%d",&tc);
    while(tc--){
        memset(lazy,0,sizeof(lazy));
        scanf("%d",&n);
        build(1,0,99999);
        ans=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&s,&e,&h);
            s--;e-=2;
            get(1,0,99999);
            modify(1,0,99999);
        }
        printf("%d\n",ans);
    }
    return 0;
}
