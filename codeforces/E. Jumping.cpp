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
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
const double EPS=1e-8;
const int oo=1000000009;
const int N=100003;
typedef complex<double> point;
#define X real()
#define Y imag()
#define cp(a,b) (conj(a)*b).imag()
#define dp(a,b) (conj(a)*b).real()
#define lengthsq(a)    dp(a,a)
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int t, n,dis[N];
vector<int> e[N];
bool valid(int x){
    return x>0&&x<=n;
}
int main(){
    freopen("jumping.in","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=n;i++){e[i].clear();dis[i]=oo;}
        int d,b;
        for(int i=1;i<=n;i++){
            scanf("%d",&d);
            b=i+d;
            if(valid(b)){
                e[b].push_back(i);
            }
            b=i-d;
            if(valid(b)){
                e[b].push_back(i);
            }
        }
        dis[n]=0;
        priority_queue<pair<int,int > >pq;
        pq.push(make_pair(0,n));
        while(pq.size()){
            int v=pq.top().second;
            int w=pq.top().first;
            w*=-1;
            pq.pop();
            if(w>dis[v]){continue;}
            for(int i=0;i<e[v].size();i++){
                int to=e[v][i];
                if(dis[to]>w+1){
                    dis[to]=w+1;
                    pq.push(make_pair(-dis[to],to));
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dis[i]==oo){dis[i]=-1;}
            printf("%d\n",dis[i]);
        }
    }
    
    return 0;//rev Ab steps
}
