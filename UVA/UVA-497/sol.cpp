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
const int N=10000007;
string s;
int a[N];
int lis[N];
int p[N];
int id[N];
int t;
int las;
void pr(int idx){
if(p[idx]==-1){
    cout<<a[idx]<<endl;
    return ;


}
pr(p[idx]);
cout<<a[idx]<<endl;
}
int main()
{
scanf("%d",&t);
cin.ignore();
cin.ignore();
while(t--){
        int sz=0;
   while(1){
    getline(cin,s);
    if(s.size()==0){break;}
    int mm=0;
    for(int i=0;i<s.size();i++){
mm*=10;
mm+=s[i]-'0';

    }
a[sz++]=mm;

   }

int mx=0;
for(int i=0;i<sz;i++){
    int pos=lower_bound(lis,lis+mx,a[i])-lis;
    lis[pos]=a[i];
    id[pos]=i;
    if(pos){p[i]=id[pos-1];}else{p[i]=-1;}
    if(pos==mx){
    mx=pos+1;
    las=i;
    }

}
printf("Max hits: %d\n",mx);
pr(las);
if(t){cout<<endl;}




}

    return 0;
}
