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
//const int oo=1e9;
int t;
char s[128];
int dp[111][111];
int arg_dp[111][111];
void dfs(int l, int r){
    if(l>r){
        return ;
    }
    if(l==r){
        if(s[l]==')'||s[l]=='('){
            printf("()");
        }else{
            printf("[]");
        }
        return ;
    }
    int kk=arg_dp[l][r];
    if(kk==-1){
        printf("%c",s[l]);
        dfs(l+1,r-1);
        printf("%c",s[r]);
    }else{
        dfs(l,kk);
        dfs(kk+1,r);
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char foo[128];

    scanf("%d",&t);
    while (getchar() != '\n');
    while (getchar() != '\n');
    while(t--){
        gets(s);
        gets(foo);
        int sz=(int)strlen(s);
        memset(dp,0,sizeof(dp));
        memset(arg_dp,-1,sizeof(arg_dp));
        for(int i=sz-1;i>-1;i--){
            for(int j=i;j<sz;j++){
                if(i==j){
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=1e9;
                if(s[i]=='('&&s[j]==')'){
                    dp[i][j]=dp[i+1][j-1];
                    arg_dp[i][j]=-1;
                }
                if(s[i]=='['&&s[j]==']'){
                    dp[i][j]=dp[i+1][j-1];
                    arg_dp[i][j]=-1;
                }
                for(int k=i;k<j;k++){
                    if(dp[i][j]>dp[i][k]+dp[k+1][j]){
                        dp[i][j]=dp[i][k]+dp[k+1][j];
                        arg_dp[i][j]=k;
                    }
                }
            }
        }
        dfs(0,sz-1);
        puts("");
        if(t){
            puts("");
        
        }
    }
    return 0;
}
