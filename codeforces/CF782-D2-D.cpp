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
const int N=3005;
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

string s1,s2;

vector<string> v;

map<string,int> mp;

vector<int> e[3222];

pair<string ,string> all[N];

int n, out[N], match[3222],vis[3222];

int aug(int idx){
    if(vis[idx]){return 0;}
    vis[idx]=1;
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i];
        if(match[to]==-1||aug(match[to])){
            match[to]=idx; match[idx]=to;
            return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        all[i].first=all[i].second="";
        all[i].first=s1.substr(0,3);
        all[i].second=s1.substr(0,2)+s2[0];
        if(!mp.count(all[i].first)){
            mp[all[i].first]=(int)v.size()+1001;
            v.push_back(all[i].first);
        }
        if(!mp.count(all[i].second)){
            mp[all[i].second]=(int)v.size()+1001;
            v.push_back(all[i].second);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){continue;}
            if(all[i].first==all[j].first){
                if(all[i].second==all[j].second){
                    puts("NO");
                    return 0;
                }
                out[i]=2;out[j]=2;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        e[i].push_back(mp[all[i].second]);
        e[mp[all[i].second]].push_back(i);
        if(!out[i]){
        e[i].push_back(mp[all[i].first]);
        e[mp[all[i].first]].push_back(i);
        }
    }
    int t=0;
    memset(match,-1,sizeof(match));
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        t+=aug(i);
    }
    if(t==n){
        puts("YES");
        for(int i=0;i<n;i++){
            cout<<v[match[i]-1001]<<endl;
        }
        return 0;
    }
    puts("NO");
    return 0;//rev Ab steps
}
