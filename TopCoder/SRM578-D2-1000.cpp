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
const int md=1000000007;

class WolfInZooDivTwo{
public:
    int p[301],n;
    long long memo[300][2501];
    vector<int> ll,rr;
    long long solve(int i,int j){
        if(j==rr.size()){
            return p[n-i];
        }
        if(i>=n){return 0;}
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(i>rr[j]){
            return 0;
        }
        int new_j=j;
        // take
        while(new_j<(int)rr.size() && i>=ll[new_j]&&i<=rr[new_j]){new_j++;}
        long long ans=solve(i+1,new_j);
        if(ans>md){ans-=md;}
        ans+=solve(i+1,j);
        if(ans>md){ans-=md;}
        return memo[i][j]=ans;
    }
    void go(vector<string> &a,vector<int> &b){
        int s=-1;
        string temp="";
        for(int i=0;i<a.size();i++){
            temp+=a[i];
        }
        for(int i=0;i<(int)temp.size();i++){
            if(temp[i]!=' '){
                s=max(s,0);
                s*=10;
                s+=temp[i]-'0';
            }
            if(temp[i]==' '||i+1==(int)temp.size()){
                if(s!=-1){
                    b.push_back(s);
                    s=-1;
                }
                continue;
            }
        }
    }
    int count(int N , vector<string> l , vector<string> r){
        memset(memo,-1,sizeof(memo));
        p[0]=1;
        n=N;
        for(int i=1;i<301;i++){
            p[i]=(1LL*p[i-1]<<1)%md;
        }

        go(l,ll);go(r,rr);
        for(int i=0;i<ll.size();i++){
            if(ll[i]>rr[i]){swap(ll[i],rr[i]);}
        }
        for(int i=0;i<(int)ll.size();i++){
            for(int j=i+1;j<(int)ll.size();j++){
                if(ll[j]<ll[i]){
                    swap(ll[i],ll[j]);
                    swap(rr[i],rr[j]);
                    continue;
                }
                if(ll[i]==ll[j]&&rr[j]<rr[i]){
                    swap(ll[i],ll[j]);
                    swap(rr[i],rr[j]);
                    
                }
            }
        }
        /*
        cout<<(int)ll.size()<<" SZ "<<(int)rr.size()<<endl;
        for(int i=0;i<ll.size();i++){
            cout<<ll[i]<<" "<<rr[i]<<endl;
        }
         */
        return (int)solve(0,0);
    }

};

