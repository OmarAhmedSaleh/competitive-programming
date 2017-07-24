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
int n,x[1001],y[1001],dir[1001];

int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    // U D R L
    // 0 1 2 3
    int ans=0;
    for(int i=0;i<n;i++){
        int xx=x[i+1],yy=y[i+1];
        if(x[i]==xx){
            if(y[i]<yy){
                dir[i]=0;
            }else{
                dir[i]=1;
            }
        }
        if(y[i]==yy){
            if(x[i]<xx){
                dir[i]=2;
            }else{
                dir[i]=3;
            }
        }
    }
    // U -> L
    // D -> R
    // R -> U
    // L -> D
    for(int i=0;i<n;i++){
        if(dir[i]==0&&dir[i+1]==3){
            ans++;
        }
        if(dir[i]==1&&dir[i+1]==2){
            ans++;
        }
        if(dir[i]==2&&dir[i+1]==0){
            ans++;
        }
        if(dir[i]==3&&dir[i+1]==1){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
