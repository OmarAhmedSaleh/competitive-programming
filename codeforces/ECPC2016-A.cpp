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
/*
int mex(set<int> st){
    int ret=0;
    while(st.find(ret)!=st.end()){
        ret++;
    }

return ret;
}
int memo[1001][1001];
int solve(int n ,int b){
    if(!n){
        return 0;
    }
    if(memo[n][b]!=-1){
        return memo[n][b];
    }
    set<int> s;
    long long bb=1;
    for(int i=0;i<n;i++){
        if(bb>n){
            break;
        }
        s.insert(solve(n-bb,b));
        bb*=b;
    }
    return memo[n][b]=mex(s);
}

*/

int n, g, t, b;

int main(){
   /*
    memset(memo,-1,sizeof(memo));
   
    for(int i=1;i<=1000;i++){
        for(int j=2;j<=1000;j+=2){
            int cyc=j+1;
            int md=i%cyc;
            // cout<<n<<" "<<cyc<<" "<<md<<endl;
            if(md==cyc-1){
                if(solve(i,j)!=2){
                    cout<<i<<" "<<j<<endl;
                }
            }else{
                if(md&1){
                    if(solve(i,j)!=1){
                        cout<<i<<" "<<j<<endl;
                    }
                }else{
                    if(solve(i,j)!=0){
                        cout<<i<<" "<<j<<endl;
                    }
                }
            }
        }
    }
    */
  //  cout<<"Done"<<endl;
    freopen("powers.in","r",stdin);
   
    scanf("%d",&t);
    while(t--){
        scanf("%d",&g);
        int ans=0;
        for(int i=0;i<g;i++){
            scanf("%d%d",&b,&n);
            if(b&1){
                if(n&1){
                    ans^=1;
                }else{
                    ans^=0;
                }
            }else{
                int cyc=b+1;
                int md=n%cyc;
                if(md==cyc-1){
                    ans^=2;
                }else{
                    if(md&1){
                        ans^=1;
                    }else{
                        ans^=0;
                    }
                }
            }
        }
        if(ans!=0){
            cout<<"1"<<endl;
        }else{
            cout<<"2"<<endl;
        }
    }
    
    return 0;
}
