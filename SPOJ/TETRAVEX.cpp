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
struct node{
    int t,b,l,r;
};
node a[3][3];
int t;
node all[9];

int main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        vector<int> ord;
        for(int i=0;i<9;i++){
            ord.push_back(i);
            scanf("%d%d%d%d",&all[i].t,&all[i].l,&all[i].b,&all[i].r);
        }
        int idx=0;
        bool ok=1;

        do{
            idx=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    a[i][j]=all[ord[idx++]];
                }
            }
            ok=1;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i&&a[i][j].t!=a[i-1][j].b){
                        ok=0;
                    }
                    if(j&&a[i][j].r!=a[i][j-1].l){
                        ok=0;
                    }
                    if(i+1<3&&a[i][j].b!=a[i+1][j].t){
                        ok=0;
                    }
                    if(j+1<3&&a[i][j].l!=a[i][j+1].r){
                        ok=0;
                    }
                
                }
            }
            if(ok){break;}
        }while(next_permutation(ord.begin(),ord.end()));
        printf("Case %d: \n",tt);
        if(ok){
            puts("YES");
            
        }else{
            puts("NO");
            
        }
        if(tt<t){
            cout<<endl;
        }
    
    
    }
    
    return 0;
}
*/
 
