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
int n ;
int memo[1<<21];
int pp[22];
string s;
class EllysCheckers{
public:
    int solve(int mask){
        int mask2=mask;
        if(mask2&1){
            mask2--;
        }
        
        if(!mask2){
            return 0;
        }
        if(memo[mask2]!=-1){
            return memo[mask2];
        }
        int ans=0;
        for(int i=1;i<n;i++){
            int mm=mask2-pp[i];
            if(mask2&(1<<i) && !(mask2&(1<<(i-1)))){
                ans|=!solve(mm|(1<<(i-1)));
            }
            if(i>2&&(mask2&(1<<i))&&(mask2&(1<<(i-1)))&&(mask2&(1<<(i-2)))&&!(mask2&(1<<(i-3)))){
                ans|=!solve(mm|(1<<(i-3)));
                
            }
            
        }
        return memo[mask2]=ans;
    }

    string getWinner(string board){
        pp[0]=1;
        for(int i=1;i<21;i++){
            pp[i]=pp[i-1]*2;
        }
        s=board;
        reverse(s.begin(),s.end());
        int mask=0;
        memset(memo,-1,sizeof(memo));
        n=(int)s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='o'){
                mask|=1<<i;
            }
        }
        if(mask&1){mask--;}
        int ret=solve(mask);
        if(ret){
        return "YES";
        }
        return "NO";
    
    }



};


