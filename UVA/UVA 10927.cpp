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
int n , x[100000],y[100000],z[100000];
map<pair<int,int> ,int> mp;
int gcd(int aa, int bb){
    while(aa&&bb){
        if(aa>bb){aa%=bb;}else{
            bb%=aa;
        }
    }
    return aa+bb;
}
int tc;
int main(){
    while(scanf("%d",&n)==1){
        if(!n){break;}
        printf("Data set %d:\n",++tc);
        vector<pair<long long ,int > > all;
        all.clear();
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
            all.push_back(make_pair(1LL*x[i]*x[i]+1LL*y[i]*y[i],i));
        }
        sort(all.begin(),all.end());
        mp.clear();
        vector<pair<int,int> >ans;
        for(int idx=0;idx<(int)all.size();idx++){
            int i=all[idx].second;
            int gg=gcd(abs(x[i]),abs(y[i]));
            int si=1;
            if(x[i]<0 && y[i] < 0){
                si=-1;
            }
            if(mp.count(make_pair(si*x[i]/gg,si*y[i]/gg))&&mp[make_pair(si*x[i]/gg,si*y[i]/gg)]>=z[i]){
                ans.push_back(make_pair(x[i],y[i]));
                //cout<<mp[make_pair(x[i]/gg,y[i]/gg)]<<endl;
            }
            mp[make_pair(si*x[i]/gg,si*y[i]/gg)]=max(mp[make_pair(si*x[i]/gg,si*y[i]/gg)],z[i]);
        }
        if(ans.size()){
            sort(ans.begin(),ans.end());
            cout<<"Some lights are not visible:"<<endl;
            for(int i=0;i+1<ans.size();i++){
                printf("x = %d, y = %d;\n",ans[i].first
                       ,ans[i].second);
            }  printf("x = %d, y = %d.\n",ans.back().first
                      ,ans.back().second);
            
        }else{
            cout<<"All the lights are visible."<<endl;
        }
    }
    return 0;
}
