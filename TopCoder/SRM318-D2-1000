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
double memo[1001][3001],p1,p2,p3;
bool cal[1001][3001];
int n , w;

class SimplifiedDarts{
public:
    double solve(int idx,int cur){
        if(idx==n){
            if(cur<w){
                return 0;
            }
            return 1;
        }
        if(cal[idx][cur]){
            return memo[idx][cur];
        }
        double ans=solve(idx+1,cur)*(1-p1)+solve(idx+1,cur+2)*p1;
        ans=max(ans,solve(idx+1,cur)*(1-p2)+solve(idx+1,cur+3)*p2);
        cal[idx][cur]=1;
        return memo[idx][cur]=ans;
    }
    double tryToWin(int W, int N, int P1, int P2){
        p1=P1/100.0;
        p2=P2/100.0;
        printf("%.3lf %.3lf %.3lf\n",p1,p2,p3);
        n=N;w=W;
        double res=solve(0,0);
        return res*100.0;
    }
};
/*
int main(){
    SimplifiedDarts s;
    cout<<s.tryToWin(5, 2, 50, 25)<<endl;
    cout<<s.tryToWin(6, 3, 90, 20)<<endl;

       return 0;
}
 */
