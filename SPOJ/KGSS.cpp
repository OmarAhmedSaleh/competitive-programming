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
struct node{
    int mx,b[2];
};
node st[100000<<2];

int n,a[100000];
void pull(node &aa,node&bb,node&c){
    vector<int> v;
    v.push_back(aa.b[0]);
    v.push_back(aa.b[1]);
    v.push_back(bb.b[0]);
    v.push_back(bb.b[1]);
    sort(v.begin(),v.end());
    c.b[0]=v.back();v.pop_back();c.b[1]=v.back();v.pop_back();
    c.mx=c.b[0]+c.b[1];
    return ;
}
void build(int idx,int l,int r){
    if(l==r){
        st[idx].b[0]=a[l];
        st[idx].b[1]=-1;
        return ;
    }
    build(idx<<1,l,(l+r)/2);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
int x, y;
void modify(int idx,int l,int r){
    if(l>x||r<x){
        return ;
    }
    if(l==r&&l==x){
        a[x]=y;
        st[idx].b[0]=y;
        st[idx].b[1]=-1;
        return ;
    }
    modify(idx<<1,l,(l+r)/2);
    modify((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
    return ;
}
node get(int idx,int l,int r){
    node ret;
    if(l>y||r<x){
        ret.b[0]=ret.b[1]=-1;
        return ret;
    }
    if(l>=x&&r<=y){
        return st[idx];
    }
    node ll=get(idx<<1,l,(l+r)/2);
    node rr=get((idx<<1)+1,(l+r)/2+1,r);
    pull(ll,rr,ret);
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    build(1,0,n-1);
    int q;
    scanf("%d",&q);
    char c;
    while(q--){
        scanf(" %c%d%d",&c,&x,&y);
        x--;
        if(c=='U'){
            modify(1,0,n-1);
        }else{
            y--;
            printf("%d\n",get(1,0,n-1).mx);
        }
    }
    return 0;
}
