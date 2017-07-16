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
//const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
int n , m, l[100000],r[100000],ty,x,y,rev;
void right(int xx,int yy){
    if(r[yy]==xx){return;}//right
    int lf_xx=l[xx],r_xx=r[xx],r_yy=r[yy];
    if(l[yy]==xx){
        // left
        r[xx]=r_yy;
        r[yy]=xx;
        if(r_yy!=-1){
            l[r_yy]=xx;
        }
        l[yy]=lf_xx;
        l[xx]=yy;
        if(lf_xx!=-1){
            r[lf_xx]=yy;
        }
        return ;
    }
    if(r_xx!=-1){
        l[r_xx]=lf_xx;
    }
    if(lf_xx!=-1){
        r[lf_xx]=r_xx;
    }
    l[xx]=yy;
    r[yy]=xx;
    r[xx]=r_yy;
    if(r_yy!=-1){
        l[r_yy]=xx;
    }
    
}

void left(int xx,int yy){
    if(l[yy]==xx){return ;}//left
    int lf_xx=l[xx],lf_yy=l[yy],r_xx=r[xx];
    if(r[yy]==xx){
    // Right
        r[xx]=yy;
        l[xx]=lf_yy;
        r[yy]=r_xx;
        l[yy]=xx;
        if(r_xx!=-1){
            l[r_xx]=yy;
        }
        if(lf_yy!=-1){
            r[lf_yy]=xx;
        }
        return ;
    }
    if(r_xx!=-1){
        l[r_xx]=lf_xx;
    }
    if(lf_xx!=-1){
        r[lf_xx]=r_xx;
    }
    r[xx]=yy;
    l[xx]=lf_yy;
    l[yy]=xx;
    if(lf_yy!=-1){
        r[lf_yy]=xx;
    }
}
void sw(int xx,int yy){
    int lf_xx=l[xx],lf_yy=l[yy],r_xx=r[xx],r_yy=r[yy];
    if(l[xx]==yy){
        left(xx,yy);
        return;
    }
    if(r[xx]==yy){
        right(xx,yy);
        return ;
    }
    swap(l[xx],l[yy]);
    swap(r[xx],r[yy]);
    if(r_xx!=-1){
        l[r_xx]=yy;
    }
    
    if(lf_xx!=-1){
        r[lf_xx]=yy;
    }
    
    if(r_yy!=-1){
        l[r_yy]=xx;
    }
    
    if(lf_yy!=-1){
        r[lf_yy]=xx;
    }
    
}
int tc=1;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(l,-1,sizeof(l));
        memset(r,-1,sizeof(r));
        for(int i=0;i<n;i++){
            l[i]=i-1;
            r[i]=i+1;
        }
        r[n-1]=-1;
        l[0]=-1;
        rev=0;
        while(m--){
            scanf("%d",&ty);
            if(ty==4){
                rev^=1;
                continue;
            }
            scanf("%d%d",&x,&y);
            if(x==y){continue;}
            if(rev&&ty!=3){
                if(ty==1){
                    ty=2;
                }else{
                    ty=1;
                }
            }
            x--;y--;
            if(ty==1){
                left(x,y);
            }
            if(ty==2){
                right(x,y);
            }
            if(ty==3){
                sw(x,y);
            }
        }
        int idx=-1;
        //cout<<endl;
        for(int i=0;i<n;i++){
          //  cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
            if(l[i]==-1){idx=i;break;}
        }
        //cout<<endl;
        vector<int> v;
        while(idx!=-1){
          //  cout<<idx<<" ";
            v.push_back(idx);
            idx=r[idx];
        }
      //  cout<<endl;
        if(rev){reverse(v.begin(),v.end());}
        idx=0;
        long long ans=0;
        //cout<<endl;
        while(idx<(int)v.size()){
          //  cout<<v[idx]<<" ";
            ans+=v[idx]+1;
            idx+=2;
        }
        //cout<<endl;
        printf("Case %d: %lld\n",tc++,ans);
    }
    return 0;
}
