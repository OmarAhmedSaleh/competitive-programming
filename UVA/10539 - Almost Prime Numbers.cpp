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
int n;
bool iscomp[1000006];
int main(){
    iscomp[0]=iscomp[1]=1;
    for(int i=4;i<1000006;i+=2){
        iscomp[i]=1;
    }
    for(int i=3;i<1000006;i+=2){
        if(!iscomp[i]){
            for(long long j=1LL*i*i;j<1000006;j+=i){
               // cout<<j<<endl;
                iscomp[j]=1;
            }
        }
    }
    vector<long long> all;
    for(int i=2;i<=1e6;i++){
        if(!iscomp[i]){
            long long p=1LL*i*i;
            while(p<=1e12){
                all.push_back(p);
                p*=i;
            }
        }
    }
    sort(all.begin(),all.end());
    scanf("%d",&n);
    while(n-->0){
        long long l,h;
        scanf("%lld %lld",&l,&h);
        int pos=(int)(lower_bound(all.begin(),all.end(),l)-all.begin());
        while(pos<all.size()&&all[pos]<l){
            pos++;
        }
        int pos2=(int)(lower_bound(all.begin(),all.end(),h)-all.begin());
        while(pos2<all.size()&&all[pos2]<=h){
            pos2++;
        }
        cout<<pos2-pos<<endl;
    }
    
    return 0;
}
