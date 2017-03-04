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
const int N=50001;
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
vector<int> e[N];
int s[2];
int vis[N],x[N],y[N],n;
void dfs(int idx,int pos){
    s[pos]++;
    vis[idx]=1;
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i];
        if(!vis[to]){
            dfs(to,!pos);
        }
    }
    
}
map<pair<int,int> ,int > mp;
int ans=0;
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<=n;i++){
            e[i].clear();
            vis[i]=0;
        }
        mp.clear();
        for(int i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
            mp[make_pair(x[i],y[i])]=i;
        }
        for(int i=0;i<n;i++){
            for(int xx=-5;xx<=5;xx++){
                for(int yy=-5;yy<=5;yy++){
                    int xxx=x[i]+xx;
                    int yyy=y[i]+yy;
                    long long p1=(long long)xxx-x[i];
                    p1*=p1;
                    long long p2=(long long)yyy-y[i];
                    p2*=p2;
                    long long dis=p1+p2;
                    if(!mp.count(make_pair(xxx,yyy))||dis>25||(xxx==x[i]&&yyy==y[i])){continue;}
                    e[i].push_back(mp[make_pair(xxx,yyy)]);
                    
                }
            }
            
        }
        ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                s[0]=s[1]=0;
                dfs(i,0);
                ans+=min(s[0],s[1]);
            }
        }
        printf("%d\n",ans);
    }
    
    
    
    
    return 0;//rev Ab steps
}
