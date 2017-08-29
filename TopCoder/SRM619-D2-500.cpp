/*
 CF844-D2-C
 */

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

class ChooseTheBestOne{
public:
    int countNumber(int N){
        vector<int> all;
        for(int i=1;i<=N;i++){all.push_back(i);}
        int cur=0;
        for(int turn=1;turn<N;turn++){
            long long req=1LL*turn*turn*turn;
            req--;
            int md=req%((int)all.size());
            //cout<<req<<" "<<all.size()<<" "<<md<<endl;
            for(int i=0;i<md;i++){
                cur++;
                cur%=(int)all.size();
            }
            //cout<<cur<<endl;
            all.erase(all.begin()+cur);
            if(cur>=all.size()){cur=0;}
        }
        return all.back();
    }
};
