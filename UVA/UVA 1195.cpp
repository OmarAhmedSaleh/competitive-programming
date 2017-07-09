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
int n ,m , a, b , p,q,t;
bool isc[100005];
long long mx;
vector<int> all;
void check(int i,int j){
    double aa=(double)i/j;
    double bb=(double)a/b;
    //  printf("%.3lf %.3lf\n",aa,bb);
    if(aa<bb){
        return ;
    }
    if(aa>1){
        return ;
    }
    if(1LL*i*j>mx){
        mx=1LL*i*j;
        p=i,q=j;
    }
}
int main(){
    isc[0]=isc[1]=1;
    for(int i=4;i<100005;i+=2){
        isc[i]=1;
    }
    for(int i=3;i<100005;i+=2){
        if(isc[i]){continue;}
        for(int j=i;1LL*j*i<100005;j++){
            isc[i*j]=1;
        }
    }
    for(int i=2;i<100005;i++){
        if(isc[i]){continue;}
        all.push_back(i);
    }
    while(1){
        scanf("%d%d%d",&m,&a,&b);
        if(!m&&!a&&!b){break;}
        int g=__gcd(a,b);
        a/=g;
        b/=g;
        mx=-1;
        for(int i=0;i<all.size();i++){
            int rem=m/all[i];
            int pos=lower_bound(all.begin(),all.end(),rem)-all.begin();
            if(pos==all.size()){pos--;}
            if(pos>i){pos=i;}
            while(pos>-1&&1LL*all[pos]*all[i]>m){pos--;}
            if(pos==-1){continue;}
            check(min(all[i],all[pos]),max(all[i],all[pos]));
        }
        if(p>q){swap(p,q);}
        cout<<p<<" "<<q<<endl;
    }
    return 0;
}
