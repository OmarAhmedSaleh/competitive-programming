
/*
 a^n + b^n = (a+b)*(a^(n-1)+b^(n-1)) - (ab)*(a^(n-2)+b^(n-2))
 mat[0][0]=(a^(n-1)+b^(n-1));
 mat[0][1]=(a^(n-2)+b^(n-2));
 
 trasition matrix  = tr
 tr[0][0]=(a+b);
 tr[0][1]=1;
 tr[1][0]=-(ab);

 (a^n + b^n)=(mat*(tr^(n-1)))[0][0];
 
 
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

vector<vector<long long> > mat(2,vector<long long> (2));
vector<vector<long long> > tr(2,vector<long long> (2));
vector<vector<long long> > mul(vector<vector<long long> > a, vector<vector<long long> > b){
    vector<vector<long long> > ret(a.size(),vector<long long> (b[0].size()));
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            for(int k=0;k<a[0].size();k++){
                ret[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return ret;
}

vector<vector<long long> > pow(vector<vector<long long> > a,int k){
    if(k==1){
        return a;
    }
    vector<vector<long long> > ret(a.size(),vector<long long> (a.size()));
    if(k&1){
        return mul(a,pow(a,k-1));
    }
    ret=pow(a,k/2);
    return mul(ret,ret);
}
int n, p,q;
int main(){
    while(scanf("%d%d%d",&p,&q,&n)==3){
        if(!p&&!q&&!n){break;}
        
        mat[0][0]=p;
        mat[0][1]=2;
        mat[1][0]=0;
        mat[1][1]=0;
        
        tr[0][0]=p;
        tr[0][1]=1;
        tr[1][0]=-q;
        tr[1][1]=0;
        if(n==1){
            printf("%d\n",p);
        }
        if(n==0){
            printf("%d\n",2);
        }
        if(n>1){
            tr=pow(tr,n-1);
            mat=mul(mat,tr);
            printf("%lld\n",mat[0][0]);
        }
    }
    return 0;}
