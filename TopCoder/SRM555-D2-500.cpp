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
class CuttingBitString{
public:
    vector<int> v[55];
    long long all[30];
    int memo[55],n;
    int solve(int idx){
      //  cout<<idx<<" idx "<<endl;
        if(idx>=n){
            return 0;
        }
        if(memo[idx]!=-1){
            return memo[idx];
        }
        int ans=oo;
        for(int i=0;i<v[idx].size();i++){
            ans=min(ans,solve(v[idx][i]+1)+1);
        }
        return memo[idx]=ans;
    }
    int getmin(string s)
    {
        for(int i=0;i<55;i++){v[i].clear();}
        long long lim=((long long)1<<50)-1;
        all[0]=1;
        for(int i=1;i<30;i++){
            if(all[i-1]*5>lim){break;}
            all[i]=all[i-1]*5;
        }
        reverse(s.begin(),s.end());
        n=(int)s.size();int ret=0;
        long long p=1;
        long long sum=0;
        for(int i=0;i<n;i++){
            p=1;sum=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1'){sum+=p;}
                p<<=1;
                for(int k=0;s[j]=='1'&&sum&&k<30;k++){
                    if(!all[k]){
                        break;
                    }
                    if(all[k]==sum){
                        v[i].push_back(j);
                        break;
                    }
                    if(all[k]>sum){
                        break;
                    }
                }
            }
        }
        memset(memo,-1,sizeof(memo));
        ret=solve(0);
        if(ret==oo){ret=-1;}
        return ret;
    }
};
