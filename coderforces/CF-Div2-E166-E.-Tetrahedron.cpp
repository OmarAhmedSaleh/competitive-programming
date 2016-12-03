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
// http://codeforces.com/contest/166/problem/E
const int MOD=1000000007;
vector<vector<long long > > id;
int n;
vector<vector<long long > > mat(4,vector<long long> (4));
vector<vector<long long > > mul(vector<vector<long long > > a,vector<vector<long long > > b){
    vector<vector<long long > > ret(a.size(),vector<long long >(b[0].size()));
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            for(int k=0;k<b.size();k++){
                if(a[i][k]>MOD){a[i][k]%=MOD;}
                if(b[k][j]>MOD){b[k][j]%=MOD;}
                ret[i][j]+=(1LL*a[i][k]*b[k][j]);
                if(ret[i][j]>MOD){ret[i][j]%=MOD;}
            }
        
        }
    }

    return ret;
        }
vector<vector<long long > > pow(vector<vector<long long > > a,int k){
    if(k==1){
        return a;
    }
    vector<vector<long long > > ret(a.size(),vector<long long > (a[0].size()));
    if(k&1){
        return ret=mul(a,pow(a,k-1));
    }
    ret=pow(a,k/2);
    return ret=mul(ret,ret);}
int main(){
    scanf("%d",&n);
    id.resize(4,vector<long long > (4,0));
    
    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            mat[i][j]=1;
        }
    }
    for(int i=0;i<4;i++){
        id[i][i]=1;
        mat[i][i]=0;
    }
   mat=pow(mat,n);
    if(mat[0][0]>MOD){mat[0][0]%=MOD;}
    printf("%lld\n",mat[0][0]);
    return 0;}
