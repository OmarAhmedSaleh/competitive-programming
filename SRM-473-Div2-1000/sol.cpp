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
// ss
using namespace std;
class ChildlessNumbers{
public:
    int howMany(int A, int B){
        int ret=0;
        while(A<=B){
            bool ok=1;
            for(int i=1;i<1001;i++){
                long long ydx=1LL*i*A;
                long long t=ydx;
                int sum=0;
                while(t){
                    sum+=t%10;
                    t/=10;
                }
                if(sum==i){ok=0;break;}
                
            }
            ret+=ok;
            A++;
        }
        
        
        
        return ret; }
};
