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
const int N=1000006;
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
bool vis[N];
int p[N];
int cnt[N], a, t[N], n,pos,ff[3];
vector<int> e[N];
int each=0;
void dfs(int idx){
    vis[idx]=1;
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i];
        if(!vis[to]){
            dfs(to);
            cnt[idx]+=cnt[to];
        }
    }
    cnt[idx]+=t[idx];
    if(cnt[idx]==each&&ff[pos]==-1&&p[idx]){ff[pos]=idx;}
}

int main(){
    scanf("%d",&n);
    int st=-1;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&t[i]);
        each+=t[i];
        if(!a){st=i;continue;}
        p[i]=a;
        e[i].push_back(a);
        e[a].push_back(i);
    }
    if(st==-1){st=1;}
    if(each%3!=0){
        puts("-1");
        return 0;
    }
    each/=3;
    pos=0;
    ff[0]=ff[1]=-1;
    dfs(st);
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    if(ff[pos]==-1){
        puts("-1");
        return 0;
    }
    vis[ff[0]]=1;
    pos++;
    dfs(st);
    if(ff[pos]==-1){
        puts("-1");
        return 0;
    }
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
     vis[ff[0]]=1;
     vis[ff[1]]=1;
    pos++;
    dfs(st);
    if(cnt[st]!=each){
        puts("-1");
        return 0;
    }
    cout<<ff[0]<<" "<<ff[1]<<endl;
    return 0;//rev Ab steps
}
