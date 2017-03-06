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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int n , mat[2002][2002],nw[2002][2002];
bool vis[2002];
vector<pair<int,int> > e[2002];
int f,t,b;
void dfs(int idx,long long cur){
    vis[idx]=1;
  //  cout<<idx<<" "<<cur<<" "<<b<<" "<<t<<" "<<mat[idx][b]<<endl;
    if((cur+mat[idx][b])==t){
        f=idx;
       // return ;
    }
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i].first;
        int w=e[idx][i].second;
        if(!vis[to]){
            dfs(to,cur+w);
        }
    }


}
int c;
void dis(int idx,int cur){
    nw[c][idx]=cur;
    vis[idx]=1;
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i].first;
        int w=e[idx][i].second;
        if(!vis[to]){
            dis(to,cur+w);
        }
    }

}
int main(){
    scanf("%d",&n);
    int mn=1000000009;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
            if(i!=j){
            mn=min(mat[i][j],mn);
            }
        }
    }
 // NO
    for(int i=0;i<n;i++){
        if(mat[i][i]){
            puts("NO");
            return 0;
        }
        for(int j=0;j<n;j++){
            
            if(i==j){continue;}
            if(!mat[i][j]){
                puts("NO");
                return 0;
            }
            if(mat[i][j]!=mat[j][i]){
                puts("NO");
                return 0;
            }
            
        }
    }
    // find root
    int root=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){continue;}
            if(mat[i][j]==mn){root=i;}
        }
    }
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        if(i==root){continue;}
        v.push_back(make_pair(mat[root][i],i));
    }
    sort(v.begin(),v.end());
    // Merge
    //e[root].push_back(make_pair(v[0].second,v[0].first));
    for(int i=0;i<v.size();i++){
        t=v[i].first;
        b=v[i].second;
        memset(vis,0,sizeof(vis));
        f=root;
        dfs(root,0);
        //cout<<f<<endl;
        e[f].push_back(make_pair(b,mat[f][b]));
        e[b].push_back(make_pair(f,mat[f][b]));

    }
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        c=i;
        dis(c,0);
    }
    /*
    cout<<endl;
    for(int idx=0;idx<n;idx++){
        for(int i=0;i<e[idx].size();i++){
            cout<<idx<<" "<<e[idx][i].first<<" "<<e[idx][i].second<<endl;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<nw[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(nw[i][j]!=mat[i][j]){
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
