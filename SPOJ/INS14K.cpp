/**/

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
int n , t , q , ty;
vector<pair< int , int > > all;
int main(){
    scanf("%d",&t);
    while(t-->0){
        scanf("%d",&n);
        all.clear();
        double xx[2],yy[2];
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                scanf("%lf %lf",&xx[j],&yy[j]);
            }
            if(xx[0]>xx[1]){swap(xx[0],xx[1]);}
            all.push_back(make_pair(xx[0],xx[1]));
        }
        scanf("%d",&q);
        while(q-->0){
            scanf("%d",&ty);
            if(ty){
                for(int j=0;j<2;j++){
                    scanf("%lf %lf",&xx[j],&yy[j]);
                }
                if((int)xx[0]>(int)xx[1]){swap(xx[0],xx[1]);}
                all.push_back(make_pair(xx[0],xx[1]));
            }else{
                scanf("%lf",&xx[0]);
                int ans=0;
                for(int i=0;i<all.size();i++){
                    if((all[i].first<=xx[0]) && (all[i].second>=xx[0])){
                        ans++;
                    }
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
