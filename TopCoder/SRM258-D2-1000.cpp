/*
find centroid point
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


class MissileTarget{
public:
    vector<int>X,Y;
    long long dis(int xx,int yy){
        long long sum=0;
        for(int i=0;i<X.size();i++){
            sum+=1LL*(xx-X[i])*(xx-X[i])+1LL*(yy-Y[i])*(yy-Y[i]);
        }
        return sum;
    }
    vector<int> all[2];
    vector<int> ret;
    int xxx,yyy;
    vector<int> bestFit(vector<int> x,vector<int> y){
        X=x;
        Y=y;
        for(int i=0;i<x.size();i++){
            xxx+=x[i];
            yyy+=y[i];
        }
        xxx/=(int)x.size();
        yyy/=(int)y.size();
        for(int i=0;i<100;i++){
            all[0].push_back(xxx-i);
            all[0].push_back(xxx+i);
        }
        for(int i=0;i<100;i++){
            all[1].push_back(yyy-i);
            all[1].push_back(yyy+i);
        }
        long long mn=1e18;
        for(int i=0;i<all[0].size();i++){
            for(int j=0;j<all[1].size();j++){
                long long cal=dis(all[0][i],all[1][j]);
                if(mn>cal){
                    mn=cal;
                    ret.clear();
                    ret.push_back(all[0][i]);
                    ret.push_back(all[1][j]);

                }
            }
        }
        
        return ret;
    }
    
};
/*


int main(){
   
   }
 */
