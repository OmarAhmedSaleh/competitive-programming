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
#include <queue>

using namespace std;
const int N=20004;
const int oo=1000000009;
int tc;
vector<pair<int,int> > e[N];
int n,a,b,c,m,s,t;
int dis[N];



int main(){
   //freopen("in.txt","r",stdin);
scanf("%d",&tc);
for(int tt=1;tt<=tc;tt++){
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=0;i<=n;i++){
        e[i].clear();
        dis[i]=oo;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        e[a].push_back(make_pair(b,c));
        e[b].push_back(make_pair(a,c));

    }
    dis[s]=0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int vv=pq.top().second;
        int dd=-pq.top().first;
        pq.pop();
        if(dis[vv]<dd){continue;}
    for(int i=0;i<e[vv].size();i++){
        b=e[vv][i].first;
        if(dis[b]>dis[vv]+e[vv][i].second){
            dis[b]=dis[vv]+e[vv][i].second;
                pq.push(make_pair(-dis[b],b));

        }

    }
    }
printf("Case #%d: ",tt);
if(dis[t]==oo){
    printf("unreachable\n");

}else{
printf("%d\n",dis[t]);
}
}





return 0;}
