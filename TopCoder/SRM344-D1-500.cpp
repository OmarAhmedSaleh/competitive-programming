/**/

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
class QuantumAlchemy{
    public:
    bool bad=0;
    int call;
    int have[26];
    string let[26];
    bool waiting[26];
    void fun(int idx){
        if(have[idx]){return ;}
        call++;
        if(let[idx]==""){
            bad=1;
            return ;
        }
        bool all=1;
        for(int i=0;i<(int)let[idx].size();i++){
            if(!have[let[idx][i]-'A']&&!waiting[let[idx][i]-'A']){
                waiting[let[idx][i]-'A']=1;
                fun(let[idx][i]-'A');
                waiting[let[idx][i]-'A']=0;
            }
            all&=have[let[idx][i]-'A']>0;
            have[let[idx][i]-'A']--;
        }
        if(!all){
            bad=1;
            return;
        }
        have[idx]++;
    }
    int minSteps(string initial,vector<string> reactions){
        memset(have,0,sizeof(have));
        for(int i=0;i<(int)initial.size();i++){
            have[initial[i]-'A']++;
        }
        memset(waiting ,0,sizeof(waiting));
        for(int i=0;i<26;i++){let[i]="";}
        for(int i=0;i<(int)reactions.size();i++){
            let[reactions[i].back()-'A']=reactions[i].substr(0,(int)reactions[i].size()-3);
        }
        bad=0;
        fun('X'-'A');
        if(bad){return -1;}
        return call;
    }
};
