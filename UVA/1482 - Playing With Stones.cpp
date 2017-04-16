
/*
grundy of n :
if n is even number grundy = n/2
if n is odd number grundy = grundy((n-1)/2)
you can generate some cases and see it
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

int mex(set<int> v){
    int ret=0;
    while(v.find(ret)!=v.end()){
        ret++;
    }
   return ret;
}
int dp[1003];
int gr(int idx){
    if(idx<2){
        return dp[idx]=0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int h=(idx)/2;
    set<int> st;
    for(int i=1;i<=h;i++){
        st.insert(gr(idx-i));
    }
 
    return dp[idx]=mex(st);
}

long long get(long long idx){
    if(idx&1){
        return get(idx/2);
    }
    return idx/2;

}
int n ,t;
long long x,a;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        x=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&a);
                x^=get(a);
        }
        if(x!=0){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
    
}
