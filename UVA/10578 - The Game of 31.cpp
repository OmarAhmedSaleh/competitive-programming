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
string s;
int memo[2][1<<24];
int cnt[7];
int solve(int mask,int turn,int sum){
       if(memo[turn][mask]!=-1){
        return memo[turn][mask];
    }
    int ans=0;
    for(int i=0;i<24;i++){
        if(!(mask&(1<<i))){
            int dig=i/4;
            dig++;
            if(sum+dig<32&&!solve(mask|(1<<i),turn^1,sum+dig)){
                ans=1;
            }
        }
    }
    return memo[turn][mask]=ans;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(getline(cin,s)){
        int sz=(int)s.size();
        memset(cnt,0,sizeof(cnt));
        int mask=0;
        int dig=0;
        int ss=0;
        for(int i=0;i<sz;i++){
            dig=s[i]-'0';
            dig--;
            mask|=(1<<(4*dig + cnt[dig]));
            cnt[dig]++;
            ss+=dig+1;
        }
        cout<<s<<" ";
        memset(memo,-1,sizeof(memo));
        if(sz&1){
            if(!solve(mask,1,ss)){
                printf("A\n");
            }else{
                printf("B\n");
            }
        }else{
            if(!solve(mask,0,ss)){
                printf("B\n");
            }else{
                printf("A\n");
            }
        }

    }
    return 0;
}
