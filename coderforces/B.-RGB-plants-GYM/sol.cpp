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
// http://codeforces.com/gym/101061/problem/B
const long long MOD=1000000007;
int len;
vector<vector<long long> > mat(3,vector<long long> (3));
vector<vector<long long> > tr(3,vector<long long> (3));
vector<vector<long long> > id(3,vector<long long> (3));

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
    if(k==0){
        return id;
    }
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
        scanf("%d",&m);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mat[i][j]=0;
                id[i][i]=i;
            }
        }mat[0][0]=mat[0][1]=mat[0][2]=1;
        int cnt=1;
        for(int i=0;i<tr.size();i++){
            for(int j=0;j<tr[i].size();j++){
                tr[i][j]=cnt++;
            }
        }
        
        tr=pow(tr,m-1);
        mat=mul(mat,tr);
        
        printf("%lld\n",(mat[0][0]+mat[0][2]+mat[0][1])%MOD);
    }
    return 0;}
