/*
We will solve the task for every distinct bit.
Now we must handle new constraint: l[i], r[i], q[i]. 
If number q[i] has 1 in bit with number pos, then all numbers in segment [l[i], r[i]] will have 1 in that bit too. 
To do that, we can use a standard idea of adding on a segment.
Let's do two adding operation in s[pos] array — in position l[i] we will add 1, and in posiotion r[i] + 1 — -1.
Then we will calculate partial sums of array s[pos], and if s[pos][i] > 0 (the sum on prefix length i + 1), then bit at position pos will be 1, otherwise — 0.
After that, you can use segment tree to check satisfying constraints
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
/*
 const long long OO=4e18;
 const int oo=1e9;
 int dx[8]={1,-1,0,0,1,-1,1,-1};
 int dy[8]={0,0,-1,1,1,-1,-1,1};
 */
long long lim=(1<<30) -1;
const int MAX=100000<<2;
struct node{
    int lazy;
    long long val;
    node(){
        lazy=0;val=0;
    }
};
int n , m, s, e, q,a[(MAX>>2) +1];
bool bad;
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
    if(st[idx].lazy){
        push(idx);
    }
    if(l==r){
        a[l]=(int)st[idx].val;
        return ;
    }
    build(idx<<1,l,(l+r)>>1);
    build((idx<<1)+1,(l+r)/2+1,r);
    pull(st[idx<<1],st[(idx<<1)+1],st[idx]);

}
void update(int idx,int l, int r){
    if(st[idx].lazy){
        push(idx);
    }
    if(l>e||r<s){
        return ;
    }
    if(l>=s&&r<=e){
        st[idx].lazy=q;
        push(idx);
        return;
    }
    update(idx<<1,l,(l+r)>>1);
    update((idx<<1)+1,(l+r)/2+1,r);
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
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&s,&e,&q);
        s--;e--;
        if(s>e){swap(s,e);}
        update(1,0,n-1);
        all.push_back(make_pair(q,make_pair(s,e)));
    }
    build(1,0,n-1);
    for(int i=0;i<n;i++){
    //cout<<a[i]<<" ";
    }
    //cout<<endl;
    for(int i=0;i<(int)all.size();i++){
        s=all[i].second.first;
        e=all[i].second.second;
        long long ret=get(1,0,n-1);
        if(ret!=all[i].first){
            //cout<<ret<<" "<<all[i].first<<" "<<i<<endl;
            bad=1;
        }
    }
    if(bad){
        puts("NO");
    }else{
        puts("YES");
        for(int i=0;i<n;i++){
            if(i){printf(" ");}
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
