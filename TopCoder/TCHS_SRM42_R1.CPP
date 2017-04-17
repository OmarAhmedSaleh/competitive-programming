
/*
 find New_postion using Ternary search
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
class MonkeyTreeDistance{
public:
    vector<long long > x,y;
    long long get(long long xx){
        long long mx=0;
        for(int i=0;i<x.size();i++){
            for(int j=i+1;j<x.size();j++){
                long long dis=0;
                if(x[i]==x[j]){
                    dis=abs(y[i]-y[j]);
                }else{
                    dis=abs(y[i]-xx)+abs(y[j]-xx)+abs(x[i]-x[j]);
                }
                mx=max(mx,dis);
            }
        }
        return mx;
    }
    string minimalMaximumDistance(vector<int> X,vector<int> Y){
        for(int i=0;i<X.size();i++){
            x.push_back(1LL*X[i]);
            y.push_back(1LL*Y[i]);
        }
        string ret="";
        long long ll=-1000000009,hh=1000000009;
        long long ans=0;
        int it=0;
        while(it<333){
            it++;
            long long each=(hh-ll)/3;
            long long f=ll+each;
            long long s=hh-each;
            long long c1=get(f);
            long long c2=get(s);
           // cout<<ll<<" "<<hh<<" "<<c1<<" "<<c2<<" "<<each<<endl;
            if(!each){
                while(ll<=hh){
                    ans=min(ans,get(ll));
                    ll++;
                }
                break;
            }
            if(c1<c2){
                hh=s;
                ans=c1;
            }else{
                ll=f;
                ans=c2;
            }
        }
        while(ans){
        ret+=(ans%10)+'0';
            ans/=10;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }

};

