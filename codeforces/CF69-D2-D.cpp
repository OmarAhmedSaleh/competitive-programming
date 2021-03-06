/*
How to reflect a point over the y=x axis
    https://www.youtube.com/watch?v=GyaGjC8xgKk
 swap(x,y)
 
 
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
//const long long OO=4e18;
//const int oo=1e9;
int n ,x[22],y[22],d;
int dis(int xx, int yy){
    return xx*xx + yy*yy;
}
int memo[401][401][2][2][2];
int solve(int xx,int yy,int r1,int r2,int turn){
    if(dis(xx,yy)>d){
        return 1;
    }
    if(memo[xx+200][yy+200][r1][r2][turn]!=-1){
        return memo[xx+200][yy+200][r1][r2][turn];
    }
    int win=0;
    if(turn&&!r2){
        win|=!solve(yy,xx,r1,1,turn^1);
    }
    if(!turn&&!r1){
        win|=!solve(yy,xx,1,r2,turn^1);
    }
    for(int i=1;i<=n;i++){
        win|=!solve(xx+x[i],yy+y[i],r1,r2,turn^1);
    }
    return memo[xx+200][yy+200][r1][r2][turn]=win;
}
int main(){
    scanf("%d%d%d%d",&x[0],&y[0],&n,&d);
    d*=d;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    memset(memo,-1,sizeof(memo));
    if(solve(x[0],y[0],0,0,0)){
        cout<<"Anton"<<endl;
    }else{
        cout<<"Dasha"<<endl;
    }
    return 0 ;
}
