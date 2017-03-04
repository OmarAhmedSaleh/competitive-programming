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
using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

const int N=200005;
vector<int> all[N];
int n,q,k,r;
int a,b;
set<pair<int,int> > s;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        
        if(all[a].size()){
            pair<int,int> p=make_pair(all[a].back(),a);

            s.erase(p);
        }
        all[a].push_back(b);
        s.insert(make_pair(b,a));
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&k);
        vector<pair<int,int> > allr;
        for(int j=0;j<k;j++){
            scanf("%d",&r);
            pair<int,int> p;
            if(all[r].empty()){continue;}
            p=make_pair(all[r].back(),r);
            allr.push_back(p);
            s.erase(p);
        }
       

        if(!s.size()){
            printf("%d %d\n",0,0);
        }else{
        set<pair<int,int> >::iterator it=s.end();
        if(s.size()==1){
            it--;
            printf("%d %d\n",(*it).second,all[(*it).second][0]);
        }else{
        set<pair<int,int> >::iterator sec=s.end();
        sec--;
        sec--;
        it--;
        int ll=(*sec).first;
        int pos=upper_bound(all[(*it).second].begin(),all[(*it).second].end(),ll)-all[(*it).second].begin();
        if(pos==all[(*it).second].size()){pos--;}
        int kk=all[(*it).second][pos];
        while(pos<all[(*it).second].size()&&pos>-1&&all[(*it).second][pos]>ll){
            kk=all[(*it).second][pos];
            pos--;
        }
            printf("%d %d\n",(*it).second,kk);
        }}
        for(int ww=0;ww<allr.size();ww++){
            s.insert(allr[ww]);
        
        }
    }
    
    return 0;//rev Ab steps
}
