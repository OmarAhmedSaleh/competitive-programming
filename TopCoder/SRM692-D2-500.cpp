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
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
class Dubs{
public:
    long long count(long long L, long long R){
        long long ret=0;
        long long df=R-L;
        df/=100;
        long long a=10;
        while(df){
            if(df%10 != 0 ){
                ret+=a*(df%10);
                L+=1LL*(df%10)*a*10;
              //  cout<<L<<endl;
            }
            a*=10;
            df/=10;
        }
       // cout<<L<<" "<<R<<endl;
        while(L<=R){
            if(L%10 == (L%100)/10){
                ret++;
            }
            L++;
        }
        return ret;
    }
};
