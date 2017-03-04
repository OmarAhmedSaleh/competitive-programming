include <cstring>
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
// ss
using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
const int N=33;
string a,b;
vector<int> c[N];
bool take[100005];
int st[100005],ed[100005];
bool g;
bool valid(int k){
    int rem=(int)b.size();
    rem-=k;
    if(rem>a.size()){return 0;}
    if(st[rem]!=-1){
        if(g){
            for(int j=0;j<rem;j++){
                cout<<b[j];
            }
        
        }
        return 1;
    }
    if(ed[rem]!=-1){
        if(g){
            int pos=b.size()-rem;
            for(int j=0;j<rem;j++){
                cout<<b[pos+j];
            }
            cout<<endl;

        }
        return 1;
    }
    for(int i=1;i<rem;i++){
        if(st[i]>-1&&ed[rem-i]>st[i]&&ed[rem-i]>-1){
            if(g){
                for(int j=0;j<i;j++){
                    cout<<b[j];
                }
                int pos=b.size()-(rem-i);
                for(int j=0;j<rem-i;j++){
                    cout<<b[pos+j];
                }
                cout<<endl;
            }
            return 1;
        }
    
    }

    return 0;

}

int main(){
    cin>>a>>b;
    int n=(int)a.size();
    for(int i=0;i<n;i++){
        c[a[i]-'a'].push_back(i);
    }
    int s=0;
    int e=(int)b.size()-1;
    int cur=-1;
    memset(st,-1,sizeof(st));
    memset(ed,-1,sizeof(ed));
    int mat=1;

    while(s<n){
        if(c[b[s]-'a'].empty()){break;}
        int pos=lower_bound(c[b[s]-'a'].begin(),c[b[s]-'a'].end(),cur)-c[b[s]-'a'].begin();
        if(pos==c[b[s]-'a'].size()){pos--;}
        while(pos<c[b[s]-'a'].size()&&(take[c[b[s]-'a'][pos]]||c[b[s]-'a'][pos]<=cur)){pos++;}
        if(pos==c[b[s]-'a'].size()){break;}
        cur=c[b[s]-'a'][pos];
        take[cur]=1;
        st[mat++]=cur;
        s++;
    }
    int cur2=11111111;
    mat=1;
    memset(take,0,sizeof(take));
    while(e>-1){
        if(c[b[e]-'a'].empty()){
            break;
        }
        int pos=lower_bound(c[b[e]-'a'].begin(),c[b[e]-'a'].end(),cur2)-c[b[e]-'a'].begin();
        if(pos==c[b[e]-'a'].size()){pos--;}
        while(pos>-1&&(take[c[b[e]-'a'][pos]]||c[b[e]-'a'][pos]>=cur2)){pos--;}
        if(pos==-1){break;}
        cur2=c[b[e]-'a'][pos];
        ed[mat++]=cur2;
        take[cur2]=1;
        e--;
    }
    int l ,h;
    l=0;
    h=(int)b.size();
    while(l<h){
        int mid=l+(h-l)/2;
        if(valid(mid)){
            h=mid;
        }else{
            l=mid+1;
        }
    }
    if(h==b.size()){
        cout<<"-"<<endl;
        return 0;
    }
    g=1;
    valid(h);
    
    
    return 0;//rev Ab steps
}
