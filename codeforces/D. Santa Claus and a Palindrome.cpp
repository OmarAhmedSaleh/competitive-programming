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
using namespace std;

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int k,n,a;
string s;
map<string ,vector<int> > mp;
set<string> same;
int main(){
scanf("%d%d",&k,&n);
set<string>st;
for(int i=0;i<k;i++){
    cin>>s;
    scanf("%d",&a);
    mp[s].push_back(a);
    string temp=s;
    reverse(temp.begin(),temp.end());
    if(temp==s){
        same.insert(s);
    }else{
        st.insert(s);
    }

}
long long ans=0;
set<string> ::iterator it=st.begin();
    while(it!=st.end()){
    s=*(it);
    sort(mp[s].begin(),mp[s].end());
    it++;}
    it=st.begin();
    while(it!=st.end()){
    s=*(it);
    string rev=*(it);
    reverse(rev.begin(),rev.end());
    while(mp[rev].size()&&mp[s].size()){
        int sum=mp[s].back()+mp[rev].back();
            if(sum<0){break;}
            ans+=sum;
            mp[s].pop_back();
            mp[rev].pop_back();
    }
it++;
}
    it=same.begin();
     while(it!=same.end()){
    s=*(it);
    sort(mp[s].begin(),mp[s].end());
    it++;}
        it=same.begin();

    while(it!=same.end()){
    s=*(it);
  while(mp[s].size()>1){
        int sz=mp[s].size();
        int sum=mp[s].back()+mp[s][sz-2];
            if(mp[s].back()<0||mp[s][sz-2]<0){break;}
            ans+=sum;
            mp[s].pop_back();
            mp[s].pop_back();
    }

    it++;
}
vector<pair<int,int > > all;
   int pp=0;




it=same.begin();
long long oo=0;
while(it!=same.end()){
    s=*(it);
    vector<int> e=mp[s];
    if(e.size()>1){
        int aa=e.back();
        int ss=e[e.size()-2];
        if(aa<0){mp[s].clear();}
        if(aa>0&&ss<0){
            if(abs(ss)>=aa){
                mp[s].clear();
                mp[s].push_back(aa);

            }

        }

    }
it++;
}

 it=same.begin();
    while(it!=same.end()){
    s=*(it);
  if(mp[s].size()==1){
    if(pp<mp[s].back()){
        pp=mp[s].back();
    }
   }
it++;
}

it=same.begin();

    while(it!=same.end()){
    s=*(it);
    vector<int> e=mp[s];
    vector<int>l,g;
  while(e.size()>1){
        if(e.back()<0){break;}
        g.push_back(e.back());
        e.pop_back();
        l.push_back(e.back());
        e.pop_back();
    }
    for(int i=0;i<g.size();i++){
        if(i>=l.size()){break;}
        if(g[i]>0&&l[i]<0&&g[i]>abs(l[i])){
     all.push_back(make_pair(g[i],l[i]));
     oo+=(g[i]+l[i]);
        }
    }

   it++;
}
long long c1=oo+pp;
long long c2=0;
for(int i=0;i<all.size();i++){
    long long kk=oo;
    kk-=(all[i].first+all[i].second);
    c2=max(c2,kk+all[i].first);
}
printf("%lld\n",ans+max(c1,c2));
return 0;}
