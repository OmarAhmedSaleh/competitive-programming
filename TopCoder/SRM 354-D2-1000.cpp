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
using namespace std;

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

class UnsealTheSafe{

public:
    long long memo[33][11];
    int a[4][3];
    pair<int,int> e[10];
    int dx[8]={1,-1,0,0,1,1, 1, 0};
    int dy[8]={0, 0, 1,-1,1,0,-1,-1};
    bool valid(int i,int j){
    return (i<4&&j<3)&&(i>-1&&j>-1);
    }
    long long solve(int idx,int l){
    if(idx==0){
        return 1;
    }
    if(memo[idx][l]!=-1){return memo[idx][l];}
    long long ans=0;
    for(int k=0;k<4;k++){
        int aa=e[l].first+dx[k];
        int bb=e[l].second+dy[k];
        if(valid(aa,bb)){
            if(a[aa][bb]==-1||a[aa][bb]==l){continue;}
            ans+=solve(idx-1,a[aa][bb]);
        }
    }
    return memo[idx][l]=ans;
    }
     long long countPasswords(int N){
     memset(memo,-1,sizeof(memo));
     memset(a,-1,sizeof(a));
        int cnt=1;
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            e[cnt]=make_pair(i,j);
            a[i][j]=cnt++;

        }

     }
     a[3][0]=0;
    e[0]=make_pair(3,0);

     long long ret=0;
     for(int i=0;i<10;i++){
        ret+=solve(N-1,i);
     }
     return ret;
     }

};


