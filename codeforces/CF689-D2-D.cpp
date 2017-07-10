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
class SegmentTree{
public:
    int ans,a[200000],st[800000],i,j;
    
    void pull(int idx){
        st[idx]=min(st[idx<<1],st[(idx<<1)+1]);
    }
    void build(int idx,int l,int r){
        if(l==r){
            st[idx]=a[l];
            return ;
        }
        build(idx<<1,l,(l+r)>>1);
        build((idx<<1)+1,(l+r)/2 +1,r);
        pull(idx);
    }
    void get(int idx,int l,int r){
        if(l>j||r<i){
            return ;
        }
        if(l>=i&&r<=j){
            ans=min(ans,st[idx]);
            return ;
        }
        get(idx<<1,l,(l+r)>>1);
        get((idx<<1)+1,(l+r)/2 +1,r);
    }
};
int n ;
SegmentTree S[2];
inline pair<int,int> cal(int x ,int y){
    int ret[2];
    for(int i=0;i<2;i++){
        S[i].ans=1e9;S[i].ans+=99;
        S[i].i=x;S[i].j=y;
        S[i].get(1,0,n-1);
        ret[i]=S[i].ans;
    }
    return make_pair(ret[0],ret[1]);
}
int bs_last(int x){
    int l=0,r=(n-1)-x,ret=-1;
    pair<int,int> c;
    bool br=0;
    while(l<=r&&!br){
        int mid=l+(r-l)/2;
        if(l==r){
            br=1;
            c=cal(x,x+l);
        }else{
            c=cal(x,x+mid);
        }
        if(-c.first>c.second){
            r=mid-1;
            continue;
        }
        if(-c.first<c.second){
            l=mid+1;
            continue;
        }
        if(-c.first==c.second){
            l=mid+1;
            ret=max(ret,mid);
            continue;
        }
    }
    return ret;
}
int bs_first(int x){
    int l=0,r=(n-1)-x,ret=1e9;
    pair<int,int> c;
    bool br=0;
    while(l<=r&&!br){
        int mid=l+(r-l)/2;
        if(l==r){
            br=1;
            c=cal(x,x+l);
        }else{
            c=cal(x,x+mid);
        }
        if(-c.first>c.second){
            r=mid-1;
            continue;
        }
        if(-c.first<c.second){
            l=mid+1;
            continue;
        }
        if(-c.first==c.second){
            r=mid-1;
            ret=min(ret,mid);
            continue;
        }
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    int si=-1;
    for(int j=0;j<2;j++){
        for(int i=0;i<n;i++){
            scanf("%d",&S[j].a[i]);
            S[j].a[i]*=si;
        }
        si=1;
        S[j].build(1,0,n-1);
    }
    long long ans=0;
    pair<int,int> range;
    for(int i=0;i<n;i++){
        range.first=bs_first(i);
        range.second=bs_last(i);
        if(range.first==1e9||range.second==-1){
            continue;
        }
        ans+=range.second-range.first+1;
    }
    printf("%lld\n",ans);
    return 0;
}
