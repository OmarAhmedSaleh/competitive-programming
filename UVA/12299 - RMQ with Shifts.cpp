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

int st[MAX],a[MAX];
void pull(int &a,int &b,int &c){
    c=min(a,b);
}
void build(int idx,int l,int r){
    if(l==r){
        scanf("%d",&a[l]);
        st[idx]=a[l];
        return ;
    }
    build((idx<<1),l,(l+r)/2);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
int ans,s,v,m,n,sz,Q[2];
void modify(int idx,int l, int r){
    if(l>s||r<s){
        return ;
    }
    if(l==r&&r==s){
        a[l]=v;
        st[idx]=a[l];
        return ;
    }
   
    modify((idx<<1),l,(l+r)/2);
    modify((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);
}
int get(int idx,int l, int r){
    if(l>Q[1]||r<Q[0]){
        return oo;
    }
    if(l>=Q[0]&&r<=Q[1]){
        return st[idx];
    }
    int a=get((idx<<1),l,(l+r)/2);
    int b=get((idx<<1)+1,(l+r)/2+1,r);
    int ret;
    pull(a,b,ret);
    return ret;
}
char str[33];
inline void q(){
    sz=(int)strlen(str);
    int pos=0;
    Q[0]=Q[1]=0;
    for(int i=6;i<sz;i++){
        if(str[i]==','||str[i]==')'){pos++;continue;}
        Q[pos]*=10;Q[pos]+=str[i]-'0';
    }
    Q[0]--;Q[1]--;
    if(Q[0]>Q[1]){swap(Q[0],Q[1]);}
   // cout<<Q[0]<<" "<<Q[1]<<endl;
    printf("%d\n",get(1,0,n-1));
}
vector<int> all,values;
inline void sh(){
    all.clear();
    values.clear();
    int aa=0;
    sz=(int)strlen(str);
    for(int i=6;i<sz;i++){
        if(str[i]==','||str[i]==')'){
            aa--;
            all.push_back(aa);
            values.push_back(a[aa]);
            aa=0;
            continue;
        }
        aa*=10;aa+=str[i]-'0';
    }
    values.push_back(values[0]);
    aa=1;
    for(int i=0;i<all.size();i++){
        s=all[i];
        v=values[aa++];
        modify(1,0,n-1);
    }
    /*
    for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
    }
    cout<<endl;
     */
}
int main(){
    scanf("%d%d",&n,&m);
    build(1,0,n-1);
    for(int i=0;i<m;i++){
        scanf(" %s",&str);
        if(str[0]=='q'){
            q();
        }else{
            sh();
        }
    }
    return 0;
}
