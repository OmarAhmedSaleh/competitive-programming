// Rank 5 Time 0.020
//10040 - Ouroboros Snake

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
bool cal[22];
string e[22];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        s="";
        if(!cal[n]){
            memset(vis,0,sizeof(vis));
            for(int i=0;i<n;i++){
                s+='0';
            }
            long long x=1<<n;
            x--;
            long long mask=x;
            // only first (from right) n bits are 1
            // greedy (see it by useing conplete search function )
            // generate strting first n Bits are 0 , and last n are 1
            
            for(int i=0;i<n;i++){
            // mark all number visited (can be produced)
            // example for n = 3
            // 111 -> 110 -> 100 -> 000
                
                vis[x]=1;
                x<<=1;
                // anding with mask
                // example if n=2 and x=3 (11) x<<=1 then x=4 (100)
                //i need only first (from right) n bits (mask=011)
                // after Anding x = 0 (00)
                // it is valid now
                
                
                x&=mask;
            }
            
            int sz=1<<n;
            // string length 2 power n
            sz-=n;
            // first n bits are 0 (from) left
            int cur=0;
            // first number is zero
            // if n = 3
            // my string must be 2 power 3
            // now it is 000?????
            vis[cur]=1;
            // mark zero
            while((int)s.size()<sz){
                int c1=cur;
                int c2=cur;
                // from cur number , i can move to next by shifting left 1 bit,then adding 0 or 1
                c1<<=1;
                c2<<=1;
                c2+=1;
                c1&=mask;
                c2&=mask;
                
                // c1<c2
                // check if you can put 0 first (smallest possible)
                // in our example if n=3 ,and cur =0
                // c1=0 (000) , c2 = 1 (001)
                // c1 is visited
                // then check c2
                // out string now is 0001????
             
                // cur = 1
                // c1 = 2 (010) c2=3 (011)
                // c1 is ok
                // out string 00010???
                
                // cur = 2
                // c1 = 4 (100) c2=7 (111)
                // c1 is ok
                // out string 000100??
                
                // cur = 4
                // c1 = 8 (1000) c1> 2 power n -1
                // then c1&=mask ((1000) & (0111))= 000
                // c1= 0 (000)
                // c2 = 9 (1001) c2> 2 power n -1
                // then c2&=mask ((1001) & (0111))= 001
                // c2= 1 (001)
                // c2 is ok
                // out string 0001001?
                
                // cur = 1
                // c1 = 2 (010)
                // c2 = 3 (011)
                // c2 is ok
                // out string 00010011
            
                // Done
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
                // if my idea is Wrong , finish
                // cout <<"Wrong Here With N = "<<n<<endl;
                // But it is ok (^-^)
                return 0;
                
            }
            
            for(int i=0;i<n;i++){
                s+='1';
            }
            // save string for n
            // mark for n done
            // if multitest Case with same n , generate string one time only
            
            e[n]=s;
            cal[n]=1;
        }
        // from position k
        int pos=k;
        string temp="";
        for(int i=0;i<n;i++){
            // check remeber string is circular
            if(pos==e[n].size()){
                pos=0;
            }
            // add all bits
            temp+=e[n][pos++];
        }
        int ans=0;
        int p=1;
        // binary -> Decimal
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
