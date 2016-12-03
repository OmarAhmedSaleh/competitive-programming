#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <queue>

using namespace std;
const int N=1001;
int memo[N][N],t,n;
string s;
int solve(int i,int j){
if(j<i){return 0;}
if(i==j){return 0;}
if(memo[i][j]!=-1){return memo[i][j];}
int ans=solve(i+1,j-1)+(s[i]!=s[j]);
ans=min(ans,solve(i+1,j)+1);
ans=min(ans,solve(i,j-1)+1);
return memo[i][j]=ans;

}

int main(){
   // freopen("in.txt","r",stdin);
scanf("%d",&t);
for(int tt=1;tt<=t;tt++){
cin>>s;
n=(int)s.size();
memset(memo,-1,sizeof(memo));
printf("Case %d: %d\n",tt,solve(0,n-1));


}



return 0;}
