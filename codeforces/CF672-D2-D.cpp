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
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int n,a[500005],k;

int main(){
    scanf("%d%d",&n,&k);
    long long all=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        all+=a[i];
    }
    int mn ,mx;
    sort(a,a+n);
    mn=a[0];
    mx=a[n-1];
    int kk=k;
    for(int i=0;i<n;){
        int j=i;
        while(j<n&&a[i]==a[j]){j++;}
        int df=1000000009;
        if(j<n){
            df=a[j]-a[i];
        }
        if(1LL*df*j<=kk){
            mn=a[j];
            kk-=df*j;
        }else{
            mn=a[i] + kk/j;
            break;
        }
        i=j;
    }
    mn=min(1LL*mn,all/n);
    reverse(a,a+n);
    kk=k;
    for(int i=0;i<n;){
        int j=i;
        while(j<n&&a[i]==a[j]){j++;}
        int df=1000000009;
        if(j<n){
            df=a[i]-a[j];
        }
        if(1LL*df*j<=kk){
            mx=a[j];
            kk-=df*j;
        }else{
            mx=a[i] - kk/j;
            break;
        }
        i=j;
    }
    mx=max(1LL*mx,(all+n-1)/n);
    printf("%d\n",mx-mn);
    return 0;//rev Ab steps
}
