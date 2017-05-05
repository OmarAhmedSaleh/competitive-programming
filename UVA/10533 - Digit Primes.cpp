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
bool iscomp[10000007];
int sum[10000007],n,l,r;
int main(){
    iscomp[0]=iscomp[1]=1;
    for(int i=4;i<10000007;i+=2){
        iscomp[i]=1;
    }
    for(int i=3;i*i<10000007;i+=2){
        if(iscomp[i]){continue;}
        for(int j=i*i;j<10000007;j+=i){
            iscomp[j]=1;
        }
    }
    int p,dig;
    for(int i=2;i<10000007;i++){
        if(!iscomp[i]){
            p=i;
            dig=0;
            while(p){
                dig+=p%10;
                p/=10;
            }
            if(!iscomp[dig]){
                sum[i]=1;
            }
        }
    }
    for(int i=1;i<10000007;i++){
        sum[i]+=sum[i-1];
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);
    }
    
    return 0;
}
