/*
go through the points in increasing order,
keeping track of the maximum seen so far.
When processing a new value, 
compare its difference to the maximum seen so far and save this difference if it is the largest seen so far
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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

int a, b, c, d,p,n;
double sofar,ans,mm;
int main(){
    while(scanf("%d",&p)!=EOF){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
        ans=sofar=0;
        for(int i=1;i<=n;i++){
        mm=p*(sin(a*i+b)+cos(c*i+d)+2);
            sofar=max(sofar,mm);
            ans=max(ans,sofar-mm);
        }
        printf("%.6lf\n",ans);
    }
    
    return 0;
}
