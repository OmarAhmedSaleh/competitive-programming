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
const int N=500010;
int x[N];
vector<pair<int,int> > e[N];  
int n;
int ans[N];
bool vis[N];
int t;
vector<pair<long long,int> > path;
int lazy[N];
long long dis[N];
void dfs(int idx,long long cur){
       dis[idx]=cur;
      vis[idx]=1;
      path.push_back(make_pair(dis[idx],idx));
      for(int i=0;i<e[idx].size();i++){
           int vv=e[idx][i].first;
           if(!vis[vv]){
              dfs(vv,cur+e[idx][i].second);
 		if(lazy[path.size()]>0){
          ans[path.back().second]+=lazy[path.size()];
          if(path.size()){lazy[path.size()-1]+=lazy[path.size()];}
          lazy[path.size()]=0;

      }
               

 }
		}
      int pos=lower_bound(path.begin(),path.end(),make_pair(dis[idx]-x[idx],-1))-path.begin();

      if(pos<path.size()-1){
           lazy[path.size()-1]+=1;
           if(pos){lazy[pos]+=-1;}
        }
      path.pop_back();

}

int main(){
    //  freopen("in.txt","r",stdin);
   //	 freopen("out.txt","w",stdout);	


      scanf("%d",&n);
      for(int i=1;i<=n;i++){
           e[i].clear();
           ans[i]=0;
           dis[i]=0;
           vis[i]=0;
           lazy[i]=0;           
      }

      path.clear();

      for(int i=1;i<=n;i++){ 
        scanf("%d",&x[i]);
      }         
      int a,b,c;
      for(int i=1;i<n;i++){
          scanf("%d%d",&a,&b);
          e[i+1].push_back(make_pair(a,b));
          e[a].push_back(make_pair(i+1,b));

      }
      dfs(1,0);
      for(int i=1;i<=n;i++){
           if(i>1){printf(" ");}
           printf("%d",ans[i]);
           }
      puts(" ");



      return 0;

}
