#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int t,pos,x,y,f,sz,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char g[100][100];
bool valid(int i,int j){
return i>-1&&j>-1&&i<pos&&j<sz;
}
void dfs(int a,int b){
g[a][b]='#';
int curx,cury;
for(int i=0;i<4;i++){
curx=dx[i]+a;cury=dy[i]+b;
if(valid(curx,cury)&&g[curx][cury]==' '){
    dfs(curx,cury);
}
}

}

int main()
{
//freopen("in.txt","r",stdin);

scanf("%d",&t);
        cin.ignore();
while(t--){
    pos=0;
    f=0;
    sz=-1;
    while(1){
        gets(g[pos]);
        //cout<<g[pos]<<endl;
        if(sz==-1){
        sz=strlen(g[pos]);
        }
        if(g[pos][0]=='_'){break;}
        if(!f){
            for(int i=0;i<sz;i++){
                if(g[pos][i]=='*'){x=pos;y=i;f=1;break;}
}}
pos++;
}
dfs(x,y);
for(int i=0;i<=pos;i++){
   printf("%s\n",g[i]);
}
}
    return 0;
}
