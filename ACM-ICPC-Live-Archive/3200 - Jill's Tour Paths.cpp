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

int n , m, a,b,c,s,d,mx;
map<vector<int> ,int > mp[22];
vector<pair<int,int > > e[22];
bool vis[22];
vector<int> vv;

vector<pair<int,vector<int> > >all;

void bk(int idx,int cur){
    if(idx==d){
        all.push_back(make_pair(cur,vv));
        return ;
    }
    for(int i=0;i<e[idx].size();i++){
        int to=e[idx][i].first;
        int w=e[idx][i].second;
        if(!vis[to]&&cur+w<=mx){
            vv.push_back(to);
            vis[to]=1;
            bk(to,cur+w);
            vis[to]=0;
            vv.pop_back();
        }
        
    }

}


int tt;



int main(){
   

        while(scanf("%d",&n)==1){
        if(n==-1){
            break;
        }
        scanf("%d",&m);
        if(tt){
            printf("\n");
        }
        all.clear();
        for(int i=0;i<=20;i++){
            mp[i].clear();
            e[i].clear();
        }
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            e[a].push_back(make_pair(b,c));
            e[b].push_back(make_pair(a,c));
        }
                scanf("%d%d",&s,&d);
                scanf("%d",&mx);
                memset(vis,0,sizeof(vis));
                vis[s]=1;
                vv.clear();
                vv.push_back(s);
                bk(s,0);
            printf("Case %d:\n",++tt);
            set<pair<int,vector<int> > > st;
        if(all.size()==0){
            cout<<" NO ACCEPTABLE TOURS"<<endl;
        }else{
            for(int i=0;i<all.size();i++){
                st.insert(all[i]);
            }
            all.clear();
            set<pair<int,vector<int> > > ::iterator it=st.begin();
            while(it!=st.end()){
                all.push_back(*it);
                            it++;
            }
            for(int i=0;i<all.size();i++){
                st.insert(all[i]);
                printf(" %d%c ",all[i].first,':');
                for(int j=0;j<all[i].second.size();j++){
                    printf("%d ",all[i].second[j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
