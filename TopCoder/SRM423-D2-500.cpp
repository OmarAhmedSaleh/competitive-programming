/*
 http://www.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm423
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
class TheTower{
public:
    vector<int> count(vector<int> x,vector<int> y){
        vector<int> ans((int)x.size(),1e9);
        vector<int> all;
        int sz=(int)x.size();
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                int xx=x[i];
                int yy=y[j];
                all.clear();
                for(int k=0;k<sz;k++){
                    all.push_back(abs(xx-x[k])+abs(yy-y[k]));
                }
                sort(all.begin(),all.end());
                int sum=0;
                for(int n=0;n<sz;n++){
                    sum+=all[n];
                    ans[n]=min(ans[n],sum);
                }
            }
        }
        
        return ans;
    }
};
