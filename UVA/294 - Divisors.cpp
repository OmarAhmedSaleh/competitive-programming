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
int n ;
bool iscomp[1000006];
vector<int> all;
long long k;
long long numd(int a){
    long long ret=1;
    int cnt=0;
    for(int i=0;i<all.size();i++){
        if(a==1||a<1LL*all[i]*all[i]){break;}
        cnt=0;
        while(a%all[i]==0){cnt++; a/=all[i];}
        ret*=(cnt+1);
    }
    if(a!=1){
        ret*=2;
    }
    return ret;
}
int l,r;

int main(){
    iscomp[0]=iscomp[1]=1;
    for(int i=4;i<=1000006;i+=2){
        iscomp[i]=1;
    }
    for(int i=3;1LL*i*i<=1000006;i+=2){
        if(!iscomp[i]){
            for(int j=i*i;j<=1000006;j+=i){
                iscomp[j]=1;
            }
        }
    }
    for(int i=1;i<1000006;i++){
        if(!iscomp[i]){
            all.push_back(i);
        }
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&l,&r);
        if(l>r){swap(l,r);}
        long long mx=-1;
        int ans=0;
        long long ret=-1;
        int it=l;
        while(it<=r){
            ret=numd(it);
            if(ret>mx){
                mx=ret;
                ans=it;
            }
            it++;
        }
        printf("Between %d and %d, %d has a maximum of %lld divisors.\n",l,r,ans,mx);
    }
    
    return 0;
}
