/*
 
 
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
//const long long OO=4e18;
const int MAX=100000<<2;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
int n , q ;
pair<int,int> st[MAX];
bool lazy[MAX];
void pull(pair<int,int> &a,pair<int,int > &b, pair<int,int > &c){
    c.first=a.first+b.first;
    c.second=a.second+b.second;
}
void swap(int idx){
    swap(st[idx].first,st[idx].second);
    if(idx<<1 < MAX){
        lazy[idx<<1]^=1;
    }
    if((idx<<1)+1 < MAX){
        lazy[(idx<<1)+1]^=1;
    }
    lazy[idx]=0;
}
void build(int idx,int l,int r){
    if(l==r){
        st[idx].first=1;
        return ;
    }
    build(idx<<1,l,(l+r)/2);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
int x,y,ty;
void modify(int idx,int l,int r){
    if(lazy[idx]){
        swap(idx);
    }
    if(l>y || r<x){
        return ;
    }
    if(l>=x && r<=y){
        lazy[idx]=1;
        swap(idx);
        return ;
    }
    modify(idx<<1,l,(l+r)/2);
    modify((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
pair<int,int>  get(int idx,int l,int r){
    if(lazy[idx]){
        swap(idx);
    }
    pair<int,int> ret{0,0};
    if(l>y || r<x){
        return ret;
    }
    if(l>=x && r<=y){
        return st[idx];
    }
    pair<int,int> a=get(idx<<1,l,(l+r)/2);
    pair<int,int> b=get((idx<<1)+1,(l+r)/2+1,r);
    pull(a,b,ret);
    return ret;
}
int main(){
    scanf("%d%d",&n,&q);
    build(1,0,n-1);
    while(q--){
        scanf("%d%d%d",&ty,&x,&y);
        if(ty){
            printf("%d\n",get(1,0,n-1).second);
        }else{
            modify(1,0,n-1);
        }
    }
    
    return 0;
}
