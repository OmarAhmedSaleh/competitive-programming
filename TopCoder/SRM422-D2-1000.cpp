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
class BirthdayCake{
public:
int howManyFriends(vector <string> availableFruits, vector <string> friendsDislikings, int K){
bool fr[55];
bool le[55];
vector<int> mark[55];
vector<int> e[22];
map<string,int> mp;
mp.clear();
int n=(int)availableFruits.size();
int m=(int)friendsDislikings.size();
for(int i=0;i<n;i++){
    mp[availableFruits[i]]=i;
}

string s;
for(int i=0;i<m;i++){
    s="";
    for(int j=0;j<friendsDislikings[i].size();j++){
    if(friendsDislikings[i][j]==' '){
        if(mp.count(s)){
           mark[mp[s]].push_back(i);
        e[i].push_back(mp[s]);
        }
    s="";
    continue;
    }
     s+=friendsDislikings[i][j];
    }
    if(s.size()&&mp.count(s)){
            mark[mp[s]].push_back(i);
            e[i].push_back(mp[s]);
                    }
}

   int ret=0;
   int qq=0;
   for(int mask=0;mask<(1<<m);mask++){
    memset(le,0,sizeof(le));
    memset(fr,0,sizeof(fr));
    for(int i=0;i<m;i++){
    if(!(mask&(1<<i))){continue;}
    s="";
    qq++;
    for(int j=0;j<e[i].size();j++){
        le[e[i][j]]=1;

    }
        }
        int tt=0;
        for(int i=0;i<n;i++){
            if(le[i]){tt++;}
            }
        if(n-tt<K){continue;}
        for(int f=0;f<n;f++){
            if(!le[f]){
                for(int j=0;j<mark[f].size();j++){
                    fr[mark[f][j]]=1;
                }

            }

        }
        int sum=0;
        for(int f=0;f<m;f++){
            sum+=(!fr[f]);
            }
        ret=max(sum,ret);
        }


return ret;
}

};
