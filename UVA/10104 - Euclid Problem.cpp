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
long long aa, bb, x , y ,d;

void extendedEuclid(long long a, long long b) {
    if (b == 0) { x = 1; y = 0; d = a; return; } // base case
    extendedEuclid(b, a % b);
    long long x1 = y;
    long long y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){
    while(cin>>aa>>bb){
    extendedEuclid(aa,bb);
    cout<<x<<" "<<y<<" "<<d<<endl;
    }
    
    
    return 0;
}
