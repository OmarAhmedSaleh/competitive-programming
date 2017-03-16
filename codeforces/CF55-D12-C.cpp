 /*
 
if first player can move pie to (first, last) (row,col) before second ban (4 corners ) , first player will be the winner 

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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

int n,m,k,x,y;
bool win;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&x,&y);
        if(x-1<5||n-x<5||y-1<5||m-y<5){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
   return 0;//rev Ab steps
}
