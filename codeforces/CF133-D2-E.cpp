/**/

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
//const long long OO=4e18;
const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
pair<int,int> memo[2][2][101][51];
int N,sz;
string s;
int solve(int let,int idx,int n,int dir){
    if(idx==sz){return -oo*(n!=0);}
    if(memo[let][dir][idx][n].first!=-1){return memo[let][dir][idx][n].first;}
    int new_dir=dir;
    if(let){new_dir^=1;}
    int sig=1;
    if(dir){sig=-1;}
    int ans=solve(s[idx+1]=='T',idx+1,n,new_dir)+(!let)*(sig);
    if(n){
        ans=max(ans,solve(let^1,idx,n-1,dir));
    }
    return memo[let][dir][idx][n].first=ans;
}
int solve2(int let,int idx,int n,int dir){
    if(idx==sz){return oo*(n!=0);}
    if(memo[let][dir][idx][n].second!=-1){return memo[let][dir][idx][n].second;}
    int new_dir=dir;
    if(let){new_dir^=1;}
    int sig=1;
    if(dir){sig=-1;}
    int ans=solve2(s[idx+1]=='T',idx+1,n,new_dir)+(!let)*(sig);
    if(n){
        ans=min(ans,solve2(let^1,idx,n-1,dir));
    }
    return memo[let][dir][idx][n].second=ans;
}

int main(){
    memset(memo,-1,sizeof(memo));
    cin>>s>>N;
    sz=(int)s.size();
    s+='F';
    //cout<<abs(solve(s[0]=='T',0,N,0))<<" "<<abs(solve2(s[0]=='T',0,N,0))<<endl;
    cout<<max(abs(solve(s[0]=='T',0,N,0)),abs(solve2(s[0]=='T',0,N,0)))<<endl;
    
    return 0;
}
