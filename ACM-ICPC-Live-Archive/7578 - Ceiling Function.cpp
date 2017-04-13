/*
 O(N*N*K)
 -build Binary search Tree
 -compare two BST using DFS
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
int n ,k,v,ans;
bool un[50];
struct BST{
    // Left , Right
    BST *child[2];
    int value;
    BST(){
        // constructor
        memset(child,0,sizeof(child));
        value=-1;
    }
    void insert(){
    
        if(value==-1){
            value=v;
            return ;
        }
        // left-> insert
        if(value>v){
            if(!child[0]){
                child[0]=new BST();
            }
            child[0]->insert();
            return ;
        }
        // right-> insert
        if(!child[1]){
            child[1]=new BST();
        }
        child[1]->insert();
    }
};
bool s;
void dfs(BST a,BST b){
    for(int i=0;i<2;i++){
        
        if(a.child[i]&&!b.child[i]){
                s=0;
                return ;
            }
            if(!a.child[i]&&b.child[i]){
                s=0;
                return ;
            }
    }
    if(a.child[0]){
        dfs(*a.child[0],*b.child[0]);
    }
    if(a.child[1]){
        dfs(*a.child[1],*b.child[1]);
    }

}
BST all[50];
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(all,0,sizeof(all));
        for(int i=0;i<n;i++){
            un[i]=1;
            for(int j=0;j<k;j++){
                scanf("%d",&v);
                all[i].insert();
            }
        }
        ans=n;
        for(int i=0;i<n;i++){
            if(!un[i]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                s=1;
                dfs(all[i],all[j]);
                if(s){
                    ans--;
                    un[j]=0;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;

}
