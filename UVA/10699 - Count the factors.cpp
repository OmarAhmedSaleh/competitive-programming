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
int n , dif[1000006];
int main(){
    for(int i=2;i<=1000006;i++){
        if(!dif[i]){
            for(int j=i;j<=1000006;j+=i){
                dif[j]++;
            }
        
        }
    
    }
    while(scanf("%d",&n)==1){
        if(!n){break;}
        cout<<n<<" : "<<dif[n]<<endl;
    }
    return 0;
}
