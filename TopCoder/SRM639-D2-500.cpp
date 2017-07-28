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
/*
const long long OO=4e18;
const int oo=1e9;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
 */
class AliceGameEasy{
public:

    long long findMinimumValue(long long x, long long y){
        long long sum = 0;
        int ret = 0;
        int ok = -1;
        for(int i=0;i<=1e7;i++){
            sum+=i;
            if(sum==x+y){ok=i; break;}
            if(sum>x+y){return -1;}
        }
        //cout<<ok<<endl;
        while(ok&&x>0){
            ret++;
            x-=ok;
            ok--;
        }
        return ret;
    }
};
/*
int main(){
       return 0;
}
*/
