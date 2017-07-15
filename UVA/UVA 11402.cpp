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
const int MAX=1024000<<2;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
int tc,n,m,t,q,a,b,lazy[MAX+2],ty;
char c;
string s,p;
// Barbary , Buccaneer

// 1->2, 2->1 , 1->2 (AND) 2->1

/*
 F + I = E
 F + E = E
 F + F = F
 
 E + I = F
 E + E = E
 E + F = F
 
 I + I = 0
 I + E = E
 I + F = F
 
 */
pair<int,int> st[MAX];
void pull(pair<int,int> &a, pair<int,int> &b,pair<int,int> &c){
    c.first=a.first+b.first;
    c.second=a.second+b.second;
}
void modi_lazy(int i,int j){
    if(lazy[i]==3&&lazy[j]==3){
        lazy[j]=0;
        return ;
    }
    if(lazy[j]!=0&&lazy[j]!=lazy[i]){
        if(lazy[j]==1){
            lazy[j]=2;
            return ;
        }
        if(lazy[j]==2){
            lazy[j]=1;
            return ;
        }
        if(lazy[j]==3){
            lazy[j]=lazy[i];
        }
    }else{
        lazy[j]=lazy[i];
    }
}
void push(int idx){
    if(lazy[idx]==1){
        st[idx].second+=st[idx].first;
        st[idx].first=0;
    }
    if(lazy[idx]==2){
        st[idx].first+=st[idx].second;
        st[idx].second=0;
    }
    if(lazy[idx]==3){
        swap(st[idx].first,st[idx].second);
    }
    if((idx<<1)<MAX){
        modi_lazy(idx,idx<<1);
    }
    if((idx<<1)+1<MAX){
        modi_lazy(idx,(idx<<1)+1);
    }
    lazy[idx]=0;
}
void build(int idx,int l,int r){
    if(l==r){
        st[idx].first=s[l]=='0';
        st[idx].second=st[idx].first^1;
        return ;
    }
    build((idx<<1),l,(l+r)>>1);
    build((idx<<1)+1,(l+r)/2 + 1, r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
void modify(int idx,int l,int r){
    if(lazy[idx]!=0){
        push(idx);
    }
    if(l>b||r<a){
        return ;
    }
    if(l>=a&&r<=b){
        lazy[MAX+1]=ty;
        modi_lazy(MAX+1,idx);
        push(idx);
        return ;
    }
    modify((idx<<1),l,(l+r)>>1);
    modify((idx<<1)+1,(l+r)/2 + 1, r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
pair<int,int> get(int idx,int l,int r){
    if(lazy[idx]!=0){
        push(idx);
    }
    if(l>b||r<a){
        return make_pair(0,0);
    }
    if(l>=a&&r<=b){
        return st[idx];
    }
    pair<int,int> ret[3];
    ret[0]=get((idx<<1),l,(l+r)>>1);
    ret[1]=get((idx<<1)+1,(l+r)/2 + 1, r);
    pull(ret[0],ret[1],ret[2]);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
    return ret[2];
}
int main(){
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++){
        printf("Case %d:\n",tt);
        s="";
        memset(lazy,0,sizeof(lazy));
        memset(st,0,sizeof(st));
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&t);
            cin>>p;
            while(t-->0){
                s+=p;
            }
        }
        n=(int)s.size();
        build(1,0,n-1);
        scanf("%d",&q);
        int it=1;
        while(q-->0){
            scanf(" %c%d%d",&c,&a,&b);
            if(c=='F'){
                ty=1;
                modify(1,0,n-1);
            }
            if(c=='E'){
                ty=2;
                modify(1,0,n-1);
            }
            if(c=='I'){
                ty=3;
                modify(1,0,n-1);
            }
            if(c=='S'){
                printf("Q%d: %d\n",it++,get(1,0,n-1).second);
            }
        }
    }
    return 0;
}
