/*
 let prob= probability of pair = (1/sum of(i) from 1 to (r+s+k)-1)
 crs = number of pairs from r , s = r*c
 crk = number of pairs from r , k = r*k
 csk = number of pairs from s , k = s*k
 
 cr = number of pairs from r , r = r*(r-1)/2
 cs = number of pairs from s , s = s*(s-1)/2
 ck = number of pairs from k , k = k*(k-1)/2
 
 pair can be any of (r,r) , (r,s) , (r,k) , (s,s) , (s,k), (k,k)
 
 p(pair(r,r))=cr * prob * p(r,s,k)
 
 p(pair(r,k))=crk * prob * p(r-1,s,k)
 
 p(pair(r,s))=crs * prob * p(r,s-1,k)
 
 p(pair(s,k))=csk * prob * p(r,s,k-1)
 
    -----------------------------------------------------------------------------------
 
 probability of state :
 
 p(r,s,k)= p(pair(r,r)) + p(pair(r,k)) + p(pair(s,s)) + p(pair(s,k)) + p(pair(k,k))
 
 
 
 finally probability of state is equal to 
 
 p(r,s,k)=prob*( crs * p(r,s-1,k) + crk * (r-1,s,k) + csk * (r,s,k-1) ) / ( 1 - prob * ( cr + cs+ ck ))
 
 */
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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
struct node{
    double R,S,P;
};
bool cal[101][101][101];
node memo[101][101][101];
node solve(int rr,int ss,int kk){
    node ret;
    ret.R=ret.S=ret.P=0;
    if(ss==0&&rr==0&&kk>0){
        ret.P=1.0;
        return ret;
    }
    if(ss>0&&rr==0&&kk==0){
        ret.S=1.0;
        return ret;
    }
    if(ss==0&&rr>0&&kk==0){
        ret.R=1.0;
        return ret;
    }
    if(ss<0||rr<0||kk<0){
        return ret;
    }
    if(cal[rr][ss][kk]){
        return memo[rr][ss][kk];
    }
    double cr,cs,ck,crs,crk,csk;
    int m=rr+ss+kk;
    double pro=2.0/(m*(m-1));
    node ret1,ret2,ret3;
    cr=rr*(rr-1);cr/=2; cs=ss*(ss-1);cs/=2; ck=kk*(kk-1);ck/=2;
    
    crs=rr*ss;  crk=rr*kk;  csk=ss*kk;
    
    ret1=solve(rr,ss-1,kk); ret2=solve(rr-1,ss,kk); ret3=solve(rr,ss,kk-1);
    
    ret1.R*=crs*pro;    ret2.R*=crk*pro;    ret3.R*=csk*pro;
    ret1.S*=crs*pro;    ret2.S*=crk*pro;    ret3.S*=csk*pro;
    ret1.P*=crs*pro;    ret2.P*=crk*pro;    ret3.P*=csk*pro;
    
    ret.R=ret1.R+ret2.R+ret3.R; ret.S=ret1.S+ret2.S+ret3.S; ret.P=ret1.P+ret2.P+ret3.P;
    
    ret.R/=1-(pro*(cr+ck+cs));   ret.S/=1-(pro*(cr+ck+cs)); ret.P/=1-(pro*(cr+ck+cs));
   
    cal[rr][ss][kk]=1;
    return memo[rr][ss][kk]=ret;
}
int r,s,p;
int main(){
    scanf("%d%d%d",&r,&s,&p);
    
    node ans=solve(r,s,p);
    
    printf("%.9lf %.9lf %.9lf\n",ans.R,ans.S,ans.P);

    return 0;//rev Ab steps
}
