/*
 steps:
 1- we can see that Memory cluster ai as subset of bits
 2- for each array with size 2^bi find (bit >=bi)
    - if there is bit == bi , then remove it and ans++;
    - if there is bit > bi , remove it and add new memory cluser = 2^bit - 2^bi (rep step 1)
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
int n ,m,foo;
const int oo=1e9;
int p[33];
int a[1000000];

int st[150],cnt[33];
void pull(int idx){
    st[idx]=min(st[idx+idx],st[idx+idx+1]);
}
int query(int idx,int l ,int r, int i , int j){
    if(l>j||r<i){
        return oo;
    }
    if(l>=i&&r<=j){
        return st[idx];
    }
    return min(query(idx+idx,l,(r+l)/2,i,j),query(idx+idx+1,(r+l)/2+1,r,i,j));
}
void update(int idx,int l ,int r,int i,int j,int val){
    if(l>j||r<i){
        return ;
    }
    if(l==r&&l==i){
        cnt[l]+=val;
        if(cnt[l]==0){
            st[idx]=oo;
        }else{
            st[idx]=l;
        }
        return ;
    }
    update(idx+idx,l ,(r+l)/2,i,j,val);
    update(idx+idx+1,(r+l)/2 +1,r,i,j,val);
    pull(idx);
}
void get(int x){
    int bit=0;
    while(x){
        if(x&1){
            if(cnt[bit]){
                cnt[bit]++;
            }else{
                update(1,0,30,bit,bit,1);
            }
        }
        x>>=1;
        bit++;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<150;i++){
        st[i]=oo;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&foo);
        get(foo);
    }
    p[0]=1;
    for(int i=1;i<=30;i++){
        p[i]=p[i-1]<<1;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+m);
    int ans=0;
    for(int i=0;i<m;i++){
        int mn=query(1,0,30,a[i],30);
        if(mn==oo){
            break;
        }
        ans++;
        if(cnt[mn]==1){
            update(1,0,30,mn,mn,-1);
        }else{
            cnt[mn]--;
        }
        if(mn>a[i]){
            get(p[mn]-p[a[i]]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
