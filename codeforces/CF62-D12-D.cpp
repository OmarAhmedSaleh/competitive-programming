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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int n,m;
int p[2222];
vector<int> e[101];
int cnt[101][101];
vector<int> eu;
void dfs(int idx,int v){
    int to;
    for(int i=0;i<e[idx].size();i++){
        to=e[idx][i];
        if(to<=v||cnt[idx][to]!=0){continue;}
        cnt[idx][to]=2;
        cnt[to][idx]=2;
        dfs(to,-1);
    }

    eu.push_back(idx);
}
void rem(){
    int to;
    for(int idx=1;idx<=n;idx++){
        for(int i =0;i<e[idx].size();i++){
            to=e[idx][i];
            if(cnt[idx][to]!=2){continue;}
            cnt[idx][to]=0;
            cnt[to][idx]=0;
        }
    
    }
}
bool done(){
    int to;
    for(int idx=1;idx<=n;idx++){
        for(int i =0;i<e[idx].size();i++){
            to=e[idx][i];
            if(cnt[idx][to]==0){return 0;}
        }
        
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=m;i++){
        scanf("%d",&p[i]);
        if(i){
            e[p[i]].push_back(p[i-1]);
            e[p[i-1]].push_back(p[i]);
            cnt[p[i]][p[i-1]]=cnt[p[i-1]][p[i]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end());
    }
    vector<int> out;
    for(int i=m;i>0;i--){
        out.clear();eu.clear();
        cnt[p[i - 1]][p[i]] = cnt[p[i]][p[i - 1]] = 0;
        dfs(p[i-1],p[i]);
        if(done()){
            for(int j =0;j<i;j++){
            cout<<p[j]<<" ";
            }
            reverse(eu.begin(),eu.end());
            for(int j=1;j<eu.size();j++){
            cout<<eu[j]<<" ";
            }
            return 0;
        }else{
            rem();
        
        }
        
    }
    cout<<"No solution"<<endl;
    return 0;
}

