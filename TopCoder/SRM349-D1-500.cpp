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
const long long OO=4e18;
const int oo=1e9;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
 */
class DiceGames{
public:
    long long memo[33][33];
    long long solve(int idx,int pre,vector<int> &all){
        if(idx==(int)all.size()){
            return 1;
        }
        if(memo[idx][pre]!=-1){
            return memo[idx][pre];
        }
        long long ans=0;
        if(all[idx]<pre){
            return memo[idx][pre]=ans;
        }
        for(int i=pre;i<=all[idx];i++){
            ans+=solve(idx+1,i,all);
        }
        return memo[idx][pre]=ans;
    }
    long long countFormations(vector<int> sides){
        sort(sides.begin(),sides.end());
        memset(memo,-1,sizeof(memo));
        return solve(0,1,sides);
    }
};
/*
int main(){
       return 0;
}
*/
