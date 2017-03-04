#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <set>
using namespace std;
const int MAX=100005;
map<int,int> p,r,l;
int foo,n;
vector<int> all;
int pp[MAX];
int main()
{
cin>>n;
set<int> a;
for(int i=0;i<n;i++){
    cin>>foo;
    all.push_back(foo);
      pair< set<int>::iterator ,bool> it=  a.insert(foo);
if(!i){continue;}
    if(it.first!=a.begin()){
   set<int>::iterator bb=it.first;
   bb--;
    if(!r.count(*bb)){
        r[*bb]=foo;
p[i]=*bb;
            }else{
bb++; // me
bb++; // next
     l[*bb]=foo;
p[i]=*bb;
            }
continue;
    }
if(it.first==a.begin()){
           set<int>::iterator bb=it.first;
bb++;
p[i]=*bb;
l[*bb]=foo;

continue;
}
}

for(int i=1;i<n;i++){
 if(i>1){cout<<" ";}
    cout<<p[i];

}

    return 0;
}
