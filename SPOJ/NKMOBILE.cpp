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
// ss
using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

const int N=1044;
int bit[N][N];
int c, v, r1, r2, c1, c2, s;
void update(){
    int x=r1;
    while(x<=s){
    int y=c1;
        while(y<=s){
            bit[x][y]+=v;
            y+=(y&(-y));
        }
        x+=(x&(-x));
    }
}
int get(int x,int y){
    int ret=0;
    while(x>0){
        int y1=y;
        while(y1>0){
            ret+=bit[x][y1];
            y1-=(y1&(-y1));
        
        }
        x-=(x&(-x));
    }
    return ret;
}

int main(){
    while(scanf("%d",&c)==1){
        if(c==3){
            break;
        }
        if(c==0){
            scanf("%d",&s);
            memset(bit,0,sizeof(bit));
            continue;
        }
        if(c==1){
            scanf("%d%d%d",&r1,&c1,&v);
            update();
            continue;
        }
        if(c==2){
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            printf("%d\n",get(r2,c2)-get(r2,c1-1)-get(r1-1,c2)+get(r1-1,c1-1));
            continue;
        }
    }
    
    
    
    
    return 0;//rev Ab steps
}
