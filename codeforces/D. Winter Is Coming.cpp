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
 */

const int N=300005;
int n,k;
int a[N];
int e,neg;
int ans=0;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            neg++;
        }
    }
    if(neg>k){
        puts("-1");
        return 0;
    }
    int pos=-1;
    for(int i=0;i<n;i++){
        if(a[i]<0){pos=i;break;}
    }
    if(pos==-1){
        puts("0");
        return 0;
    }
    int t=1;
    int sum=0;
    bool las=0;
    for(int i=pos;i<n;i++){
        if(t&&a[i]>-1){
            t^=1;
            sum++;
        }
        if(!t&&a[i]<0){
            t^=1;
            sum++;

        }
    }
    if(!las){
        sum++;
    }
    int s=pos;
    vector<pair<int,int> > all;
    las=0;
    for(int i=pos;i<n;i++){
        if(a[i]<0&&s==-1){
            s=i;
        }
        if(a[i]>-1&&s!=-1){
            all.push_back(make_pair(s,i-1));
            s=-1;
        }
        if(s!=-1&&(i+1)==n){
         all.push_back(make_pair(s,n-1));
            s=-1;
            las=1;
        }
    }
    int et=k-neg;
    ans=sum;
    if(!et){
        printf("%d\n",ans);
        return 0;
    }
    if(!las){
    all.push_back(make_pair(n,-2));
    }
    vector<int> mn;
    for(int i=0;i<all.size();i++){
      //  cout<<all[i].first<<" "<<all[i].second<<endl;
    }
    for(int i=1;i<all.size();i++){
        if(!las&&(i+1)==all.size()){break;}
        int df=all[i].first-all[i-1].second;
        df--;
        if(!df){continue;}
        mn.push_back(df);
        
    }
    if(mn.size()){
    sort(mn.begin(),mn.end());
    }
    for(int i=0;i<mn.size();i++){
        if(et>=mn[i]){
            ans-=2;
            et-=mn[i];
       }
    }
if(all.size()>1&&et&&!las){
    int oo=all.back().first-all[(int)all.size()-2].second;
    oo--;
    if(et>=oo){
    ans--;
    }
    }
    printf("%d\n",ans);
    /*
     -- Valid
     -- const (10^9>sz)
     -- array index
     -- less or more , check if
     -- even or odd
     */
    return 0;
}
