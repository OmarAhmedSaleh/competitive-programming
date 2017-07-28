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
int n ;
bool sp=0;
long long d;
int cnt[5];
bool ok(int x, int y){
    return 4*(1LL*(x-n)*(x-n)+1LL*(y-n)*(y-n))<=d;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        if(!sp){sp=1;}else{printf("\n");}
        d=2*n -1;
        d*=d;
        for(int i=0;i<5;i++){
            cnt[i]=0;
        }
        for(int i=1;i<=2*n;i++){
            for(int j=1;j<=2*n;j++){
                int c=0;
                for(int ii=0;ii<2;ii++){
                    for(int jj=0;jj<2;jj++){
                        if(ok(i-ii,j-jj)){
                            c++;
                        }
                    }
                }
                cnt[c]++;
            }
        }
        for(int i=2;i<4;i++){cnt[i]+=cnt[i-1];}
        printf("In the case n = %d, %d cells contain segments of the circle.\nThere are %d cells completely contained in the circle.\n",n,cnt[3],cnt[4]);
    }
    return 0;
}
