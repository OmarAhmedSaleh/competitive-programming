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
int n , a[100000],g;
vector<int> d;
bool vis[100000];
bool ok(int idx){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        if(vis[i]||!a[i]){continue;}
        int cur=i;
        while(a[cur]&&!vis[cur]){
            vis[cur]=1;
            cur+=d[idx];
            if(cur>=n){cur%=n;}
            if(cur==i){return 1;}
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        g+=a[i];
    }
    if(g<3){
     cout<<"NO";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(n%i==0&&n/i>2){
            d.push_back(i);
        }
    }
    for(int i=0;i<d.size();i++){
        if(ok(i)){
            puts("YES");
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
