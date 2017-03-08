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
const int N=50001;
const long long oo=1000000007; 
int n , k;
vector<int> e[N];
int memo[N][501];
long long ans;
int was[N];
void dfs(int id){
	was[id]=1;
	vector<int> p;
	memo[id][0]=1;
	for(int i=0;i<e[id].size();i++){
	int to=e[id][i];
	if(!was[to]){
	p.push_back(to);
	dfs(to);

	for(int j=1;j<k;j++){
	ans+=1LL*memo[id][j]*memo[to][(k-j)-1];
	}
	for(int j=0;j<k;j++){
	memo[id][j+1]+=memo[to][j];
	}
	}
	}
	
	

}

int main(){          
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&k);
	 int f,t;
	for(int i=1;i<n;i++){
	scanf("%d%d",&f,&t);
	e[f].push_back(t);
	e[t].push_back(f);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
	ans+=memo[i][k];
	}
	printf("%I64d\n",ans);
	return 0;
}
