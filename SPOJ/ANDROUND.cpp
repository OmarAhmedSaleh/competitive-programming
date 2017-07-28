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
/*
 const long long OO=4e18;
 const int oo=1e9;
 int dx[8]={1,-1,0,0,1,-1,1,-1};
 int dy[8]={0,0,-1,1,1,-1,-1,1};
 */
long long lim=(1<<30) -1;
const int MAX=20000<<2;
struct node{
    int lazy;
    long long val;
    node(){
        lazy=0;val=0;
    }
};
int n , k, s, e, q,a;
node st[MAX];
void pull(node &a ,node &b,node &c){
    c.val=a.val&b.val;
}
void push(int idx){
    st[idx].val|=st[idx].lazy;
    if(idx<<1 < MAX){
        st[idx<<1].lazy|=st[idx].lazy;
    }
    if((idx<<1)+1< MAX){
        st[(idx<<1)+1].lazy|=st[idx].lazy;
    }
    st[idx].lazy=0;
}
void build(int idx,int l ,int r){
    if(l==r){
        scanf("%d",&a);
        st[idx].val=a;
        return ;
    }
    build(idx<<1,l,(l+r)>>1);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
    
}
vector<pair<int,pair<int,int> > > all;
long long get(int idx,int l, int r){
    if(st[idx].lazy){
        push(idx);
    }
    // cout<<idx<<" "<<l<<" "<<r<<" "<<st[idx].val<<" "<<s<<" "<<e<<endl;
    if(l>e||r<s){
        return lim;
    }
    if(l>=s&&r<=e){
        return st[idx].val;
    }
    long long a=get(idx<<1,l,(l+r)>>1);
    long long b=get((idx<<1)+1,(l+r)/2+1,r);
    long long ret=a&b;
    return ret;
}
int t;
int main(){
    scanf("%d",&t);
    while(t-->0){
        scanf("%d%d",&n,&k);
        build(1,0,n-1);
        for(int i=0;i<n;i++){
            s=i;e=min(i+k,n-1);
            long long ret=get(1,0,n-1);
            if(i+k>=n){

                int kk=k;
                kk-=(n-1)-i;
                kk--;
                s=0;e=min(i,kk);
                ret&=get(1,0,n-1);

            }
            e=i;s=max(i-k,0);
            ret&=get(1,0,n-1);
            if(k>i){
                int kk=k;
                kk-=i;
                kk--;
                e=n-1;s=max(n-1-kk,i);
                ret&=get(1,0,n-1);
               // cout<<s<<" "<<e<<" "<<i<<endl;

            }
            if(i){cout<<" ";}
            cout<<ret;
        }
        cout<<endl;
    }
    return 0;
}
