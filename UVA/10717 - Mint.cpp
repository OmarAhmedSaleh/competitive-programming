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
int n ,t;
int arr[50],l;
int gcd(int aa,int bb){
    while(aa&&bb){
        if(aa>bb){
            aa%=bb;
        }else{
            bb%=aa;
        }
    
    }
    return aa+bb;
}
int lcm(int aa,int bb){
    return aa*(bb/gcd(aa,bb));
}
int main(){
  //  freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&t)==2){
        if(!n&&!t){
            break;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        for(int j=0;j<t;j++){
            scanf("%d",&l);
            int mn=0;
            int mx=1e9;
            for(int a=0;a<n;a++){
                for(int b=a+1;b<n;b++){
                    for(int c=b+1;c<n;c++){
                        for(int d=c+1;d<n;d++){
                            int lc=lcm(arr[a],lcm(arr[b],lcm(arr[c],arr[d])));
                            int dv=l/lc;
                            while(lc*dv>l&&dv>0){
                                dv--;
                            }
                            dv=l/lc;
                            mn=max(mn,lc*dv);
                            while(lc*dv<l){dv++;}
                            mx=min(mx,lc*dv);
                        }
                    }
                }
            }
            cout<<mn<<" "<<mx<<endl;
        }
    
    }
    return 0;
}
