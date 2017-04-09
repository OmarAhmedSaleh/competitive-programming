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
double memo[301][15];
bool cal[301][15];
int sz,k;
vector<int> v;

class CyclicGame{
public:
    double solve(int n,int idx){
        if(n==k){
            return 0;
        }
        if(cal[n][idx]){
            return memo[n][idx];
        }
        double p1=1.0/6,ans=0;
        for(int i=1;i<=6;i++){
        ans+=p1*(v[(idx+i)%sz]+solve(n+1,(idx+i)%sz));
        }
        ans=max(ans,0.0);
        cal[n][idx]=1;
        return memo[n][idx]=ans;
    }
    double estimateBank(vector<int> cells){
        v=cells;
        sz=(int)cells.size();
        double ret=0;
        for(int i=0;i<300;i++){
            k=i;
            memset(cal,0,sizeof(cal));
            ret=max(ret,solve(0,0));

        }
        
        return ret;
    }


};

