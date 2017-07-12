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
const int md=1000000007;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
int a,b,c,t,n,f[200000];
int main(){
    f[0]=1;
    scanf("%d",&t);
    while(t--){
        priority_queue<int> pq[2];
        pq[0].push(-1);
        scanf("%d%d%d%d",&a,&b,&c,&n);
        long long ans=1;
        for(int i=1;i<n;i++){
            f[i]=((long long)(1LL*a*(-pq[0].top()))%md + (1LL*b*(i+1))%md+c)%md;
            ans+=f[i];
            if(i%2==0){
                int top=-pq[0].top();
                pq[0].pop();
                pq[1].push(top);
            }
            if(pq[0].empty()||-pq[0].top()>f[i]){
                pq[1].push(f[i]);
                    bool br=0;
                    while(!br){
                        int top=pq[1].top();
                        pq[1].pop();
                        if(pq[0].empty()||top<-pq[0].top()){
                            br=1;
                        }
                        pq[0].push(-top);
                    }
            }else{
                pq[0].push(-f[i]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
