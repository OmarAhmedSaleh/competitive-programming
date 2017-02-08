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
// ss
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

const int N=500005;
double w,r;
double pi=acos(-1);
double l;
int tc;
int main(){
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++){
        scanf("%lf",&l);
        w=6*l;
        w/=10;
        r=l/5;
        double ca=pi*r*r;
        
        printf("%.2lf %.2lf\n",ca,(l*w)-ca);
    }
    
    
    
    
    return 0;//rev Ab steps
}
