/*
 
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
//const long long OO=4e18;
//const int MAX=100000<<2;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
int n , m ;
vector<pair<int,int> > all,cur,ans;
void bk(int idx){
    if(idx==all.size()){
        if(cur.size()> ans.size()){ans=cur;}
        return ;
    }
    bk(idx+1);
    if(cur.empty()){
        cur.push_back(all[idx]);
        bk(idx+1);
        cur.pop_back();
    }else{
        bool ok=1;
        for(int i=0;i<cur.size();i++){
            int xx=cur[i].first-all[idx].first;
            int yy=cur[i].second-all[idx].second;
            xx*=xx;yy*=yy;
            int sq=sqrt(xx+yy);
            if(sq*sq == xx+yy){
                ok=0;
                break;
            }
        }
        if(ok){
            cur.push_back(all[idx]);
            bk(idx+1);
            cur.pop_back();
        }else{
            bk(idx+1);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    int nn=n,mm=m;
    if(n>m){swap(n,m);}
    int xx=0,yy=m;
    while(xx<=max(nn,mm)&&yy>-1){
        all.push_back(make_pair(xx,yy));
        xx++;yy--;
        if(all.back().first>-1 && all.back().first<=nn && all.back().second>-1 && all.back().second<=mm){ans.push_back(all.back());}
    }
    
   // bk(0);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
    
    return 0;
}
