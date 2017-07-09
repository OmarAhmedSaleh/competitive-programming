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
const int MAX=4*200001;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
int n, a[200000],m,lf,rg,v;
long long st[MAX],lazy[MAX];
void pull(int idx){
    st[idx]=min(st[idx<<1],st[(idx<<1)+1]);

}
void push(int idx){
    st[idx]+=lazy[idx];
    if((idx<<1)<MAX){
        lazy[idx<<1]+=lazy[idx];
    }
    if((idx<<1)+1<MAX){
        lazy[(idx<<1)+1]+=lazy[idx];
    }
    lazy[idx]=0;
}
void build(int idx, int l, int r){
    if(l==r){
        st[idx]=a[l];
        return ;
    }
    build(idx<<1,l,(l+r)/2);
    build((idx<<1) +1,(l+r)/2 +1,r);
    pull(idx);
}
void update(int idx,int l ,int r, int i,int j){
    if(lazy[idx]!=0){
        push(idx);

    }
    if(i>r||j<l){
        return ;
    }
    if(l>=i&&r<=j){
        lazy[idx]+=v;
        push(idx);
        return ;
    }
    update(idx<<1,l,(l+r)>>1,i,j);
    update((idx<<1)+1,(l+r)/2+1,r,i,j);
    pull(idx);
}
int pos;
long long ans[2];
void get(int idx,int l,int r, int i,int j){
    if(lazy[idx]!=0){
        push(idx);
    }
    if(i>r||j<l){
        return ;
    }
    if(l>=i&&r<=j){
        ans[pos]=min(ans[pos],st[idx]);
        return ;
    }
    get(idx<<1,l,(l+r)>>1,i,j);
    get((idx<<1)+1,(l+r)/2+1,r,i,j);
}
int conv(string s){
    int ret=0;
    for(int i=0;i<s.size();i++){
        ret*=10;
        ret+=s[i]-'0';
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    build(1,0,n-1);
    scanf("%d",&m);
    string ss;
    cin.ignore();
    for(int i=0;i<m;i++){
        getline(cin,ss);
        int cur=0;
        int si=1;
        v=0;
        string t="";
        for(int j=0;j<ss.size();j++){
            if(ss[j]=='-'){
                si=-1;
                continue;
            }
            if(ss[j]==' '||j+1==ss.size()){
                if(j+1==ss.size()){
                    t+=ss[j];
                }
                if(!cur){
                    lf=conv(t)*si;
                }
                if(cur==1){
                    rg=conv(t)*si;
                    
                }
                if(cur==2){
                    v=conv(t)*si;
                }
                t="";si=1;
                cur++;
                continue;
            }
            t+=ss[j];
        }
    //    cout<<cur<<endl;
     // cout<<" TR "<<lf<<" "<<rg<<" "<<v<<" "<<cur<<endl;
        if(cur==3){
            if(rg<lf){
                update(1,0,n-1,lf,n-1);
                update(1,0,n-1,0,rg);
            }else{
                update(1,0,n-1,lf,rg);
            }
        }else{
            ans[0]=ans[1]=1e18;
            if(rg<lf){
                pos=0;
                get(1,0,n-1,lf,n-1);
                pos++;
                get(1,0,n-1,0,rg);
            }else{
                pos=0;
                get(1,0,n-1,lf,rg);
            }
            printf("%lld\n",min(ans[0],ans[1]));
        
        }
    
    }
    return 0;
}
