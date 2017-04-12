
/*
 
 - get path from a to b using DFS
 
 if length is odd they will meet at path[length/2]
 if a = 1 and b = 5
 path -> 1 2 3 4 5
 
Step  a_Cur  a_Next  b_Cur b_Next
 0     1       2       5    4
 1     2       3       4    3
 2     3       -       3    -
 
 The fleas meet at 3
 
 ---------------------------------------
 Even-> they won't meet
 if a = 1 and b = 6
 path -> 1 2 3 4 5 6
 
  Step   a_Cur  a_Next  b_Cur  b_Next
    0     1       2       6    5
    1     2       3       5    4
    2     3       4       4    3     
    3     4       3       3    4   
    4     3       4       4    3     
    5     4       3       3    4    
    6     3       4       4    3   
    .
    .
    .
    infinite loop
 
  fleas will jump forever between 3 and 4
 
 
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
int n ,q,a,b;
vector<int> e[5001],path;
bool was[5001];
void dfs(int idx){
    path.push_back(idx);
    was[idx]=1;
    if(idx==b){
        int sz=(int)path.size();
    
        if(sz&1){
            // odd
            printf("The fleas meet at %d.\n",path[sz/2]);
        }else{
            // even
            int p=path[sz/2];
            int q=path[(sz-1)/2];
            if(p>q){swap(p,q);}
            printf("The fleas jump forever between %d and %d.\n",p,q);
        }
        return ;
    }
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i];
        if(!was[to]){
            dfs(to);
        }
    }
    path.pop_back();
}

int main(){
    while(scanf("%d",&n)==1){
        if(!n){
            break;
        }
        for(int i=0;i<=n;i++){
            e[i].clear();
        }
        for(int i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            e[a].push_back(b);
            e[b].push_back(a);
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&a,&b);
            path.clear();
            memset(was,0,sizeof(was));
            dfs(a);
        }
    }
    return 0;

}
