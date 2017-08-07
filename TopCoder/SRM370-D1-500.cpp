/*
 
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
//const long long OO=4e18;
const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
class ConnectTheCities{
public:
    int dis,range;
    vector<int> a;
    int memo[50][101];
    int solve(int idx,int last){
        if(last>dis){return oo;}
        if(dis-last<=range){return 0;}
        if(idx==(int)a.size()){return oo;}
        if(memo[idx][last]!=-1){return memo[idx][last];}
        int ans=oo;
        if(a[idx]<=last){
            ans=min(ans,solve(idx+1,last));
        }
        for(int i=last;i<=range+last&&i<=100;i++){ans=min(solve(idx+1,i)+abs(i-a[idx]),ans);}
        return memo[idx][last]=ans;
    }
    int minimalRange(int distance, int funds, vector<int> position){
        dis=distance;a=position;
        int ret=0;
        sort(a.begin(),a.end());
        for(int i=0;i<=100;i++){
            range=i;
            memset(memo,-1,sizeof(memo));
            if(solve(0,0)<=funds){
                ret=i;
                break;
            }
        }
        return ret;
    }
};
