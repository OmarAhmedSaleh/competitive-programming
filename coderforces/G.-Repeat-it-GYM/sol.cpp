#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

using namespace std;
// http://codeforces.com/gym/101061/problem/G
const long long MOD=1000000007;
int len;
vector<vector<long long> > mat(2,vector<long long> (2));
vector<vector<long long> > tr(2,vector<long long> (2));

vector<vector<long long> > mul(vector<vector<long long> > a, vector<vector<long long> > b){
    vector<vector<long long> > ret(a.size(),vector<long long> (b[0].size()));
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            for(int k=0;k<a[0].size();k++){
                if(a[i][k]>MOD){a[i][k]%=MOD;}
                if(b[k][j]>MOD){b[k][j]%=MOD;}
                ret[i][j]+=a[i][k]*b[k][j];
                if(ret[i][j]>MOD){ret[i][j]%=MOD;}
                }
            }
        }
    return ret;}

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

int m , re;
int t ;
int main(){
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&re,&m);
    mat[0][0]=m;
    mat[0][1]=m;
    mat[1][0]=0;
    mat[1][1]=0;
    tr[0][0]=tr[0][1]=1;
    tr[1][0]=0;
    int ww=m;
    len=0;
    while(ww){
        len++;
        ww/=10;
    }
    tr[1][1]=1;
    for(int i=0;i<len;i++){
        tr[1][1]*=10;
    }
        if(re>1){
    tr=pow(tr,re-1);
    mat=mul(mat,tr);
        }
        printf("%lld\n",mat[0][1]);
    }
    return 0;}
