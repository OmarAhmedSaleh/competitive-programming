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
string s;
vector<string> g;
int b,w;
int t;
bool vis[9][9];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int mark[111][2];
int c[111];
int cc;
bool valid(int a,int b){
return a>-1&&b>-1&&a<9&&b<9;
}
void dfs(int a,int b,char l){
vis[a][b]=1;
if(l=='.'){c[cc]++;}
for(int k=0;k<4;k++){
    int x=dx[k]+a;
    int y=dy[k]+b;
    if(valid(x,y)){
        if(l=='.'&&g[x][y]!='.'){
            mark[cc][1]|=(g[x][y]=='O');
            mark[cc][0]|=(g[x][y]=='X');

        }
        if(l==g[x][y]&&!vis[x][y]){dfs(x,y,l);}


    }
}
}
int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    scanf("%d",&t);
while(t--){
        g.clear();
memset(mark,0,sizeof(mark));
memset(c,0,sizeof(c));
memset(vis,0,sizeof(vis));
    for(int i=0;i<9;i++){
        cin>>s;
        g.push_back(s);

    }
    b=w=0;
        cc=0;
for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
                b+=g[i][j]=='X';
                w+=g[i][j]=='O';
            if(!vis[i][j]){
                if(g[i][j]=='.'){cc++;}
                dfs(i,j,g[i][j]);
            }

        }


        }
for(int i=0;i<111;i++){
    if(mark[i][0]&&!mark[i][1]){b+=c[i];}
    if(!mark[i][0]&&mark[i][1]){w+=c[i];}
}



        printf("Black %d White %d\n",b,w);



}    return 0;
}
