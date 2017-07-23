/*
 more simple
 https://apps.topcoder.com/wiki/display/tc/SRM+691
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
//const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
class Sunnygraphs2{
public:
    int cyc[55],all[55],belong[55],n,cc;
    void get(vector<int> &a){
        for(int i=0;i<n;i++){
            int cur=i;
            if(belong[i]!=-1){continue;}
            for(int j=0;j<n;j++){
                cur=a[cur];
                if(belong[cur]!=-1){
                    belong[i]=belong[cur];
                    break;
                }
            }
            if(belong[cur]==-1){cc++;}
            while(belong[cur]==-1){
                belong[cur]=cc;
                cyc[cc]++;
                cur=a[cur];
            }
        }
    }
    long long count(vector<int> a){
        long long ret=1;
         n=(int)a.size();
         cc=0;
        for(int i=0;i<=n;i++){
            cyc[i]=all[i]=0;belong[i]=-1;
        }
        get(a);get(a);
        for(int i=0;i<n;i++){
            all[belong[i]]++;
        }
        for(int i=1;i<=cc;i++){
         //   cout<<cyc[i]<<" "<<all[i]<<endl;
            ret*=1LL*((1LL*1<<cyc[i])-1)*(1LL*1<<(all[i]-cyc[i]));
        }
        if(cc==1){
            ret++;
        }
        return ret;
    }
};
