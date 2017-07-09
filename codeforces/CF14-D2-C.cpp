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
struct seg{
    int x[2],y[2];
};
seg all[4],temp[4];
int a[4];
long long dis(seg s){
    return 1LL*(s.x[0]-s.x[1])*(s.x[0]-s.x[1])+1LL*(s.y[0]-s.y[1])*(s.y[0]-s.y[1]);

}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    seg s;
    for(int i=0;i<4;i++){
        scanf("%d%d%d%d",&s.x[0],&s.y[0],&s.x[1],&s.y[1]);
        temp[i]=s;
        a[i]=i;
        if(!dis(temp[i])){
            puts("NO");
            return 0;
        }
    }
    do{
    // u d l r
        for(int i=0;i<4;i++){
            all[i]=temp[a[i]];
        }
        if(dis(all[0])!=dis(all[1]) || dis(all[2])!=dis(all[3])){
            continue;
        }
        for(int i=2;i<4;i++){
            if(all[i].y[1]<all[i].y[0]){
                swap(all[i].y[1],all[i].y[0]);
                swap(all[i].x[0],all[i].x[1]);
            }
        }
        for(int i=0;i<2;i++){
            if(all[i].x[1]<all[i].x[0]){
                swap(all[i].y[1],all[i].y[0]);
                swap(all[i].x[0],all[i].x[1]);
            }
        }
        if(all[2].x[0]!=all[1].x[0] || all[2].y[0]!=all[1].y[0]){
            continue;
        }
        if(all[2].x[1]!=all[0].x[0] || all[2].y[1]!=all[0].y[0]){
            continue;
        }
        if(all[3].x[0]!=all[1].x[1] || all[3].y[0]!=all[1].y[1]){
            continue;
        }
        if(all[3].x[1]!=all[0].x[1] || all[3].y[1]!=all[0].y[1]){
            continue;
        }
        
        if(all[0].x[0]!=all[1].x[0] || all[0].x[1]!=all[1].x[1]){
            continue;
        }
        
        if(all[2].y[0]!=all[3].y[0] || all[2].y[1]!=all[3].y[1]){
            continue;
        }
        puts("YES");
        return 0;
        
    }while(next_permutation(a,a+4));
    puts("NO");
    return 0;
}
