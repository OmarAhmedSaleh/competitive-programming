/*
 all the different hieroglyphic shapes contain a different number of “holes”.
 find the connected regions of the picture and then, for every
 black region R, count how many different white regions are adjacent to R (making sure to
 pad the entire picture with a white frame to make the outer region one single region).

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
int h ,w, mark[2][201][201],cc;
vector<int> g[201];
map<char,string > mp;
bool vis[201][201],bad[201*201];
set<int> all[201*201];

bool valid(int xx,int yy){
    return xx>-1&&yy>-1&&xx<h&&yy<w;
}

void dfsb(int xx,int yy){
    mark[1][xx][yy]=cc;
    vis[xx][yy]=1;
    for(int i=0;i<4;i++){
        int new_x=dx[i]+xx;
        int new_y=dy[i]+yy;
        if(valid(new_x,new_y)&&g[new_x][new_y]&&!vis[new_x][new_y]){
            dfsb(new_x,new_y);
        }
    }
}
void dfsw(int xx,int yy){
    mark[0][xx][yy]=cc;
    vis[xx][yy]=1;
    for(int i=0;i<4;i++){
        int new_x=dx[i]+xx;
        int new_y=dy[i]+yy;
        if(!valid(new_x,new_y)){
            bad[mark[0][xx][yy]]=1;
        }else{
            if(!vis[new_x][new_y]){
                if(!g[new_x][new_y]){
                    dfsw(new_x,new_y);
                }else{
                    all[mark[1][new_x][new_y]].insert(mark[0][xx][yy]);
                }
            }
        }
    }
}
string ss="WAKJSD",s;

int main(){
    mp['0']="0000";
    mp['1']="0001";
    mp['2']="0010";
    mp['3']="0011";
    mp['4']="0100";
    mp['5']="0101";
    mp['6']="0110";
    mp['7']="0111";
    mp['8']="1000";
    mp['9']="1001";
    mp['a']="1010";
    mp['b']="1011";
    mp['c']="1100";
    mp['d']="1101";
    mp['e']="1110";
    mp['f']="1111";
    
    int tt=1;
   
    while(scanf("%d%d",&h,&w)){
        if(!h&&!w){
            break;
        }
        char c;
        for(int i=0;i<h;i++){
            g[i].clear();
            for(int j=0;j<w;j++){
                cin>>c;
                 s=mp[c];
                for(int k=0;k<(int)s.size();k++){
                    g[i].push_back(s[k]-'0');
                }
            }
        }
        w*=4;
        memset(vis,0,sizeof(vis));
        memset(mark,0,sizeof(mark));
        memset(bad,0,sizeof(bad));
        int pos=0;
        for(int i=0;i<=h;i++){
            for(int j=0;j<=w;j++){
                all[pos++].clear();
            }
        }
        cc=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!vis[i][j]&&g[i][j]){
                    cc++;
                    dfsb(i,j);
                }
            }
        }
        int cb=cc;
        memset(vis,0,sizeof(vis));
        cc=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!vis[i][j]&&!g[i][j]){
                    cc++;
                    dfsw(i,j);
                }
            }
        }
        string ans="";
        set<int> :: iterator it;
        for(int i=1;i<=cb;i++){
            it=all[i].begin();
            int cnt=0;
            while(it!=all[i].end()){
                cnt++;
                if(bad[*it]){
                    cnt--;
                }
                it++;
            }
            ans+=ss[cnt];
        }
        sort(ans.begin(),ans.end());
        printf("Case %d: %s\n",tt++,ans.c_str());
    }
    
    return 0;
}
