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
//const long long OO=4e18;
const int oo=1e9;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};
class WordPattern{
public:
    int g[101][101];
    long long cnt[101][101];
    long long countWords(string word){
        int sz=(int)word.size();
        for(int i=0;i<2*sz;i++){
            for(int j=0;j<2*sz;j++){
                g[i][j]=-1;
                cnt[i][j]=0;
            }
        }
        g[sz-1][sz-1]=0;
        queue<pair<int,int> > q;
        q.push(make_pair(sz-1,sz-1));
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(g[x][y]==sz-1){
                cnt[x][y]=1;
                continue;
            }
            for(int i=0;i<4;i++){
                int xx=dx[i]+x;
                int yy=dy[i]+y;
                if(xx<0||yy<0||xx>=2*sz||yy>=2*sz||g[xx][yy]!=-1){continue;}
                g[xx][yy]=g[x][y]+1;
                q.push(make_pair(xx,yy));
            }
        }
        for(int i=sz-1;i>0;i--){
            for(int j=0;j<2*sz;j++){
                for(int k=0;k<2*sz;k++){
                    if(g[j][k]!=i){continue;}
                    for(int kk=0;kk<4;kk++){
                        int xx=j+dx[kk];
                        int yy=k+dy[kk];
                        if(xx<0||yy<0||xx>=2*sz||yy>=2*sz||g[xx][yy]!=g[j][k]-1){continue;}
                        cnt[xx][yy]+=cnt[j][k];
                    }
                }
            }
        }
        return cnt[sz-1][sz-1];
    }
    
};
