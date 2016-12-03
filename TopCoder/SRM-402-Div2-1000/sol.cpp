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
class RandomSort{
public:
    map<vector<int> ,double >memo;
    double getExpected(vector <int> permutation){
        double ret=0.0;
        int numofp=0;
        if(memo.count(permutation)){return memo[permutation];}
        for(int i=0;i<(int)permutation.size();i++){
            for(int j=i+1;j<(int)permutation.size();j++){
                if(permutation[i]>permutation[j]){
                    swap(permutation[i],permutation[j]);
                    ret+=1+getExpected(permutation);
                    // swap + answer of  subproblem
                    numofp++;
                    swap(permutation[i],permutation[j]);

                
                }
                
            }
        }
        // handle case if numofp == 0
        if(numofp==0){
            return memo[permutation]=0.0;
        }
        // Expectation = sum of number of swaping * pro(swaping)
        return memo[permutation]=ret/numofp;}

};




