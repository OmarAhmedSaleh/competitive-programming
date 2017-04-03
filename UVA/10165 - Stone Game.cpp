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
int n;
long long a;
int main(){
    while(scanf("%d",&n)==1){
        if(!n){break;}
        long long b=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&a);
            b^=a;
        }
        if(!b){
            puts("No");
        }else{
            puts("Yes");
        }
    }
    return 0;
}
