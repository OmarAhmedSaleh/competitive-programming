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
int n,ok[100000];
pair<int,int> a[100000],b[100000];
map<int,int> mp;
vector<int> ans[100000];
int idx;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].first);
        b[i].first=a[i].first;
        b[i].second=i;
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        mp[b[i].first]=i;
    }
    for(int i=0;i<n;i++){
        a[i].second=mp[a[i].first];
    }
    for(int i=0;i<n;i++){
        if(ok[i]){continue;}
        int to=i;
        while(!ok[to]){
            ans[idx].push_back(b[to].second);
            ok[to]=1;
            to=a[to].second;
        }
        idx++;
    }
    printf("%d\n",idx);
    for(int i=0;i<idx;i++){
        printf("%d",(int)ans[i].size());
        for(int j=0;j<(int)ans[i].size();j++){
            printf(" %d",ans[i][j]+1);
        }
        printf("\n");
    }
    return 0;
}
