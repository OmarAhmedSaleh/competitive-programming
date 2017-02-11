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
// ss
using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

const int N=100005;
int pl[3*N], n, team[N][3], k, mark[3*N], cap[N], t, tt[3*N],take[3*N];

int main(){
    scanf("%d",&n);
    int m =3*n;
    for(int i=0;i<m;i++){
        scanf("%d",&pl[i]);
        mark[pl[i]]=i;
    }
    for(int i=0;i<n;i++){
        int mn=m+1;
        int c=mn;
        for(int j=0;j<3;j++){
            scanf("%d",&team[i][j]);
            if(mark[team[i][j]]<mn){mn=mark[team[i][j]]; c=team[i][j];}
            tt[team[i][j]]=i;
        }
        cap[i]=c;
    }
    scanf("%d",&k);
    if(k!=cap[tt[k]]){
        for(int i=1;i<=m;i++){
            if(i==k){continue;}
            printf("%d ",i);
        }
        return 0;
    }
    vector<int> v;
    int mx=-1;
    for(int j=0;j<3;j++){
        if(team[tt[k]][j]==k){continue;}
        mx=max(team[tt[k]][j],mx);
    
    }
    for(int i=0;i<=tt[k];i++){
        for(int j=0;j<3;j++){
            if(team[i][j]==k){continue;}
            if(team[i][j]>mx){continue;}
            v.push_back(team[i][j]);
            take[team[i][j]]=1;
        }
    }
    sort(v.begin(),v.end());
        for(int i=1;i<=m;i++){
        if(!take[i]){
            v.push_back(i);
        }
    }
    for(int i=0;i<(int)v.size();i++){
        if(v[i]==k){continue;}
        printf("%d ",v[i]);
    }
    
    
    
    return 0;//rev Ab steps
}
