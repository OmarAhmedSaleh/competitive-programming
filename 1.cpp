#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
const int N=1000006;
const long long MOD=1234567891;
class TheBrickTowerHardDivTwo{
public:
int c;
long long memo[50][9][9][9][9][9];
long long solve(int hh,int kk,int ll,int rr,int uu, int dd){
cout<<hh<<" "<<kk<<" "<<ll<<" "<<rr<<" "<<uu<<" "<<dd<<endl;
if(kk<0){return 0;}
if(hh == 0){return 1;}
if(memo[hh][kk][ll][rr][uu][dd]!=-1){return memo[hh][kk][ll][rr][uu][dd];}
long long ans=0; // cur seq
for(int i=0;i<c;i++){
for(int j=0;j<c;j++){
for(int q=0;q<c;q++){
for(int w=0;w<c;w++){
int tt=0;
tt=(i==q)+(q==w)+(w==j)+(i==j)+(q==uu)+(i==ll)+(w==dd)+(j==rr);
if(kk<tt){continue;}
ans+=1+solve(hh-1,kk-tt,i,j,q,w);
ans%=MOD;


	}
	}
	}
	}

return memo[hh][kk][ll][rr][uu][dd]=ans%MOD;	



}
int find(int C, int K, int H){
memset(memo,-1,sizeof(memo));
 c=C;
long long ret=solve(H,K,5,5,5,5)%MOD;
   return (int)ret;


}

};

long long solve(int hh,int kk,int ll,int rr,int uu, int dd){
cout<<hh<<" "<<kk<<" "<<ll<<" "<<rr<<" "<<uu<<" "<<dd<<endl;
if(kk<0){return 0;}
if(hh == 0){return 1;}
if(memo[hh][kk][ll][rr][uu][dd]!=-1){return memo[hh][kk][ll][rr][uu][dd];}
long long ans=0; // cur seq
for(int i=0;i<c;i++){
for(int j=0;j<c;j++){
for(int q=0;q<c;q++){
for(int w=0;w<c;w++){
int tt=0;
tt=(i==q)+(q==w)+(w==j)+(i==j)+(q==uu)+(i==ll)+(w==dd)+(j==rr);
if(kk<tt){continue;}
ans+=1+solve(hh-1,kk-tt,i,j,q,w);
ans%=MOD;


	}
	}
	}
	}

return memo[hh][kk][ll][rr][uu][dd]=ans%MOD;	



}
int find(int C, int K, int H){
memset(memo,-1,sizeof(memo));
 c=C;
long long ret=0;
   return (int)ret;


}


int a, b, c;
int main(){
//freopen("in.txt","r",stdin); 
freopen("out.txt","w",stdout); 

//cin>>a>>b>>c;
cout<<find(2,0,2)<<endl;


return 0;
}      