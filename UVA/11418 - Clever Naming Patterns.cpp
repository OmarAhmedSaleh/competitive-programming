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
int n,m,tc,flow[101][101],res[101][101],dis[101],work[101],st=99,t=100,ans,oo=1000000009;
vector<int> e[101];
string s;
vector<string> es[101];
int dfs(int idx,int mn){
    //cout<<idx<<" "<<mn<<endl;
    if(idx==t){return mn;}
    for(int &i=work[idx];i<e[idx].size();i++){
        int to=e[idx][i];
        if(flow[idx][to]<res[idx][to]&&dis[to]==dis[idx]+1){
            int ret= dfs(to,min(mn,res[idx][to]-flow[idx][to]));
            if(ret>0){
                flow[idx][to]+=ret;
                flow[to][idx]-=ret;
                return ret;
            }
        }
    }

    return 0;
}

int main(){
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++){
        memset(flow,0,sizeof(flow));
        memset(res,0,sizeof(res));
        for(int i=0;i<101;i++){
            e[i].clear();
            es[i].clear();
        }
        scanf("%d",&n);
       
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            for(int j=0;j<m;j++){
                cin>>s;
                for(int k=0;k<s.size();k++){
                    s[k]=tolower(s[k]);
                }
                s[0]=toupper(s[0]);

                char c=s[0];
                es[26+i].push_back((string)s);
                e[c-'A'].push_back(26+i);
                res[c-'A'][26+i]=1;
                e[26+i].push_back(c-'A');
            }
        }
        for(int i=0;i<n;i++){
            e[st].push_back(i);
            res[st][i]=1;
            e[i].push_back(st);
            
            e[26+i].push_back(t);
            res[26+i][t]=1;
            e[t].push_back(26+i);

        }
        while(1){
            memset(dis,-1,sizeof(dis));
            memset(work,0,sizeof(work));
            dis[st]=0;
            queue<int> q;
            q.push(st);
            while(!q.empty()){
                int from=q.front();
                q.pop();
                for(int i=0;i<e[from].size();i++){
                    int to=e[from][i];
                    if(dis[to]==-1&&flow[from][to]<res[from][to]){
                        dis[to]=dis[from]+1;
                        q.push(to);
                    }
                }
            }
            if(dis[t]==-1){break;}
            while(int f=dfs(st,oo)){ans+=f;}
        }
        vector<string> o;
        for(int i=0;i<n;i++){
            bool f=0;
            for(int j=0;j<e[i].size();j++){
                int tt=e[i][j];
                if(!f&&flow[i][tt]){
                for(int kk=0;kk<es[tt].size();kk++){
                        if(toupper(es[tt][kk][0])-'A'== i){
                            o.push_back(es[tt][kk]);
                            f=1;
                            break;
                        }
                    }
                }
            }
        }
        printf("Case #%d:\n",tt);
        for(int i=0;i<o.size();i++){
            printf("%s\n",o[i].c_str());
        }
    }
    
    return 0;
}
