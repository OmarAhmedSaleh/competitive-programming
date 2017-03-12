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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
class TheBoredomDivOne{
public:
    double find(int n, int m){
        double dp[100];
        int t=n+m;
        dp[t]=dp[t+1]=dp[t+2]=0.0;
        for(int i=t-1;i>=n;i--){
            double all,t1,t2,t0;
            all=t1=t2=t0=0;
            for(int a=1;a<=t;a++){
                for(int b=a+1;b<=t;b++){
                    all++;
                    if(a>i && b>i){
                        t2++;
                    }else{
                    if((a>i||b>i)){
                        t1++;
                    }else{
                        t0++;
                    }
                  }
                }
                dp[i]=(1+dp[i+1]*(t1/all) + dp[i+2]*(t2/all))/(1-(t0/all));
            }
        }
        return dp[n];
    
    }
};

