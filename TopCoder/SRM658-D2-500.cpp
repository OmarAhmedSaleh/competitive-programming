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
//const int MAX=100000<<2;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
class MutaliskEasy{
    public:
    vector<int> v;
    int n ,cur;
    int memo[3][16][16][16];
    int solve(int idx,int a,int b,int c){
        if(idx==n){
            return 1;
        }
        if(memo[idx][a][b][c]!=-1){return memo[idx][a][b][c];}
        int ans=0;
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                for(int k=0;k<=c;k++){
                    if(i+j+k>cur){break;}
                    if(i*9 + j*3 + k < v[idx]){continue;}
                    ans|=solve(idx+1,a-i,b-j,c-k);
                }
            }
        }
        return memo[idx][a][b][c]=ans;
    }
    int minimalAttacks(vector<int> x){
        n=(int)x.size();
        sort(x.rbegin(),x.rend());
        v=x;
        for(int i=x[0]/9;i<16;i++){
            cur=i;
            memset(memo,-1,sizeof(memo));
            if(solve(0,i,i,i)){return i;}
        }
        return -1;
    }
};
