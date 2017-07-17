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
const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
const int MAX=100000<<2;
struct node{
    int cnt[3];
};
node st[MAX];
int lazy[MAX], n, m, ty, s,e;
void pull(node &a,node &b,node &c){
    for(int i=0;i<3;i++){
        c.cnt[i]=a.cnt[i]+b.cnt[i];
    }
}
void push(int idx){
    lazy[idx]%=3;
    if(!lazy[idx]){return ;}
    int old[3];
    for(int i=0;i<3;i++){
        old[i]=st[idx].cnt[i];
        st[idx].cnt[i]=0;
    }
    for(int i=0;i<3;i++){
        st[idx].cnt[i]=old[(lazy[idx]+i)%3];
    }
    if(idx<<1 < MAX){
        lazy[idx<<1]+=lazy[idx];
    }
    if((idx<<1)+1 < MAX){
        lazy[(idx<<1)+1]+=lazy[idx];
    }
    lazy[idx]=0;
}
void build(int idx,int l,int r){
    for(int i=0;i<3;i++){
        st[idx].cnt[i]=0;
    }
    if(l==r){
        st[idx].cnt[0]=1;
        return ;
    }
    build((idx<<1),l,(l+r)/2);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
void modify(int idx,int l,int r){
    if(lazy[idx]!=0){
        push(idx);
    }
    if(r<s||l>e){
        return ;
    }
    if(l>=s&&r<=e){
        lazy[idx]++;
        push(idx);
        return ;
    }
    modify((idx<<1),l,(l+r)/2);
    modify((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
node get(int idx,int l,int r){
    if(lazy[idx]!=0){
        push(idx);
    }
    node ret;
    for(int i=0;i<3;i++){
        ret.cnt[i]=0;
    }
    if(r<s||l>e){
        return ret;
    }
    if(l>=s&&r<=e){
        return st[idx];
    }
    node a=get((idx<<1),l,(l+r)/2);
    node b=get((idx<<1)+1,(l+r)/2+1,r);
    pull(a,b,ret);
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    build(1,0,n-1);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&ty,&s,&e);
        if(ty){
            printf("%d\n",get(1,0,n-1).cnt[0]);
        }else{
            modify(1,0,n-1);
        }
    }
    return 0;
}
