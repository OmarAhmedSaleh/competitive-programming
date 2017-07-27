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
// ss
using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
const int N=100005;
struct mes{
    char c;
    int id;
};
int n , m;
bool no[N];
mes all[N];
int p[N];
int main(){
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<m;i++){
        cin>>all[i].c>>all[i].id;
    }
    int on=0;
    for(int i=0;i<m;i++){
        if(all[i].c=='+'){
            p[all[i].id]=1;
        }
        if(all[i].c=='-'&&!p[all[i].id]){
            p[all[i].id]=0;
            on++;
        }
    }
    for(int i=0;i<m;i++){
        if(all[i].c=='+'&&(on||(i>0&&all[i-1].id!=all[i].id))){
            no[all[i].id]=1;
        }
        if(all[i].c=='+'){
            on++;
        }
        if(all[i].c=='-'){
            on--;
        }
        if(all[i].c=='-'&&(on||(i+1<m&&(all[i+1].id!=all[i].id)))){
            no[all[i].id]=1;
        }

    }
    int k=0;
    for(int i=1;i<=n;i++){
        k+=1-no[i];
    }
    cout<<k<<endl;
    for(int i=1;i<=n;i++){
        if(!no[i]){
        cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;//rev Ab steps
}
  
