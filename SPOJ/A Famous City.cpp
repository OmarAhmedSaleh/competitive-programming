/*
- you can see the highest building (at this moment)
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
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

int n ,a;
vector<int> v;
int ans;
int tt;
int main(){
    while(scanf("%d",&n)==1){;
        ans=0;
        v.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(!v.size()||v.back()<a){
                if(a){
                v.push_back(a);
                }
            }else{
                while(v.size()){
                    if(v.back()==a){v.pop_back();break;}
                    if(v.back()>a){ans++;v.pop_back();}
                    if(v.back()<a){break;}
                }
                if(a){
                v.push_back(a);
            }
            }
        }
        ans+=v.size();
        printf("Case %d: %d\n",++tt,ans);
        
    }
    return 0;//rev Ab steps
}
