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
//const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
int n , a , it;
vector<int> e[2000];
vector<int> S;
int dfs_num[2000],dfs_low[2000],dfsNumberCounter,visited[2000],numSCC,SCC[2000];

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;
    S.push_back(u);
    visited[u] = 1;
    for (int j = 0; j < (int)e[u].size(); j++) {
        int v = e[u][j];
        if (dfs_num[v] == 0){
            tarjanSCC(v);
        }
        if (visited[v]){
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }
    
    if (dfs_low[u] == dfs_num[u]) {
        numSCC++;
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            SCC[numSCC]++;
            if (u == v) break;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a);
            if(a){
                e[i].push_back(j);
                
            }
        }
    }
    tarjanSCC(0);
    for(int i=0;i<=numSCC;i++){
        if(SCC[i]==n){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
