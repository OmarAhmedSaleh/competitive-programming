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
const int MAX=100000<<2;
int n , k, t, v;
struct node {
    int mn , mx;
};
node st[MAX];
void pull(node &a, node &b,node &c){
    c.mn=min(a.mn,b.mn);
    c.mx=max(a.mx,b.mx);
}
void build(int idx,int l,int r){
    if(l==r){
        st[idx].mn=st[idx].mx=k;
        return;
    }
    build(idx<<1,l,(r+l)/2);
    build((idx<<1)+1,(r+l)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
void get(int idx,int l,int r){
    if(l==r){
        st[idx].mx-=v;
        st[idx].mn-=v;
        return ;
    }
    if(st[idx<<1].mn>=v||st[idx<<1].mx>=v){
        get(idx<<1,l,(l+r)/2);
    }else{
        if(st[(idx<<1)+1].mn>=v||st[(idx<<1)+1].mx>=v){
            get((idx<<1)+1,(r+l)/2+1,r);
        }
    }
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
int use;
long long w;
void ans(int idx,int l,int r){
    if(l==r){
        if(st[idx].mn!=k){
            use++;
            w+=st[idx].mn;
        }
        return;
    }
    ans(idx<<1,l,(r+l)/2);
    ans((idx<<1)+1,(r+l)/2+1,r);
}
int main(){
    scanf("%d",&t);
    while(t-->0){
        scanf("%d%d",&k,&n);
        string s;
        int x=MAX>>2;
        build(1,0,x-1);
        while(n){
            cin>>s;
            int rep=1;
            if(s[0]=='b'){
                scanf("%d%d",&rep,&v);
            }else{
                v=0;
                for(int j=0;j<(int)s.size();j++){
                    v*=10;v+=s[j]-'0';
                }
            }
            n-=rep;
            while(rep){
                get(1,0,x-1);
                rep--;
            }
        }
        use=w=0;
        ans(1,0,x-1);
        printf("%d %lld\n",use,w);
    }
    return 0;
}
