
/*
From the track description follows that Maria moves the way that the water always located to the right from her,
so she could fall into the water only while turning left.
To check if the turn is to the left, let's give every Maria's moves directions a number: moving to the north — 0, moving to the west — 1, to the south — 2 and to the east — 3.
Then the turn is to the left if and only if the number of direction after performing a turn dir is equal to the number before performing a turn oldDir plus one modulo 4 .
This solution has complexity O(n).
One can solve this problem in alternative way. 
Let the answer be equal to x (that means that the number of inner corners of 270 degrees equals x, but the number of inner corners of 90 degrees to n - x).
As soon as the sum of the inner corners' values of polygon of n vertices is equal to 180 × (n - 2), then x × 270 + (n - x) × 90 equals to 180 × (n - 2). 
This leads us to , being the answer for the problem calculated in O(1)
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
int n,x[1001],y[1001],dir[1001];

int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    // U D R L
    // 0 1 2 3
    int ans=0;
    for(int i=0;i<n;i++){
        int xx=x[i+1],yy=y[i+1];
        if(x[i]==xx){
            if(y[i]<yy){
                dir[i]=0;
            }else{
                dir[i]=1;
            }
        }
        if(y[i]==yy){
            if(x[i]<xx){
                dir[i]=2;
            }else{
                dir[i]=3;
            }
        }
    }
    // U -> L
    // D -> R
    // R -> U
    // L -> D
    for(int i=0;i<n;i++){
        if(dir[i]==0&&dir[i+1]==3){
            ans++;
        }
        if(dir[i]==1&&dir[i+1]==2){
            ans++;
        }
        if(dir[i]==2&&dir[i+1]==0){
            ans++;
        }
        if(dir[i]==3&&dir[i+1]==1){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
