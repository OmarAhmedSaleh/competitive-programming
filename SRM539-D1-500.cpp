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
const int oo=1e9;
class SafeReturn{
public:
    vector<int> e[55];
    int match[55], was[55],dis[55][55];
    bool aug(int idx){
        if(was[idx]){
            return 0;
        }
        was[idx]=1;
        for(int i=0;i<e[idx].size();i++){
            int to=e[idx][i];
            if(match[to]==-1||aug(match[to])){
                match[to]=idx;
                return 1;
            }
        }
        return 0;
    }
    int minRisk(int N, vector<string> streets){
        int ret=0;
        int sz=(int)streets.size();
        for(int i=0;i<=(int)streets.size();i++){
            e[i].clear();
        }
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                if(streets[i][j]=='-'){
                    dis[i][j]=oo;
                    continue;
                }
                dis[i][j]=streets[i][j]-'0';
            }
        }
        for(int k=0;k<sz;k++){
            for(int i=0;i<sz;i++){
                for(int j=0;j<sz;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(dis[0][j]==dis[0][i]+dis[i][j]){
                    e[i].push_back(j);
                }
            }
        }
        ret=N;
        memset(match,-1,sizeof(match));
        for(int i=1;i<=N;i++){
            memset(was,0,sizeof(was));
            if(aug(i)){
                ret--;
            }
        }
        return ret;
    }
};
