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
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
class Sunnygraphs2{
    
public:
    int vs_of_cc[55],cc,cnt,a[55],cyc[55],belong[55];
    int dfs_low[55],dfs_num[55];
    vector<int>s;
    long long p[51];
    void dfs(int idx){
       dfs_low[idx]=dfs_num[idx]=++cnt;
        s.push_back(idx);
        belong[idx]=cc;
        if(!dfs_num[a[idx]]){
            dfs(a[idx]);
        }
        belong[idx]=belong[a[idx]];
        dfs_low[idx]=min(dfs_low[idx],dfs_low[a[idx]]);
        if(dfs_num[idx]==dfs_low[idx]){
            int xx=0;
            bool br=0;
            while(!br){
                xx++;
                br|=s.back()==idx;
                s.pop_back();
            }
            cyc[belong[idx]]=max(cyc[belong[idx]],xx);
        }
        vs_of_cc[belong[idx]]++;
    }
    long long count(vector<int> aa){
        p[0]=1;
        for(int i=1;i<51;i++){
            p[i]=p[i-1]<<1;
        }
        long long ret=1;
        for(int i=0;i<55;i++){
            if(i<(int)aa.size()){a[i]=aa[i];}
            vs_of_cc[i]=dfs_num[i]=dfs_low[i]=cyc[i]=belong[i]=0;
        }
        cc=0;
        cnt=0;
        for(int i=0;i<(int)aa.size();i++){
            s.clear();
            if(!dfs_num[i]){
                cc++;
                dfs(i);
            }
        }
        vector<long long > all;
        int bridges=0;
        for(int i=0;i<=cc;i++){
            if(!vs_of_cc[i]){
                continue;
            }
          //  cout<<i<<" "<<cyc[i]<<" "<<vs_of_cc[i]<<endl;
            bridges=(vs_of_cc[i]-cyc[i]);
            all.push_back(1LL*p[cyc[i]]*p[bridges] - p[bridges]);
            ret*=all.back();
            
        }
        if(all.size()==1){
            ret++;
        }
        return ret;
    }
};
