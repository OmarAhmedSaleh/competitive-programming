/**/

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
int n ;
vector<int> e[100000];
double ans;
bool seen[100000];
void dfs(int idx,double prob,int len){
    seen[idx]=1;
    double p=1;
    int can=0;
    for(int i=0;i<(int)e[idx].size();i++){can+=!seen[e[idx][i]];}
    bool isl=1;
    p/=can;
    for(int i=0;i<(int)e[idx].size();i++){
        int to=e[idx][i];
        if(!seen[to]){
            isl=0;
            dfs(to,prob*p,len+1);
        }
    }
    if(isl){ans+=prob*len;}
}
int main(){
    scanf("%d",&n);
    int a,b;
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    ans=0;
    dfs(0,1,0);
    printf("%.6lf\n",ans);
    return 0;
}
