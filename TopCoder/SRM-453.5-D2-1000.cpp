#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
class TheProduct{
public:
    long long oo=1e18;
    long long maxProduct(vector <int> numbers, int k, int maxDist){
        long long ret=-oo;
        long long dp[2][55][15];
        for(int i=0;i<50;i++){
            for(int j=0;j<11;j++){
                dp[0][i][j]=oo;
                dp[1][i][j]=-oo;
            }
        }
        for(int i=0;i<numbers.size();i++){
            dp[0][i][1]=dp[1][i][1]=numbers[i];
            for(int j=2;j<=k;j++){
                for(int w=0;w<i;w++){
                    if(i-w>maxDist){continue;}
                    if(dp[0][w][j-1]!=oo){
                    dp[0][i][j]=min(dp[0][i][j],numbers[i]*dp[0][w][j-1]);
                    dp[1][i][j]=max(dp[1][i][j],numbers[i]*dp[0][w][j-1]);
                    }
                if(dp[1][w][j-1]!=-oo){
                    dp[0][i][j]=min(dp[0][i][j],numbers[i]*dp[1][w][j-1]);
                    dp[1][i][j]=max(dp[1][i][j],numbers[i]*dp[1][w][j-1]);
                    }
                }
            }
        }
        for(int i=0;i<numbers.size();i++){
            if(dp[1][i][k]!=-oo){
            ret=max(ret,dp[1][i][k]);
            }
            if(dp[0][i][k]!=oo){
                ret=max(ret,dp[0][i][k]);
            }
        
        }
        return ret;
    }

};



