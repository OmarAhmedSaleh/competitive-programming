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
class CatAndRabbit{
public:
    string getWinner(string tiles){
        vector<int> all;
        int sz=(int)tiles.size();
        int n=0;
        for(int i=0;i<sz;i++){
            if(tiles[i]=='#'){
                all.push_back(i);
            }
        }
        if(!all.size()){
            return "Rabbit";
        }
        n=all[0];
        for(int i=0;i<(int)all.size()-1;i++){
            if(all[i+1]==all[i]+1){continue;}
            n^=(all[i+1]-all[i])-1;
        }
        
        n^=(sz-all.back())-1;
        if(!n){
        return "Rabbit";
        }
        return "Cat";
    }

};
/*
int main(){
       return 0;
}
*/
