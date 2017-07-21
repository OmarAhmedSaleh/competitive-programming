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
//const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
class LittleElephantAndIntervalsDiv2{
public:
    set<string> ss;
    string s;
    int getNumber(int M, vector <int> L, vector <int> R){
        int sz=(int)L.size();
        for(int i=0;i<sz;i++){
            L[i]--;R[i]--;
        }
        for(int i=0;i<(1<<sz);i++){
            s="";
            for(int i=0;i<M;i++){
                s+='0';
            }
            for(int j=0;j<sz;j++){
                for(int k=L[j];k<=R[j];k++){
                    if(i&(1<<j)){
                        s[k]=(char)'1';
                    }else{
                       s[k]=(char)'0';
                    }
                }
            }
            ss.insert(s);
        }
        return (int)ss.size();
    }
};
