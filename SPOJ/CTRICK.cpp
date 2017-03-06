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
int bit[20003];
void add(int x,int val){
    while(x<20003){
        bit[x]+=val;
        x+=(x&(-x));
    }
}
int get(int x){
    int ret=0;
    while(x>0){
        ret+=bit[x];
        x-=(x&(-x));
    }
    return ret;
}
int t, out[20003],n;
int main(){
    scanf("%d",&t);
    while(t--){
        memset(bit,0,sizeof(bit));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            add(i,1);
        }
        // need move+1
        int move=1;
        int sz=n;
        for(int i=1;i<=n;i++){
            move+=i;
            move%=sz;
            if(!move){move=sz;}
            sz--;
            int l=0,h=n;
            // FFFFFFTTTTTT
            while(l<h){
                int mid=(l+h)>>1;
                if(get(mid)>=move){
                    h=mid;
                }else{
                    l=mid+1;
                }
            }
            out[h]=i;
            add(h,-1);
        }
        for(int i=1;i<=n;i++){
            if(i>1){printf(" ");}
            printf("%d",out[i]);
        }
        puts(" ");;
    }
    return 0;
}
