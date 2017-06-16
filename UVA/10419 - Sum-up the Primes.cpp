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

vector<pair<string,int> > all;
bool isc[333];
int memo[68][1001][15];
/*
 idx: index of "primes".
 nn: the current sum.
 tt: the number of chosen primes.
 */
int solve(int idx,int nn,int tt){
    if(nn<0||tt<0){return 0;}
    if(!nn){
        return tt==0;
    }
    if(idx==(int)all.size()){
        return 0;
    }
    if(memo[idx][nn][tt]!=-1){
        return memo[idx][nn][tt];
    }
    int ans=0;
     ans|=solve(idx+1,nn,tt);
    ans|=solve(idx+1,nn-all[idx].second,tt-1);
    if(all[idx].second!=2){
        ans|=solve(idx+1,nn-2*all[idx].second,tt-2);
    }
    return memo[idx][nn][tt]=ans;
}
void ge(){
    isc[0]=isc[1]=1;
    for(int i=4;i<300;i+=2){isc[i]=1;}
    for(int i=3;i<300;i+=2){
        if(isc[i]){continue;}
        for(int j=i;i*j<333;j++){
            isc[i*j]=1;
        }
    }
    for(int i=0;i<300;i++){
        if(!isc[i]){
            int p=i;
            string ss="";
            while(p){
                int dig=p%10;
                ss+=dig+'0';
                p/=10;
            }
            reverse(ss.begin(),ss.end());
            all.push_back(make_pair(ss,i));
        }
    }
    // sort to get the lexicographically smallest one
    sort(all.begin(),all.end());
}
int n , t;
vector<string> ans;
void get(int idx,int nn,int tt){
    if(nn<0||tt<0){return ;}
    if(!nn){
        return ;
    }
    if(idx==(int)all.size()){
        return;
    }
    if(all[idx].second!=2&&solve(idx+1,nn-2*all[idx].second,tt-2)){
        ans.push_back(all[idx].first);
        ans.push_back(all[idx].first);
        get(idx+1,nn-2*all[idx].second,tt-2);
        return ;
    }
    if(solve(idx+1,nn-all[idx].second,tt-1)){
        ans.push_back(all[idx].first);
        get(idx+1,nn-all[idx].second,tt-1);
        return ;
    }
    get(idx+1,nn,tt);
    
}
int TC=0;
int main(){
    ge();
    memset(memo,-1,sizeof(memo));
    while(scanf("%d%d",&n,&t)!=EOF){
        if(!n&&!t){break;}
        printf("CASE %d:\n",++TC);
        if(!solve(0,n,t)){
            printf("No Solution.\n");
            continue;
        }
        ans.clear();
        get(0,n,t);
        for(int i=0;i<ans.size();i++){
            if(i){
                printf("+");
            }
            printf("%s",ans[i].c_str());
        }
        printf("\n");
    }
    return 0;
}
