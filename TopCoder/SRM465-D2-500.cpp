/*
Assume that we have two points A and B and want to place a square with side size a with its center in A and a square with side size b with its center in B. 
It's useful to find an easy way to check when a placement with overlap is possible. 
Let's denote the Euclidean distance between points A and B as d.

we need to count the number of pairs (a, b) such that a/2 + b/2 ≤ d. Let's transform the inequality a bit. 
First multiply both sides by 2 to get a + b ≤ 2 * d. 
Then note that the right part can be rounded down to the nearest integer: a + b ≤ floor(2 * d).
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

class TurretPlacement{
public:
    long long count(vector <int> x, vector <int> y){
        long long ret=0;
        for(int i=0;i<x.size();i++){
            for(int j=i+1;j<x.size();j++){
                int xx=x[i]-x[j];
                int yy=y[i]-y[j];
                long long dd=sqrt((1LL*xx*xx) + (1LL*yy*yy));
                ret+=(dd*(dd+1))/2;
            }
        }
        return ret;
    }

};
