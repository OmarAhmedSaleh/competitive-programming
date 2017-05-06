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
int n,k,a[555],ex;
long long ans;
vector<pair<int,vector<int> > >all;
bool g;
bool valid(long long x){
    int cur=0;
    int pre=-1;
    ex=n-k;
    long long sum=0;
    vector<int> v;
    for(int i=n-1;i>-1;i--){
        if(cur==k){
            return 0;
        }
        //cout<<cur<<" "<<ex<<endl;
        if(sum+a[i]>x||(pre==cur&&!ex)){
            cur++;
            if(g){
                all.push_back(make_pair(sum,v));
            }
            sum=0;
            v.clear();
        }
        if(cur==pre){
            ex--;
        }
        sum+=a[i];
        if(sum>x){
            return 0;
        }
        v.push_back(i);
        pre=cur;
    }
    if(sum){
        cur++;
        if(g){
            all.push_back(make_pair(sum,v));
        }
    }
    if(cur==k){
        ans=min(ans,x);
    }
    return cur<=k;
}
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        long long lo=0,hi=1e18;
        ex=n-k;
        all.clear();g=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            lo=max(lo,(long long)a[i]);
        }
        ans=hi;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(valid(mid)){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        g=1;
        valid(ans);
        reverse(all.begin(),all.end());
        for(int i=0;i<all.size();i++){
            sort(all[i].second.begin(),all[i].second.end());
            if(i){
                cout<<" / ";
            }
            for(int j=0;j<all[i].second.size();j++){
                if(j){
                    cout<<" ";
                }
                cout<<a[all[i].second[j]];
            }
        }
        cout<<endl;
        
    }
    
    return 0;
}
