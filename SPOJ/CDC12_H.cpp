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
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
const int MAX=100000<<2;
struct node{
    int lazy,l,r;
    long long sum;
    node(){
        lazy=sum=0;
    }
};
node st[MAX];
void push(int idx){
    st[idx].sum+=1LL*(st[idx].r-st[idx].l+1)*st[idx].lazy;
    if((idx<<1)<MAX){
        st[idx<<1].lazy+=st[idx].lazy;
    }
    if((idx<<1)+1<MAX){
        st[(idx<<1)+1].lazy+=st[idx].lazy;
    }
    st[idx].lazy=0;
}
void pull(node &a,node&b,node&c){
    c.sum=a.sum+b.sum;
}
void build(int idx,int l, int r){
    st[idx].l=l,st[idx].sum=0,st[idx].r=r,st[idx].lazy=0;
    if(l==r){
        return ;
    }
    build(idx<<1,l,(l+r)/2);
    build((idx<<1)+1,(l+r)/2+1,r);
}
int s,e;
void modi(int idx,int l, int r){
    if(st[idx].lazy){
        push(idx);
    }
    if(l>e||r<s){
        return ;
    }
    if(l>=s&&r<=e){
        st[idx].lazy++;
        push(idx);
        return ;
    }
    modi(idx<<1,l,(l+r)/2);
    modi((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
node get(int idx,int l, int r){
    node ret;
    if(st[idx].lazy){
        push(idx);
    }
    if(l>e||r<s){
        return ret;
    }
    if(l>=s&&r<=e){
        return st[idx];
    }
    node a=get(idx<<1,l,(l+r)/2);
    node b=get((idx<<1)+1,(l+r)/2+1,r);
    pull(a,b,ret);
    return ret;
}
int n , q,tc;
char c[15];
int main(){
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++){
        scanf("%d%d",&n,&q);
        build(1,0,n-1);
        printf("Scenario #%d:\n",tt);
        while(q-->0){
            scanf("%s%d%d",c+1,&s,&e);
         //   cout<<c[1]<<" "<<s<<" "<<e<<endl;
            s--;e--;
            if(c[1]=='a'){
                printf("%lld\n",get(1,0,n-1).sum);
            }else{
                modi(1,0,n-1);
                printf("OK\n");
            }
        }
    }
    
    return 0;
}
