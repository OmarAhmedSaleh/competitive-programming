#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int t,tc,n,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},ans;
char ch,g[101][101];
bool valid(int i,int j){
return i>-1&&j>-1&&i<n&&j<n;
}

void dfs(int a,int b){
g[a][b]='.';
int curx,cury;
for(int i=0;i<4;i++){
curx=a+dx[i];cury=b+dy[i];
if(valid(curx,cury)&&g[curx][cury]!='.'){dfs(curx,cury);}
}}
int main()
{
    //freopen("in.txt","r",stdin);

scanf("%d",&t);

while(t--){
    scanf("%d",&n);
    ans=0;
    for(int i=0;i<n;i++){scanf(" %s",&g[i]);}
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]=='x'){ans++;dfs(i,j);}

        }

    }
   printf("Case %d: %d\n",++tc,ans);
}


    return 0;
}
