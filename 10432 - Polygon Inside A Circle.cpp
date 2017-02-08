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
using namespace std;

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

const double pi=acos(-1);
double r,n;

int main(){
    while(scanf("%lf%lf",&r,&n)!=EOF){
        double angle=2*pi/n;
        double rem=pi-angle;
        rem/=2;
        double c=r*sin(angle);
        c/=sin(rem);
        printf("%.3lf\n",n*c*sin(rem)*r*.5);
    
    }
    
    
    
    
    return 0;//rev Ab steps
}
