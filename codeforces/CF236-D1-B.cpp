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
const int md=1000000007;
int n , m, y[1000001], mark[1000001];

string s[1];
int z[1][1000001];
void z_algorithm(int pos) {
    string S=s[pos];
    int N=(int)S.size();
    z[pos][0] = N;
    int L = -1, R = -1;
    for(int i=1;i<N;i++){
        z[pos][i] = i >= R ? 0 : min(R-i, z[pos][i-L]);
        while (i+z[pos][i] < N && S[i+z[pos][i]] == S[z[pos][i]]) ++z[pos][i];
        if (i+z[pos][i] > R) L = i, R = i+z[pos][i];
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s[0];
    for(int i=0;i<m;i++){
        scanf("%d",&y[i]);
    }
    int sz=(int)s[0].size();
    if(m){
        sort(y,y+m);
    }
    z_algorithm(0);
    long long ans=1;
    for(int i=0;i<m;i++){
        if(i+1<m&&y[i]+sz-1>=y[i+1]){
            int df=y[i+1]-y[i];
            if(z[0][df]!=sz-df){
                printf("0\n");
                return 0;
            }
        }
        mark[y[i]+sz-1]++;
        mark[y[i]-1]--;
    }
    for(int i=n;i>0;i--){
        mark[i]+=mark[i+1];
    }
    for(int i=1;i<=n;i++){
        if(!mark[i]){
            ans*=26;
            ans%=md;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
