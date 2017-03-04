#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX=100005;
int a[MAX],b[MAX],n,k;
long long ans;
bool ok(long long qq){
long long all=0;
for(int i=0;i<n;i++){
long long req=(long long)a[i]*qq;
if(req-b[i]>k){return 0;}
if(req>b[i]){
    all+=(long long)req-b[i];
}
}
return all<=k;

}
int main()
{
//freopen("in.txt","r",stdin);
scanf("%d %d",&n,&k);
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for(int i=0;i<n;i++){scanf("%d",&b[i]);}
long long  ll=0,hh=2000000022;
while(ll<hh){
    long long  mid=ll+(hh-ll+1)/2;
    if(ok(mid)){
       ans=max(ans,mid);
        ll=mid;
    }else{
    hh=mid-1;
    }

}
printf("%lld\n",ans);



    return 0;
}
