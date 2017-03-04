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
using namespace std;

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */ 
const int N=200055;
const int M=100005;
const int K=100005;
const int oo=1000000009;
const long long INF=10000000000000016;
int n;
int all[N];
int dp[N];



int main(){          
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	scanf("%d",&all[i]);
	dp[i]=INF;
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
	dp[i]=min(dp[i],dp[i-1]+20);
	int pos=lower_bound(all,all+i+1,(all[i]-90)+1)-all;
	if(pos<i&&(all[pos]+90)-1>=all[i]){
	pos--;
	if(pos<0){pos=0;}
	dp[i]=min(dp[i],dp[pos]+50);
	}
	pos=lower_bound(all,all+i+1,(all[i]-1440)+1)-all;
	if(pos<i&&(all[pos]+1440)-1>=all[i]){
	pos--;
	if(pos<0){pos=0;}
	dp[i]=min(dp[i],dp[pos]+120);
	}
	printf("%d\n",dp[i]-dp[i-1]);
	}
	
	


		return 0;
}
