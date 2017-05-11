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
int n , Ephi[1000006];
bool iscomp[1000006];
vector<int> all;
long long k;
void eulerPhi(int aa){
    int ans=aa;
    int idx=aa;
    for(int i=0;i<all.size();i++){
        if(aa!=1&&aa>=1LL*all[i]*all[i]){
            if(aa%all[i]==0){ans-=ans/all[i];}
            while(aa%all[i]==0){aa/=all[i];}
        }else{
            break;
        }
    
    }
    if(aa!=1){ans-=ans/aa;}
    Ephi[idx]=ans;
   
}
int main(){
    iscomp[0]=iscomp[1]=1;
    for(int i=4;i<=1000006;i+=2){
        iscomp[i]=1;
    }
    for(int i=3;i<=1000006;i+=2){
        if(!iscomp[i]){
            for(int j=i+i;j<=1000006;j+=i){
                iscomp[j]=1;
            }
        }
    }
    for(int i=1;i<1000006;i++){
        if(!iscomp[i]){
            all.push_back(i);
        }
    }
    Ephi[1]=2;
    for(int i=2;i<1000006;i++){
        eulerPhi(i);
    }
    while(cin>>k){
        if(!k){break;}
        int idx=0;
        for(int i=0;i<1000006;i++){
            if(k<=Ephi[i]){idx=i;break;}
            k-=Ephi[i];
        }
        for(int i=0;i<=idx;i++){
            if(__gcd(i,idx)==1){
                k--;
                if(!k){
                    cout<<i<<"/"<<idx<<endl;
                    break;
                }
            }
        
        }
    }
    
    return 0;
}
