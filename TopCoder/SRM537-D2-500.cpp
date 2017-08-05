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
class KingXNewCurrency{
public:
    bool isok(int a, int x,int y){
        for(int i =0;x*i<=a;i++){
            if((a-x*i)%y==0){return 1;}
        }
        return 0;
    }
    int howMany(int A, int B, int X){
        if((A%X)== 0 &&(B%X)== 0){return -1;}
        int ret=0;
        for(int i=1;i<=1e3;i++){
            ret+=isok(A,X,i)&&isok(B,X,i);
        }
        return ret;
    }
};
