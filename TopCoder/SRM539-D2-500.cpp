/*
    -try all subset , calculate lower_bound and Upper_bound (interval)
    - check if there is interval that is a sub-interval from other intervals (remove A)
        interval A (LA,UA) is sub-interval of Interval B (LB,UB)
           if(lA>=LB && UA<+UB)
           LB-----------------------------UB
                  LA-------------UA
     -check if there is a common part (remove Common part from A)
            LB--------------UB
                    [LA-----] --------UA 
                     Common
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

int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

class Over9000Rocks{
public:
    bool bad[(1<<15) +1];
    vector<pair<int,int> > all;
    int countPossibilities(vector <int> lowBound, vector <int> upperBound){
        int ret=0;
        int a,b,sz=(int)lowBound.size();
        for(int i=0;i<(1<<sz);i++){
            a=b=0;
            for(int j=0;j<sz;j++){
                if(i&(1<<j)){
                    a+=lowBound[j];
                    b+=upperBound[j];
                }
            }
            if(b>9000){
                all.push_back(make_pair(max(a,9001),b));
            }
        }
        sort(all.begin(),all.end());
        for(int i=0;i<all.size();i++){
            // cout<<all[i].first<<" "<<all[i].second<<endl;
            for(int j=0;j<all.size();j++){
                if(i==j || bad[j]){continue;}
                if(all[i].first>=all[j].first&&all[i].second<=all[j].second){
                    bad[i]=1;
                    break;
                }
                if(all[i].first>=all[j].first&&all[i].second>all[j].second&&all[i].first<=all[j].second){
                    all[i].first=all[j].second+1;
                }
            }
        }
        // cout<<endl;
        for(int i=0;i<all.size();i++){
            if(bad[i]){continue;}
            // cout<<all[i].first<<" "<<all[i].second<<endl;
            ret+=all[i].second-all[i].first +1;
        }
        return ret;
    }
    
};
