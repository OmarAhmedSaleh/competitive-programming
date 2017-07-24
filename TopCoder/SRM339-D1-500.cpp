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
//const long long OO=4e18;
//const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
class TestBettingStrategy{
public:
    bool seen[2001][50][11];
    double memo[2001][50][11],prob;
    int goal;
    double solve(int M,int R,int L){
        if(M>=goal){
            return 1;
        }
        if(!R){
            return 0;
        }
        if(seen[M][R][L]){
            return memo[M][R][L];
        }
        double ret=0;
        if(M>=(1<<L)){
            // win
            ret=solve(M+(1<<L),R-1,0)*prob;
            //Lose
            ret+=solve(M-(1<<L),R-1,L+1)*(1-prob);
        }
        seen[M][R][L]=1;
        return memo[M][R][L]=ret;
    }
    double winProbability(int initSum, int goalSum, int rounds, int p){
        memset(seen,0,sizeof(seen));
        goal=goalSum,prob=p;
        prob/=100;
        return solve(initSum,rounds,0);
    }

};
