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
class BearChairs{
public:
    vector<int> findPositions(vector<int> atLeast, int d){
        vector<int> all,ret;
        all.clear();ret.clear();
        all.push_back(-2e9);
        all.push_back(2e9);
        bool ins=0;
        for(int i=0;i<(int)atLeast.size();i++){
            sort(all.begin(),all.end());
            ins=0;
            for(int j=0;j<(int)all.size()-1;j++){
                if(atLeast[i]>=all[j]&&atLeast[i]<=all[j+1]){
                    int dis[2]={atLeast[i]-all[j],all[j+1]-atLeast[i]};
                    if(dis[0]>=d && dis[1]>=d){
                        ins=1;
                        ret.push_back(atLeast[i]);
                        all.push_back(atLeast[i]);
                    }
                    break;
                }
            }
            if(ins){continue;}
            for(int j=1;j<(int)all.size()-1;j++){
                int nxt=all[j]+d;
                if(nxt<atLeast[i]){continue;}
                if(all[j+1]-nxt>=d){
                    ins=1;
                    all.push_back(nxt);
                    ret.push_back(nxt);
                    break;
                }
            }
        }
        for(int i=0;i<ret.size();i++){
            cout<<ret[i]<<" ";
        }
        return ret;
    }
    
};
