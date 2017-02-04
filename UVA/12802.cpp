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
// ss
using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

const int N=10000007;
const int M=30004;
bool isc[N];
int n;
int main(){
    isc[1]=isc[0]=1;
    for(int i=4;i<=N;i+=2){
        isc[i]=1;
    }
    for(int i=3;i<=M;i+=2){
        if(!isc[i]){
        for(int j=i*i;j<N;j+=i){
            isc[j]=1;
        }
        }
    }
    bool stop=0;
    while(!stop&&scanf("%d",&n)==1){
        if(!isc[n]){
            string s="";
            int m=n;
            while(m){
                int dig=m%10;
                m/=10;
                s+=dig+'0';
            }
            bool isp=1;
            int e=(int)s.size()-1;
            for(int i=0;i<s.size()&&i<e;i++){
                if(s[i]!=s[e]){isp=0;break;}
                e--;
            }
            stop|=isp;
        }
        printf("%d\n",n*2);
            }
    
    
    
    return 0;//rev Ab steps
}
