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
const double EPS=1e-8;
const int N=100005;
typedef complex<double> point;
#define X real()
#define Y imag()
#define cp(a,b) (conj(a)*b).imag()
#define dp(a,b) (conj(a)*b).real()
#define lengthsq(a)    dp(a,a)
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
string s;
int k ,n,t;
bool vis[(1<<21)];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        memset(vis,0,sizeof(vis));
        s="";
        for(int i=0;i<n;i++){
            s+='0';
        }
        long long x=1<<n;
        x--;
        long long mask=x;
        for(int i=0;i<n;i++){
            vis[x]=1;
            x<<=1;
            x&=mask;
        }
        
        int sz=1<<n;
        sz-=n;
        int cur=0;
        vis[cur]=1;
        while((int)s.size()<sz){
            int c1=cur;
            int c2=cur;
            c1<<=1;
            c2<<=1;
            c2+=1;
            c1&=mask;
            c2&=mask;
            if(!vis[c1]){
                cur=c1;
                vis[c1]=1;
                s+='0';
                continue;
            }
            if(!vis[c2]){
                cur=c2;
                vis[c2]=1;
                s+='1';
                continue;
            }
            // If Wrong
            cout<<n<<" Here"<<endl;
            return 0;
            
        }
        for(int i=0;i<n;i++){
            s+='1';
        }
        int pos=k;
        string temp="";
        for(int i=0;i<n;i++){
            if(pos==s.size()){
                pos=0;
            }
            temp+=s[pos++];
        }
        int ans=0;
        int p=1;
        for(int i=n-1;i>-1;i--){
            if(temp[i]=='1'){
                ans+=p;
            }
            p*=2;
        }
        printf("%d\n",ans);
    }
    
    
    
    
    return 0;//rev Ab steps
}
