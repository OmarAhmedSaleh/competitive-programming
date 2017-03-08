#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
using namespace std;
class FoxAndTouristFamilies{
    public:
    int mark[55];
    bool vis[55];
    int cc[2];
    vector<int> e[55];
    void dfs(int id,int c){
        mark[id]=c;
        vis[id]=1;
        cc[c]++;
        for(int i=0;i<e[id].size();i++){
            if(!vis[e[id][i]]){
                dfs(e[id][i],c);
            }
        }
    
    }
    double expectedLength(vector <int> A, vector <int> B, vector <int> f){
        double ret=0;
        int sz=(int)A.size();
        for(int i=0;i<sz;i++){
            e[A[i]].push_back(B[i]);
            e[B[i]].push_back(A[i]);

        }
        for(int i=0;i<sz;i++){
            memset(mark,-1,sizeof(mark));
            memset(vis,0,sizeof(vis));
            cc[0]=cc[1]=0;
            vis[B[i]]=1;
            dfs(A[i],0);
            vis[B[i]]=0;
            dfs(B[i],1);
            double P=1;
            for(int j=0;j<(int)f.size();j++){
                int a=f[j];
                P*=(double)cc[mark[a]^1]/(sz);
            }
            ret+=P;
        }
        
    
        return ret;}


};




