#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,p[120],f[120],memo[400005][120],sum;
int solve(int mo,int pos){
if(pos>=n){
       if((mo<=m)||(mo>2000&&mo<=(m+200))){return 0;}
       return -10000000;
       }
if(memo[mo][pos]!=-1){return memo[mo][pos];}
int c1=0,c2;
if((mo+p[pos]<=m)||(mo+p[pos]>2000&&mo+p[pos]<=m+200)){
    c1=f[pos]+solve(mo+p[pos],pos+1);
}
c2=solve(mo,pos+1);
return memo[mo][pos]=max(c1,c2);
}
int main()
{
 //freopen("in.txt","r",stdin);

while(scanf("%d %d",&m,&n)!=EOF){
memset(memo,-1,sizeof(memo));
for(int i=0;i<n;i++){scanf("%d %d",&p[i],&f[i]);}
printf("%d\n",solve(0,0));
}
return 0;
}
