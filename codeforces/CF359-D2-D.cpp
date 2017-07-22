/*
 Quite simple note: if the pair (l, r) satisfies the condition 1 from the statements,
 then min(l, r) = GCD(l, r), where min(l, r) is smallest number ai from the segment (l, r) 
 and GCD(l, r) is a GCD of all numbers from the segment (l, r). 
 Calculate some data structure that will allow us to respond quickly to requests GCD(l, r) and min(l, r). 
  For example, you can use Sparce Table. Solutuions, that uses segment tree, is too slow. 
  So I think, you should use Sparce Table. So, now our task quite simple. 
  Let's use binary search to find greatest value of r - l:
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
const long long OO=4e18;
const int oo=1e9;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
int n ,lg[300001],sp[20][300000],a[300000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sp[0][i]=a[i];
    }
    lg[1]=0;
    for(int i=2;i<=n;i++){
        lg[i]=log2(i);
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i<n;i++){
            sp[j][i]=sp[j-1][i];
            if(i+(1<<(j-1))<n){
                sp[j][i]=__gcd(sp[j-1][i],sp[j-1][i+(1<<(j-1))]);
            }
        }
    }
    int mx=-1;
    vector<int> out;
    int l=0,h=n,mid,g;
    bool br=0;
    for(int i=0;i<n;i++){
        // binary search 3la Len
        l=1,h=n-i;
        int ll,rr;
        ll=rr=0;
        br=0;
        while(!br&&l<=h){
            mid=l+(h-l)/2;
            if(l==h){
                br=1;
            }
            g=__gcd(sp[lg[mid]][i],sp[lg[mid]][i+mid-(1<<lg[mid])]);
          //  cout<<g<<" "<<l<<" "<<h<<" "<<mid<<endl;
            if(g%a[i]==0){
                rr=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
       // cout<<rr<<" "<<i<<endl;
        br=0;
        l=1,h=i+1;
        while(!br&&l<=h){
            mid=l+(h-l)/2;
            if(l==h){
                br=1;
            }
            // new_idx= i-mid+1
            g=__gcd(sp[lg[mid]][(i-mid)+1],sp[lg[mid]][i+1-(1<<lg[mid])]);
            if(g%a[i]==0){
                ll=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
       // cout<<i<<" "<<ll<<" "<<rr<<endl;
        int len=rr+ll-2;
        if(len>mx){mx=len;out.clear();
        }
        if(len==mx){
            out.push_back(i-ll+2);
        }
    }
    vector<int> all;
    sort(out.begin(),out.end());
    for(int i=0;i<out.size();i++){
        if(i&&out[i]==out[i-1]){continue;}
        all.push_back(out[i]);
    }
    swap(all,out);
    printf("%d %d\n",(int)out.size(),mx);
    for(int i=0;i<(int)out.size();i++){
        if(i){
            printf(" ");
        }
        printf("%d",out[i]);
    }
    printf("\n");
    
    return 0;
}
