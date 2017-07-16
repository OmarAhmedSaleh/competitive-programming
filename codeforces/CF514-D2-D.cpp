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
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
int n, m , a[100000][5], sp[5][20][100000], k , rq[5], ans[5], mx,lg[100001];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            sp[j][0][i]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        lg[i]=log2(i);
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i<n;i++){
            for(int mm=0;mm<m;mm++){
                sp[mm][j][i]=sp[mm][j-1][i];
                if(i+(1<<(j-1))<n){
                    sp[mm][j][i]=max(sp[mm][j][i],sp[mm][j-1][i+(1<<(j-1))]);
                }
            }
        }
    }
    int l=0,tot=0,h=n,mid;
    bool br=0;
    for(int i=0;i<n;i++){
        l=1,h=n-i;
        br=0;
        while(!br&&l<=h){
            mid=l+(h-l)/2;
            if(l==h){
                br=1;
            }
            tot=0;
            for(int j=0;j<m;j++){
                rq[j]=max(sp[j][lg[mid]][i],sp[j][lg[mid]][i+mid-(1<<lg[mid])]);
                tot+=rq[j];
            }
            if(tot<=k){
                l=mid+1;
                if(mid>mx){
                    mx=mid;
                    for(int j=0;j<m;j++){
                        ans[j]=rq[j];
                    }
                }
            }else{
                h=mid-1;
            }
        }
    }
   // printf("%d\n",mx);
    for(int i=0;i<m;i++){
        if(i){printf(" ");}
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
