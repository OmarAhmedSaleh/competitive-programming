/*
 
 
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
//const long long OO=4e18;
//const int MAX=100000<<2;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
class RepeatedPatterns{
public:
    int pre[2],suf[2];
    void cal(string &s , int idx){
        int it=0;
        while(it<(int)s.size()&&s[it]=='0'){pre[idx]++;it++;}
        it=(int)s.size()-1;
        while(it > -1 && s[it] == '0'){suf[idx]++;it--;}
    }
    long long findZeroSegment(string p1,string p2,string k){
        long long zero=0;
        for(int i=0;i<(int)k.size();i++){
            zero*=10;zero+=k[i]-'0';
        }
        for(int i=0;i<2;i++){pre[i]=suf[i]=0;}
        cal(p1,0);cal(p2,1);
        int cnt=0;
        string p3=p1+p1;
        for(int i=0;i<(int)p3.size();i++){
            if(p3[i]=='0'){cnt++;}else{cnt=0;}
            if(cnt==zero){
                return i-cnt+1;
            }
        }
        if(pre[0]==(int)p1.size()){
            if(pre[1]==(int)p2.size()){
                return 0;
            }
            if(pre[1]+(int)p1.size() * 1000000 >= zero){
                return 0;
            }
        }
        cnt=0;
        string  p4=p1+p2;
        for(int i=0;i<(int)p4.size();i++){
            if(p4[i]=='0'){cnt++;}else{cnt=0;}
            if(cnt==zero){
                return i-cnt+1+(999999*((int)p1.size()));
            }
        }
        cnt=0;
        for(int i=0;i<(int)p2.size();i++){
            if(p2[i]=='0'){cnt++;}else{cnt=0;}
            if(cnt==zero){
                return i-cnt+(1000000*((int)p1.size()))+1;
            }
        }
        if(pre[0]==(int)p1.size()){
            if(pre[1]+suf[1]+(int)p1.size() * 1000000 >= zero){
                return (int)p2.size()-suf[1] + (1000000 * (int) p1.size() );
            }
        }
        cnt=0;
        p4=p1+p2+p1;
        for(int i=0;i<(int)p4.size();i++){
            if(p4[i]=='0'){cnt++;}else{cnt=0;}
            if(cnt==zero){
                return i-cnt+(999999*((int)p1.size()))+1;
            }
        }
        p4=p1+p2+p2;
        cnt=0;
        for(int i=0;i<(int)p4.size();i++){
            if(p4[i]=='0'){cnt++;}else{cnt=0;}
            if(cnt==zero){
                return i-cnt+1+(1999999*((int)p1.size()))+(int)p2.size();
            }
        }
        if(pre[1]==(int)p2.size()){
            long long rem=zero-pre[0];
            rem-=suf[0];
            long long d=rem/(int) p2.size();
            if(rem%(int)p2.size()!=0){d++;}
            long long ans=0;
            long long d1=d;
            long long d2=d-1;
            if((1LL*20000000000000000)/d < (d+1)* (int)p2.size()){return -1;}
            if(((1LL*10000000000000000)-((1LL* d*(d+1))/2 * (int)p2.size()))/d < 1000000*(int)p1.size()){return -1;}
            if(d1&1){d2/=2;}else{d1/=2;}
            long long sum=1LL*d1*d2;
            ans+=1LL*sum*(int)p2.size();
            ans+=1LL*(d)*1000000*((int)p1.size());
            ans-=suf[0];
            return ans;
        }
        return -1;
    }
};
