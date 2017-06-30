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

int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
class Quacking{
public:
    vector<int> let[26];
    string Q="quack";
    int pos[5]={-1,-1,-1,-1,-1};
    int quack(string s){
        int ret=0;
        int sz=(int)s.size();
        for(int i=0;i<sz;i++){
            let[s[i]-'a'].push_back(i);
            ret=max(ret,(int)let['q'-'a'].size());
            if(!let['q'-'a'].size()){
                continue;
            }
            pos[0]=0;
            char c='q';
            bool bad=0;
            for(int j=1;j<5;j++){
                c=Q[j];
                pos[j]=(int)(lower_bound(let[c-'a'].begin(),let[c-'a'].end(),let[Q[j-1]-'a'][pos[j-1]])-let[c-'a'].begin());
                if(pos[j]==let[c-'a'].size()){
                    bad=1;
                    break;
                }
            }
            if(bad){
                continue;
            }
            for(int j=0;j<5;j++){
                let[Q[j]-'a'].erase(let[Q[j]-'a'].begin()+pos[j]);
            }
        }
        for(int j=0;j<5;j++){
            if(let[Q[j]-'a'].size()){
                return -1;
            }
        }
        return ret;
    }
};
