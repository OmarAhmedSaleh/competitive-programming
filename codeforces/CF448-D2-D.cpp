
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
using namespace std;
int n,m;
long long k;
long long ans;

int check(long long w){
    long long less=0;
    int eq=0;
    for(int i=1;i<=n;i++){
        long long d=(long long)w/i;
        d=min(d,1LL*m);
        if(1LL*d*i==w){eq++;d--;}
        less+=d;
    }
    if(k>less&&k<=less+eq){ return 2;}
    if(less+eq<k){return 1;}
    return 0;}
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    long long ll=1,hh=1LL*n*m;
   
    while(ll<=hh){
        long long mid=ll+(hh-ll)/2;
        //cout<< ll<<" "<<hh<<endl;
        //cout<<mid<<endl;
        if(hh-ll<3){break;}
        int ret=check(mid);
        if(ret==2){ans=mid;break;}
        if(ret==0){hh=mid;}
        if(ret==1){ll=mid;}
    }
    while(ll<=hh){
        if(check(ll)==2){ans=ll;break;}
            ll++;
    }
    printf("%lld\n",ans);
    return 0;
}
