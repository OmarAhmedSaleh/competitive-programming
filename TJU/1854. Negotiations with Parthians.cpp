/* 1854. Negotiations with Parthians - http://acm.timus.ru/problem.aspx?num=1854
 *
 * Strategy:
 * Find all prime factors p1, p2, ... up to the cube root of the input number. Above this there are
 * at most two divisors remaining (since they are larger than the cube root). Next, (implicitly)
 * calculate the number of divisors (m1+1)*(m2+1)*.. where mx is the multiplicity of each prime
 * factor. To get an odd number of divisors, divide from the input the base of each even factor of
 * the number of divisors function. Then consider the two possible divisors above the cube root -
 * if they are unequal they have multiplicity 1 and thus contribute even factors, into the
 * number-of-divisor function so they are removed similarly.
 *
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

int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

long long n,ans;
int k;
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%lld",&n);
    ans=n;
    for(int i=3;1LL*i*i*i<=n;i+=2){
         k=0;
        while(n%i==0){
            n/=i; k++;
        }
        if(k&1){
            ans/=i;
        }
    }
    int sq=sqrt(n);
    if(1LL*sq*sq<n){
        ans/=n;
    }
    printf("%lld\n",ans);
    return 0;
}
