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
//const int MAX=100000<<2;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
int tc,n,f,cur;
vector<int> out[1000],in[1000],st;
bool seen[1000];
int low[1000],dfs_num[1000],id;
vector<int> all[1000];
void SCC(int idx){
    low[idx]=dfs_num[idx]=++id;
    seen[idx]=1;
    st.push_back(idx);
    if(!dfs_num[out[idx].back()]){
        SCC(out[idx].back());
    }
    if(seen[out[idx].back()]){
        low[idx]=min(low[idx],low[out[idx].back()]);
    }
    if(dfs_num[idx] == low[idx]){
        while(1){
            int f=st.back();
            all[cur].push_back(f);
            st.pop_back();
            seen[f]=0;
            if(f==idx){break;}
        }
        cur++;
    }
}
int b;
void longest_path(int idx,int len){
    seen[idx]=1;
    b=max(b,len);
    int to;
    for(int i=0;i<(int)in[idx].size();i++){
        to=in[idx][i];
        if(!seen[to]){
            longest_path(to,len+1);
        }
    }
}
int main(){
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            out[i].clear();in[i].clear();all[i].clear();
        }
        st.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&f);
            f--;
            out[i].push_back(f);
            in[f].push_back(i);
        }
        memset(seen,0,sizeof(seen));
        memset(dfs_num,0,sizeof(dfs_num));
        memset(low,0,sizeof(low));
        cur=id=0;
        for(int i=0;i<n;i++){
            if(!dfs_num[i]){
                SCC(i);
            }
        }
        int ans=0;
        int mxt=0;
        for(int i=0;i<id;i++){
            ans=max(ans,(int)all[i].size());
            if((int)all[i].size()==2){
                memset(seen,0,sizeof(seen));
                seen[all[i][0]]=seen[all[i][1]]=1;
                int tot=2;
                b=0;
                longest_path(all[i][0],0);
                tot+=b;
                b=0;
                longest_path(all[i][1],0);
                tot+=b;
                mxt+=tot;
                ans=max(ans,mxt);
            }
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
