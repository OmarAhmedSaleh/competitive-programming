/*
try all permutations of messages.
 
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
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int tt=1,cur,ans,n,m,sz[6],mx;
map<int,int> to[6],pass[6];
struct pac{
    int a,b,c;
};
pac pp;
vector<pac> all;
vector<int> p;

int main(){
    while(scanf("%d%d",&n,&m)==2){
        if(!n&&!m){break;}
        p.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&sz[i]);
            p.push_back(i);
        }
        all.clear();
        cur=0;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&pp.a,&pp.b,&pp.c);
            all.push_back(pp);
             }
        ans=1e9;
        do{
            int pos=0;
            for(int i=1;i<=n;i++){
                pass[i].clear();to[i].clear();
                pass[i][0]=1;
            }
            cur=0;
             mx=0;
            for(int i=0;i<m;i++){
                pp=all[i];
                if(pp.a==p[pos]){
                    if(pass[p[pos]].count(pp.b-1)){
                        pass[pp.a][pp.c]=1;
                        int q=pp.c;
                        while(to[p[pos]].count(q+1)){
                            pass[p[pos]][to[p[pos]][q+1]]=1;
                            cur-=to[p[pos]][q+1]-q;
                            q=to[p[pos]][q+1];
                        }
                       while(pos+1<n&&q==sz[p[pos]]){
                           pos++;
                           q=0;
                           while(to[p[pos]].count(q+1)){
                               pass[p[pos]][to[p[pos]][q+1]]=1;
                               cur-=to[p[pos]][q+1]-q;
                               q=to[p[pos]][q+1];
                           }
                        }
                    }else{
                        to[pp.a][pp.b]=pp.c;
                        cur+=(pp.c-pp.b)+1;
                    }
                }else{
                    to[pp.a][pp.b]=pp.c;
                    cur+=(pp.c-pp.b)+1;
                }
                mx=max(cur,mx);
            }
            ans=min(ans,mx);
        }while(next_permutation(p.begin(), p.end()));
        printf("Case %d: %d\n\n",tt++,ans);
    }
   
    return 0;
}
